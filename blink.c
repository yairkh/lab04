#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{

  int i;
  int pin_num;

  if (argc < 2)
  {
	printf("usage: blink pin#\n");
	exit(1);
  }
  
  pin_num  = atoi(argv[1]);
  printf ("The value entered is %d.\n",pin_num);
  
  wiringPiSetup () ;

  pinMode (pin_num, OUTPUT) ;
  for (;;)
  {
    digitalWrite (pin_num, HIGH) ; delay (500) ;
    digitalWrite (pin_num,  LOW) ; delay (500) ;
   }
  return 0 ;
}
