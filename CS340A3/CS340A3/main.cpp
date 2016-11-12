//
//  main.cpp
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <iostream>
#include "sorter.h"

using namespace std;

int main() {

    Sorter sorter = *new Sorter();
    
    sorter.runTimerTests();
    
    //cout <<  sorter.randomNatural() << endl;
    
    return 0;
}
