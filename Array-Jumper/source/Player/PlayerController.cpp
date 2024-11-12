#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Level/LevelModel.h"
#include "../../header/Sound/SoundService.h"

namespace Player
{
	using namespace Global;
	using namespace Event;
	using namespace Level;
	using namespace Sound;

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController() { destroy(); }

	void PlayerController::initialize()
	{
		player_model->initialize();
		player_view->initialize();

		event_service = ServiceLocator::getInstance()->getEventService();

		resetPlayer();
	}

	void PlayerController::update()
	{
		player_view->update();
		readInput();
	}

	void PlayerController::render()
	{
		player_view->render();
	}

	PlayerState PlayerController::getPlayerState()
	{
		return player_model->getPlayerState();
	}

	void PlayerController::setPlayerState(PlayerState new_player_state)
	{
		player_model->setPlayerState(new_player_state);
	}

	int PlayerController::getCurrentPosition()
	{
		return player_model->getCurrentPosition();
	}

	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->getCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->setCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}

	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < Level::LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			move(MovementDirection::BACKWARD);
		}
	}

	void PlayerController::destroy()
	{
		delete(player_model);
		delete(player_view);
	}

	void PlayerController::resetPlayer()
	{
		player_model->setCurrentPosition(0);
		player_model->setPlayerState(PlayerState::ALIVE);
	}
}