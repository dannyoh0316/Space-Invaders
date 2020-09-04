#pragma once
#include "ge211.h"

struct Geometry{
    const ge211::Dimensions scene_dims;

    const ge211::Dimensions alien_tl;

    const ge211::Dimensions alien_spacing;

    const ge211::Dimensions alien_dims;

    const ge211::Dimensions alien_num;

    const ge211::Dimensions v0;

    const int worth_mult;

    const ge211::Dimensions user_dims;

    const ge211::Position user_start;

    const int init_lives;

    const ge211::Position mystery_start;

    const ge211::Dimensions mystery_velocity;

    const int mystery_worth;

    const ge211::Dimensions mystery_dims;

    const int init_barrier_health;

    const ge211::Position barrier_l;

    const ge211::Dimensions barrier_spacing;

    const ge211::Dimensions barrier_dims;

    const int barrier_num;

    const ge211::Dimensions user_laser_velocity;

    const ge211::Dimensions alien_laser_velocity;

    const ge211::Dimensions laser_dims;

    const ge211::Dimensions alien_move_down;


    const int bounding;
    ///Constructor
    explicit Geometry();
};