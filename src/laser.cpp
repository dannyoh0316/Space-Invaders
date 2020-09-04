#include "laser.h"

bool Laser::hits_user(User const& user) const {
    ge211::Position p = center;
    int top_laser = p.y - dims.height/2;
    int bot_laser = p.y + dims.height/2;
    int left_laser = p.x - dims.width/2;
    int right_laser = p.x + dims.width/2;

    int top_user = user.get_center().y - user.get_dims().height/2;
    int bot_user = user.get_center().y + user.get_dims().height/2;
    int left_user = user.get_center().x - user.get_dims().width/2;
    int right_user = user.get_center().x + user.get_dims().width/2;

    if (right_laser < left_user || left_laser > right_user) {
        return false;
    }
    if (bot_laser < top_user || top_laser > bot_user) {
        return false;
    }

    return true;
}

bool Laser::hits_alien(Alien const& alien) const {
    ge211::Position p = center;
    int top_laser = p.y - dims.height/2;
    int bot_laser = p.y + dims.height/2;
    int left_laser = p.x - dims.width/2;
    int right_laser = p.x + dims.width/2;

    int top_alien = alien.get_center().y - alien.get_dims().height/2;
    int bot_alien = alien.get_center().y + alien.get_dims().height/2;
    int left_alien = alien.get_center().x - alien.get_dims().width/2;
    int right_alien = alien.get_center().x + alien.get_dims().width/2;

    if (right_laser < left_alien || left_laser > right_alien) {
        return false;
    }
    if (bot_laser < top_alien || top_laser > bot_alien) {
        return false;
    }

    return true;
}

bool Laser::hits_barrier(Barrier const& barrier) const {
    ge211::Position p = center;
    int top_laser = p.y - dims.height/2;
    int bot_laser = p.y + dims.height/2;
    int left_laser = p.x - dims.width/2;
    int right_laser = p.x + dims.width/2;

    int top_barrier = barrier.get_center().y - barrier.get_dims().height/2;
    int bot_barrier = barrier.get_center().y + barrier.get_dims().height/2;
    int left_barrier = barrier.get_center().x - barrier.get_dims().width/2;
    int right_barrier = barrier.get_center().x + barrier.get_dims().width/2;

    if (right_laser < left_barrier || left_laser > right_barrier) {
        return false;
    }
    if (bot_laser < top_barrier || top_laser > bot_barrier) {
        return false;
    }

    return true;
}