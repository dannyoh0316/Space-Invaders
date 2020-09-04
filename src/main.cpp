#include "model.h"
#include "controller.h"
#include "geometry.h"

int main()
{
    Model model;
    Controller space_invaders(model);
    space_invaders.run();
}