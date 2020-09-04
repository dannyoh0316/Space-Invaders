#pragma once
#include "ge211.h"

struct Barrier {
    ge211::Position center;
    int health;
    ge211::Dimensions dims;

    // Accessors
    const ge211::Position get_center() const;
    const ge211::Position get_top_left() const;
    const ge211::Dimensions get_dims() const;
    int get_health() const;
};