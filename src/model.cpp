#include "model.h"

Model::Model(const Geometry& geometry)
    :geometry_(geometry)
    ,aliens_()
    ,user_(geometry_.user_start, geometry_.user_dims, geometry_.init_lives)
    ,mystery_(geometry_.mystery_start, geometry_.mystery_worth, geometry.mystery_dims, geometry_.mystery_velocity)
    ,barriers_()
    ,lasers_()
    ,score(0)
    ,wave({0, 0})
    ,game_over_(false)
{ }

///Accessors
const ge211::Position Model::get_user_top_left() const {
    return {user_.get_center().x - geometry_.user_dims.width/2, user_.get_center().y - geometry_.user_dims.height/2};
}

const std::vector<Alien_stack>& Model::get_aliens() const {
    return aliens_;
}

const ge211::Position Model::get_mystery_top_left() const {
    return {mystery_.get_center().x - geometry_.mystery_dims.width/2,
                mystery_.get_center().y - geometry_.mystery_dims.height/2};
}

const std::vector<Barrier>& Model::get_barriers() const {
    return barriers_;
}

const std::vector<Laser>& Model::get_lasers() const {
    return lasers_;
}

bool Model::is_game_over() const {
    return game_over_;
}

const ge211::Dimensions Model::get_laser_dims() const {
    return geometry_.laser_dims;
}

const std::string Model::get_score() const {
    int i = score;
    std::string out_string;
    std::stringstream ss;
    ss << i;
    out_string = ss.str();
    return out_string;
}

const ge211::Dimensions Model::get_window_dims() const {
    return geometry_.scene_dims;
}
const std::string Model::get_lives() const {
   int i = user_.get_lives();
   return std::to_string(i);
}

bool Model::is_mystery_alive() const {
    return mystery_.get_live();
}

///On start functions
void Model::create_aliens() {
    aliens_ = {};
    for (int i = 0; i < geometry_.alien_num.height; i++) {
        aliens_.emplace_back(Alien_stack(geometry_.alien_tl.width +
        i * (geometry_.alien_spacing.width + geometry_.alien_dims.width), geometry_.v0 + wave, geometry_ ));
    }
}

void  Model::create_barriers() {
    for (int i = 0; i <  geometry_.barrier_num; i++) {
        barriers_.push_back(Barrier{geometry_.barrier_l + i * geometry_.barrier_spacing, geometry_.init_barrier_health
        , geometry_.barrier_dims});
    }
}

///UPDATE
void Model::update(bool can_alien_fire, int stack_fire_num, ge211::Dimensions user_velocity, bool mystery_launch) {
    alien_update(can_alien_fire, stack_fire_num);
    user_update(user_velocity);
    mystery_update(mystery_launch);
    barrier_update();
    laser_update();
}

bool Model::user_is_hit() {
    for (size_t i = 0; i < lasers_.size(); i++)
    {
        if (lasers_[i].hits_user(user_)) {
            lasers_.erase(lasers_.begin() + i);
            return true;
        }
    }
    return false;
}

bool Model::alien_is_hit(Alien& alien) {
    for (size_t i = 0; i < lasers_.size(); i++)
    {
        if (lasers_[i].hits_alien(alien)) {
            lasers_.erase(lasers_.begin() + i);
            return true;
        }
    }
    return false;
}

bool Model::barrier_is_hit(Barrier& barrier) {
    for (size_t i = 0; i < lasers_.size(); i++)
    {
        if (lasers_[i].hits_barrier(barrier)) {
            lasers_.erase(lasers_.begin() + i);
            return true;
        }
    }
    return false;
}

///Alien Update
void Model::alien_update(bool can_alien_fire, int stack_fire_num) {
    //Checks if Aliens are hit
    for (Alien_stack& stack : aliens_) {
        for (size_t i = 0; i < stack.get_stack().size(); i++) {
            if (alien_is_hit(stack.return_stack()[i])) {
                score += stack.return_stack()[i].get_worth();
                stack.remove_alien(i);
                stack.reassign_front();
            }
        }
    }

    //Checks aliens are not all dead
    if (aliens_all_dead()) {
        wave.width++;
        user_.gain_life();
        create_aliens();
        return;
    }

    //Checks if aliens hit side
    if (aliens_hit_side()) {
        for (Alien_stack& stack: aliens_) {
            stack.move_down(geometry_.alien_move_down);
            stack.reverse_velocity();
            stack.update_position();
        }
    }

    if (aliens_hit_bounding()) {
        game_over();
        return;
    }

    if (can_alien_fire) {
        if (!aliens_[stack_fire_num].get_stack().empty()) {
            ge211::Position firing_pos  = aliens_[stack_fire_num].get_front_pos();
            firing_pos += {0, geometry_.alien_dims.height/2 + 1};
            lasers_.push_back({firing_pos, geometry_.alien_laser_velocity, geometry_.laser_dims});
        }
    }

    for (Alien_stack& stack : aliens_) {
        stack.update_position();
    }
}

//Helpers for alien_update()
 bool Model::aliens_all_dead() const {
    for (Alien_stack stack: aliens_) {
        if (!stack.get_stack().empty()) {
            return false;
        }
    }
    return true;
}

bool Model::aliens_hit_side() {
 for (Alien_stack& stack : aliens_) {
     if (stack.get_stack().empty()) {
         continue;
     }
     if (stack.get_x() < 0 || stack.get_x() > 1024) {
         return true;
     }
 }
 return false;
}

 bool Model::aliens_hit_bounding() const {
    for (Alien_stack stack: aliens_) {
        if (stack.get_stack().empty()) {
            continue;
        }
        for (Alien alien: stack.get_stack()) {
            if (alien.get_front()) {
                if (alien.get_center().y > geometry_.bounding) {
                    return true;
                }
            }
        }
    }
    return false;
}

///User Updates
void Model::user_update(ge211::Dimensions user_velocity) {
    if (user_is_hit()) {
        user_.decrement_lives();
        if (user_.is_dead()) {
            game_over();
            return;
        }
    }
    user_.update_position(user_velocity);
}

///Mystery Update
void Model::mystery_update(bool mystery_launch) {
    if (mystery_.get_live()) {
        if (alien_is_hit(mystery_)) {
            score += mystery_.get_worth();
            mystery_.reset_mystery(geometry_.mystery_start);
        }
        mystery_.mystery_update_position();
    }
    if (mystery_launch) {
        mystery_.make_live();
    }

}

///Barriers Update
void Model::barrier_update() {
    for (size_t i = 0; i < barriers_.size(); i++) {
        if (barrier_is_hit(barriers_[i])) {
            barriers_[i].health--;
            if (barriers_[i].health == 0) {
                barriers_.erase(barriers_.begin() + i);
            }
        }
    }
}

///Laser update
void Model::laser_update() {
    if (lasers_.empty()) {
        return;
    }
    for (size_t i = 0; i < lasers_.size(); i++) {
        lasers_[i].center += lasers_[i].velocity;
        if (lasers_[i].center.y < 0 || lasers_[i].center.y > 768) {
            lasers_.erase(lasers_.begin() + i);
        }
    }
}

void Model::user_laser_launch() {
    ge211::Position firing_pos = {user_.get_center().x, user_.get_center().y - geometry_.user_dims.height};
    lasers_.push_back(Laser{firing_pos, geometry_.user_laser_velocity, geometry_.laser_dims});
}

///GameOver
void Model::game_over() {
    game_over_ = true;
}

///For Controller
bool Model::user_laser_exists() const {
    for (const Laser& laser : lasers_) {
        if (laser.velocity == geometry_.user_laser_velocity) {
            return true; 
        }
    }
    return false;
}