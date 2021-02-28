#include <iostream>
#include <time.h>
#include "Cube.hpp"


using namespace std;


    int Box::Cube::countID = 1;

    Box::Cube::Cube()
    {
        CubeID = countID;
        countID++;
    }

    Box::Cube::~Cube()
    {
    }

    void Box::Cube::setMass(int Mass)
    {
        if(checkMass(Mass))
           this -> Mass = Mass;
        else
            throw invalid_argument("Invalid mass");
    }

    void Box::Cube::setAcceleration(int Acceleration)
    {
        if(checkAcceleration(Acceleration))
        this -> Acceleration = Acceleration;
        else
        throw invalid_argument("Invalid Acceleration");
    }

    void Box::Cube::setColor(string Color)
    {
        this -> Color = Color;
    }

    int Box::Cube::getMass()
    {
        return Mass;
    }

    int Box::Cube::getAcceleration()
    {
        return Acceleration;
    }

    string Box::Cube::getColor()
    {
        return Color;
    }

    int Box::Cube::getForce()
    {
        return Mass * Acceleration;
    }

    void Box::Cube::toString()
    {
        cout << "Color: " << getColor() << endl;
        cout << "Mass: " << getMass() << endl;
        cout << "Acceleration: " << getAcceleration() << endl;
        cout << "(" << CubeID << ") Cube color is " << getColor() << " and has " << getForce() << " force.\n" << endl;
    }

    bool Box::Cube::checkMass(int Mass)
    {
        if(Mass >= 0)
        return true;
        else
        return false;

    }

    bool Box::Cube::checkAcceleration(int Acceleration)
    {
        if(Acceleration >= 0)
        return true;
        else
        return false;

    }
