#include <stdio.h>
#include <sys/neutrino.h>
#include <sys/dispatch.h>

typedef struct {
    int num;
} my_msg_t;

int main() {
    int coid;
    my_msg_t msg;

    // Connect using server name
    coid = name_open("segment_server", 0);

    if(coid == -1) {
        perror("name_open failed");
        return -1;
    }

   printf("Enter number (0-9): ");
    scanf("%d", &msg.num);
    MsgSend(coid, &msg, sizeof(msg), NULL, 0);

    return 0;
}
