#ifndef PID_H
#define PID_H

class PID {
 public:
  /**
   * Constructor
   */
  PID();

  /**
   * Destructor.
   */
  virtual ~PID();

  /**
   * Initialize PID.
   * @param (Kp_, Ki_, Kd_) The initial PID coefficients
   */
  void Init(double Kp_, double Ki_, double Kd_, double prev_error_);

  /**
   * Update the PID error variables given cross track error.
   * @param cte The current cross track error
   */
  void UpdateError(double cte);

  /**
   * Calculate the total PID error.
   * @output The total PID error
   */
  double TotalError();

	/**
	 * Calculate the steering value and restrict the value to stay in the range [-1;1].
	 * @output The steering value
	 */
	double calculate_steering();

	/**
	 * Calculate the throttle value and restrict the value to stay in the range [0;1]
	 * @output The throttle value
	 */
	double calculate_throttle();
	

 private:
  /**
   * PID Errors
   */
  double p_error;
  double i_error;
  double d_error;
	double prev_error;

  /**
   * PID Coefficients
   */ 
  double Kp;
  double Ki;
  double Kd;
};

#endif  // PID_H
