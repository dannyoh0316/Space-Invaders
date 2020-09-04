#pragma once
#include "ge211.h"
#include "alien.h"
#include "geometry.h"

class Alien_stack {
public:
    Alien_stack(int x, ge211::Dimensions velocity, const Geometry& geometry);

    void reassign_front();

    void move_down(ge211::Dimensions);

    void reverse_velocity();

    void update_position();

    const ge211::Position get_front_pos() const;

    ///Accessors and Returners
    std::vector<Alien> return_stack();
    const std::vector<Alien>& get_stack() const;

    int get_x() const;

    void remove_alien(int);

private:
    int x_;
    ge211::Dimensions velocity_;
    std::vector<Alien> stack_;

    ///Helper function
    std::vector<Alien> create_stack(const Geometry& );
};