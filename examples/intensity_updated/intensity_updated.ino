/* Slightly modified version - giving a fade up to fade down look 
 *  LeRoy Miller
 */

#include <WEMOS_Matrix_LED.h>

MLED mled(0); //set intensity=0

void setup() {
  Serial.begin(115200);
  for(int i=0; i<8; i++)
  {
    mled.disBuffer[i]=0xff;  //full screen
  }
  
  
}

void loop() {

  for(int i=0;i<8;i++){
    mled.intensity=i;//change intensity
    mled.display();
    delay(100);
    }
    for (int i=7;i>0;i--) {
      mled.intensity=i;
      mled.display();
      delay(100);
    }
}
