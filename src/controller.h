#pragma once
#include "model.h"
#include "view.h"

class Controller : public ge211::Abstract_game {
public:
    explicit Controller(Model& model);

protected:
    void on_start() override;
    void on_key_down(ge211::Key) override;
    void on_key_up(ge211::Key) override;

    void on_frame(double) override;
    void draw(ge211::Sprite_set&) override;

    ge211::Dimensions initial_window_dimensions() const override;

private:
    Model model_;
    View view_;
    int movement_;
    ge211::time::Timer alien_fire_timer;

};