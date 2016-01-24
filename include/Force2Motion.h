#ifndef FORCE2MOTION_H
#define FORCE2MOTION_H

/*****************************************************
******************* Includes *************************
******************************************************/

#include "RigidBody.h"
#include <vector>
#include <array>

/*****************************************************
****************** Prototypes ************************
******************************************************/

/*****************************************************
**************** Class Definition ********************
******************************************************/

class Force2Motion
{
    public:
        Force2Motion(const RigidBody& rigid_body);

        void        LoadVectorData(const std::vector<std::array<float, 4>>& force_position_vectors);
        float       GetNewX();
        float       GetNewY();
        float       GetNewAngle();
        float  GetNetXForce();


    protected:
    private:
        // Private Member Function
        void   CalcNetForcesTorques(const std::vector<std::array<float, 4>>& force_position_vectors);
        void   CalcNewX();
        void   CalcNewY();
        void   CalcNewAngle();

        // Private Member Variables
        float   _netForceX; // net force in x direction
        float   _netForceY; // net force in y direction
        float   _netTorque; // net torque
        float   _newX;
        float   _newY;
        float   _newAngle;
        const   RigidBody&  _rigidBody;


};

#endif // FORCE2MOTION_H
