#pragma once

#include "EZ-Template/api.hpp"
#include "api.h"
#include "EZ-Template/piston.hpp"


extern Drive chassis;

inline pros::Motor stage1intake(8);
inline pros::Motor stage2intake(12);
inline pros::Motor lady_brown(11);
inline pros::Rotation rotation(15);
inline pros::Vision vision_sensor(21);

namespace pistons {
    inline ez::Piston clamp('A', false);
    inline ez::Piston doinker('H', false);
}

