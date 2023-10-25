/*
 * PWM_Freq_Calculation.h
 *
 *  Created on: 25 paü 2023
 *      Author: karol_d6xg4r2
 */

#ifndef PWM_FREQ_CALC_H_
#define PWM_FREQ_CALC_H_

#define fpwm 30e3
#define hspclkdiv 0
#define clkdiv 0
#define sysclk 150e6
#define tbprd (sysclk/(2 * 1 * 1 * fpwm))

//if (hspclkdiv == 0){
//    tbprd = (sysclk/(2 * 1 * 2^clkdiv * fpwm))
//}
//else{
//    tbprd = (sysclk/(2 * 2*hspclkdiv * 2^clkdiv * fpwm))
//}
//


//struct PWM_Calc_Struct{
//    unsigned long int F_PWM;
//    unsigned long int SYSCLK;
//    unsigned long int HSPCLKDIV;
//    unsigned long int CLKDIV;
//    unsigned long int TBPRD;
//};
//
//void PWM_Calc(struct PWM_Calc_Struct *pwm, int F_PWM, long int SYSCLK, int HSPCLKDIV, int CLKDIV);


#endif /* PWM_FREQ_CALC_H_ */
