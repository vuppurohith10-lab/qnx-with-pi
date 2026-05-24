#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/dispatch.h>

typedef struct
{
    char text[32];
} lcd_msg_t;

int main()
{
    int coid;

    lcd_msg_t msg;

    // Connect to server
    coid = name_open("lcd_server", 0);

    if(coid == -1)
    {
        perror("name_open");
        return -1;
    }

    printf("Enter Text: ");

    fgets(msg.text, sizeof(msg.text), stdin);

    // Remove newline
    msg.text[strcspn(msg.text, "\n")] = 0;

    // Send text to server
    MsgSend(coid, &msg, sizeof(msg), NULL, 0);

    name_close(coid);

    return 0;
}
