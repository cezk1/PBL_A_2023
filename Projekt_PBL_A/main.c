#include "DSP28x_Project.h"
/**
* main.c
*/


void GPIO_Setup(){
    EALLOW;

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ustawia wyjœcie na GPIO na ePWM
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1; // ustala wejœcie wyjœcie
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1; // pull up ressistor

    EDIS;
}

void PWMA_Setup(){
    EALLOW;

    EPwm1Regs.TBCTL.bit.CTRMODE = 2; // ustawienie trybu pracy up-down

    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 0; // ustawienie jednego z dzielnikow TBCLK
    EPwm1Regs.TBCTL.bit.CLKDIV = 0; // ustawienie drugiego z dzielnikow TBCLK
    // TBCLK = SYSCLKOUT/(HSPCLKDIV*CLKDIV), gdzie SYSCLKOUT wynosi standardowo 150MHz

    EPwm1Regs.TBCTL.bit.FREE_SOFT = 2;

    EPwm1Regs.AQCTLA.bit.CAU = 1; // Set: force EPWMxA output high (przy zliczaniu w gore)
    EPwm1Regs.AQCTLA.bit.CAD = 2; // Clear: force EPWMxA output low (przy zliczaniu w dol)

    EPwm1Regs.TBPRD = 750; // ustwienie okresu PWM (T_PWM = 2*TBPRD*T_TBCLK) (strona 3 w instrukcji do PWM)

    EPwm1Regs.CMPA.half.CMPA = 250; // ustawienie wypelnienia dla komparatora A


    EDIS;

}

void GPIO_toggle(){
    GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1; //przelacza wyjœcie miedzy stanami
}

int main(void)
{
    InitSysCtrl();
    GPIO_Setup();
    PWMA_Setup();

    DINT;

    while(1){

    __asm(" NOP");

    }
}

