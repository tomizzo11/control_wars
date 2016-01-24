#include "Simulator.h"
#include <SFML/Graphics.hpp>
#include "RigidBody.h"
#include "Force2Motion.h"
#include <array>
#include <iostream>

Simulator::Simulator()
: mWindow(sf::VideoMode(640,480), "Physics Box!")
, mPlayer()
, body(InitParameters{90, 20.0, 0.0, 0.0, 60.0, 100.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.02})
, motionBox(body)
{
    mPlayer.setSize(sf::Vector2f(40.f, 40.f));
    mPlayer.setRotation(23.0);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);

}


void Simulator::processEvent()
{
    sf::Event newEvent;

    while (mWindow.pollEvent(newEvent))
    {
        if (newEvent.type == sf::Event::Closed)
        {
            mWindow.close();
        }
    }
}

void Simulator::updateDisplay()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Simulator::run()
{

    while(mWindow.isOpen())
    {
        logic();
        processEvent();
        updateDisplay();
    }

}

void Simulator::logic()
{
    std::array<float, 4> testArray{{100, 0, 5, 3.14/2}};
    std::vector< std::array<float, 4>> inputVector;
    std::vector< std::array<float, 4>>::iterator it = inputVector.begin();
    inputVector.insert(it, testArray);
    motionBox.LoadVectorData(inputVector);
    std::cout << "Current X Position = " << body.GetXPosition() << "\n";
    std::cout << "New X Position     = " << motionBox.GetNewX() << "\n";
    std::cout << "Net X Force        = " << motionBox.GetNetXForce() << "\n";
    std::cout << "Mass               = " << body.GetMass() << "\n";

    body.SetXPosition(motionBox.GetNewX());
    body.SetYPosition(motionBox.GetNewY());
    body.SetAngle(motionBox.GetNewAngle());

    mPlayer.setPosition(body.GetXPosition(), body.GetYPosition());
    mPlayer.setRotation(body.GetAnglePosition());



//    motionBox.LoadVectorData(inputArray);
 //   body.SetXPosition(motionBox.GetNewX());

 //   std::cout << "Current X Position = " << body.GetXPosition() << " \n";
 //   body.SetYPosition(motionBox.GetNewY());
 //   body.SetAngle(motionBox.GetNewAngle());
 //   mPlayer.setPosition(body.GetXPosition(), body.GetYPosition());
 //   mPlayer.setRotation(body.GetAnglePosition());

}
