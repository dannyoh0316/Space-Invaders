#include "model.h"
#include <catch.h>

struct Test_access
{
    Model& model;
    Geometry geometry = model.geometry_;

    void clear_aliens()
    {
        model.aliens_= std::vector<Alien_stack>{};
    }

    int get_score()
    {
        return model.score;
    }

    void create_mystery()
    {
        Mystery mystery{{500, 500}, 5000, geometry.mystery_dims, {0, 0}};
        Mystery& mystery1 = mystery;
        mystery1.make_live();
        model.mystery_ = mystery;
    }

    void add_hit_laser()
    {
        Laser laser{{500, 500}, {0, 0}, geometry.laser_dims};
        Laser& laser1 = laser;
        model.lasers_.push_back(laser1);
    }

    void create_barrier()
    {
        Barrier barrier{{500, 500}, 5, geometry.barrier_dims};
        model.barriers_.push_back(barrier);
    }

    Barrier& get_barrier()
    {
        return model.barriers_[0];
    }

    void create_aliens()
    {
        model.create_aliens();
    }

    void add_alien_laser()
    {
        Laser laser{{geometry.alien_tl.width, geometry.alien_tl.height}, {0, 0}, geometry.laser_dims};
        Laser& laser1 = laser;
        model.lasers_.push_back(laser1);
    }

    void create_user()
    {
        User user{{500, 500}, geometry.user_dims, 1};
        model.user_ = user;
    }

    User& get_user()
    {
        return model.user_;
    }
};

TEST_CASE("new alien set after all aliens die")
{
    Model model;
    Test_access t{model};
    CHECK(model.get_aliens().empty());
    model.alien_update(false, 0);
    CHECK(!model.get_aliens().empty());
    t.clear_aliens();
    CHECK(model.get_aliens().empty());
    model.alien_update(false, 0);
    CHECK(!model.get_aliens().empty());
}

TEST_CASE("hit mystery ship")
{
    Model model;
    Test_access t{model};
    CHECK(t.get_score() == 0);
    t.create_mystery();
    t.add_hit_laser();
    model.mystery_update(false);
    CHECK(t.get_score() == 5000);
}

TEST_CASE("barrier destroyed")
{
    Model model;
    Test_access t{model};
    t.create_barrier();
    CHECK(t.get_barrier().health == 5);
    t.add_hit_laser();
    model.barrier_update();
    CHECK(t.get_barrier().health == 4);
    t.add_hit_laser();
    model.barrier_update();
    CHECK(t.get_barrier().health == 3);
    t.add_hit_laser();
    model.barrier_update();
    CHECK(t.get_barrier().health == 2);
    t.add_hit_laser();
    model.barrier_update();
    CHECK(t.get_barrier().health == 1);
    t.add_hit_laser();
    model.barrier_update();
    CHECK(t.model.get_barriers().empty());
}

TEST_CASE("laser hits alien")
{
    Model model;
    Test_access t{model};
    t.create_aliens();
    CHECK(t.get_score() == 0);
    t.add_alien_laser();
    model.alien_update(false, 0);
    CHECK(t.get_score() != 0);
}

TEST_CASE("laser hits user")
{
    Model model;
    Test_access t{model};
    t.create_user();
    CHECK(!t.get_user().is_dead());
    CHECK(!model.is_game_over());
    t.add_hit_laser();
    model.user_update(ge211::Dimensions{0, 0});
    CHECK(t.get_user().is_dead());
    CHECK(model.is_game_over());
}