#pragma once

// Each level should be represented as a array of integers
    //     -1   : Obstacle 1
    //     -2   : Obstacle 2
    //      0   : End block
    //  1,2,3   : Numbers

namespace Level
{
    enum BlockType
    {
        OBSTACLE_ONE = -1,
        OBSTACLE_TWO = -2,
        TARGET = 0,
        ONE = 1,
        TWO = 2,
        THREE = 3,
    };
}