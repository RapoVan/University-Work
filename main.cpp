#include <iostream>
#include <time.h>
#include "Cube.hpp"

using namespace std;
using namespace Box;


int main(){

try{
    Cube C1;
    C1.setColor("blue");
    C1.setMass(5);
    C1.setAcceleration(2);
    C1.toString();

    Cube C2;
    C2.setColor("red");
    C2.setMass(9);
    C2.setAcceleration(10);
    C2.toString();

    Cube C3[2];
    C3[0].setColor("yellow");
    C3[0].setMass(10);
    C3[0].setAcceleration(0);
    C3[0].toString();

    C3[1].setColor("green");
    C3[1].setMass(50);
    C3[1].setAcceleration(100);
    C3[1].toString();

    Cube *C4 = new Cube;
    C4 -> setColor("purple");
    C4 -> setMass(30);
    C4 -> setAcceleration(1);
    C4 -> toString();

    delete C4;

}
catch (invalid_argument& error){
    cout << error.what() << endl;
}
catch (...){
cout << "Something happend" << endl;
}

return 0;
}
