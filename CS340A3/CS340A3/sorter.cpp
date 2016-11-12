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
#include "sorter.h"

void Sorter::insertionSort (){
    for(int i = 1; i < N ; i++){
        int temp = array[i];
        int j = i;
        while(( j > 0 ) && (temp < array[j - 1])){
            array[j] = array[j - 1];
            j--;
        }
        array[j] = temp;
    }
    return;
}

void Sorter::quickSort(int left, int right){

      int pivot = medianThree(left, right);
      int i = left;
      int j = (right - 1);
      while(1){
        while(array[++i] < pivot) {}
        while(pivot < array[--j]) {}
        if(i < j){
            swap(i, j);
        }
        else
            break;
      }
     swap(i, (right-1)); // Restore pivot
     quickSort(left, (i-1));      // Sort small elements
     quickSort(i+1, right);    // Sort large elements

    return;
}

void Sorter::quickInsertionSort (int left, int right){

    if (left + K <= right){
        int pivot = medianThree(left, right);
        int i = left;
        int j = (right - 1);
        while(1){
            while(array[++i] < pivot) {}
            while(pivot < array[--j]) {}
            if(i < j){
                swap(i, j);
            }
            else
                break;
        }
        swap(i, (right-1)); // Restore pivot
        quickSort(left, (i-1));      // Sort small elements
        quickSort(i+1, right);    // Sort large elements
    }
    
    else       // Do an insertion sort on the subarray
       //  insertionSort(left, right);
    
     return;
}

//void mergeSort(int array[], int left, int right){

/*
    if bottomLeft < topRight
// partition phase
bottomRight = (bottomLeft + topRight) / 2
MergeSort (a, b, bottomLeft, bottomRight)
topLeft = bottomRight + 1
MergeSort (a, b, topLeft, topRight)
// merge phase
i = bottomLeft
elementCount = topRight - bottomLeft + 1
while bottomLeft <= bottomRight and topLeft <= topRight
if a [bottomLeft] <= a [topLeft]
b [i] = a [bottomLeft]
bottomLeft ++
else
b [i] = a [topLeft]
topLeft ++
i ++
while bottomLeft <= bottomRight
b [i] = a [bottomLeft]
bottomLeft ++
i ++
while topLeft <= topRight
b [i] = a [topLeft]
topLeft ++
i ++
// result in a
i = 0
while i < elementCount
a [topRight] = b [topRight]
i ++
topRight --
*/
   // return;
 
//}


void Sorter::runInsertionSortTimed(){
    
    clock_t startTime = clock();

    insertionSort();
    
    for(int i = 0; i < 10000000; i++);
    
    clock_t endTime = clock();
    
    clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC;
    
    double dur = (double)duration * 1000;
    
    cout<<"Insertion Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::runMergeSortTimed(){
 
    clock_t startTime = clock();
    
    //mergeSort(array, 0, (N-1));
    
    clock_t endTime = clock();
    
    clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC * 1000;
    
    cout<<"Merge Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::runQuickSortTimed(){
    
    clock_t startTime = clock();
    
    quickSort(0, (N-1));
    
    clock_t endTime = clock();
    
    clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC * 1000;
    
    cout<<"Quick Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::runQuickInsertionSortTimed(){
    
    clock_t startTime = clock();
    
    quickInsertionSort(0, (N-1));
    
    clock_t endTime = clock();
    
    clock_t duration = double(endTime - startTime)/CLOCKS_PER_SEC * 1000;
    
    cout<<"Quick Insertion Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::promtUser(){
    
}

void Sorter::takeUserInput(){
    
}

void Sorter::copyArray(){
    
    for(int i = 0; i < N ; i++){
        arrayToSort[i] = array[i];
    }
}

void Sorter::runTimerTests(){
    
    fillArrayWithRandomNaturals();
    
    copyArray();
    
    printArray();
    runInsertionSortTimed();
    printArray();
    
    /*
    *arrayToBeSorted = *array;
    printArray(arrayToBeSorted);
    runMergeSortTimed(arrayToBeSorted);
    printArray(arrayToBeSorted);
    */
    
    copyArray();
    printArray();
    runQuickSortTimed();
    printArray();
    
    copyArray();
    printArray();
    runQuickInsertionSortTimed();
    printArray();
    
}


int Sorter::medianThree(int left, int right){
    
    /*
    int center = (left+right)/2;
    if (a[center] < a[left])
        swap(a[left], a[center]);
    if (a[right] < a[left])
        swap(a[left], a[right]);
    if (a[right] < a[center])
        swap(a[center], a[right]);
    swap(a[center], a[right − 1]); // Place pivot at position right - 1 10
    return a[right − 1];
     */
    return 1;
}

Sorter::Sorter(){
    
    K = 5;
    N = 200;
    
    srand (time(NULL));
}

void Sorter::swap(int index1, int index2){        //the swap function takes the index of two nodes in the heap and then switches the two values
    
    if(index1 > N || index2 > N)               //first it checks that the two values to be swapped are in bounds
        throw OutOfBounds();                    //throws and out of bounds error if they are not
    
    int temp = array[index1];                //it creates a temp to hold the first value
    array[index1] = array[index2];            //puts the second value in the first value
    array[index2] = temp;                    //then puts the first value in the second effictively swapping them
    
    return;
}

void Sorter::fillArrayWithRandomNaturals(){
 
    if(N <= 0){
        throw EmptySet();
    }
    
    for(int i = 0; i < N; i++){
        array[i] = randomNatural();
    }
    return;
}

void Sorter::printArray(){
    
    if(N <= 0){
        throw EmptySet();
    }
    
    cout << array[0];
    
    for(int i = 1; i < N; i++){
        cout << ", " << array[i];
    }
    
    cout << endl;
    
    return;
}

int Sorter::randomNatural(){
    
    return ((rand() % 100) + 1);
}


