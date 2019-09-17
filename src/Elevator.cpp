#include "Elevator.h"
#include <iostream>
#include <thread>
#include <chrono>

void Elevator::operate()
{
    while(true){
        std::cout << "Elevator is running..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}