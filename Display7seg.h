#ifndef DISPLAY7SEG_H
#define DISPLAY7SEG_H

void ConmutarDigito(void);
void MostrarDisplay(unsigned int valor);
unsigned char Codificar(unsigned char x);
long D1=0111111, D2=0111111, D3=0111111; 
unsigned int DigitoOn=0;
#define DATA PORTBbits.RB7
#define CLOCK PORTBbits.RB6
#define STROBE PORTBbits.RB5
#define BJT1 PORTBbits.RB3
#define BJT2 PORTBbits.RB2
#define BJT3 PORTBbits.RB1
#endif