#ifndef MYGPIO___
#define MYGPIO___

//___include files______________________________________________
//___project defines____________________________________________

#define LED1 12
#define LED2 13

#define KNOP1 27
#define KNOP2 14



//___project variabele__________________________________________
//___project new type___________________________________________
//___project functies___________________________________________

void MyGPIO_setup_output(int pin);
void MyGPIO_setup_button(int pin);

int MyGPIO_read(int pin);
int MyGPIO_flank(int pin);

void MyGPIO_write(int pin, int value);
void MyGPIO_toggle(int pin);



#endif