#include "controller.h"

using namespace ge211;

Controller::Controller(Model& model)
    :model_(model)
    ,view_(model_)
    ,movement_(0)
    ,alien_fire_timer(ge211::time::Timer())
{ }

void Controller::on_key_down(ge211::Key key) {
    if(model_.is_game_over()) {
        return;
    }
    if (key == ge211::Key::right()) {
        movement_ = 5;
    }

    if (key == ge211::Key::left()) {
        movement_ = -5;
    }
    if (key == ge211::Key::code('q')) {
        quit();
    }
    if (key == ge211::Key::code(' ')) {
        if (!model_.user_laser_exists()) {
            model_.user_laser_launch();
        }
    }
}

void Controller::on_key_up(ge211::Key key) {
    if(model_.is_game_over()){
        return;
    }
    if (key == ge211::Key::right()) {
        movement_ = 0;
    }
    if (key == ge211::Key::left()) {
        movement_ = 0;
    }
}

void Controller::on_start() {
    model_.create_aliens();
    model_.create_barriers();
}

void Controller::on_frame(double) {
    bool can_alien_fire = false;
    if (alien_fire_timer.elapsed_time().seconds() > 2) {
        can_alien_fire = true;
        alien_fire_timer.reset();
    }
    int stack_fire_num = ge211::Abstract_game::get_random().between(0, 6);
    
    ge211::Dimensions user_velocity = ge211::Dimensions{movement_, 0};
    
    bool mystery_launch = false;
    
    int guess = ge211::Abstract_game::get_random().between(0, 99);
    
    if (guess == 7) {
        mystery_launch = true;
    }
    model_.update(can_alien_fire, stack_fire_num, user_velocity, mystery_launch);
}

void Controller::draw(Sprite_set& sprites) {
    view_.draw(sprites);
}

Dimensions Controller::initial_window_dimensions() const {
    return model_.get_window_dims();
}