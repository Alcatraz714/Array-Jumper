#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"


namespace Player
{
	PlayerService::PlayerService() { player_controller = new PlayerController(); }

	PlayerService::~PlayerService() { destroy(); }

	void PlayerService::initialize()
	{
		player_controller->initialize();
	}

	void PlayerService::update()
	{
		player_controller->update();
	}

	void PlayerService::render()
	{
		player_controller->render();
	}


	void PlayerService::destroy() { delete(player_controller); }
}