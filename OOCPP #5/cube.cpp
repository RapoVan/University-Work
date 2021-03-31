#include <iostream>
#include <iomanip>
#include <time.h>
#include <sstream>
#include <string>
#include <stdexcept>


#include "cube.h"


using namespace std;

namespace box{

    class cube::innerCube{

        int mass, acceleration;
        string color;
        static int countId;
        int cubeId;

        friend class cube;

    };

    int cube::innerCube::countId = 0;

    cube::cube()
    {
        ptr = NULL;
    }

    cube::cube(const string &color, int mass, int acceleration)
    {
        ptr = new innerCube();

        init(++innerCube::countId, color, mass, acceleration);
    }

    cube::cube(const cube &other_cube)
    {
        innerCube *temp = new innerCube();

        temp->cubeId = other_cube.getCubeId();
        temp->color = other_cube.getColor();
        temp->mass = other_cube.getMass();
        temp->acceleration = other_cube.getAcceleration();

        this->ptr = temp;
    }

    cube& cube::operator =(const cube &other_cube)
    {
        if(ptr == NULL || other_cube.ptr == NULL){
            throw logic_error("Object not Initialized");
        }

        if(this->ptr == other_cube.ptr){
            return *this;
        }

        innerCube *temp = new innerCube();

        temp->cubeId = other_cube.getCubeId();
        temp->color = other_cube.getColor();
        temp->mass = other_cube.getMass();
        temp->acceleration = other_cube.getAcceleration();

        delete this->ptr;
        this->ptr = temp;

        return *this;
    }

    void cube::init(int cubeId, const string &color, int mass, int acceleration)
    {
        setCubeId(cubeId);
        setColor(color);
        setMass(mass);
        setAcceleration(acceleration);
    }

    cube::~cube()
    {
        --innerCube::countId;
        delete ptr;
    }

    void cube::setMass(int mass)
    {
        if(ptr == NULL){
            ptr = new innerCube();
        }
        if(checkMass(mass))
            this->ptr->mass = mass;
        else
            throw invalid_argument("Invalid mass");
    }

    void cube::setAcceleration(int acceleration)
    {
        if(ptr == NULL){
            ptr = new innerCube();
        }
        if(checkAcceleration(acceleration))
            this->ptr->acceleration = acceleration;
        else
            throw invalid_argument("Invalid Acceleration");
    }

    void cube::setColor(const string &color)
    {
        if(ptr == NULL){
            ptr = new innerCube();
        }
        this->ptr->color = color;
    }

    void cube::setCubeId(int cubeId)
    {
        if(ptr == NULL){
            ptr = new innerCube();
        }
        this->ptr->cubeId = cubeId;
    }

    int cube::getMass() const
    {
        if(ptr == NULL){
            throw logic_error("No init");
        }
        return ptr->mass;
    }

    int cube::getAcceleration() const
    {
        if(ptr == NULL){
            throw logic_error("No init");
        }
        return ptr->acceleration;
    }

    string cube::getColor() const
    {
        if(ptr == NULL){
            throw logic_error("No init");
        }
        return ptr->color;
    }

    int cube::getCubeId() const
    {
        if(ptr == NULL){
            throw logic_error("No init");
        }
        return ptr->cubeId;
    }

    int cube::getForce() const
    {
        if(ptr == NULL){
            throw logic_error("No init");
        }
        return ptr->mass * ptr->acceleration;
    }

    string cube::toString() const
    {
        if(ptr == NULL){
            throw logic_error("No init");
        }

        ostringstream ss;
        ss << "Color: " << getColor() << endl;
        ss << "Mass: " << getMass() << endl;
        ss << "Acceleration: " << getAcceleration() << endl;
        ss << "(" << getCubeId() << ") Cube color is " << getColor() << " and has " << getForce() << " force.\n" << endl;

        return ss.str();
    }

    bool cube::operator==(const cube &other) const
    {
        if(this->getMass() == other.getMass()){
            return true;
        }else{
            return false;
        }
    }

    bool cube::operator!=(const cube &other) const
    {
        return !(*this == other);
    }

    bool cube::operator>(const cube &other) const
    {
        if(this->getMass() > other.getMass()){
            return true;
        }else{
            return false;
        }
    }

    bool cube::operator<(const cube &other) const
    {
            return other > *this;
    }

    bool cube::operator>=(const cube &other) const
    {
        if(*this ==other){
            return true;
        }else{
            return *this > other;
        }
    }

    bool cube::operator<=(const cube &other) const
    {
        if(*this ==other){
            return true;
        }else{
            return *this < other;
        }
    }

    cube cube::operator++()
    {
        ++ptr->mass;
        return *this;
    }

    cube cube::operator++(int)
    {
        cube temp = *this;
        ++ptr->mass;
        return temp;
    }

    cube cube::operator--()
    {
        --ptr->mass;
        return *this;
    }

    cube cube::operator--(int)
    {
        cube temp = *this;
        --ptr->mass;
        return temp;
    }

    istream& operator>>(std::istream &is, cube &is_cube)
    {
        int temp_cubeId;
        string temp_color;
        int temp_mass;
        int temp_acceleration;

        is >> temp_cubeId >> temp_color >> temp_mass >> temp_acceleration;
        is_cube.init(temp_cubeId, temp_color, temp_mass, temp_acceleration);

        return is;
    }

    ostream& operator<<(std::ostream &os, const cube &os_cube)
    {
        os << os_cube.toString();
        return os;
    }

    bool cube::checkMass(int mass)
    {
        if(mass >= 0){
            return true;
        }else{
            return false;
        }
    }

    bool cube::checkAcceleration(int acceleration)
    {
        if(acceleration >= 0){
            return true;
        }else{
            return false;
        }
    }
}
