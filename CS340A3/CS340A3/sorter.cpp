//
//  sorter.cpp
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <sys/time.h>
#include "sorter.h"

void Sorter::insertionSort(int start, int end){             //insertion sort is called on the array from the start to end value
    for(int i = start; i < end ; i++){              //a for loop is called starting at the start loop and ending at the end value
        int temp = array[i];                        //a temp is set to the value the for loop is at in the array
        int j = i;                                  //a second value is set to that index
        while(( j > 0 ) && (temp < array[j - 1])){          //then while the value is greater than 0, and the array value is greater than the temp
            array[j] = array[j - 1];                    //the array values are moved down the line
            j--;                                        //the index is decremented
        }
        array[j] = temp;                //then a new temp is set to the next value in the array
    }
    return;                     //then the function returns after sorting the elements
}

void Sorter::quickSort(int left, int right){            //quicksort takes the left and right ends of the array and sorts that portion
    
    int pivot = medianThree(left, right);           //first a pivot is
    
    int i = left;                       //i is set to the left
    int j = right;                          //j is set to the right value
    for(;;){                                //a loop is entered
        while(array[++i] < pivot) {}        //i is incremented then the value at that index is checked against the pivot
        while(pivot < array[--j]) {}       //j is decremented then the value at that index is checked against the pivot
        if(i <= j){                         //if i is less than or equal to J then the values at the indexes are swapped
            swap(i, j);             //then the values at the indexes are swapped
        }
        else
            break;              //otherwise break out of the loop
    }
    
    if (left < j)           //if left is smaller than the J value
        quickSort(left, j);   // Sort recursively called for smaller elements
    if (i < right)              //if right is larger than the i value
        quickSort(i, right);    // Sort recursively called for larger elements
    
    return;
}

void Sorter::quickInsertionSort (int left, int right){
    
    if (left + K <= right){                             //if the subarray is larger than K hen the quicksort is done
        int pivot = medianThree(left, right);           //first a pivot is
        
        int i = left;                       //i is set to the left
        int j = right;                          //j is set to the right value
        for(;;){                                //a loop is entered
            while(array[++i] < pivot) {}        //i is incremented then the value at that index is checked against the pivot
            while(pivot < array[--j]) {}       //j is decremented then the value at that index is checked against the pivot
            if(i <= j){                         //if i is less than or equal to J then the values at the indexes are swapped
                swap(i, j);             //then the values at the indexes are swapped
            }
            else
                break;              //otherwise break out of the loop
        }
        
        if (left < j)           //if left is smaller than the J value
            quickInsertionSort(left, j);   // Sort recursively called for smaller elements
        if (i < right)              //if right is larger than the i value
            quickInsertionSort(i, right);    // Sort recursively called for larger elements
    }
    
    else                                    //if it is not bigger than K then
        insertionSort(left, right);             //insertion sort is called on that subarray
    
    return;
}


void Sorter::mergeSort(int left, int right){       //the merge sort alorithm is called with the left and right values as the ends of the array to be sorted
    
    int bottomLeft = left;
    int topRight = right;                   //since the array is split into two arrays two variables for the top of one array and bottom of the other are set based on the values that were passed in
    
    if (bottomLeft < topRight){         //then the array is partitioned if the left bottom value is less than the right top value
        
        int bottomRight = ((bottomLeft + topRight) / 2);        //the bottom right is set at the center of the original array
        mergeSort(bottomLeft, bottomRight);                 //merge sort calls itself recursively
        
        int topLeft = (bottomRight + 1);                    //the top left is set to one past the bottom right
        mergeSort(topLeft, topRight);                           //again it is called recursively on the subarray
        
        int i = bottomLeft;                         //finally bottom left is set to the i value
        int count = topRight - bottomLeft + 1;          //the count is set to the length of the array
        
        while(bottomLeft <= bottomRight && topLeft <= topRight){            //a while loop for while we are inside both of the sub arrays is enteted
            if(array[bottomLeft] <= array[topLeft]){                //if the bottom left value is less than the top left
                mergeB [i] = array[bottomLeft];                     //put the bottom left into the second array
                bottomLeft ++;                                  //and increment the bottom left value
            }
            else{                                   //if ti is not less
                mergeB [i] = array[topLeft];            //put the top left value into the other array
                topLeft ++;                         //and increment the top left value
            }
            i ++;                                   //then increment the i value
        }
        while(bottomLeft <= bottomRight){       //for the bottom array
            mergeB[i] = array[bottomLeft];              //put the value in the original array into the second array
            bottomLeft++;                       //then increment both the i value and the bottom left value
            i++;
        }
        while(topLeft <= topRight){             //for the top array
            mergeB[i] = array[topLeft];           //put the value in the original array into the second array
            topLeft++;
            i++;                               //then increment both the i value and the top left value
        }
        
        i = 0;                          //i is set to 0, if i is less than the count then
        while(i < count){
            array[topRight] = mergeB[topRight];         //it loops through and puts the elements in the second array back in the first array
            i++;                                    //increment the i value until it gets to the count
            topRight--;                         //decrement the top right each time so the next element can be moved over
        }
    }
    return;
}

double Sorter::runInsertionSortTimed(){         //the run insertion sort timed function starts the timer and then calls the insertion sort to time it
    
    double startTime = myTime();                //the start time is set and then the function for sorting is called
    
    insertionSort(0, N);                        //insertion sort is called for the whole array
    
    double endTime = myTime();                     //then the end time is set by calling the timing function again
    
    double duration = double((endTime - startTime))/1000;          //then that value is divided by 1000 to get the time in ms
    
    return duration;                                          //and that time is returned
    
}

double Sorter::runMergeSortTimed(){         //the run merge sort timed function calls a timer to start and then runs the sorting function and times it
    
    double startTime = myTime();               //the start time is set and then the function for sorting is called
    
    mergeSort(0, N-1);                        //merge sort is called for the whole array
    
    double endTime = myTime();                     //then the end time is set by calling the timing function again
    
    double duration = double(endTime - startTime)/1000;        //then that value is divided by 1000 to get the time in ms
    
    return duration;                                          //and that time is returned
    
}

double Sorter::runQuickSortTimed(){       //the run quick sort timed function calls a timer to start and then runs the sorting function and times it
    
    double startTime = myTime();               //the start time is set and then the function for sorting is called
    
    quickSort(0, N);                                //quick sort is called for the whole array
    
    double endTime = myTime();                     //then the end time is set by calling the timing function again
    
    double duration = double(endTime - startTime)/ 1000;        //then that value is divided by 1000 to get the time in ms
    
    return duration;                                          //and that time is returned
}

double Sorter::runQuickInsertionSortTimed(){    //the run quick insertion sort timed function calls a timer and then runs the sorting function and times it
    
    double startTime = myTime();               //the start time is set and then the function for sorting is called
    
    quickInsertionSort(0, N);                        //quick insertion sort is called for the whole array
    
    double endTime = myTime();                      //then the end time is set by calling the timing function again
    
    double duration = double(endTime - startTime)/ 1000;        //then that value is divided by 1000 to get the time in ms
    
    return duration;                            //and that time is returned
    
}

double Sorter::myTime(){                //the timer function gets the time of day and returns that value as a number of seconds
    gettimeofday(tp,tzp);               //gets the time of day
    return (( (double)  tp->tv_sec) * CLOCKS_PER_SEC )+ ( (double) tp->tv_usec );         //converts it to seconds and micro seconds and returns that value
}

void Sorter::promptUser(){              //the prompt user function is the function that asks the user for input and takes that input
    
    int input;                  //sets some values to take input from the user
    string extra;
    
    cout << "This program sorts arrays of randomly generated numbers using Quick Insertion Sort, Quick Sort, Merge Sort and Insertion Sort and times each sorting algorithm. The size of the array to be sorted is based on user input. " << endl;  //prints a message to tell the user what the program does
    
    cout << "N is the number of random naturals to sorted. The maximum value for N in this system is 690000. Please enter a value for N: ";
            //then prints a message to tell the user what the value N is and to ask them to enter it
    
    cin >> input;       //takes the value in from the user
    
    getline(cin, extra);            //takes in anything extra just to get it out of the way
    
    while(1){                   //enters a while loop to check the user input and ask for new input if it is not valid
        if(input < 1 ){                 //if the user entered a number of elements in the array to be sorted that was less than one it is not valid
            cout << "A value less than 1 is not valid for N, please enter a valid (between 1 and 690000) N value:";
            
            cin >> input;               //the user is asked to enter a different value and the input is again taken from the user
            getline(cin, extra);
        }
        else if(input > 690000){            //the max value is the size at which the program will crash, if the user enters a value larger than this they will be told it is not valid and asked to enter a new value
            cout << "A value greater than 690000 is not valid for N, this will cause an array that is too big and could cause overflow or other access errors. Please enter a valid (between 1 and 690000) N value:";
            
            cin >> input;           //again the user input is taken in
            getline(cin, extra);
        }
        else            //if the value entered by the user is valid then break out of the loop
            break;
    }
    
    N = input;          //and then set the value that the user entered as the value for N
    
    cout << "K is the number used by quick insertion sort. The maximum value for K in this system is also 690000. Please enter a value for K: ";
            //then the user is told what K is used for and is asked to enter a valid number for K
    
    cin >> input;
    
    getline(cin, extra);            //the user input is taken in and an extra line to make sure there is nothing extra
    
    while(1){
        if(input < 0 ){     //if the user entered a number of elements in the array to be sorted that is not valid the user is asked to enter it again
            cout << "A value less than 0 is not valid for K, please enter a valid (between 1 and 690000) K value:";
            
            cin >> input;                   //if the value is non positve then a new value is taken in
            getline(cin, extra);
        }
        else if(input > N){    //if the user entered a number of elements in the array to be sorted that is not valid the user is asked to enter it again
            cout << "A value greater than the N value entered is not valid for K, please enter a valid (between 1 and 690000 and less than N) K value:";
            
            cin >> input;           //if the value is larger than the size of the array entered then new input is taken
            getline(cin, extra);
        }
        else if(input > 690000){  //if the user entered a number of elements in the array to be sorted that is not valid the user is asked to reenter it
            cout << "A value greater than 690000 is not valid for K, this will cause an array that is too big and could cause overflow or other access errors. Please enter a valid (between 1 and 690000) K value:";
            
            cin >> input;               //if the value was too large then the users input is taken in again
            getline(cin, extra);
        }
        else
            break;              //break from the loop when a good value for K is found
    }
    K = input;              //then K is set to the value that the user entered is valid
}

void Sorter::copyArray(){               //copies the values from the array to be saved into the array that will be sorted
    
    for(int i = 0; i < N ; i++){        //goes through each element in the array of length n
        array[i] = arrayToSave[i];      //copies each element from the array to be saved into the array named array which is the one to be sorted
    }
}

void Sorter::runTimerTests(){   //the run timer tests function takes the user input and then calls the timed tests of all the sorters and prints the times
    
    double duration;                //the duration variables for the times is initialized
    
    promptUser();                   //the user is prompted to enter the values for N and K
    
    fillArrayWithRandomNaturals();          //the array to save is filled with the random values
    copyArray();                            //that array is copied into the array that is to be sorted
    //printArray();                               //the unsorted array is printed out to the user
    
    duration = runQuickInsertionSortTimed();
    cout<<"Quick Insertion Sort Time: "<< duration << " ms" << endl;        //the function to run quick insetion sort and time it is called
    //printArray();                                                       //then the time is printed out to the user and then the sorted array is printed
    
    copyArray();
    duration = runQuickSortTimed();
    cout<<"Quick Sort Time: "<< duration << " ms" << endl;        //the function to run quick sort and time it is called
    //printArray();                                                       //then the time is printed out to the user and then the sorted array is printed
    
    copyArray();
    duration = runMergeSortTimed();
    cout<<"Merge Sort Time: "<< duration << " ms" << endl;        //the function to run merge sort and time it is called
    //printArray();                                                       //then the time is printed out to the user and then the sorted array is printed
    
    copyArray();
    duration = runInsertionSortTimed();
    cout<<"Insertion Sort Time: "<< duration << " ms" << endl;          //the function to run insetion sort and time it is called
    //printArray();                                                       //then the time is printed out to the user and then the sorted array is printed
    
}

void Sorter::findBestSorter(){
    
    int jMax = 7, iMax = 38;        // the size of the arrays are set as a max
    
    int testK[] = {1, 5, 10, 15, 20, 25, 50, 100};                  //arrays of values to be tested are set
    int testN[] = {2, 5, 10, 15, 20, 25, 50, 75, 100, 200, 300, 400, 500, 750, 1000, 1250, 1500, 1750, 2000, 2500, 3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 12000, 14000, 15000, 17500, 20000, 30000, 50000, 65000, 70000, 90000, 100000, 150000, 250000, 300000};
    
    double bestQuick = 1000, bestQuickInsert = 1000, bestInsert = 1000;
    
    double quick = 1000, quickInsert = 1000, insert = 1000, merge = 1000, best = 1000;          //other variables are set as test variables to be used
    
    int bestQuickN = 0, bestQuickInsertK = 0, bestQuickInsertN = 0, bestInsertN = 0,  bestQuickK = 0, bestInsertK = 0;
    
    N = arrayMax;       //the array is set to the max size
    fillArrayWithRandomNaturals();      //and then it is filled with values
    
    for(int i = 0; i < iMax; i++){     //a for loop that goes through the values in the arrays is called
        
        N = testN[i];               //the value of N is set based on the arrays
        
        copyArray();
        quick = runQuickSortTimed();                //the array is copied and then the function to call quicksort and time it is called
        
        copyArray();
        merge = runMergeSortTimed();              //the array is copied and then the function to call mergesort and time it is called
        
        copyArray();
        insert = runInsertionSortTimed();              //the array is copied and then the function to call insertion sort and time it is called
        
        for(int j = 0; j < jMax ; j++){    //a for loop that goes through the values in the arrays is called
            
            K = testK[j];               //the value of K is set based on the arrays
            
            if(N >= K)                      //if the value of K is not greater than N
            {
                copyArray();                            //the array is copied
                quickInsert = runQuickInsertionSortTimed();         //and quick insertion sort is called to sort the array
            }
            best = minOfFour(quickInsert, quick, merge, insert);            //the best time is the four sorts is determined
            
            if(quickInsert == best){        //if quick insert was the best then it is printed out to the user
                if(quickInsert < bestQuickInsert && quickInsert > 0){           //then if it is the best it has been so far
                    bestQuickInsert = quickInsert;                          //it is saved into the best time value and the N and K values
                    bestQuickInsertK = K;
                    bestQuickInsertN = N;
                    cout << "Current Best Quick Insertion Sort Time: " << bestQuickInsert << " with N = " << bestQuickInsertN << " and K = " << bestQuickInsertK << endl;               //then that time is printed out to the user as the current best time
                }
            }
            else if(insert == best){
                if(insert < bestInsert && insert > 0){      //then if it is the best it has been so far
                    bestInsert = insert;                 //it is saved into the best time value and the N value
                    bestInsertN = N;
                    bestInsertK = K;
                    cout << "Current Best Insertion Sort Time: " << bestInsert << " with N = " << bestInsertN  << " with K = " << bestInsertN << endl;         //then that time is printed out to the user as the current best time
                }
            }
            else if(quick == best){
                if(quick < bestQuick && quick > 0){     //then if it is the best it has been so far
                    bestQuick = quick;                      //it is saved into the best time value and the N value
                    bestQuickN = N;
                    bestQuickK = K;
                    cout << "Current Best Quick Sort Time: " << bestQuick << " with N = " << bestQuickN << " with K = " << bestQuickK << endl;         //then that time is printed out to the user as the current best time
                }
            }
        }
    }
    
    for(int i = 2; i < 200000; i = (i * 2)){            //then for a variety of different sizes of array
        
        N = i;                      //the value of N is set based on the loop

        copyArray();
        quick = runQuickSortTimed();                //the array is copied and then the function to call quicksort and time it is called
        
        copyArray();
        merge = runMergeSortTimed();              //the array is copied and then the function to call mergesort and time it is called
        
        copyArray();
        insert = runInsertionSortTimed();              //the array is copied and then the function to call insertion sort and time it is called
        
        for(int j = 1; j < 200; j = (j*2)){
            
            K = j;              //sets the K value based on the for loop
            
            if(N >= K)                      //if the value of K is not greater than N
            {
                copyArray();                            //the array is copied
                quickInsert = runQuickInsertionSortTimed();         //and quick insertion sort is called to sort the array
            }
            best = minOfFour(quickInsert, quick, merge, insert);            //the best time is the four sorts is determined
            
            if(quickInsert == best){        //if quick insert was the best then it is printed out to the user
                if(quickInsert < bestQuickInsert && quickInsert > 0){           //then if it is the best it has been so far
                    bestQuickInsert = quickInsert;                          //it is saved into the best time value and the N and K values
                    bestQuickInsertK = K;
                    bestQuickInsertN = N;
                    cout << "Current Best Quick Insertion Sort Time: " << bestQuickInsert << " with N = " << bestQuickInsertN << " and K = " << bestQuickInsertK << endl;               //then that time is printed out to the user as the current best time
                }
            }
            else if(insert == best){
                if(insert < bestInsert && insert > 0){      //then if it is the best it has been so far
                    bestInsert = insert;                 //it is saved into the best time value and the N value
                    bestInsertN = N;
                    bestInsertK = K;
                    cout << "Current Best Insertion Sort Time: " << bestInsert << " with N = " << bestInsertN  << " with K = " << bestInsertN << endl;         //then that time is printed out to the user as the current best time
                }
            }
            else if(quick == best){
                if(quick < bestQuick && quick > 0){     //then if it is the best it has been so far
                    bestQuick = quick;                      //it is saved into the best time value and the N value
                    bestQuickN = N;
                    bestQuickK = K;
                    cout << "Current Best Quick Sort Time: " << bestQuick << " with N = " << bestQuickN << " with K = " << bestQuickK << endl;         //then that time is printed out to the user as the current best time
                }
            }
        }
    }
    //the best values are printed out
    
    cout << "Best Quick Insertion Sort Time: " << bestQuickInsert << " with N = " << bestQuickInsertN << " and K = " << bestQuickInsertK << endl;
    cout << "Best Quick Sort Time: " << bestQuick << " with N = " << bestQuickN << " with K = " << bestQuickK << endl;
    cout << "Best Insertion Sort Time: " << bestInsert << " with N = " << bestInsertN <<  " with K = " << bestInsertK  <<endl;
    
    //then the best values found throughout the whole set of tests are printed out for the user to see
}

double Sorter::minOfFour(double a, double b, double c, double d){       //figures out which of the four doubles is the smallest and returns that value
    
    if(a < b && a < c && a < d)             //if a is smaller than all the others, then it is returned by the function as the min
        return a;
    else if(b < a && b < c && b < d)             //if b is smaller than all the others, then it is returned by the function as the min
        return b;
    else if(c < a && c < b && c < d)             //if c is smaller than all the others, then it is returned by the function as the min
        return c;
    else if(d < a && d < b && d < a)             //if d is smaller than all the others, then it is returned by the function as the min
        return d;
    else
        return 0;                           //if none of the values are smaller than all of the other values then zero is simply returned
}

int Sorter::medianThree(int left, int right){           //gets the median of three for picking the pivot
    
    if(right >= N)                             //sets the right value to the value at the end of the array
        right = N - 1;                          //if it is passed the end of the array it is set to the end of the array
    
    int center = ((right + left) / 2);          //the center is set based on being half way between the left and right
    
    if(array[center] < array[left])             //if the center value if smaller than the left value then they are swapped
        swap(left, center);
    if (array[right] < array[left])              //if the right value if smaller than the left value then they are swapped
        swap(left, right);
    if (array[right] < array[center])             //if the right value if smaller than the center value then they are swapped
        swap(center, right);
    
    return array[center];               //then with all of those three values in the right place, the center value is returned
}

Sorter::Sorter(){               // a constructor for the sorter class
    
    K = 0;
    N = 0;                      //sets the two main variables to 0 to start
    
    tp=(struct timeval *) calloc(1,sizeof(struct timeval));     //initializes the structure to be used be the timing function
    
    srand (time(NULL));                 //initializes the random number generator
}

void Sorter::swap(int index1, int index2){        //the swap function takes the index of two nodes in the heap and then switches the two values
    
    if(index1 > N || index2 > N || index1 < 0 || index2 < 0 )  //first it checks that the two values to be swapped are in bounds
        throw OutOfBounds();                    //throws and out of bounds error if they are not
    
    int temp = array[index1];                //it creates a temp to hold the first value
    array[index1] = array[index2];            //puts the second value in the first value
    array[index2] = temp;                    //then puts the first value in the second effictively swapping them

    return;
}

void Sorter::fillArrayWithRandomNaturals(){         //fills the array to save with random number up to N
    
    if(N <= 0){
        throw EmptySet();               //if the amount to fill, the value of N, not a positive number it throws an empty exception
    }
    
    for(int i = 0; i < N; i++){                 //goes through the array from zero to the Nth number and fills it
        arrayToSave[i] = randomNatural();           //filling each spot in the array by calling the function that gets random numbers
    }
    return;
}

void Sorter::printArray(){      //prints the array
    
    if(N <= 0){
        throw EmptySet();           //if the array is empty, N is set to a non positive number, then an empty set error is thrown
    }
    
    cout << array[0];                   //prints out the first element in the array
    
    for(int i = 1; i < N; i++){
        cout << ", " << array[i];           //then loops throught the rest of the array printing each element with a comma in between each, all the way to the Nth element
    }
    
    cout << endl;                       // prints out an end line at the end of printing all of the elements in the array
    return;
}

int Sorter::randomNatural(){            //gets a random number for the array
    
    return ((rand() % 100) + 1);        //returns a random number between 1 and 100, obviously this number can be adjusted
}


