
/*
 * Animation 1 for Wemos D1 mini with 8x8 LED shield
 *  
 * created using the hex vaules from:
 * https://www.riyas.org/2013/12/online-led-matrix-font-generator-with.html
 * 
 * Copyright 2017 LeRoy Miller
 * 
 * License:
 * Free to do with as you please. Please leave credit in place.
 * 
 */

#include <WEMOS_Matrix_LED.h>

MLED mled(0); //set intensity=0

int small[8] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};
int med1[8] = {0x00,0x00,0x3c,0x3c,0x3c,0x3c,0x00,0x00};
int med2[8] = {0x00,0x7e,0x7e,0x7e,0x7e,0x7e,0x7e,0x00};
int large[8] = {0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};

int wait = 100;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  cycle(small, wait , 6);
  cycle(med1, wait, 4);
  cycle(med2, wait, 2);
  cycle(large, wait, 0);
  cycle(large, wait, 0);
  cycle(med2, wait, 2);
  cycle(med1, wait, 4);
  cycle(small, wait, 6);
}

void cycle(int temp[], int duration, int bright) {
  for (int i = 0; i < 8; i++) {
    mled.disBuffer[i]=temp[i];
  }
  mled.intensity=bright;
  mled.display();
  delay(duration);
}

