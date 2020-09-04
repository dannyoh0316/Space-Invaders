#pragma once
#include <ge211.h>
#include <vector>
#include "geometry.h"
#include "alien_stack.h"
#include "user.h"
#include "mystery.h"
#include "barrier.h"
#include "laser.h"

class Model {
public:
    explicit Model(Geometry const& geometry = Geometry());

    void create_aliens();
    void create_barriers();

    ///Accessors
    const ge211::Position get_user_top_left() const;
    const std::vector<Alien_stack>& get_aliens() const;
    const ge211::Position get_mystery_top_left() const;
    const std::vector<Barrier>& get_barriers() const;
    const std::vector<Laser>& get_lasers() const;
    bool is_game_over() const;
    const ge211::Dimensions get_laser_dims() const;
    const std::string get_score() const;
    const std::string get_lives() const;
    const ge211::Dimensions get_window_dims() const;
    bool is_mystery_alive() const;

    ///Update functions
    void update(bool, int, ge211::Dimensions, bool);

    ///Hit function
    bool user_is_hit ();
    bool alien_is_hit (Alien&);
    bool barrier_is_hit(Barrier&);

    ///Alien Updates
    void alien_update(bool, int);

    //Alien update helpers
    bool aliens_all_dead() const;
    bool aliens_hit_side();
    bool aliens_hit_bounding() const;

   ///User Update
   void user_update(ge211::Dimensions);

   ///Mystery Update
   void mystery_update(bool);

   ///Barrier Update
   void barrier_update();

   ///Laser Update
   void laser_update();
   void user_laser_launch();

   ///GameOver
   void game_over();
   
   ///For Controller
   bool user_laser_exists() const; 

   ///Test access
   friend struct Test_access;

private:
    const Geometry& geometry_;
    std::vector<Alien_stack> aliens_;
    User user_;
    Mystery mystery_;
    std::vector<Barrier> barriers_;
    std::vector<Laser> lasers_;
    int score;
    ge211::Dimensions wave;
    bool game_over_;
};
