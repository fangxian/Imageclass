//
// Created by YuFangxian on 16/6/17.
//

#ifndef IMGE_S_POSITION2U_H
#define IMGE_S_POSITION2U_H

#include <cstdint>

namespace Im {
    struct Position2u
    {
        Position2u();
        Position2u(uint32_t w, uint32_t h): x(w), y(h) {};
        ~Position2u();
        uint32_t x;
        uint32_t y;
    };
}

#endif //IMGE_S_POSITION2U_H
