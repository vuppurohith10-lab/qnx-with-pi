#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("Starting LED blink on GPIO16...\n");

    /* Configure GPIO16 as output */
    system("gpio-bcm2711 set 16 op");

    while(1)
    {
        /* Turn LED ON */
        system("gpio-bcm2711 set 16 op dh");
        usleep(500000);

        /* Turn LED OFF */
        system("gpio-bcm2711 set 16 op dl");
        usleep(500000);
    }

    return 0;
}
