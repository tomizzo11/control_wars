#ifndef RIGIDBODY_H
#define RIGIDBODY_H

/*****************************************************
******************* Includes *************************
******************************************************/

/*****************************************************
****************** Prototypes ************************
******************************************************/

struct InitParameters;

/*****************************************************
**************** Class Definition ********************
******************************************************/

class RigidBody
{
    public:
        RigidBody(const InitParameters& init_values);

        // Setters
        void    SetMass(float mass);
        void    SetMomentIntertia(float moment_inertia);
        void    SetXCenterMass(float x_center_mass);
        void    SetYCenterMass(float y_center_mass);
        void    SetXPosition(float x_pos);
        void    SetYPosition(float y_pos);
        void    SetAngle(float angle);
        void    SetTimeStep(float time_step);

        // Getters
        float   GetMass() const;
        float   GetMomentIntertia() const;
        float   GetXCenterMass() const;
        float   GetYCenterMass() const;
        float   GetXPosition() const;
        float   GetYPosition() const;
        float   GetXVelocity() const;
        float   GetYVelocity() const;
        float   GetXAccel() const;
        float   GetYAccel() const;
        float   GetAnglePosition() const;
        float   GetAngleVelocity() const;
        float   GetAngleAccel() const;
        float   GetTimeStep() const;

    protected:
    private:

        // Member Objects
        float               _mass;
        float               _momentInertia;
        float               _xCenterMass; // Center of mass X coordinate with respect to spatial center of rigid body
        float               _yCenterMass; // Center of mass Y coordinate with respect to spatial center of rigid body
        float               _xPosition;    // previous x and y positions are temporarily held for velocity and accel calcs
        float               _yPosition;
        float               _xVelocity;
        float               _yVelocity;
        float               _xAccel;
        float               _yAccel;
        float               _anglePosition;
        float               _angleVelocity;
        float               _angleAccel;
        float               _timeStep;

};

/*****************************************************
*************** Other Definitions ********************
******************************************************/

// Data type used for rigid body initialization
struct InitParameters {
    float mass;
    float moment_inertia;
    float x_center_mass;
    float y_center_mass;
    float x_pos;
    float y_pos;
    float x_vel;
    float y_vel;
    float x_acc;
    float y_acc;
    float angle_pos;
    float angle_vel;
    float angle_acc;
    float time_step;
};

#endif // RIGIDBODY_H
