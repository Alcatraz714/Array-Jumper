#include "../../header/Level/LevelModel.h"

namespace Level
{
	LevelModel::LevelModel() {}
	LevelModel::~LevelModel() {}

	BlockType LevelModel::getCurrentBoxValue(int currentPosition)
	{
		return current_level_data.level_boxes[currentPosition];
	}
}