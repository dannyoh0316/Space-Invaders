#include "barrier.h"

const ge211::Position Barrier::get_center() const {
    return center;
}

const ge211::Position Barrier::get_top_left() const {
    return {center.x - dims.width / 2, center.y - dims.height / 2};
}

const ge211::Dimensions Barrier::get_dims() const {
    return dims;
}

int Barrier::get_health() const {
    return health;
}