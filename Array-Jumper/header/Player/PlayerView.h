#pragma once
#include "../../Header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;
	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;

		float player_height;
		float player_width;

		void initializePlayerImage();
		void drawPlayer();
		void loadPlayer();
		void calculatePlayerDimensions();
		void updatePlayerPosition();
		sf::Vector2f calulcatePlayerPosition();

	public:
		PlayerView();
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}