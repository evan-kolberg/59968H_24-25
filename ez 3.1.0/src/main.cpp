#include "main.h"
#include "subsystems.hpp"


ez::Drive chassis(
    // the first motor is used for sensing
    // negative port will reverse it
    {-11, -12, -13},
    {1, 2, 3},
    8,
    3.25,
    600,
    (60. / 36.));


void initialize() {

  chassis.opcontrol_curve_buttons_toggle(false);
  chassis.opcontrol_drive_activebrake_set(0.1);

  default_constants();

  ez::as::auton_selector.autons_add({
      Auton("Example Drive\n\nDrive forward and come back.", drive_example),
      Auton("Example Turn\n\nTurn 3 times.", turn_example),
      Auton("Drive and Turn\n\nDrive forward, turn, come back. ", drive_and_turn),
      Auton("Drive and Turn\n\nSlow down during drive.", wait_until_change_speed),
      Auton("Swing Example\n\nSwing in an 'S' curve", swing_example),
      Auton("Motion Chaining\n\nDrive forward, turn, and come back, but blend everything together :D", motion_chaining),
      Auton("Combine all 3 movements", combining_movements),
      Auton("Interference\n\nAfter driving forward, robot performs differently if interfered or not.", interfered_example),
  });

  chassis.initialize();
  ez::as::initialize();
  master.rumble(".");
}


void disabled() {
  // . . .
}


void competition_initialize() {
  // . . .
}


void autonomous() {
  chassis.pid_targets_reset();
  chassis.drive_imu_reset();
  chassis.drive_sensor_reset();
  chassis.drive_brake_set(MOTOR_BRAKE_HOLD);

  ez::as::auton_selector.selected_auton_call();
}


void opcontrol() {

  pros::motor_brake_mode_e_t driver_preference_brake = MOTOR_BRAKE_COAST;

  chassis.drive_brake_set(driver_preference_brake);

  while (true) {

    if (!pros::competition::is_connected()) {
      // Enable / Disable PID Tuner
      //  When enabled:
      //  * use A and Y to increment / decrement the constants
      //  * use the arrow keys to navigate the constants
      if (master.get_digital_new_press(DIGITAL_X))
        chassis.pid_tuner_toggle();

      if (master.get_digital(DIGITAL_B) && master.get_digital(DIGITAL_DOWN)) {
        autonomous();
        chassis.drive_brake_set(driver_preference_brake);
      }

      chassis.pid_tuner_iterate();
    }

    chassis.opcontrol_tank();

    int R = master.get_digital(pros::E_CONTROLLER_DIGITAL_R1) -
            master.get_digital(pros::E_CONTROLLER_DIGITAL_R2);
    cata.move_velocity(R * 200);

    solenoid_a.button_toggle(master.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_LEFT));


    pros::delay(ez::util::DELAY_TIME);
  }
}

