//
// Created by axeMaltesse on 06.03.16.
// Author Lukasz Wrzolek - luw19
//
#include <iostream>
#include <ostream>
#include <vector>
//vector is a dynamic array to store the values from files
//http://cpp0x.pl/kursy/Kurs-STL-C++/Kontener-tablicy-std-vector/119
#ifndef GRIDS_POSE_H
#define GRIDS_POSE_H

/**
 * creates a Position structure to have a position of the robot and store output from robot sensor.
 */
struct Position {
    double x; //position on axis X
    double y; //position on axis Y
    int degrees; //degrees to obstacle
    std::vector<double> sensors; //dynamic array of double type to store values from sensors
};

/**
 * creates a structure Cell to hold position of each cell
 */
struct Cell {
    int x, y; //position of single cell
};
#endif //GRIDS_POSE_H
