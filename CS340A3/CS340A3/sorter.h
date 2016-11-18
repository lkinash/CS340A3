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

class OutOfBounds{};            //if access an element that is outside of the range of the array attempted then an out of bounds error will be thrown

class EmptySet{};           //if access to an empty array is tried then an empty set error will be thrown

class Sorter{               //the sorter class is the main class for the program
    public:
    Sorter();               //a constructor for the sorter class
    
                //the sorter class contains an array called array, this is the array that the sorting functions will sort
    
    void insertionSort(int start, int end);         //the array will be sorted using insertion sort form the start value to the end value
    void quickSort(int left, int right);                   //quicksort takes the left and right ends of the array and sorts that portion
    void quickInsertionSort(int left, int right);  //quickinsertionsort takes the left and right ends of the array and sorts that portion calling insertion when the subarray is shorter than K
    void mergeSort(int left, int right);           //the merge sort alorithm is called with the left and right values as the ends of the array to be sorted
    
    double runInsertionSortTimed();         //the run insertion sort timed function calls a timer and then runs the sorting function and times it
    double runMergeSortTimed();         //the run merge sort timed function calls a timer and then runs the sorting function and times it
    double runQuickSortTimed();         //the run quick sort timed function calls a timer and then runs the sorting function and times it
    double runQuickInsertionSortTimed();    //the run quick insertion sort timed function calls a timer and then runs the sorting function and times it
    
    void promptUser();              //the prompt user function is the function that asks the user for input and takes that input
    
    void copyArray();               //copies the values in the array to be saved into the array to be sorted
    void printArray();          //prints out the values in the array
    void runTimerTests(); //the run timer tests function takes the user input and then calls the timed tests of all the sorters and prints the times
    
    void findBestSorter();              //runs tests to find the best sorter of the algorithms for the given amount of elements in the array
    
    int medianThree(int left, int right);                                   //gets the median of three for picking the pivot
    double minOfFour(double a, double b, double c, double d);     //figures out which of the four doubles is the smallest and returns that value
    
    void swap(int index1, int index2);              //swaps the values at the indexes passed in
    
    void fillArrayWithRandomNaturals();         //fills the array to be saved with N natural numbers
    int randomNatural();                    //gets a random number for the array
    
    double myTime();                  //the timer function gets the time of day and returns that value as a number of seconds
    
    private:
        const static int arrayMax = 690000;     //sets the max size that the array to be sorted can be
        int K, N;                           //creates the K and N values used by the user to set the array size
        int array[arrayMax];            //creates an array to be sorted
        int arrayToSave[arrayMax];      //creates an array that will save the values to be sorted in their unsorted order
        int mergeB[(arrayMax/2) + 2];           //merge sort needs a second array for merging, this is that second array
    
        struct timeval *tp;             //creates a time value structure to be used for timing the algorithms
        struct timezone *tzp;         //creates a time zone structure to be used for timing the algorithms
    
};

#endif /* sorter_h */
