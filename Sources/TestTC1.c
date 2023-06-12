/*
* SOUNDMUSIC1.c
*
* Created: 02.01.2014 9:51:31
*  Author: Big-Boss
*/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h> //библиотека нужна для работы прерываний
#include <Util/delay.h>


uint8_t i=0;
uint8_t melodia[30]={13, 22, 22, 20, 22, 18, 13, 13, 13, 22, 22, 23, 20, 25, 25, 25, 25, 15, 15, 23, 23, 22, 20, 18, 18, 22, 22, 20, 22, 18 };// melodia
uint8_t softTimer=0; //переменная для программного счетчика


void nota(uint8_t x) //Пианино на 12 ноток
{
	switch(x)
	{
		case 0: {OCR1A=10000;};break; //
		
		
		
		case 1: {OCR1A=30576;}; break; // 130.82 hz   "do" mal okt
		case 2: {OCR1A=28862;}; break; // 138.59 hz   "do diez" mal okt
		case 3: {OCR1A=27058;}; break; // 147.83 hz   "re" mal okt
		case 4: {OCR1A=25714;}; break; // 155.56 hz   "re dies" mal okt
		case 5: {OCR1A=24270;}; break; // 164.81 hz   "mi" mal okt
		case 6: {OCR1A=22907;}; break; // 174.62 hz   "fa" mal okt
		case 7: {OCR1A=21622;}; break; // 185.00 hz   "fa diez" mal okt
		case 8: {OCR1A=20408;}; break; // 196.00 hz   "sol" mal okt
		case 9: {OCR1A=19324;}; break; // 207.00 hz   "sol diez" mal okt
		case 10: {OCR1A=18182;}; break; // 220.00 hz   "lya" mal okt
		case 11: {OCR1A=17161;}; break; // 233.08 hz   "si bemol" mal okt
		case 12: {OCR1A=16197;}; break; // 246,96 hz   "si" mal okt
		case 13: {OCR1A=15289;};break; // 261,63 hz   "do" 1 okt
		case 14: {OCR1A=14431;};break; // 277,18 hz   "do diez" 1 okt
		case 15: {OCR1A=13621;};break; // 293,66 hz   "re" 1 okt
		case 16: {OCR1A=12856;};break;  // 311,13 hz   "re diez" 1 okt
		case 17: {OCR1A=12135;};break;  // 329,63 hz   "mi" 1 okt
		case 18: {OCR1A=11454;};break;  // 349,23 hz   "fa" 1 okt
		case 19: {OCR1A=10811;};break;  // 369,99 hz   "fa diez" 1 okt
		case 20: {OCR1A=10204;};break;  // 392,00 hz   "sol" 1 okt
		case 21: {OCR1A=9632;};break;   // 415,30 hz   "soi-diez" 1 okt
		case 22: {OCR1A=9091;};break;  // 440,00 hz   "lya" 1 okt
		case 23: {OCR1A=8581;};break;  // 466,16 hz   "si-bemol" 1 okt
		case 24: {OCR1A=8099;};break;  // 493,88 hz   "si" 1 okt
		case 25: {OCR1A=7645;}; break; // 523.25 hz   "do" 2 okt
		case 26: {OCR1A=7216;}; break; // 554.36 hz   "do-diez" 2 okt
		case 27: {OCR1A=6811;}; break; // 587.32 hz   "re" 2 okt
		case 28: {OCR1A=6428;}; break; // 622.26 hz   "re-diez" 2 okt
		case 29: {OCR1A=6067;}; break; // 659.26 hz   "mi" 2 okt
		case 30: {OCR1A=5727;}; break; // 698.46 hz   "fa" 2 okt
		case 31: {OCR1A=5406;}; break; // 739.98 hz   "fa-diez" 2 okt
		case 32: {OCR1A=5102;}; break; // 784.00 hz   "sol" 2 okt
		case 33: {OCR1A=4816;}; break; // 830.60 hz   "sol-diez" 2 okt
		case 34: {OCR1A=4545;}; break; // 880.00 hz   "lya" 2 okt
		case 35: {OCR1A=4290;}; break; // 932.32 hz   "si-bemol" 2 okt
		case 36: {OCR1A=4050;}; break; // 987.75 hz   "si" 2 okt
		case 37: {OCR1A=3822;}; break; // 1046.50 hz   "do" 3 okt
		//case 38: {OCR1A=10000}; break; // 493,88 hz   "do-diez" 3 okt
		//case 39: {OCR1A=10000}; break; // 493,88 hz   "re" 3 okt
		//case 40: {OCR1A=10000}; break; // 493,88 hz   "re-diez" 3 okt
		//case 41: {OCR1A=10000}; break; // 493,88 hz   "mi" 3 okt
		//case 42: {OCR1A=10000}; break; // 493,88 hz   "fa" 3 okt
		//case 43: {OCR1A=10000}; break; // 493,88 hz   "fa-diez" 3 okt
		//case 44: {OCR1A=10000}; break; // 493,88 hz   "sol" 3 okt
		//case 45: {OCR1A=10000}; break; // 493,88 hz   "sol-diez" 3 okt
		//case 46: {OCR1A=10000}; break; // 493,88 hz   "lya" 3 okt
		//case 47: {OCR1A=10000}; break; // 493,88 hz   "si-bemol" 3 okt
		//case 48: {OCR1A=10000}; break; // 493,88 hz   "si" 3 okt
	}
}

ISR(TIMER0_OVF_vect)
{

	if (softTimer==10 )
	{
		softTimer=0;
		
		if (i<30)
		{
			nota(melodia[i]);
			i++;
		}
		else {i=0;}
	}
	else {softTimer++;}

}

int main(void)
{
	DDRB=0b00000010; //Делаю выходом выход блока 16битного таймера.
	DDRD=0b00000100; //Делаю выходом ногу к которой подпаян светодиод.


	//Настрока таймера счетчика 0. Который меняет ноты и работает в прерывании.
	TCCR0B=0b00000101; //Тактовая частота для 0-го таймера.
	TIMSK0=0b00000001;//Разрешаю прерывания от таймера счетчика 0

	//Настроки 16 битного таймера счетчика.
	TCCR1A=0B01000000;
	TCCR1B=0B00001001;
	
	sei();
	
	while(1)
	{
	  //Не чего делать давай помигаем))
	  PORTD=0b00000100;
	  	_delay_ms(500);
	  PORTD=0;
		_delay_ms(500);
	}
}


