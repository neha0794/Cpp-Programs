#include <iostream>
using namespace std;
#include"vehicle.h"
#include "car.h"

int main(){
    Car c;
    Vehicle v;

    v.print();
    c.print();

    Vehicle *v1 = new Vehicle;
    Vehicle *v2;
    v2 = &c;
    
    v1 -> print();
    v2 -> print();

}