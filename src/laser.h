#pragma once
#include "ge211.h"
#include "user.h"
#include "alien.h"
#include "barrier.h"
#include "mystery.h"

struct Laser {
    ge211::Position center;
    ge211::Dimensions velocity;
    ge211::Dimensions dims;

    bool hits_user(User const&) const;

    bool hits_alien(Alien const&) const;

    bool hits_barrier(Barrier const&) const;

    bool hits_mystery(Mystery const&) const;
};