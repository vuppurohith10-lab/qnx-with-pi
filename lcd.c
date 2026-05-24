#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/mman.h>
#include <hw/inout.h>
#include <sys/neutrino.h>

#define GPIO_BASE 0xFE200000

// GPIO Registers
#define GPFSEL1 0x04
#define GPFSEL2 0x08
#define GPSET0  0x1C
#define GPCLR0  0x28

// LCD Pins
#define LCD_RS 17
#define LCD_EN 27
#define LCD_D4 22
#define LCD_D5 23
#define LCD_D6 24
#define LCD_D7 25

uintptr_t gpio_base;

// --------------------------------------------
// GPIO Functions
// --------------------------------------------

void gpio_output(int pin)
{
    uintptr_t fsel_reg = gpio_base + ((pin / 10) * 4);
    uint32_t value = in32(fsel_reg);

    value &= ~(7 << ((pin % 10) * 3));
    value |=  (1 << ((pin % 10) * 3));

    out32(fsel_reg, value);
}

void gpio_write(int pin, int value)
{
    if(value)
        out32(gpio_base + GPSET0, (1 << pin));
    else
        out32(gpio_base + GPCLR0, (1 << pin));
}

// --------------------------------------------
// LCD Functions
// --------------------------------------------

void lcd_enable()
{
    gpio_write(LCD_EN, 1);
    usleep(1);

    gpio_write(LCD_EN, 0);
    usleep(100);
}

void lcd_send_nibble(uint8_t nibble)
{
    gpio_write(LCD_D4, (nibble >> 0) & 1);
    gpio_write(LCD_D5, (nibble >> 1) & 1);
    gpio_write(LCD_D6, (nibble >> 2) & 1);
    gpio_write(LCD_D7, (nibble >> 3) & 1);

    lcd_enable();
}

void lcd_send_byte(uint8_t data, int rs)
{
    gpio_write(LCD_RS, rs);

    lcd_send_nibble(data >> 4);
    lcd_send_nibble(data & 0x0F);

    usleep(2000);
}

void lcd_command(uint8_t cmd)
{
    lcd_send_byte(cmd, 0);
}

void lcd_data(uint8_t data)
{
    lcd_send_byte(data, 1);
}

void lcd_init()
{
    usleep(50000);

    lcd_command(0x33);
    lcd_command(0x32);

    lcd_command(0x28); // 4-bit, 2-line
    lcd_command(0x0C); // display on
    lcd_command(0x06); // increment cursor
    lcd_command(0x01); // clear display

    usleep(5000);
}

void lcd_print(char *str)
{
    while(*str)
    {
        lcd_data(*str++);
    }
}

// --------------------------------------------

int main()
{
    if(ThreadCtl(_NTO_TCTL_IO, 0) == -1)
    {
        perror("ThreadCtl");
        return -1;
    }

    gpio_base = mmap_device_io(0xB4, GPIO_BASE);

    // Configure GPIOs
    gpio_output(LCD_RS);
    gpio_output(LCD_EN);

    gpio_output(LCD_D4);
    gpio_output(LCD_D5);
    gpio_output(LCD_D6);
    gpio_output(LCD_D7);

    lcd_init();

    lcd_print("Hello Rohith");

    return 0;
}
