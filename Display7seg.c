#include<xc.h>
#include"DISPLAY7SEG.h"

void ConmutarDigito(){ //ESTA FUNCION MUESTRA LOS NUMEROS EN LOS DIGITOS Y PRENDE Y APAGA LOS TRANSISTORES.
 unsigned char i; 
 long t1, load=11111100;
 switch(DigitoOn) 
 { 
  case 0: 
   load=D1; //En load se guarda el numero a mostrar por el digito encendido.
   BJT1=1; 
   BJT2=0;  //Enciende un digito y apaga los demas.
   BJT3=0; 
   DigitoOn=1; //Se cambia la variable para que la siguiente vez pase por otro case del switch, encendiendo otro digito.
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
 for(i=8;i>0;i--) //Carga de datos del registro de desplazamiento.
 { 
    DATA=t1%10;
    t1=t1/10;
    CLOCK=1; 
    CLOCK=0; 
 } 
 STROBE=1; //Paso de datos del registro a los digitos.
 STROBE=0;
}

void MostrarDisplay(int valor) //ESTA FUNCION DIVIDE EN CEN, DEC Y UNI VALOR ASIGNADO POR EL USUARIO Y LO CONVIERTE EN CODIGOS PARA USAR EN EL REGISTRO DE DESPLAZAMIENTO.
{ 
 int cen, dec, uni; 
 cen=valor/100; 
 dec=(valor/10)%10; //Separacion entre centena, descena y unidad.
 uni=(valor%10); 
 D1=Codificar(cen); 
 D2=Codificar(dec);  //Codificacion de numero a codigo para el registro.
 D3=Codificar(uni); 
} 
long Codificar(int x) 
{ 
  long caca; //En esta variable se guarda el codigo, se usa una LONG ya que no entra el numero en una INT.
 
 switch(x) 
 { 
  case 0: 
   caca=11111100; 
   break; 
  case 1: 
   caca=00001100; 
   break; 
  case 2: 
   caca=10110110; 
   break; 
  case 3: 
   caca=10011110; 
   break; 
  case 4: 
   caca=11001100; 
   break; 
  case 5: 
   caca=11011010; 
   break; 
  case 6: 
   caca=11111010; 
   break; 
  case 7: 
   caca=00001110; 
   break; 
  case 8: 
   caca=11111110; 
   break; 
  case 9: 
   caca=11001110; 
   break; 
 } 
 return caca; 
}