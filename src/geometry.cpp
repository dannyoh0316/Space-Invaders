#include "geometry.h"

Geometry::Geometry()
    :scene_dims{1024, 768}
    ,alien_tl{320, 112}
    ,alien_spacing{32, 32}
    ,alien_dims{32, 32}
    ,alien_num{5, 7}
    ,v0{2, 0}
    ,worth_mult(100)
    ,user_dims{96, 48}
    ,user_start{512, 744}
    ,init_lives(3)
    ,mystery_start{1024, 48}
    ,mystery_velocity{-3, 0}
    ,mystery_worth(5000)
    ,mystery_dims{64, 64}
    ,init_barrier_health(5)
    ,barrier_l{224, 640}
    ,barrier_spacing{288, 0}
    ,barrier_dims{128, 128}
    ,barrier_num(3)
    ,user_laser_velocity{0, -5}
    ,alien_laser_velocity{0, 5}
    ,laser_dims{8, 8}
    ,alien_move_down{0, 10}
    ,bounding(barrier_l.y)
{ }