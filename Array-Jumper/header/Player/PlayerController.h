#pragma once

namespace Player
{
	class PlayerView;
	class PlayerModel;
	enum class PlayerState;
	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		void destroy();
		void resetPlayer();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();

		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);

		int getCurrentPosition();
	};
}