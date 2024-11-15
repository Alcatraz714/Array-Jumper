#pragma once

#include "../UIElement/TextView.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController
		{
		private:

			float font_size = 55;

			const float top_offset = 100.f;
			const float left_offset = 100.f;
			const float right_offset = 250.f;

			UIElement::TextView* life_count_text;
			UIElement::TextView* level_text;

			void createTexts();
			void initializeTexts();
			// life count UI
			void initializeLifeCountText();
			void updateLifeCountText();
			// level number UI
			void initializeLevelText();
			void updateLevelText();

			void destroy();

		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize();
			void update();
			void render();
		};
	}
}