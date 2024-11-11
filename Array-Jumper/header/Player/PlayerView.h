#pragma once
#include "../../header/Level/LevelModel.h"
#include "../../header/UI/UIElement/ImageView.h"


namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		// TODO: Fix spacing. References grouped together + properties grouped together. 
		sf::RenderWindow* game_window;
		PlayerController* player_controller;
		UI::UIElement::ImageView* player_image;

		float player_height;
		float player_width;
		Level::BoxDimensions current_box_dimensions;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calulcatePlayerPosition();

	public:
		PlayerView(PlayerController* controller);
		~PlayerView();

		void initialize();
		void update();
		void render();

	};
}