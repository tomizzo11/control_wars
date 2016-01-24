#include "RigidBody.h"

RigidBody::RigidBody(const InitParameters& init_values)
{
    _mass = init_values.mass;
    _momentInertia = init_values.moment_inertia;
    _xCenterMass = init_values.x_center_mass;
    _yCenterMass = init_values.y_center_mass;
    _xPosition = init_values.x_pos;
    _yPosition = init_values.y_pos;
    _xVelocity = init_values.x_vel;
    _yVelocity = init_values.y_vel;
    _xAccel = init_values.x_acc;
    _yAccel = init_values.y_acc;
    _anglePosition = init_values.angle_pos;
    _angleVelocity = init_values.angle_vel;
    _angleAccel = init_values.angle_acc;
    _timeStep = init_values.time_step;


}

/*****************************************************
******************* Setters **************************
******************************************************/

void RigidBody::SetMass(float mass)
{
    _mass = mass;
}

void RigidBody::SetMomentIntertia(float moment_inertia)
{
    _momentInertia = moment_inertia;
}

void RigidBody::SetXCenterMass(float x_center_mass)
{
    _xCenterMass = x_center_mass;
}

void RigidBody::SetYCenterMass(float y_center_mass)
{
    _yCenterMass = y_center_mass;
}



void RigidBody::SetXPosition(float x_pos)
{
    // Calculate x acceleration
    float currentVel = (x_pos - _xPosition)/_timeStep;
    _xAccel = (currentVel -  _xVelocity)/_timeStep;

    // Calculate x velocity
    _xVelocity = currentVel;

    // Set new x position
    _xPosition = x_pos;

}

void RigidBody::SetYPosition(float y_pos)
{
    // Calculate y acceleration
    float currentVel = (y_pos - _yPosition)/_timeStep;
    _yAccel = (currentVel -  _yVelocity)/_timeStep;

    // Calculate y velocity
    _yVelocity = currentVel;

    // Set new y position
    _yPosition = y_pos;
}

void RigidBody::SetAngle(float angle)
{
    // Calculate angular acceleration
    float currentVel = (angle - _anglePosition)/_timeStep;
    _angleAccel = (currentVel -  _angleVelocity)/_timeStep;

    // Calculate angular velocity
    _angleVelocity = currentVel;

    // Set new angular position
    _anglePosition = angle;
}

void RigidBody::SetTimeStep(float time_step)
{
    _timeStep = time_step;
}

/*****************************************************
******************* Getters **************************
******************************************************/

float RigidBody::GetMass() const
{
    return _mass;
}

float RigidBody::GetMomentIntertia() const
{
    return _momentInertia;
}

float RigidBody::GetXCenterMass() const
{
    return _xCenterMass;
}

float RigidBody::GetYCenterMass() const
{
    return _yCenterMass;
}

float RigidBody::GetXPosition() const
{
    return _xPosition;
}

float RigidBody::GetYPosition() const
{
    return _yPosition;
}

float RigidBody::GetXVelocity() const
{
    return _xVelocity;
}

float RigidBody::GetYVelocity() const
{
    return _yVelocity;
}

float RigidBody::GetAnglePosition() const
{
    return _anglePosition;
}


float RigidBody::GetAngleVelocity() const
{
    return _angleVelocity;
}

float RigidBody::GetAngleAccel() const
{
    return _angleAccel;
}

float RigidBody::GetTimeStep() const
{
    return _timeStep;
}
