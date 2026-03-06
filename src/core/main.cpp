#include <iostream>
#include "Simulator.hpp"

int main() {
    std::cout << "Starting Simulation..." << std::endl;
    Simulator sim = Simulator();
    sim.begin_simulation();
}