//
//  BlockAllocator.hpp
//  Virtual2D
//
//  Created by Jian Wu on 20/07/2019.
//  Copyright © 2019 Jian Wu. All rights reserved.
//

#ifndef BlockAllocator_hpp
#define BlockAllocator_hpp

#include <stdio.h>

#include "settings.hpp"
#include "Math.hpp"

using namespace Vir2D::Common::Settings;

namespace Vir2D {
    namespace Common {
        
        const int32 chunkSize = 16 * 1024;
        const int32 maxBlockSize = 640;
        const int32 blockSizes = 14;
        const int32 chunkArrayIncrement = 128;
    
        struct v2Block
        {
            v2Block* next;
        };
        
        struct v2Chunk
        {
            int32 blockSize;
            v2Block* blocks;
        };
        
        class BlockAllocator
        {
        public:
            BlockAllocator();
            ~BlockAllocator();
            
            void* Allocate();
            
            void Free();
            
            void Clear();
            
        private:
            v2Block* chunks;
            int32 chunkCount;
            int32 chunkSpace;
            
            v2Block* freeList[blockSizes];
            
            static int32 s_blockSizes[blockSizes];
            static unit8 s_blockSizeLookup[maxBlockSize + 1];
            static bool s_blockSizeLookupInitialized;
        };
    }
}

#endif /* BlockAllocator_hpp */
