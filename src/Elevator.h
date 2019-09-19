#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <stdio.h>

enum ElevState
{
    ready,
    busy,   // the times between ready/moving and moving/ready
    moving,
    error,
};

class Elevator
{
public:
    // constructor / desctructor
    Elevator(){
        _state = ElevState::ready;
        _speed = 2; // m/s
        _currFloor = 1;
        _targetFloor = 1;
        _currZ = 0.0;
    };

    // getters / setters
    
    ElevState getState() {return _state;};

    // typical behaviour methods
    void operate();
    void simulate();
    double getZFromFloor(int floorNum);
    void printStatus(){
        // TODO: thread this print statement
        printf("*****************************\n");
        printf ("Current State:\t%d \n", _state);
        printf ("Current Z:\t%0.1f \n", _currZ);
        printf ("Current Floor:\t%d \n", _currFloor);
        printf ("Target Floor:\t%d \n", _targetFloor);
        printf ("Current Speed:\t%0.1f \n", _speed);
        printf("*****************************\n\n");
    }

    // miscellaneous
    // std::shared_ptr<Elevator> get_shared_this() { return shared_from_this(); }

private:
    ElevState _state;
    double _currZ; // elevation of ego
    int _currFloor; // the floor ego is at during a stop
    int _targetFloor; // the floor the ego needs to get to
    double _speed; // ego speed in m/s
    void move();
    void setTargetFloor(int floorNum);
    void setCurrFloor(int floorNum) { _currFloor = floorNum; }
    void setCurrZ(int _z) { _currZ = _z; }
    void setState(ElevState state) { _state = state; }

};

#endif