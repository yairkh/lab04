#include <stdio.h>
#include <wiringPi.h>
#include <time.h>


int main(int argc, char *argv[])
{
  struct tm tm = *localtime(&(time_t){time(NULL)});
  char *actual = asctime(&tm);

  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1) {
 /*   printf("Waiting for reset\n");*/
    while(digitalRead(0) == 1)
    {
        digitalWrite (1,  LOW);
        digitalWrite (2, HIGH) ; 
	ifttt("http://yairkh.local:8080/trigger/alarm/with/key/YairKh","Alarm on", actual, "");
    } 
    
      printf("ALARM read: %d\n", digitalRead(0));  
 /*   printf("Waiting for event\n"); */
    while(digitalRead(0) == 0) 
    {
        ifttt("http://yairkh.local:8080/trigger/alarm/with/key/YairKh","Start monitoring", actual, "");

        digitalWrite (2,  LOW);
 	digitalWrite (1, HIGH) ; delay (500) ; 
	digitalWrite (1,  LOW) ; delay (500) ; 
    }
/*    printf("Alarm\n"); */
  }
  /*NOTREACHED*/
  return 0 ;
}
