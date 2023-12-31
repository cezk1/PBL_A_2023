#include "DSP28x_Project.h"
/**
* main.c
*/
#include "PWM_Freq_Calc.h"




void dzialajacy_PWMA(){
    EALLOW;

    EPwm1Regs.TBCTL.bit.CTRMODE = 2; // ustawienie trybu pracy up-down
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = hspclkdiv; // ustawienie jednego z dzielnikow TBCLK
    EPwm1Regs.TBCTL.bit.CLKDIV = clkdiv; // ustawienie drugiego z dzielnikow TBCLK
    // TBCLK = SYSCLKOUT/(HSPCLKDIV*CLKDIV), gdzie SYSCLKOUT wynosi standardowo 150MHz
    EPwm1Regs.TBCTL.bit.FREE_SOFT = 2;
    EPwm1Regs.AQCTLA.bit.CAU = 1; // Set: force EPWMxA output high (przy zliczaniu w gore)
    EPwm1Regs.AQCTLA.bit.CAD = 2; // Clear: force EPWMxA output low (przy zliczaniu w dol)
    EPwm1Regs.TBPRD = tbprd; // ustwienie okresu PWM (T_PWM = 2*TBPRD*T_TBCLK) (strona 3 w instrukcji do PWM)
    EPwm1Regs.CMPA.half.CMPA = 1225; // ustawienie wypelnienia dla komparatora A

    EDIS;
}

void pila_PWMA(){
    EALLOW;

    EDIS;
}

void GPIO_Setup(){
    EALLOW;

    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; // ustawia wyj�cie na GPIO na ePWM
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1; // ustala wej�cie wyj�cie
    GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1; // pull up ressistor

    EDIS;
}

void PWMA_Setup(){
    dzialajacy_PWMA();

}

void GPIO_toggle(){
    GpioDataRegs.GPATOGGLE.bit.GPIO0 = 1; //przelacza wyj�cie miedzy stanami
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

