#include "mystery.h"

Mystery::Mystery(ge211::Position center, int worth, ge211::Dimensions dims, ge211::Dimensions velocity)
    :Alien(center, worth, false, dims)
    ,live_(false)
    ,velocity_(velocity)
{ }

bool Mystery::get_live() const {
    return live_;
}

const ge211::Position Mystery::get_center() const {
    return center_;
}
int Mystery::get_worth() const {
    return worth_;
}

void Mystery::mystery_update_position() {
    center_+= velocity_;
}

void Mystery::reset_mystery(ge211::Position center) {
    center_ = center;
    live_ = false;
}

void Mystery::make_live() {
    live_ = true;
}