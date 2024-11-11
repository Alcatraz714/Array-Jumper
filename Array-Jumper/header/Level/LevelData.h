#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
    struct LevelData
    {
        static const int NUMBER_OF_BOXES = 10;

        BlockType level_boxes[NUMBER_OF_BOXES] = {
            BlockType::ONE,
            BlockType::TWO,
            BlockType::OBSTACLE_ONE,
            BlockType::TWO,
            BlockType::THREE,
            BlockType::ONE,
            BlockType::OBSTACLE_TWO,
            BlockType::TWO,
            BlockType::ONE,
            BlockType::TARGET };
    };
}