#include "PID.h"
#include <iostream>

using namespace std;
/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp_, double Ki_, double Kd_, double prev_error_) {
  /**
   * TODO: Initialize PID coefficients (and errors, if needed)
   */
	Kp = Kp_;
	Ki = Ki_;
	Kd = Kd_;

	i_error = 0;
	prev_error = prev_error_;
}

void PID::UpdateError(double cte) {
  /**
   * TODO: Update PID errors based on cte.
   */
	p_error = cte;
	i_error += cte;
	d_error = (cte - prev_error);

	prev_error = cte;
}

double PID::TotalError() {
  /**
   * TODO: Calculate and return the total error
   */
  return p_error+i_error+d_error;  // TODO: Add your total error calc here!
}

double PID::calculate_steering() {

	double steer_value = -Kp*p_error -Ki*i_error -Kd*d_error;

	if(steer_value>1.0)
	{
		steer_value = 1.0;	
	}
	if(steer_value<-1.0)
	{
		steer_value = -1.0;
	}  

	return steer_value;
}

double PID::calculate_throttle() {
	cout << "p_error = " << p_error << endl;
	cout << "Kp = " << Kp << endl; 
	double throttle = Kp*p_error +Ki*i_error +Kd*d_error;

	if(throttle>1.0)
	{
		throttle = 1.0;	
	}
	if(throttle<0.0)
	{
		throttle = 0.0;
	}  

	return throttle;
}
