//! "Copyright [2019] Shivam_Akhauri and Chinmay_Joshi"
/** @author Shivam Akhauri, Chinmay Joshi
* @file Test-Driven Development exercise
* @brief PID Controller implementation test file
* Details.  PID controller implementation for a new mobile robot product development!
*/

#include <gtest/gtest.h>
#include "../include/PID_Controller.h"

/**
* @brief Unit test for the Compute function. All input values as zero.velocity returned should be zero.So test should fail
*/
TEST(PID_Controller, ComputeFunction) {
  PIDController pid(1.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  pid.max_velocity(100.0);
  pid.min_velocity(0.0);
  double vel = pid.compute();
  EXPECT_EQ(0.0, vel);
}
/**
* @brief Unit test to check the maximum boundary of the velocity of the PID
*/
TEST(PID_Controller, MaxVelocity) {
  PIDController pid(0.1, 22.0, 0.88, 0.99, 0.01, 0.5);
  pid.min_velocity(0.0);
  double maxv = pid.max_velocity(10.0);
  EXPECT_GT(100.0, maxv);
}
/**
* @brief Unit test to check the manimum boundary of the velocity of the PID
*/
TEST(PID_Controller, MinVelocity) {
  PIDController pid(0.1, 22.0, 0.88, 0.99, 0.01, 0.5);
  pid.min_velocity(0.0);
  double maxv = pid.min_velocity(1.0);
  EXPECT_LT(0.0, maxv);
}

TEST(PID_Controller, DivideByZeroError) {
  PIDController pid(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
  pid.max_velocity(100.0);
  pid.min_velocity(0.0);
  double vel = pid.compute();
  EXPECT_EQ(0.0, vel);
}
