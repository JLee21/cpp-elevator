#include "Elevator.h"
#include <iostream>
#include <thread>
#include <chrono>

#define printX(x) std::cout<<"Name of variable **"<<(#x)<<"** and value => "<<x<<"\n"


void Elevator::operate()
{
    while(true){
        std::cout << "Elevator is ready..." << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // onboard person
        setState(ElevState::busy);

        // assume person is on floor 1
        // assume ego is always starting on ground floor 1
        // wait for person to push floor button
        setTargetFloor(2);

        // ego moves to floor
        // within move, ego updates status, speed and elevation and status
        move();

        // ego arrives at floor. so maybe wait here until ego reports back?
        // also set the ego status
        setState(ElevState::busy);

    }
}

void Elevator::setTargetFloor(int floorNum){
    // TODO: write logic to check approp floor number
    _targetFloor = floorNum;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));    
    std::cout << "Elevator set desired floor to ..." << _targetFloor << std::endl;
}

double Elevator::getZFromFloor(int floorNum){
    double _z = floorNum * 3.3;
    return _z; // one floor equals around 12 feet
}

void Elevator::move(){
    std::cout << "Elevator is moving..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    setState(ElevState::moving);

    std::chrono::time_point<std::chrono::system_clock> lastUpdate;
    lastUpdate = std::chrono::system_clock::now();

    // incrementally move ego
    while(_state == ElevState::moving){
        printStatus();

        // check if _currElev is pretty close to floor elevation
        if(_currZ >= getZFromFloor(_targetFloor)){
            std::cout << "Elevator arrived at Target Floor ..." << _targetFloor << std::endl;
            setState(ElevState::busy);
            setCurrFloor(_targetFloor);
            return;
        }        

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        double timeDelta = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - lastUpdate).count();        
        double z1 = timeDelta/1000 * _speed + _currZ;
        setCurrZ(z1);




        lastUpdate = std::chrono::system_clock::now();
    }

}