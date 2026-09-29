#include "fonction.h"

void startup(void)
{
    ADC_tension_StartConvert();
    ADC_courant_StartConvert();
    Clock_Start();
    PGA_courant_Start();
    ADC_courant_Start();
    ADC_tension_Start();
    Opamp_tension_Start();
    PWM_Start();
}
