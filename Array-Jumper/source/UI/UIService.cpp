#include "../../header/UI/UIService.h"
#include "../../header/UI/Instructions/InstructionsUIController.h"
#include "../../header/Main/GameService.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/UI/UIElement/TextView.h"



namespace UI
{
    using namespace Main;
    using namespace SplashScreen;
    using namespace MainMenu;
    using namespace Credits;
    using namespace Instructions;
    using namespace Global;
    using namespace UIElement;
    using namespace GameplayUI;

    UIService::UIService()
    {
        splash_screen_ui_controller = nullptr;
        main_menu_ui_controller = nullptr;
        credits_screen_ui_controller = nullptr;
        instructions_ui_controller = nullptr;
        gameplay_ui_controller = nullptr;

        createControllers();
    }

    UIService::~UIService()
    {
        onDestroy();
    }

    void UIService::createControllers()
    {
        splash_screen_ui_controller = new SplashScreenUIController();
        main_menu_ui_controller = new MainMenuUIController();
        credits_screen_ui_controller = new CreditsScreenUIController();
        instructions_ui_controller = new InstructionsUIController();
        gameplay_ui_controller = new GameplayUIController();
    }

    void UIService::initialize()
    {
        initializeUIElements();
        initializeControllers();
    }

    void UIService::initializeControllers()
    {
        splash_screen_ui_controller->initialize();
        main_menu_ui_controller->initialize();
        credits_screen_ui_controller->initialize();
        instructions_ui_controller->initialize();
        gameplay_ui_controller->initialize();
    }

    void UIService::initializeUIElements()
    {
        TextView::initializeTextView();
    }

    void UIService::update()
    {
        switch (GameService::getGameState())
        {
        case GameState::SPLASH_SCREEN:
            splash_screen_ui_controller->update();
            break;
        case GameState::MAIN_MENU:
            main_menu_ui_controller->update();
            break;
        case GameState::INSTRUCTIONS:
            instructions_ui_controller->update();
            break;
        case GameState::CREDITS:
            credits_screen_ui_controller->update();
            break;
        case GameState::GAMEPLAY:
            gameplay_ui_controller->update();
            break;
        }
    }

    void UIService::render()
    {
        switch (GameService::getGameState())
        {
        case GameState::SPLASH_SCREEN:
            splash_screen_ui_controller->render();
            break;
        case GameState::MAIN_MENU:
            main_menu_ui_controller->render();
            break;
        case GameState::INSTRUCTIONS:
            instructions_ui_controller->render();
            break;
        case GameState::CREDITS:
            credits_screen_ui_controller->render();
            break;
        case GameState::GAMEPLAY:
            gameplay_ui_controller->render();
            break;
        }
    }

    void UIService::showSplashScreen()
    {
        splash_screen_ui_controller->show();
    }

    void UIService::onDestroy()
    {
        delete(splash_screen_ui_controller);
        delete(main_menu_ui_controller);
        delete(credits_screen_ui_controller);
        delete(instructions_ui_controller);
        delete(gameplay_ui_controller);
    }
}