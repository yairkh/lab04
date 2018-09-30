#include <stdio.h>
#include <wiringPi.h>
#include <time.h>


int main(int argc, char *argv[])
{
  struct tm tm = *localtime(&(time_t){time(NULL)});
  char *actual = asctime(&tm);

  int alarm_reading;

 
  wiringPiSetup () ;
  pinMode(0, INPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  while(1) {
    alarm_reading = digitalRead(0);
    switch (alarm_reading)
    {
	case 0: 
		printf("Ready\n");
		digitalWrite (2, LOW) ;
       		ifttt("http://yairkh.local:8080/trigger/alarm/with/key/YairKh","Alarm ready", actual, "");
		while(digitalRead(0) == 0) 
		{
			digitalWrite (1, HIGH) ; delay (200) ; 
			digitalWrite (1,  LOW) ; delay (200) ; 
		}
		break;
	case 1:
		printf("Alarm\n");
		digitalWrite (1, LOW) ;
		ifttt("http://yairkh.local:8080/trigger/alarm/with/key/YairKh","Alarm!!!!!", actual, "");
		while (digitalRead(0) == 1)
                {
        		digitalWrite (2, HIGH) ; 
                } 

		break;
   }
    
  }
  /*NOTREACHED*/
  return 0 ;
}
