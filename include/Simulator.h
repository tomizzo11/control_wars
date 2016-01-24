#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <SFML/Graphics.hpp>
#include "RigidBody.h"
#include "Force2Motion.h"

class Simulator
{
    public:
                Simulator();
        void    run();

    protected:
    private:
        // Member functions
        void    processEvent();
        void    updateDisplay();
        void    logic();

        // Member Objects
        sf::RenderWindow mWindow;
        sf::RectangleShape mPlayer;
        RigidBody body;
        Force2Motion motionBox;

        // Member Data
        InitParameters init = {
            73.0, // mass
            20.0,
            0.0, // center of mass
            0.0,
            100.0, // position
            100.0,
            0.0, // vel
            0.0,
            0.0, // acc
            0.0,
            0.0, // angle pos
            0.0,
            0.0,
            0.00000002, // time step
        };

};

#endif // SIMULATOR_H
