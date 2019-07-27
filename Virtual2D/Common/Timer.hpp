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

using namespace Vir2D::Common::Settings;

namespace Vir2D {
    namespace Common {
        
        class Timer
        {
        public:
            
            Timer();
            
            void Reset();
            
            float32 GetMilliseconds() const;
            
        private:
            timeval start;
            
            float32 difftimeval(timeval *start_t, timeval *end_t) const;
        };
    }
}

#endif /* Timer_hpp */
