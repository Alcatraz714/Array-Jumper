#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelView.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Level/LevelData.h"
#include "../../header/Main/GameService.h"

namespace Level
{

	LevelController::LevelController()
	{
		level_view = new LevelView(this);
		level_model = new LevelModel();
	}

	LevelController::~LevelController() {}

	void LevelController::initialize()
	{
		level_view->initialize();
	}

	void LevelController::update()
	{
		level_view->update();
	}

	void LevelController::render()
	{
		level_view->render();
	}

	BoxDimensions LevelController::getBoxDimensions()
	{
		return level_view->getBoxDimensions();
	}

	BlockType LevelController::getCurrentBoxValue(int currentPosition)
	{
		return level_model->getCurrentBoxValue(currentPosition);
	}

	bool LevelController::isLastLevel()
	{
		return level_model->isLastLevel();
	}

	void LevelController::loadNextLevel()
	{
		level_model->loadNextLevel();
	}

	int LevelController::getCurrentLevelNumber()
	{
		return level_model->getCurrentLevelNumber();
	}

	void LevelController::reset()
	{
		level_model->reset();
	}
}