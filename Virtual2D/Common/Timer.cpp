//
//  Timer.cpp
//  Virtual2D
//
//  Created by Jian Wu on 13/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#include <sys/time.h>

#include "Timer.hpp"

using namespace Vir2D::Common;

void Timer::Reset()
{
    timeval t;
    gettimeofday(&t, 0);
    m_start_sec = t.tv_sec;
    m_start_usec = t.tv_usec;
}

Timer::Timer()
{
    Reset();
}
