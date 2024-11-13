#pragma once
#include "../../header/Graphics/GraphicService.h"
#include "../../header/Event/EventService.h"
#include "../../header/UI/UIService.h"
#include "../../header/Sound/SoundService.h"
#include "../../header/Player/PlayerService.h"
#include "../../header/Level/LevelService.h"
#include "../../header/Gameplay/GameplayService.h"

namespace Global
{
    class ServiceLocator
    {
    private:
        Graphics::GraphicService* graphic_service;
        Event::EventService* event_service;
        Sound::SoundService* sound_service;
        UI::UIService* ui_service;
        Player::PlayerService* player_service;
        Level::LevelService* level_service;
        Gameplay::GameplayService* gameplay_service;
        

        ~ServiceLocator();

        void createServices();
        void clearAllServices();

    public:
        ServiceLocator();
        static ServiceLocator* getInstance();

        void initialize();
        void update();
        void render();

        Graphics::GraphicService* getGraphicService();
        Event::EventService* getEventService();
        Sound::SoundService* getSoundService();
        UI::UIService* getUIService();
        Player::PlayerService* getPlayerService();
        Level::LevelService* getLevelService();
        Gameplay::GameplayService* getGameplayService();
    };
}