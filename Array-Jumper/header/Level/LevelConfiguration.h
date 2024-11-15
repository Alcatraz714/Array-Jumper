#pragma once
#include "LevelData.h"
#include "BlockType.h"

namespace Level
{
    class LevelConfiguration
    {
    private:


        BlockType level_1[LevelData::NUMBER_OF_BOXES] =
        {
            ONE, TWO, OBSTACLE_ONE, TWO, THREE, ONE, OBSTACLE_TWO, TWO, ONE, TARGET
        };

        BlockType level_2[LevelData::NUMBER_OF_BOXES] =
        {
            ONE, TWO, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, THREE, OBSTACLE_ONE, ONE, TARGET
        };

        BlockType level_3[LevelData::NUMBER_OF_BOXES] =
        {
            ONE, THREE, OBSTACLE_ONE, OBSTACLE_TWO, ONE, TWO, OBSTACLE_ONE, TWO, ONE, TARGET
        };

    public:
        static const int NUMBER_OF_LEVELS = 3;
        LevelData levels[NUMBER_OF_LEVELS];

        LevelConfiguration()
        {
            for (int i = 0; i < LevelData::NUMBER_OF_BOXES; i++)
            {
                levels[0].level_boxes[i] = level_1[i];
            }

            for (int i = 0; i < LevelData::NUMBER_OF_BOXES; i++)
            {
                levels[1].level_boxes[i] = level_2[i];
            }

            for (int i = 0; i < LevelData::NUMBER_OF_BOXES; i++)
            {
                levels[2].level_boxes[i] = level_3[i];
            }
        }
    };
}