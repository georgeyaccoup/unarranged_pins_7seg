/*
 * main.c
 *
 *  Created on: 2 Jul 2023
 *      Author: george yaccoup
 */
#include "DIO_int.h"
#include "stdTypes.h"
#include <util/delay.h>
void SSG_voiddisplay(u8 Copy_u8num) {
	if (Copy_u8num <= 9) {
		DIO_vidSetPinValue(DIO_GROUP_A, DIO_PIN_1, ((Copy_u8num >> 0) & 1));
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_0, ((Copy_u8num >> 1) & 1));
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_3, ((Copy_u8num >> 2) & 1));
		DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_5, ((Copy_u8num >> 3) & 1));
	}
}
int main(){
	DIO_vidSetPinDirection(DIO_GROUP_A, DIO_PIN_1,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_0,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_3,DIO_OUTPUT);
	DIO_vidSetPinDirection(DIO_GROUP_B, DIO_PIN_5,DIO_OUTPUT);
	DIO_vidSetPinValue(DIO_GROUP_A, DIO_PIN_1,DIO_LOW);
	DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_0,DIO_LOW);
	DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_3,DIO_LOW);
	DIO_vidSetPinValue(DIO_GROUP_B, DIO_PIN_5,DIO_LOW);
	while (1) {
		for (int i = 0; i < 10; i++) {
			SSG_voiddisplay(i);
			_delay_ms(500);
		}
	}



}
