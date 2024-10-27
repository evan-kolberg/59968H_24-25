#pragma once

#include "api.h"
#include "EZ-Template/piston.hpp"

// Your motors, sensors, etc. should go here.  Below are examples

// inline pros::Motor intake(1);
// inline pros::adi::DigitalIn limit_switch('A');


inline ez::Piston solenoid_a('A', false);
inline pros::Motor cata(1);

