//
//  sorter.h
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef sorter_h
#define sorter_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sys/time.h>

using namespace std;

class OutOfBounds{};

class EmptySet{};

class Sorter{
    public:
    
    Sorter();
    
    void insertionSort(int start, int end);
    void quickSort(int left, int right);
    void quickInsertionSort(int left, int right);
    void mergeSort(int left, int right);
    
    double runInsertionSortTimed();
    double runMergeSortTimed();
    double runQuickSortTimed();
    double runQuickInsertionSortTimed();
    
    void promptUser();
    
    void copyArray();
    void printArray();
    void runTimerTests();
    
    void findBestSorter();
    
    int medianThree(int left, int right);
    double minOfFour(double a, double b, double c, double d);
    
    void swap(int index1, int index2);
    
    void fillArrayWithRandomNaturals();
    int randomNatural();
    
    double myTime();
    
    private:
    const static int arrayMax = 690000;
    int K, N;
    int array[arrayMax];
    int arrayToSave[arrayMax];
    int mergeB[arrayMax];
    
    struct timeval *tp;
    struct timezone *tzp;
    
};


#endif /* sorter_h */
