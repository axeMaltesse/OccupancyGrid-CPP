//
// Created by axeMaltesse on 06.03.16.
// Author Lukasz Wrzolek - luw19
//

#ifndef GRIDS_GRID_H
#define GRIDS_GRID_H

#include <vector>
#include "Position.h"

class OccupancyGrid {
private:
    int xWidth, yHigh;
    bool *cells;
public:

    OccupancyGrid(); // default constructor of the occupancy grid

    OccupancyGrid(int width, int high); // grid defined by the user

    ~OccupancyGrid(); //destructor

    //rest of the functions prototypes
    void const display_grid();

    void user_input(std::string posesFilename, std::string rangesFilename);

    void pose_from_file(std::vector<Position> &pose, std::string filename);

    void ranges_from_file(std::vector<Position> &pose, std::string filename);

    void markCells(const Position &position);

    Cell cell_index(double x, double y) const;

    double power(double a);
};


#endif //GRIDS_GRID_H
