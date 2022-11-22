/******************************************************************************
*
* Module: ADC
*
* File Name: adc.h
*
* Description: header file for the ATmega32 ADC driver
*
* Author: Mohamed Elshaer
*
*******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include "std_types.h"

/*******************************************************************************
*                                Definitions                                  *
*******************************************************************************/
#define ADC_MAXIMUM_VALUE    1023
#define ADC_REF_VOLT_VALUE   2.56


typedef enum {
	NO_prescaler,F_CPU_2,F_CPU_4,F_CPU_8_,F_CPU_16,F_CPU_32,F_CPU_64_,F_CPU_128
}ADC_Prescaler;

typedef enum {
	AREF,AVCC,Reserved,internalVoltage
}ADC_ReferenceVolatge;

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*******************************************************************************
*                      Functions Prototypes                                   *
*******************************************************************************/

/*
* Description :
* Function responsible for initialize the ADC driver.
*/
void ADC_init(const ADC_ConfigType * Config_Ptr);
/*
* Description :
* Function responsible for read analog data from a certain ADC channel
* and convert it to digital using the ADC driver.
*/
uint16 ADC_readChannel(uint8 channel_num);

#endif /* ADC_H_ */