#include "../../header/Sound/SoundService.h"
#include "../../header/Global/Config.h"


namespace Sound
{
	using namespace Global;

	SoundService::SoundService() = default;

	void SoundService::initialize()
	{
		loadBackgroundMusicFromFile();
		loadSoundFromFile();
	}

	void SoundService::loadBackgroundMusicFromFile()
	{
		if (!background_music.openFromFile(Config::background_music_path))
			printf("Error loading background music file");
	}

	void SoundService::loadSoundFromFile()
	{
		if (!buffer_button_click.loadFromFile(Config::button_click_sound_path))
			printf("Error loading background music file");
		if (!buffer_move.loadFromFile(Config::move_sound_path))
			printf("Error loading background music file");
		if (!buffer_jump.loadFromFile(Config::jump_sound_path))
			printf("Error loading background music file");
		if (!buffer_death.loadFromFile(Config::death_sound_path))
			printf("Error loading background music file");
		if (!buffer_level_complete.loadFromFile(Config::level_complete_sound_path))
			printf("Error loading background music file");
		if (!buffer_game_won.loadFromFile(Config::game_won_sound_path))
			printf("Error loading game won music file");
	}

	void SoundService::playSound(SoundType soundType)
	{
		switch (soundType)
		{
		case SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(buffer_button_click);
			break;
		case SoundType::MOVE:
			sound_effect.setBuffer(buffer_move);
			break;
		case SoundType::JUMP:
			sound_effect.setBuffer(buffer_jump);
			break;
		case SoundType::DEATH:
			sound_effect.setBuffer(buffer_death);
			break;
		case SoundType::LEVEL_COMPLETE:
			sound_effect.setBuffer(buffer_level_complete);
			break;
		case SoundType::GAME_WON:
			sound_effect.setBuffer(buffer_game_won);
			break;
		default:
			printf("Invalid sound type");
			return;
		}

		sound_effect.play();
	}

	void SoundService::playBackgroundMusic()
	{
		background_music.setLoop(true);
		background_music.setVolume(background_music_volume);
		background_music.play();
	}
}