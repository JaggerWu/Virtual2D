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

Timer::Timer()
{
    Reset();
}

float32 Timer::GetMilliseconds() const
{
    timeval now;
    gettimeofday(&now, 0);
    timeval t = start;
    
    return difftimeval(&t, &now);
}

float32 Timer::difftimeval(timeval *start_t, timeval *end_t) const
{
    float32 d;
    time_t s;
    suseconds_t u;
    
    s = start_t->tv_sec - end_t->tv_sec;
    u = start_t->tv_usec - end_t->tv_usec;
    
    d = s;
    d *= 1000000.0;
    d += u;
    
    return d;
}

void Timer::Reset()
{
    gettimeofday(&start, 0);
}
