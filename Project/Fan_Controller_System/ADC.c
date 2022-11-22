/*
 * ADC.c
 *
 *  Created on: Oct 1, 2022
 *      Author: Asus
 */

#include "ADC.h"
#include <avr/io.h>
#include "std_types.h"
#include "common_macros.h"

void ADC_init(const ADC_ConfigType * Config_Ptr){
	/*voltage selection = 2.56V*/
	ADMUX&=0x3F;
	ADMUX|=(0x00 | Config_Ptr-> ref_volt)<<6;

	CLEAR_BIT(ADMUX,ADLAR);	/*left adjustment off*/

	/*channel set to zero*/
	CLEAR_BIT(ADMUX,MUX0);
	CLEAR_BIT(ADMUX,MUX1);
	CLEAR_BIT(ADMUX,MUX2);
	CLEAR_BIT(ADMUX,MUX3);
	CLEAR_BIT(ADMUX,MUX4);

	SET_BIT(ADCSRA,ADEN); /*enable ADC*/

	CLEAR_BIT(ADCSRA,ADIE);/*disable intrrupts*/

	/*prescalar*/
	ADCSRA= (ADCSRA & 0xF8) | (ADCSRA | Config_Ptr->prescaler);

}
uint16 ADC_readChannel(uint8 ch_num){
	/*channel insertion*/
	ADMUX&=0xE0;
	ADMUX|=ch_num;

	SET_BIT(ADCSRA,ADSC);	/*start conversion*/

	/*polling*/
	while(bit_is_clear(ADCSRA,ADIF)){

	}
	SET_BIT(ADCSRA,ADIF);	/*clear flag*/

	return ADC;
}
