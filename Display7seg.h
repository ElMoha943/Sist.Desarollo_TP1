#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

void ConmutarDigito(void);
void MostrarDisplay(int valor);
long Codificar(int x);
long D1=11111100, D2=11111100, D3=11111100; 
unsigned int DigitoOn=0;
#define DATA PORTBbits.RB7
#define CLOCK PORTBbits.RB6
#define STROBE PORTBbits.RB5
#define BJT1 PORTBbits.RB3
#define BJT2 PORTBbits.RB2
#define BJT3 PORTBbits.RB1
#endif