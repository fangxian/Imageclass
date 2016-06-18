//
// Created by YuFangxian on 16/6/17.
//

#ifndef IMGE_S_DIM2U_H
#define IMGE_S_DIM2U_H

#include <cstdint>

namespace Im
{
    struct Dim2u
    {
        Dim2u();
        Dim2u(uint32_t w, uint32_t h): width(w), height(h) {};
        //~Dim2u();
        uint32_t width;
        uint32_t height;

    };
}

#endif //IMGE_S_DIM2U_H
