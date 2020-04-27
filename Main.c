#include<xc.h>
#include"DISPLAY7SEG.h"

void ConmutarDigito(){ 
 unsigned char t2, i; 
 long t1, load=0111111;
 switch(DigitoOn) 
 { 
  case 0: 
   load=D1;
   BJT1=1; 
   BJT2=0; 
   BJT3=0; 
   DigitoOn=1; 
   break; 
  case 1: 
   load=D2; 
   BJT1=0; 
   BJT2=1; 
   BJT3=0; 
   DigitoOn=2; 
   break; 
  case 2: 
   load=D3;
   BJT1=0; 
   BJT2=0; 
   BJT3=1; 
   DigitoOn=0; 
   break; 
 } 
 t1=load;
 for(i=8;i>0;i--) 
 { 
    t2=t1%10;
    t1=t1/10;
    DATA=t2%10; 
    CLOCK=1; 
    CLOCK=0; 
 } 
 STROBE=1; 
 STROBE=0; 
}

void MostrarDisplay(unsigned int valor) 
{ 
 unsigned char cen, dec, uni; 
 cen=valor/100; 
 dec=(valor/10)%10; 
 uni=(valor%10); 
 D1=Codificar(cen); 
 D2=Codificar(dec); 
 D3=Codificar(uni); 
} 
unsigned char Codificar(unsigned char x) 
{ 
  long caca;
 
 switch(x) 
 { 
  case 0: 
   caca=0111111; 
   break; 
  case 1: 
   caca=0000110; 
   break; 
  case 2: 
   caca=1011011; 
   break; 
  case 3: 
   caca=1001111; 
   break; 
  case 4: 
   caca=1100110; 
   break; 
  case 5: 
   caca=1101101; 
   break; 
  case 6: 
   caca=1111101; 
   break; 
  case 7: 
   caca=0000111; 
   break; 
  case 8: 
   caca=1111111; 
   break; 
  case 9: 
   caca=1100111; 
   break; 
 } 
 return caca; 
}