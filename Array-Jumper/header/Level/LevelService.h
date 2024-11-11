#pragma once
#include "../../header/Level/BlockType.h"

namespace Level
{
	class LevelController;
	struct BoxDimensions;

	class LevelService
	{
	private:
		LevelController* level_controller;

		void destroy();
	public:
		LevelService();
		~LevelService();

		void intialize();
		void update();
		void render();

		BoxDimensions getBoxDimensions();
		BlockType getCurrentBoxValue(int currentPosition);
	};
}