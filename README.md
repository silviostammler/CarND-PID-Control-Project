# **PID Control Project** 

---

**PID Control Project**

The goals / steps of this project are the following:
* Implementation of a PID controller for position control
* PID parameter tuning to achieve a safe driving behavior
* Summarize the results with a written report

## Rubric Points
### Here I will consider the [rubric points](https://review.udacity.com/#!/rubrics/1972/view) individually and describe how I addressed each point in my implementation.  

---
### Compilation

The code compiles without any errors using cmake and make. No changes to CMakeLists.txt has been made. For the sake of completeness this file is added in the submission.

### Implementation

#### 1. The PID procedure follows what was taught in the lessons.

The PID controller was implemented according to the base algorithm presented in the lesson. Each iteration the acquired cross-track-error (cte) is used as input to determine a steering angle sent to the simulator in order to control the car. Based on the given cte proportional, integral and differential error are computed in each run and are used together with the PID gains to calculate the steering value.
Only PID control according to position control is used. Therefore, the throttle value sent to the simulator is set to a constant value of 0.3. Implementing PID control also for the speed could also be beneficial in order to drive the car around the track much faster. This could be investigated in the future.

### Reflection

#### 1. Describe the effect each of the P, I, D components had in your implementation.

The proportional gain has a big impact on how fast the car adapts to the reference trajectory. It shouldn't be chosen too small because the car needs to much time to follow the center of the lane and would drive off the road especially in sharp turns. On the other hand, the P value shouldn't be too big since this would lead since the vehicle would strongly move from side to side around the center of the lane which is a sign of overshooting. To reduce the amount of overshooting the differential gain has to be adjusted reasonably. Finally, to tackle any systematic bias (e.g. steering drift) and to get an cte which becomes zero a small I gain has to be chosen as well.

#### 2. Describe how the final hyperparameters were chosen.

Choosing the PID gains was carried out by manual tuning. The final parameters were set to Kp = 2, Ki = 0.001 and Kd = 20.

### Simulation

#### 1. The vehicle must successfully drive a lap around the track.
Based on the chosen hyperparameters the car is able to drive safely around the track.
