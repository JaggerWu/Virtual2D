//
//  Timer.hpp
//  Virtual2D
//
//  Created by Jian Wu on 13/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef Timer_hpp
#define Timer_hpp

#include <stdio.h>

#include "settings.hpp"

namespace Vir2D {
    namespace Common {
        class Timer
        {
        public:
            
            Timer();
            
            void Reset();
            
        private:
            unsigned long long m_start_sec;
            unsigned long long m_start_usec;
        };
    }
}

#endif /* Timer_hpp */
