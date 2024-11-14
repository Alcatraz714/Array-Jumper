#pragma once

#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	using namespace Level;
	class GameplayController
	{
	private:

		bool isObstacle(BlockType value);
		bool isEndBlock(BlockType value);
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