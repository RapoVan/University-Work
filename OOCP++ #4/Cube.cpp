#include <iostream>
#include <time.h>
#include <sstream>

#include "Cube.hpp"


using namespace std;


int Cube::countID = 1;

Cube::Cube()
{
    CubeID = countID;
    countID++;
}

Cube::~Cube()
{
}

void Cube::setMass(const int &Mass)
{
    if(checkMass(Mass))
        this->Mass = Mass;
    else
        throw invalid_argument("Invalid mass");
}

void Cube::setAcceleration(const int &Acceleration)
{
    if(checkAcceleration(Acceleration))
        this->Acceleration = Acceleration;
    else
        throw invalid_argument("Invalid Acceleration");
}

void Cube::setColor(const string &Color)
{
    this->Color = Color;
}

int Cube::getMass()
{
    return Mass;
}

int Cube::getAcceleration()
{
    return Acceleration;
}

string Cube::getColor()
{
    return Color;
}

string Cube::toString() const
{
    ostringstream ss;
    ss << "Color: " << Color << endl;
    ss << "Mass: " << Mass << endl;
    ss << "Acceleration: " << Acceleration << endl;
    ss << "(" << CubeID << ") Cube color is " << Color << " and has " << Mass * Acceleration << " force.\n" << endl;
    return ss.str();
}

bool Cube::operator==(const Cube &n) const
{
    if(Mass == n.Mass){
        return true;
    }else{
        return false;
    }
}

bool Cube::operator!=(const Cube &n) const
{
    return !(*this == n);
}

bool Cube::operator>(const Cube &n) const
{
    if(Mass > n.Mass){
        return true;
    }else{
        return false;
    }
}

bool Cube::operator<(const Cube &n) const
{
    return n > *this;
}

bool Cube::operator>=(const Cube &n) const
{
    if(*this ==n){
        return true;
    }else{
        return *this > n;
    }
}

bool Cube::operator<=(const Cube &n) const
{
    if(*this ==n){
        return true;
    }else{
        return *this < n;
    }
}

Cube Cube::operator++()
{
    ++Mass;
    return *this;
}

Cube Cube::operator++(int)
{
    Cube temp = *this;
    ++Mass;
    return temp;
}

Cube Cube::operator--()
{
    --Mass;
    return *this;
}

Cube Cube::operator--(int)
{
    Cube temp = *this;
    --Mass;
    return temp;
}

istream& operator>>(std::istream &is, Cube &is_Cube)
{
    Cube temp;
    is >> temp.Mass >> temp.Acceleration >> temp.Color;

    Cube other;
    other.setMass(temp.Mass);
    other.setAcceleration(temp.Acceleration);
    other.setColor(temp.Color);

    is_Cube = other;
    return is;
}

ostream& operator<<(std::ostream &os, const Cube &os_Cube)
{
    os << os_Cube.toString();
    return os;
}

    bool Cube::checkMass(int Mass)
{
        if(Mass >= 0)
        return true;
        else
        return false;

}

bool Cube::checkAcceleration(int Acceleration)
{
        if(Acceleration >= 0)
        return true;
        else
        return false;

}
