#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

        BlockType level_boxes[NUMBER_OF_BOXES];
    };
}