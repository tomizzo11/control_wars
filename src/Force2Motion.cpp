#include "Force2Motion.h"
#include "RigidBody.h"
#include <cmath>
#include <iostream>

Force2Motion::Force2Motion(const RigidBody& rigid_body):
    _rigidBody(rigid_body)
{
}

/*****************************************************
************ Public Member Functions *****************
******************************************************/

void Force2Motion::LoadVectorData(const std::vector<std::array<float, 4>>& force_position_vectors)
{
        // Begin Calculations
        CalcNetForcesTorques(force_position_vectors);
        CalcNewX();
        CalcNewY();
        CalcNewAngle();
}

float Force2Motion::GetNewX()
{
    return _newX;
}

float Force2Motion::GetNewY()
{
    return _newY;
}

float Force2Motion::GetNewAngle()
{
    return _newAngle;
}

/*****************************************************
************ Private Member Functions ****************
******************************************************/

 void Force2Motion::CalcNetForcesTorques(const std::vector<std::array<float, 4>>& force_position_vectors)
 {

    // Note: Data Formatted As Follows
    // force_position_vectors[0] = Force Magnitude
    // force_position_vectors[1] = Force Angle
    // force_position_vectors[2] = Position Magnitude (distance between force and center of mass of rigid body)
    // force_position_vectors[3] = Position Angle

    float x_force_sum = 0;
    float y_force_sum = 0;
    float tan_force = 0;
    float torque_sum = 0;


    for(std::vector<std::array<float,4>>::const_iterator it = force_position_vectors.begin(); it != force_position_vectors.end(); it++)
    {
        // Calculate net force in X direction (right = positive)
        //x_force_sum += force_position_vectors[0][1]*cos(force_position_vectors[0][1]);
        x_force_sum += (*it)[0]*cos((*it)[1]);
        // Calculate net force in Y direction (left = positive)
        y_force_sum += (*it)[0]*sin((*it)[1]);
        // Calculate net torque (counter-clockwise = positive)
        tan_force = (*it)[0]*sin((*it)[3]-(*it)[1]);
        torque_sum += tan_force * (*it)[2];

    }

    _netForceX = x_force_sum;
    _netForceY = y_force_sum;
    _netTorque = torque_sum;
 }

 void Force2Motion::CalcNewX()
 {
    _newX = _netForceX/_rigidBody.GetMass()*pow(_rigidBody.GetTimeStep(),2)
            + _rigidBody.GetXVelocity()*_rigidBody.GetTimeStep()
            + _rigidBody.GetXPosition();

    std::cout << "Inside " << _netForceX << "End \n";
    std::cout << "Mass Inside    = " << _netForceX/_rigidBody.GetMass()*pow(_rigidBody.GetTimeStep(),2) << "\n";
 }

  void Force2Motion::CalcNewY()
 {
        _newY = _netForceY/_rigidBody.GetMass()*pow(_rigidBody.GetTimeStep(),2)
            + _rigidBody.GetYVelocity()*_rigidBody.GetTimeStep()
            + _rigidBody.GetYPosition();
 }

  void Force2Motion::CalcNewAngle()
 {
        _newAngle = _netTorque/_rigidBody.GetMomentIntertia()*pow(_rigidBody.GetTimeStep(),2)
                    + _rigidBody.GetAngleVelocity()*_rigidBody.GetTimeStep()
                    + _rigidBody.GetAnglePosition();
 }

 // Delete this eventual
 float  Force2Motion::GetNetXForce()
 {
     return _netForceX;
 }
