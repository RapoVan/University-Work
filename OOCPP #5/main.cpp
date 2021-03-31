#include <iostream>
#include <time.h>
#include "cube.h"

using namespace std;



int main(){

try{

    box::cube C1("blue",5,10);
    cout << C1 << endl;

    box::cube C2("yellow",100,100);
    cout << C2 << endl;

    box::cube C3("black",50,25);
    cout << C3 << endl;

    box::cube Cc1;
    cout << "Id, Color, Mass, Acceleration" << endl;
    cin >> Cc1;
    cout << Cc1 << endl;

    box::cube Cc2;
    cout << "Color, Mass, Acceleration" << endl;
    cin >> Cc2;
    cout << Cc2 << endl;


    C1++;
    cout << C1 << endl;

    --C1;
    cout << C1 << endl;



}
catch (invalid_argument& error){
    cout << error.what() << endl;
}
catch (logic_error& error){
    cout << error.what() << endl;
}

return 0;
}
