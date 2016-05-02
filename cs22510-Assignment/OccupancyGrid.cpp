//
// Created by axeMaltesse on 06.03.16.
// Author: Lukasz Wrzolek - luw19
//
#include <iostream>
#include "OccupancyGrid.h"
//fstream to read from file
#include <fstream>
//we need to include math header file to use various math operations
#include "math.h"
//to set up the delay of the output to create an animation
#include <windows.h>

#define DEFAULT 50
#define PI 3.14159265


using namespace std;

double OccupancyGrid::power(double a) { //simple function to calculate power of the value
    double b = a * a;
    return b;
}

OccupancyGrid::OccupancyGrid() : xWidth(DEFAULT),yHigh(DEFAULT) { //default constructor
    //cells = new bool[power(DEFAULT)];
    cells = new bool[DEFAULT * DEFAULT]; //creating an boolean array
    for (int i = 0; i < 50; i++) { //two for loops to fill the array of false values
        for (int j = 0; j < 50 ; j++)
            cells[i+j * 50] = false;
    }
}

OccupancyGrid::OccupancyGrid(int width, int high) : xWidth(width), yHigh(high) { //same operation like in default constructor, but we receiving variables.
    cells = new bool[width * high];
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < high; j++)
            cells[i + j * width] = false;
    }
}

OccupancyGrid::~OccupancyGrid(void) {
    cout<<"Robot finished your task" << endl; //message before deleting the object
    delete cells;
}

Cell OccupancyGrid::cell_index(double x, double y) const { //indexing cells
    Cell cell;
    cell.x = (int) (x * 100 + 10) / 20;
    cell.y = (int) (y * 100 + 10) / 20;
    return cell;
}

//function which marking cells which are an obstacles, calculating the radians
void OccupancyGrid::markCells(const Position &position) {
    double cellWidth, cellHigh;
    Cell cell;
    for (size_t i = 0; i < position.sensors.size(); i++) {
        if (position.sensors.at(i) < 2.5) {
            //calculate to radians
            cellWidth = position.x + position.sensors.at(i) * cos((position.degrees + i * 45) * PI / 180);
            //calculate to radians
            cellHigh = position.y + position.sensors.at(i) * sin((position.degrees + i * 45) * PI / 180);
            cell = cell_index(cellWidth, cellHigh); // calling function cell_index to get index of current cell
            //ignoring cells outside of the grid by setting it automatically to true
            if (cell.x >= -0.1 && cell.x <= xWidth - 0.1 && cell.y >= -0.1 && cell.y <= yHigh - 0.1)
                cells[cell.x + cell.y * xWidth] = true; // finding cells outside and setting it for false value
        }
    }
}

void const OccupancyGrid::display_grid(void){
   // freopen("OUTPUT.txt", "w", stdout); //save output to the file
    for (int i = xWidth; i >= 0; i--) {
        Sleep(1);
        for (int j = 0; j < yHigh; j++) {
            if (cells[j + i * xWidth])
                cout << "*"; // marked cells as an obstacle
            else
                cout << " "; // space where the grid is without of obstacle
            Sleep(1);
        }
        cout << endl; //next line after the loop
    }
}

//method used to read collect information from different files
void OccupancyGrid::user_input(string posesFilename, string rangesFilename) {
    cout << "Reading poses from " << posesFilename << endl;
    vector<Position> position;
    pose_from_file(position, posesFilename);
    ranges_from_file(position, rangesFilename);
    for (const auto i : position) { //incrementing
        markCells(i);
    }
}

//read the poses from file
void OccupancyGrid::pose_from_file(vector<Position> &pose, string filename) {
    ifstream file(filename); //name of the variable to hold name of the file
    //checking if file exists and we can open it
    if (!file.is_open()) { //creates abd error if the file cannot be open
        cout << "can't open the file";
    }
    double width, high; // local variables
    int d;
    //reading next values from file to the array. We are using simple shifting to get values for next variables
    //loop end when
    while (file >> width >> high >> d) {
        Position position;
        position.x = width;
        position.y = high;
        position.degrees = d;
        pose.push_back(
                position); //push_back is a vector function to add element from brackets to the last position in array
    }
}

void OccupancyGrid::ranges_from_file(vector<Position> &pose, string filename) {
    ifstream file(filename); //file name of rangers file
    double sensor[8];//table of 8 robot sensors to store values from file
    size_t counter = 0; //simple variable to count and hold number of values
    //shifting the values to the correct place in array.
    while (file >> sensor[0] >> sensor[1] >> sensor[2] >> sensor[3] >> sensor[4] >>
           sensor[5] >> sensor[6] >> sensor[7]) {
        for (int j = 0; j < 8; j++) {
            pose.at(counter).sensors.push_back(sensor[j]);//taking values from one array to dynamic vector array
        }
        counter++;
    }
}



