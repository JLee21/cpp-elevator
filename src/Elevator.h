#ifndef ELEVATOR_H
#define ELEVATOR_H

enum ElevStatus
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
        _status = ElevStatus::ready;
    };

    // getters / setters
    void setCurrentState();
    void getCurrentState();

    // typical behaviour methods
    void operate();
    void simulate();

    // miscellaneous
    // std::shared_ptr<Elevator> get_shared_this() { return shared_from_this(); }

private:
    // typical behaviour methods


    // std::shared_ptr<> _currFloor;            // street on which the vehicle is currently on
    // std::shared_ptr<Intersection> _currDest; // destination to which the vehicle is currently driving
    double _elev;                            // elevation of ego
    double _speed;                           // ego speed in m/s
    ElevStatus _status;
};

#endif