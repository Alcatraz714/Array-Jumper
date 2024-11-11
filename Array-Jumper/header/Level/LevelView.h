#pragma once
#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelModel.h";
#include "../../header/UI/UIElement/ImageView.h"

namespace Level
{
	class LevelView
	{
	private:

		sf::RenderWindow* game_window;
		LevelController* level_controller;
		
		UI::UIElement::ImageView* background_image;
		const float background_alpha = 110.f;

		// Numbers
		UI::UIElement::ImageView* box_image;
		UI::UIElement::ImageView* target_overlay_image;
		UI::UIElement::ImageView* letter_one_overlay_image;
		UI::UIElement::ImageView* letter_two_overlay_image;
		UI::UIElement::ImageView* letter_three_overlay_image;
		UI::UIElement::ImageView* obstacle_one_overlay_image;
		UI::UIElement::ImageView* obstacle_two_overlay_image;

		BoxDimensions box_dimensions;

		void createImages();
		void initializeImages();
		void updateImages();
		void drawLevel();
		void drawBox(sf::Vector2f position);
		void drawBoxValue(sf::Vector2f position, BlockType box_value);
		void deleteImages();

		void calculateBoxDimensions();
		sf::Vector2f calculateBoxPosition(int index);
		void calculateBoxWidthHeight();
		void calculateBoxSpacing();
		UI::UIElement::ImageView* getBoxOverlayImage(BlockType block_type);

	public:
		LevelView(LevelController* controller);
		~LevelView();

		void initialize();
		void update();
		void render();

		BoxDimensions getBoxDimensions();
	};
}