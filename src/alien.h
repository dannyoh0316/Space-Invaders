#pragma once
#include "ge211.h"

class Alien {
public:
    Alien(ge211::Position, int, bool, ge211::Dimensions);

    virtual ~Alien() { };

    //Accessors
    virtual const ge211::Position get_center() const;
    const ge211::Dimensions get_dims() const;
    virtual int get_worth() const;
    bool get_front() const;
    const ge211::Position get_top_left() const;

    void assign_front();

    void alien_move(ge211::Dimensions);

protected:
    ge211::Position center_;
    int worth_;
    bool front_;
    ge211::Dimensions dims_;
};