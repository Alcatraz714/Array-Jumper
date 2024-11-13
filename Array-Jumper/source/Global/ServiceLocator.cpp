#include "../../header/Global/ServiceLocator.h"
#include "../../header/Main/GameService.h"
#include "../../header/Event/EventService.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Sound;
	using namespace UI;
	using namespace Main;
	using namespace Player;
	using namespace Level;
	using namespace Gameplay;

	ServiceLocator::ServiceLocator()
	{
		graphic_service = nullptr;
		event_service = nullptr;
		sound_service = nullptr;
		ui_service = nullptr;
		level_service = nullptr;
		player_service = nullptr;
		gameplay_service = nullptr;

		createServices();
	}

	ServiceLocator::~ServiceLocator() { clearAllServices(); }

	void ServiceLocator::createServices()
	{
		graphic_service = new GraphicService();
		event_service = new EventService();
		sound_service = new SoundService();
		level_service = new LevelService();
		player_service = new PlayerService();
		gameplay_service = new GameplayService();
		ui_service = new UIService();
	}

	void ServiceLocator::initialize()
	{
		graphic_service->initialize();
		event_service->initialize();
		sound_service->initialize();
		level_service->intialize();
		player_service->initialize();
		gameplay_service->intialize();
		ui_service->initialize();
	}

	void ServiceLocator::update()
	{
		graphic_service->update();
		event_service->update();
		
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->update();
			player_service->update();
			gameplay_service->update();
		}
		ui_service->update();
	}

	void ServiceLocator::render()
	{
		graphic_service->render();
		
		if (GameService::getGameState() == GameState::GAMEPLAY)
		{
			level_service->render();
			player_service->render();
			gameplay_service->render();
		}
		ui_service->render();
	}

	void ServiceLocator::clearAllServices()
	{
		delete(graphic_service);
		delete(event_service);
		delete(sound_service);
		delete(level_service);
		delete(player_service);
		delete(gameplay_service);
		delete(ui_service);
	}

	ServiceLocator* ServiceLocator::getInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	GraphicService* ServiceLocator::getGraphicService() { return graphic_service; }

	EventService* ServiceLocator::getEventService() { return event_service; }

	SoundService* ServiceLocator::getSoundService() { return sound_service; }

	UIService* ServiceLocator::getUIService() { return ui_service; }

	PlayerService* ServiceLocator::getPlayerService() { return player_service; }

	LevelService* ServiceLocator::getLevelService() { return level_service; }

	GameplayService* ServiceLocator::getGameplayService() { return gameplay_service; }
}