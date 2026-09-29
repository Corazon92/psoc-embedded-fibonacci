#include "fonction.h"

CY_ISR(moninter)
{
    PWM_1_ReadStatusRegister();

    static volatile uint16 period;
    static volatile uint16 data;
    static volatile uint16 compare0;

    data = ADC_period_GetResult16();
    period = (360 - 65535) * data / 4095 + 65535;

    PWM_1_WritePeriod(period);
    PWM_2_WritePeriod(period);
    PWM_3_WritePeriod(period);
    PWM_WritePeriod(period / 20);

    PWM_1_WriteCompare1(period / 2);
    PWM_1_WriteCompare2(period / 2);
    PWM_2_WriteCompare1(2 * period / 3);
    PWM_2_WriteCompare2(period / 6);
    PWM_3_WriteCompare1(5 * period / 6);
    PWM_3_WriteCompare2(period / 3);

    compare0 = 116644 / (20 * period) + period / 200;
    PWM_WriteCompare(compare0);
}

void startup(void)
{
    Clock_Start();
    isr_StartEx(moninter);
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    PWM_Start();

    Opamp_period_Start();
    ADC_period_Start();
    ADC_period_StartConvert();
}
