#ifndef WEAK_BLOCK_H
#define WEAK_BLOCK_H

#include "Block.h"

namespace gm {

    class WeakBlock :
        public Block
    {
    public:
        WeakBlock();
        virtual void TakeDamage() override;
    };
}

#endif