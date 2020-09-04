#include "alien_stack.h"

Alien_stack::Alien_stack(int x, ge211::Dimensions velocity , const Geometry &geometry)
    :x_(x)
    ,velocity_(velocity)
    ,stack_(create_stack(geometry))
{ }

std::vector<Alien> Alien_stack::create_stack(const Geometry &geometry) {
    std::vector<Alien> temp;
    for (int i = 0; i < geometry.alien_num.width - 1; i++) {
        temp.emplace_back(Alien({x_, geometry.alien_tl.height
            +  i * (geometry.alien_spacing.height + geometry.alien_dims.height)}, geometry.worth_mult * (5 - i), false
            , geometry.alien_dims));
    }
    temp.emplace_back(Alien({x_, geometry.alien_tl.height
    +  4 * (geometry.alien_spacing.height + geometry.alien_dims.height)}, geometry.worth_mult, true,
            geometry.alien_dims));
    return temp;
}

void Alien_stack::reassign_front() {
    if (stack_.empty()) {
        return;
    }
    int max = 0;
    int index = 0;
    for (size_t i = 0; i < stack_.size(); i++) {
        if (stack_[i].get_center().y > max) {
            max = stack_[i].get_center().y;
            index = i;
        }
    }
    stack_[index].assign_front();
}

void Alien_stack::move_down(ge211::Dimensions move_down) {
    if (stack_.empty()) {
        return;
    }
    for (Alien& alien: stack_) {
        alien.alien_move(move_down);
    }
}

void Alien_stack::reverse_velocity() {
    velocity_ *= -1;
}

void Alien_stack::update_position() {
    if (stack_.empty()) {
        return;
    }
    x_ += velocity_.width;
    for (Alien& alien : stack_) {
        alien.alien_move(velocity_);
    }
}

const ge211::Position Alien_stack::get_front_pos() const {
    for (Alien alien : stack_) {
        if (alien.get_front()) {
            return alien.get_center();
        }
    }
    return {0,0};
}


void Alien_stack::remove_alien(int index) {
    if (stack_.empty()) {
        return;
    }
    stack_.erase(stack_.begin() + index);
}

/// Returners and Accessors
std::vector<Alien> Alien_stack::return_stack() {
    return stack_;
}
const std::vector<Alien>& Alien_stack::get_stack() const {
    return stack_;
}
int Alien_stack::get_x() const {
    return x_;
}