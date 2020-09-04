#pragma once
#include "ge211.h"

class User {
public:
    User(ge211::Position, ge211::Dimensions, int);
    ///Accessors
    const ge211::Position get_center() const;
    const ge211::Dimensions get_dims() const;
    int get_lives() const;
    void update_position(ge211::Dimensions);

    ///If hit
    void decrement_lives();
    bool is_dead() const;

    ///Gain a life
    void gain_life();

private:
    ge211::Position center_;
    ge211::Dimensions dims_;
    int lives_;
};