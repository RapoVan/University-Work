#include <iostream>
#include <time.h>
#include "Cube.hpp"

using namespace std;



int main(){

try{

    Cube C1;
    cout << "Mass, Acceleration, Color" << endl;
    cin >> C1;
    cout << C1 << endl;

    cout << "Compare:\n";
    Cube C2;
    C2.setMass(10);
    bool  compare = C1 == C2;
    cout << compare << "\n" <<endl;

    C1++;
    cout << C1 << endl;

    --C1;
    cout << C1 << endl;

}
catch (invalid_argument& error){
    cout << error.what() << endl;
}
catch (...){
    cout << "Something happend" << endl;
}

return 0;
}
