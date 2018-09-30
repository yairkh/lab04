#include <stdio.h>
#include "ifttt.h"
#include <time.h>

int main(int argc, char *argv[])
{
/*
  ifttt("https://maker.ifttt.com/trigger/button_pressed/with/key/56-YpOKO17vOh-gimC2xK1qRAhRdzXXXX", "my1", "my 2", "my 333334");
*/

  struct tm tm = *localtime(&(time_t){time(NULL)});
  char *actual = asctime(&tm);
  printf("Trying to connect to server\n");
  ifttt("http://yairkh.local:8080/trigger/alarm/with/key/YairKh", actual, "my 2", "my 33333");
  return 0;
}
