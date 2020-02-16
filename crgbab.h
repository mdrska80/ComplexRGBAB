#ifndef CRGBAB_H
#define CRGBAB_H

#define INDEX_RED   0
#define INDEX_GREEN 1
#define INDEX_BLUE  2
#define INDEX_ALPHA 3
#define INDEX_BRIGHTNESS 4

class CRGBAB
{
public:
  CRGBAB(int width, int height);

  int width = 0;
  int height = 0;

    // clean
    void fill(int value);

    // setPixel
    void setPixelPart(int x, int y, int index, int value);
    void setPixel(int x, int y, int r, int g, int b);
    void setAlpha(int x, int y, int alpha);
    void setBrightness(int x, int y, int brightness);

    // add external image to this one. External is unaffected.
    void add(CRGBAB* source, int x = 0, int y = 0);
    void invert(int x, int y, int width, int height);

    // get
    char* getPixel(int x, int y);
    void printPixel(int x, int y);
    int getPixelPos(int x, int y);


    // every
    void setEveryPixelPart(int index, int value);


    // default structure of this is
    // R - red
    // G - green
    // B - blue
    // A - alpha
    // B - brightness
    char* data;
    
};

#endif // CRGBAB_H