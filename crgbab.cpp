#include "crgbab.h"
#include <iostream>
#include <stdio.h>
#include <string.h>

CRGBAB::CRGBAB(int width, int height)
{
    std::cout << "+CRGBAB, " << width << ":" << height << std::endl;
    
    this->width = width;
    this->height = height;

    // allocate space
    data = new char[width * height * 5];
}

void CRGBAB::fill(int value)
{
    memset(data, value, width * height * 5);
}

void CRGBAB::setPixelPart(int x, int y, int index, int value)
{
    // index -->   [0][1][2][3][4]
    // meaning --> [R][G][B][A][B]

    int pos =  getPixelPos(x, y) + index;
    data[pos] = value;
}

void CRGBAB::setAlpha(int x, int y, int alpha)
{
    setPixelPart(x, y, INDEX_ALPHA, alpha);
}

void CRGBAB::setBrightness(int x, int y, int brightness)
{
    setPixelPart(x, y, INDEX_BRIGHTNESS, brightness);
}


void CRGBAB::setEveryPixelPart(int index, int value)
{
    // index -->   [0][1][2][3][4]
    // meaning --> [R][G][B][A][B]
    int max = width * height;
    for(int i = 0; i< max; i += 5)
        data[i+index] = value;

}


void CRGBAB::setPixel(int x, int y, int r, int g, int b)
{
    int pos = getPixelPos(x, y);
    data[pos] = r;
    data[pos+1] = g;
    data[pos+2] = b;
}

void CRGBAB::printPixel(int x, int y)
{
    char* pix = getPixel(x,y);
    std::cout << "Pixel [" << x << ", "  << y << "] ";
    printf("R: %hhu ", pix[0]);   // 1
    printf("G: %hhu ", pix[1]);   // 2
    printf("B: %hhu ", pix[2]);   // 3
    printf("A: %hhu ", pix[3]);   // 255
    printf("B: %hhu ", pix[4]);   // 128
    printf("\n");
}


char* CRGBAB::getPixel(int x, int y)
{
    int pos = getPixelPos(x, y);
    char* retval = &data[pos];
    return retval;
}

int CRGBAB::getPixelPos(int x, int y)
{
    std::cout << "Pixel pos [" << x << ", " << y <<
    "] - " << y*width + x * 5 << std::endl;

    return y*width + x * 5;
}

void CRGBAB::add(CRGBAB* source, int x, int y)
{
    // method will join external source to this image
    // external image will remain unaffected

    // sirka zdroje se vejde do cile?
    int lineLength = source->width;

    // paklize je cil mensi, tedy width - x, kde x je to posunuti
    // tak musime pouzit sirku toho cile, tedy to misto co
    // mame k dispozici
    if (lineLength > width - x) lineLength = width - x;

    // defacto to same s vyskou...
    // nejdrive predpokladame ze vyska cile muze byt komplet
    // nakopirovana do cile.
    int rows = source->height;

    // celokva sirka minus misto kam to chceme dat nam dava pocet
    // radku kolik tam muzeme dat.
    if (rows > height - y) rows = height - y;

    // no a ted uz je to jednoduche kazdy s radek s definovanou
    // delkou nakopirujeme na spravnou pozici do cile.

    // pro kazy radek
    for (int yy = y; yy < rows; yy++)
    {
        int pixelPosSource = source->getPixelPos(x, yy);
        int pixelPosTarget = getPixelPos(x, y+yy);

        memcpy(&data[pixelPosTarget], &source->data[pixelPosSource], lineLength*5);
    }
}

void CRGBAB::invert(int x, int y, int width, int height)
{
    // invert part of this image
}


