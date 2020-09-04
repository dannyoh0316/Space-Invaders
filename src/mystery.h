#pragma once
#include "ge211.h"
#include "alien.h"

class Mystery : public Alien {
public:
    Mystery(ge211::Position, int, ge211::Dimensions, ge211::Dimensions);

    void mystery_update_position();
    const ge211::Position get_center() const override;
    int get_worth() const override;

    void reset_mystery(ge211::Position);
    void make_live();

    ///Accessors
    bool get_live() const;

private:
    bool live_;
    ge211::Dimensions velocity_;
};