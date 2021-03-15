#include <iostream>
#include <time.h>
#include <sstream>
#include <string>


#include "Cube.h"


using namespace std;


int cube::countID = 1;

cube::cube(){
    cubeID = countID;
    countID++;
}

cube::cube(string color, int mass, int acceleration){
    setColor(color);
    setMass(mass);
    setAcceleration(acceleration);
    cubeID = countID;
    countID++;
}

void cube::inCube(string &color, int &mass, int &acceleration){
    setColor(color);
    setMass(mass);
    setAcceleration(acceleration);
}

cube::~cube(){
}

void cube::setMass(int mass){
    if(checkMass(mass))
        this->mass = mass;
    else
        throw invalid_argument("Invalid mass");
}

void cube::setAcceleration(int acceleration){
    if(checkAcceleration(acceleration))
        this->acceleration = acceleration;
    else
        throw invalid_argument("Invalid Acceleration");
}

void cube::setColor(string color){
    this->color = color;
}

int cube::getMass() const{
    return mass;
}

int cube::getAcceleration() const{
    return acceleration;
}

string cube::getColor() const{
    return color;
}

int cube::getForce() const{
    return mass * acceleration;
}

string cube::toString() const{
    ostringstream ss;
    ss << "Color: " << color << endl;
    ss << "Mass: " << mass << endl;
    ss << "Acceleration: " << acceleration << endl;
    ss << "(" << cubeID << ") Cube color is " << color << " and has " << getForce() << " force.\n" << endl;
    return ss.str();
}

bool cube::operator==(const cube &other) const{
    if(mass == other.mass){
        return true;
    }else{
        return false;
    }
}

bool cube::operator!=(const cube &other) const{
    return !(*this == other);
}

bool cube::operator>(const cube &other) const{
    if(mass > other.mass){
        return true;
    }else{
        return false;
    }
}

bool cube::operator<(const cube &other) const{
    return other > *this;
}

bool cube::operator>=(const cube &other) const{
    if(*this ==other){
        return true;
    }else{
        return *this > other;
    }
}

bool cube::operator<=(const cube &other) const{
    if(*this ==other){
        return true;
    }else{
        return *this < other;
    }
}

cube cube::operator++(){
    ++mass;
    return *this;
}

cube cube::operator++(int){
    cube temp = *this;
    ++mass;
    return temp;
}

cube cube::operator--(){
    --mass;
    return *this;
}

cube cube::operator--(int){
    cube temp = *this;
    --mass;
    return temp;
}

istream& operator>>(std::istream &is, cube &is_cube){
    string temp_color;
    int temp_mass;
    int temp_acceleration;

    is >> temp_color >> temp_mass >> temp_acceleration;
    is_cube.inCube(temp_color, temp_mass, temp_acceleration);

    return is;
}

ostream& operator<<(std::ostream &os, const cube &os_cube){
    os << os_cube.toString();
    return os;
}

bool cube::checkMass(int mass){
    if(mass >= 0){
        return true;
    }else{
        return false;
    }
}

bool cube::checkAcceleration(int acceleration){
    if(acceleration >= 0){
         return true;
    }else{
        return false;
    }
}

