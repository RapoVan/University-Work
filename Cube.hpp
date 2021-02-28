#include <string>

#ifndef CUBE_H
#define CUBE_H

using namespace std;

namespace Box
{
    class Cube
    {

    private:

    int Mass, Acceleration;
    string Color;
    static int countID;
    int CubeID;

    public:

    Cube();
    ~Cube();

    void setMass(int);
    void setAcceleration(int);
    void setColor(string);

    int getMass();
    int getAcceleration();
    string getColor();
    int getForce();

    void toString();

    private:

    bool checkMass(int);
    bool checkAcceleration(int);

    };
}


#endif
