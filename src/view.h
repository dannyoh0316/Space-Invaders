#pragma once

#include "model.h"
#include <string>

class View
{
public:
    explicit View(Model const&);

    void draw(ge211::Sprite_set& set);

    void game_over_screen(ge211::Sprite_set&);

private:
    Model const& model_;

    ge211::Image_sprite const user_sprite;

    ge211::Image_sprite const alien_sprite;

    ge211::Image_sprite const mystery_sprite;

    ge211::Rectangle_sprite const laser_sprite;

    ge211::Image_sprite const barrier5_sprite;

    ge211::Image_sprite const barrier4_sprite;

    ge211::Image_sprite const barrier3_sprite;

    ge211::Image_sprite const barrier2_sprite;

    ge211::Image_sprite const barrier1_sprite;

    ge211::Rectangle_sprite const end_sprite;

    ge211::Text_sprite const game_over_sprite;

    ge211::Text_sprite const score_text;

    ge211::Text_sprite score_sprite;

    ge211::Text_sprite const lives_sprite;

    ge211::Text_sprite num_life_sprite;
};