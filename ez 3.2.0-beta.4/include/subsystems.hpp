#pragma once

#include "api.h"
#include "EZ-Template/piston.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

inline pros::Motor intake(8);
namespace pistons {
    inline ez::Piston clamp('A', true);
}



