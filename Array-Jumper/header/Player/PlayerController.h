#pragma once

#include "../../header/Event/EventService.h"
#include "../../header/Player/MovementDirection.h"

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
		Event::EventService* event_service;

		void destroy();
		void move(MovementDirection direction);
		void jump(MovementDirection direction);
		bool isPositionInBound(int targetPosition);
		void readInput();

	public:
		PlayerController();
		~PlayerController();

		void initialize();
		void update();
		void render();
		void resetPlayer();
		PlayerState getPlayerState();
		void setPlayerState(PlayerState new_player_state);
		void takeDamage();
		int getCurrentPosition();
	};
}