/**
*    File: trajectory.h
*    Created by Hawkeye 10/2011
*
*    Generate joint and cartesian trajectories.
*    Internal datastructures track trajectory state, and update DOFs as needed upon calling.
*/

#include "struct.h"

#include <ros/ros.h>

#include <raven/util/enum.h>

// Setup and teardown of trajectory generation
//int start_trajectory(struct DOF*);
int start_trajectory(struct DOF*, float=0, float=0);
int start_trajectory_mag(struct DOF*, float=0, float=0);
int stop_trajectory(struct DOF*);

// Velocity Trajectories
int update_sinusoid_velocity_trajectory(struct DOF*);
int update_linear_sinusoid_velocity_trajectory(struct DOF*);

// Position trajectories
int update_sinusoid_position_trajectory(struct DOF*);
int update_linear_sinusoid_position_trajectory(struct DOF*);
int update_position_trajectory(struct DOF*);

bool setTrajectory(const param_pass_trajectory& traj);
bool clearTrajectory();
bool hasTrajectory();
bool getTrajectory(param_pass_trajectory& traj);

BOOST_ENUM(TrajectoryStatus, (NO_TRAJECTORY)(BEFORE_START)(OK)(ENDED));

TrajectoryStatus getCurrentTrajectoryParams(t_controlmode& controller,param_pass& param);
