#include "view.h"

using namespace ge211;

View::View(Model const& model)
        : model_(model)
        , user_sprite("user.png")
        , alien_sprite("alien.png")
        , mystery_sprite("mystery.png")
        , laser_sprite(model_.get_laser_dims(), Color::white())
        , barrier5_sprite("barrier5.png")
        , barrier4_sprite("barrier4.png")
        , barrier3_sprite("barrier3.png")
        , barrier2_sprite("barrier2.png")
        , barrier1_sprite("barrier1.png")
        , end_sprite({1024, 768}, {169, 169, 169})
        , game_over_sprite("Game Over", ge211::Font("sans.ttf", 50))
        , score_text("Score:", ge211::Font("sans.ttf", 20))
        , score_sprite(model_.get_score(), ge211::Font("sans.ttf", 20))
        , lives_sprite("Lives: ", ge211::Font("sans.ttf", 20))
        , num_life_sprite(to_string(model_.get_lives()), ge211::Font("sans.ttf", 20))
{ }

void View::draw(ge211::Sprite_set& set) {
    set.add_sprite(score_text, {0, 0});
    score_sprite.reconfigure(ge211::Text_sprite::Builder(ge211::Font("sans.ttf", 20)) << model_.get_score());
    num_life_sprite.reconfigure(ge211::Text_sprite::Builder(ge211::Font("sans.ttf", 20)) << model_.get_lives());
    set.add_sprite(score_sprite, {60, 0});
    set.add_sprite(lives_sprite, {1024 - 75, 0});
    set.add_sprite(num_life_sprite, {1012, 0});

    for (Alien_stack stack : model_.get_aliens()) {
        for (Alien alien : stack.get_stack()) {
            set.add_sprite(alien_sprite, alien.get_top_left(), 1);
        }
    }
    set.add_sprite(user_sprite, model_.get_user_top_left(), 1);
    if (model_.is_mystery_alive()) {
        set.add_sprite(mystery_sprite, model_.get_mystery_top_left());
    }
    for (Barrier barrier : model_.get_barriers()) {
        if (barrier.get_health() == 5) {
            set.add_sprite(barrier5_sprite, barrier.get_top_left());
        }
        else if (barrier.get_health() == 4) {
            set.add_sprite(barrier4_sprite, barrier.get_top_left());
        }
        else if (barrier.get_health() == 3) {
            set.add_sprite(barrier3_sprite, barrier.get_top_left());
        }
        else if (barrier.get_health() == 2) {
            set.add_sprite(barrier2_sprite, barrier.get_top_left());
        }
        else if (barrier.get_health() == 1) {
            set.add_sprite(barrier1_sprite, barrier.get_top_left());
        }
    }
    for (Laser laser : model_.get_lasers()) {
        set.add_sprite(laser_sprite, laser.center, 3);
    }
    if (model_.is_game_over()) {
        game_over_screen(set);
    }
}

void View::game_over_screen(ge211::Sprite_set& set) {
    set.add_sprite(end_sprite, {0, 0}, 10);
    set.add_sprite(game_over_sprite, {360, 340}, 11);
}