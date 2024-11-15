#pragma once
#include "../../header/Level/LevelModel.h"

namespace Level
{
	class LevelView;
	class LevelModel;

	class LevelController
	{
	private:
		LevelView* level_view;
		LevelModel* level_model;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		BoxDimensions getBoxDimensions();
		BlockType getCurrentBoxValue(int currentPosition);

		bool isLastLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();

		void reset();
	};
}