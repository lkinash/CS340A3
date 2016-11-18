//
//  main.cpp
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include "sorter.h"

using namespace std;

int main() {

    Sorter sorter = *new Sorter();      //creates a pointer to a new instance of the sorter class
    
    //sorter.runTimerTests();             //calls the function that takes input from the user to run the timed tests of the different sorting algorithms
    
    sorter.findBestSorter();        //this is the function that finds the algorithms best N value, it is commented out because it takes up to a couple minutes to run but can be un commented and run if desiered
    
    return 0;
}
