//! "Copyright [2019] Shivam Akhauri and Chinmay Joshi"
/** @author Shivam Akhauri, Chinmay Joshi
* @file Test-Driven Development exercise for pid---header file
* @brief declaration for PID_Controller class
* Details. Private and public members of the class
*/
#ifndef INCLUDE_PID_CONTROLLER_H_
#define INCLUDE_PID_CONTROLLER_H_

#include <iostream>

class PIDController {
 private:
        double dt;
        double kp;
        double kd;
        double ki;
        double setpoint;
        double velocity;
        double integral = 0;
        double pre_error = 0;

 public:
        double max;
        double min;
        PIDController(double _dt, double _kp, double _kd,
        double _ki, double _setpoint, double _velocity);
        double compute(void);
        double max_velocity(double max);
        double min_velocity(double min);
};

#endif  //  INCLUDE_PID_CONTROLLER_H_
