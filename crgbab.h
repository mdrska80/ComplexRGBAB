#ifndef CRGBAB_H
#define CRGBAB_H

class CRGBAB
{
public:
  CRGBAB();

  int width = 0;
  int height = 0;


private:
  // default structure of this is
  // R - red
  // G - green
  // B - blue
  // A - alpha
  // B - brightness
  char* data;


    
};

#endif // CRGBAB_H