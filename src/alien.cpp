#include "alien.h"

Alien::Alien(ge211::Position center, int worth, bool front, ge211::Dimensions dims)
    :center_(center)
    ,worth_(worth)
    ,front_(front)
    ,dims_(dims)
{}

void Alien::alien_move(ge211::Dimensions move) {
    center_ = center_ + move;
}

const ge211::Position Alien::get_center() const {
    return center_;
}

const ge211::Dimensions Alien::get_dims() const {
    return dims_;
}

const ge211::Position Alien::get_top_left() const {
    return {center_.x - dims_.width/2, center_.y - dims_.height/2};
}

int Alien::get_worth() const {
    return worth_;
}

bool Alien::get_front() const {
    return front_;
}

void Alien::assign_front() {
    front_ = true;
}