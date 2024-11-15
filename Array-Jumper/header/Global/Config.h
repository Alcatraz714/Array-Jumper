#pragma once
#include <SFML/Graphics.hpp>

namespace Global
{
    class Config
    {
    public:
        // Textures
        static const sf::String array_jumper_bg_texture_path;
        static const sf::String box_texture_path;
        static const sf::String target_texture_path;
        static const sf::String character_texture_path;
        static const sf::String instructions_button_texture_path;
        static const sf::String letter_one_texture_path;
        static const sf::String letter_two_texture_path;
        static const sf::String letter_three_texture_path;
        static const sf::String menu_button_texture_path;
        static const sf::String obstacle_01_texture_path;
        static const sf::String obstacle_02_texture_path;
        static const sf::String outscal_logo_texture_path;
        static const sf::String play_button_texture_path;
        static const sf::String quit_button_texture_path;

        // Fonts
        static const sf::String bubble_bobble_font_path;
        static const sf::String zorque_font_path;

        // Sounds
        static const sf::String background_music_path;
        static const sf::String button_click_sound_path;
        static const sf::String death_sound_path;
        static const sf::String jump_sound_path;
        static const sf::String level_complete_sound_path;
        static const sf::String move_sound_path;
        static const sf::String game_won_sound_path;
    };
}
