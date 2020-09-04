#include "user.h"

User::User(ge211::Position center, ge211::Dimensions dims, int lives)
    :center_(center)
    ,dims_(dims)
    ,lives_(lives)
{}

const ge211::Position User::get_center() const {
    return center_;
}

const ge211::Dimensions User::get_dims() const {
    return dims_;
}

int User::get_lives() const {
    return lives_;
}
void User::update_position(ge211::Dimensions velocity) {
    center_+= velocity;
}
void User::decrement_lives() {
    lives_--;
}

bool User::is_dead() const {
    return lives_ == 0;
}

void User::gain_life() {
    lives_++;
}