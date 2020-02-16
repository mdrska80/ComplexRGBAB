#include <iostream>
#include "crgbab.h"

int main() 
{
    CRGBAB crgbab(100, 100);
    crgbab.fill(255);
    crgbab.setPixel(0, 0, 10, 20, 30);
    crgbab.setAlpha(0, 0, 255);
    crgbab.setBrightness(0, 0, 128);

    char* pix00 = crgbab.getPixel(0, 0);

    crgbab.printPixel(0, 0);
   
    crgbab.setAlpha(1, 0, 254);
    crgbab.printPixel(1, 0);

    crgbab.setEveryPixelPart(INDEX_BRIGHTNESS, 123);
    crgbab.setEveryPixelPart(INDEX_ALPHA, 222);


    crgbab.printPixel(0, 0);
    crgbab.printPixel(1, 0);

}