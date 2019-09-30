//! "Copyright [2019] Shivam Akhauri and Chinmay Joshi"
/** @author Shivam Akhauri, Chinmay Joshi
* @file Test-Driven Development exercise
* @brief PID Controller implementation
* Details.  PID controller class dfination for a new mobile robot product development!
*/
#include <iostream>
#include "../include/PID_Controller.h"


/**
* @brief Parameterized constructor to set required values
* @author Shivam Akhauri
* @param _dt Time interval between each cycle
* @param _kp Multiplier for proportional
* @param _kd Multiplier for derivation
* @param _ki Multiplier for integration
* @param _setPoint Expected value
* @param _velocity Current value
*/
PIDController::PIDController(double _dt, double _kp, double _kd,
double _ki, double _setpoint, double _velocity) {
    dt = _dt;
    kp = _kp;
    kd = _kd;
    ki = _ki;
    velocity = _velocity;
    setpoint = _setpoint;
}

/**
* @brief compute function for calculating pid values--- stub function
* @author Toyas Dhake
*/
double PIDController::compute() {
    double error = setpoint - velocity;
    double PrpOut = kp * error;

    integral += error * dt;
    double IntgOut = ki * error;
    // check for divide by zero error
    if (dt = 0)
        return 0;
    double derivative = (error - pre_error) / dt;
    double Dout = kd * derivative;
    // check for max and min criteria
    double output = PrpOut + IntgOut + Dout;

    pre_error = error;

    if (output > max) {
        output = max;
    } else if (output < min) {}
        {output = min;}
    return output;
}
/**
* @brief assign maximum velocity value for the pid controller
* @param _max Maximum allowed limit of the output
* @author Shivam Akhauri
*/
double PIDController::max_velocity(double _max) {;
    max = _max;
    return max;
}
/**
* @brief assign maximum velocity value for the pid controller
* @param _min Minimum allowed limit of the output
* @author Shivam Akhauri
*/
double PIDController::min_velocity(double _min) {;
    min = _min;
    return min;
}



