//
//  settings.hpp
//  Virtual2D
//
//  Created by Jian Wu on 09/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef settings_hpp
#define settings_hpp

#include <stdio.h>
#include <stddef.h>
#include <assert.h>
#include <float.h>

namespace Vir2D {
    namespace Common {
        namespace Settings {

#define    pi            3.14159265359f
            
            /// int
            typedef signed int int32;
            
            /// float
            typedef float float32;
            typedef double float64;
            
            /// unit
            typedef unsigned char unit8;
            
            
            /// Logging func
            void V2Log(const char* string, ...);
            
            /// Version
            struct Version
            {
                int32 major;
                int32 minor;
                int32 reversion;
            };
            
            extern Version currenctVersion;
        }
    }
}

#endif /* settings_hpp */
