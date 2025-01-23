#pragma once

#include "api.h"
#include "EZ-Template/piston.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor stage1intake(8);
inline pros::Motor stage2intake(20);
inline pros::Motor lady_brown(11);

namespace pistons {
    inline ez::Piston clamp('A', true);
}



