/*
 * Animation 2 for Wemos D1 mini with 8x8 LED shield
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

int start[8] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};
int next1[8] = {0x00,0x00,0x24,0x18,0x18,0x24,0x00,0x00};
int next2[8] = {0x00,0x42,0x24,0x18,0x18,0x24,0x42,0x00};
int next3[8] = {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};
int plusfull[8] = {0x18,0x18,0x18,0xff,0xff,0x18,0x18,0x18};
int plusmed[8] = {0x00,0x18,0x18,0x7e,0x7e,0x18,0x18,0x00};
int plussmall[8] = {0x00,0x00,0x18,0x3c,0x3c,0x18,0x00,0x00};

int wait = 150;

void setup() {
  
}

void loop() {

  cycle(start, wait, 0);
  cycle(plussmall, wait, 2);
  cycle(next1, wait, 0);
  cycle(plusmed, wait, 0);
  cycle(next2, wait, 2);
  cycle(plusfull, wait, 2);
  cycle(next3, wait, 0);
  cycle(plusfull, wait, 2);
  cycle(next3, wait, 0);
  cycle(plusmed, wait, 0);
  cycle(next2, wait, 2);
  cycle(plussmall, wait, 2);
  cycle(next1, wait, 0);
  cycle(start, wait, 0);
}

void cycle(int temp[], int duration, int bright) {
  for (int i = 0; i < 8; i++) {
    mled.disBuffer[i]=temp[i];
  }
  mled.intensity=bright;
  mled.display();
  delay(duration);
}

