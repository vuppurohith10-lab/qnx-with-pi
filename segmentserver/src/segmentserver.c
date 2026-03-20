#include <stdio.h>
#include <stdlib.h>
#include <sys/neutrino.h>
#include <sys/dispatch.h>

typedef struct {
    int num;
} my_msg_t;

// GPIO pins (a b c d e f g)
int pins[7] = {17,18,27,22,23,24,25};

// Digit patterns
int digits[10][7] = {
    {1,1,1,1,1,1,0},
    {0,1,1,0,0,0,0},
    {1,1,0,1,1,0,1},
    {1,1,1,1,0,0,1},
    {0,1,1,0,0,1,1},
    {1,0,1,1,0,1,1},
    {1,0,1,1,1,1,1},
    {1,1,1,0,0,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};

void display(int n) {
    char cmd[100];

    if(n < 0 || n > 9) return;

    for(int i = 0; i < 7; i++) {
        if(digits[n][i] == 1)
            sprintf(cmd, "gpio-bcm2711 set %d op dh", pins[i]);
        else
            sprintf(cmd, "gpio-bcm2711 set %d op dl", pins[i]);

        system(cmd);
    }
}

int main() {
    name_attach_t *attach;
    int rcvid;
    my_msg_t msg;

    // Register server name
    attach = name_attach(NULL, "segment_server", 0);
    if(attach == NULL) {
        perror("name_attach failed");
        return -1;
    }

    printf("Server running...\n");

    while(1) {
        rcvid = MsgReceive(attach->chid, &msg, sizeof(msg), NULL);

        if(rcvid == -1)
            continue;

        printf("Received: %d\n", msg.num);

        display(msg.num);

        MsgReply(rcvid, 0, NULL, 0);
    }

    return 0;
}
