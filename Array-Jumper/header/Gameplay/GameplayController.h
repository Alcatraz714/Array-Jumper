#pragma once

#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	class GameplayController
	{
	private:

		bool isObstacle(Level::BlockType value);
		bool isEndBlock(Level::BlockType value);
		void processObstacle();
		void processEndBlock();

		void gameOver();

	public:

		void intialize();
		void update();
		void render();

		void onPositionChanged(int position);
		void onDeath();
	};
}