#include <iostream>
#include "OccupancyGrid.h"

// Author Lukasz Wrzolek - luw19

using namespace std;

int main() {

    int i = 3;
    //simple do.. while loop to put the names of the files in correct order
    do {
        OccupancyGrid *occupancyGrid = new OccupancyGrid(); //creating a new grid sized 50 by 50 cells
        string pose;
        string range;
        cout << "Please put the name of position file:" << endl << "HINT: poses.txt \n";
        cin >> pose;
        cout << "Please put the name of ranges file:" << endl << "HINT: ranges.txt \n";
        cin >> range;

        if(range == "poses.txt" && pose == "ranges.txt")
            pose.swap(range); // swapping the variables
        if (pose == "poses.txt" && range == "ranges.txt") {
            occupancyGrid->user_input(pose, range); //reading cells and ranges from file
            occupancyGrid->display_grid(); //displaying the grid

            delete occupancyGrid;
            return 0;

        }else{
            i--;
            if (i==0){
                cout << "Please restart the program to have 3 chances again... \n";}
            else
                cout << "Please put right names of the files in correct order! \n";
                cout << "Remaining tries: " << i << endl;
        }
    }while(i > 0);
}