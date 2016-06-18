#include <iostream>
#include <cstdint>
#include <stdlib.h>
#include "Dim2u.h"
#include <stdio.h>

using namespace std;
using namespace Im;
//generate random image
//test image class
//gaussian filter




void generateImage(Dim2u dim2u, uint32_t* data)
{
    uint32_t* buffer;
    const uint32_t length = dim2u.width * dim2u.height;
    uint32_t i;
    buffer = (uint32_t*)data;
    for(i = 0; i < length; i++)
    {
        buffer[i] = (rand())%(255-0) + 0;
    }
}


int main()
{
    Dim2u dim2u(80,80);
    uint32_t data[6400];
    uint8_t* src = new uint8_t[6400];
    generateImage(dim2u, data);
    printf("%d", (uint8_t)data[2]);
    memcpy(src, (uint8_t *)data, 6400);
    cout << "Hello, World!" << endl;
    delete[] src;
    return 0;
}