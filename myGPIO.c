#include <stdio.h>
//#include "rom/gpio.h"
#include "driver/gpio.h"


#include "myGPIO.h"

void MyGPIO_setup_output(int pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT_OUTPUT);

}
void MyGPIO_setup_button(int pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT);
    gpio_pullup_en(pin);

}

int MyGPIO_read(int pin)
{
    return gpio_get_level(pin);

}



int MyGPIO_flank(int pin)
{
    static int vroeger,nu;

    vroeger = nu;
    nu = (nu & ~(1<<pin))|(gpio_get_level(pin)<<pin);

    if(vroeger != nu)
    {
        if((nu & (1<<pin))==0)
        {
            return 1;
        }

    }
    return 0;
}

void MyGPIO_write(int pin, int value)
{
    gpio_set_level(pin, value);

}
void MyGPIO_toggle(int pin)
{
    gpio_set_level(pin, !gpio_get_level(pin));
}
