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

void Sorter::insertionSort(int start, int end){
    for(int i = start; i < end ; i++){
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
    int j = right;
    for(;;){
        while(array[++i] < pivot) {}
        while(pivot < array[--j]) {}
        if(i <= j){
            swap(i, j);
        }
        else
            break;
    }
    
    if (left < j)
        quickSort(left, j);   // Sort small elements
    if (i < right)
        quickSort(i, right);    // Sort large elements

    return;
}

void Sorter::quickInsertionSort (int left, int right){

    if (left + K <= right){
        int pivot = medianThree(left, right);
  
        int i = left;
        int j = right;
        for(;;){
            while(array[++i] < pivot) {}
            while(pivot < array[--j]) {}
            if(i <= j){
                swap(i, j);
            }
            else
                break;
        }
        
        if (left < j)
            quickSort(left, j);   // Sort small elements
        if (i < right)
            quickSort(i, right);    // Sort large elements
    }
    
    else
       insertionSort(left, right);
    
     return;
}


void Sorter::mergeSort(int left, int right){

    int bottomLeft = left;
    int topRight = right;
    
    if (bottomLeft < topRight){

        int bottomRight = ((bottomLeft + topRight) / 2);
        mergeSort(bottomLeft, bottomRight);
        
        int topLeft = (bottomRight + 1);
        mergeSort(topLeft, topRight);

        
        int i = bottomLeft;
        int count = topRight - bottomLeft + 1;
        
        while(bottomLeft <= bottomRight && topLeft <= topRight){
            if(array[bottomLeft] <= array[topLeft]){
                mergeB [i] = array[bottomLeft];
                bottomLeft ++;
            }
            else{
                mergeB [i] = array[topLeft];
                topLeft ++;
            }
            i ++;
        }
        while(bottomLeft <= bottomRight){
            mergeB[i] = array[bottomLeft];
            bottomLeft++;
            i++;
        }
        while(topLeft <= topRight){
            mergeB[i] = array[topLeft];
            topLeft++;
            i++;
        }

        i = 0;
        while(i < count){
            array[topRight] = mergeB[topRight];
            i++;
            topRight--;
        }
    }
    return;
 
}

void Sorter::runInsertionSortTimed(){
    
    clock_t startTime = clock();

    insertionSort(0, N);
    
    clock_t endTime = clock();
    
    double duration = double((endTime - startTime))/CLOCKS_PER_SEC * 1000;
    
    cout<<"Insertion Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::runMergeSortTimed(){
 
    clock_t startTime = clock();
    
    mergeSort(0, N-1);
    
    clock_t endTime = clock();
    
    double duration = double(endTime - startTime)/CLOCKS_PER_SEC * 1000;
    
    cout<<"Merge Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::runQuickSortTimed(){
    
    clock_t startTime = clock();
    
    quickSort(0, N);
    
    clock_t endTime = clock();
    
    double duration = double(endTime - startTime)/CLOCKS_PER_SEC * 1000;
    
    cout<<"Quick Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::runQuickInsertionSortTimed(){
    
    clock_t startTime = clock();
    
    quickInsertionSort(0, N);
    
    clock_t endTime = clock();
    
    double duration = double(endTime - startTime)/CLOCKS_PER_SEC * 1000;
    
    cout<<"Quick Insertion Sort Time: "<< duration << " ms" << endl;
    
}

void Sorter::promtUser(){
    
}

void Sorter::takeUserInput(){
    
}

void Sorter::copyArray(){
    
    for(int i = 0; i < N ; i++){
        array[i] = arrayToSave[i];
    }
}

void Sorter::runTimerTests(){
    
    fillArrayWithRandomNaturals();
    copyArray();
    printArray();
    
    runInsertionSortTimed();
    //printArray();
    
    copyArray();
    runMergeSortTimed();
    //printArray();
    
    copyArray();
    runQuickSortTimed();
    //printArray();
    
    copyArray();
    runQuickInsertionSortTimed();
    //printArray();
    
}


int Sorter::medianThree(int left, int right){
    
    if( right >= N)
        right = N - 1;
    
    int center = ((right + left) / 2);
    
    if(array[center] < array[left])
        swap(left, center);
    if (array[right] < array[left])
        swap(left, right);
    if (array[right] < array[center])
        swap(center, right);

    return array[center];
}

Sorter::Sorter(){
    
    K = 15;
    N = 100000;
    
    srand (time(NULL));
}

void Sorter::swap(int index1, int index2){        //the swap function takes the index of two nodes in the heap and then switches the two values
    
    //cout << "swap: " << index1 <<  ", " << index2 << endl;
    //cout << "swap numbers: " << array[index1] << " and " << array[index2] << endl;
    
    if(index1 > N || index2 > N || index1 < 0 || index2 < 0 )  //first it checks that the two values to be swapped are in bounds
        throw OutOfBounds();                    //throws and out of bounds error if they are not
    
    int temp = array[index1];                //it creates a temp to hold the first value
    array[index1] = array[index2];            //puts the second value in the first value
    array[index2] = temp;                    //then puts the first value in the second effictively swapping them
    
    //cout << "swapped: " << array[index1] << " and " << array[index2] << endl;
    
    return;
}

void Sorter::fillArrayWithRandomNaturals(){
 
    if(N <= 0){
        throw EmptySet();
    }
    
    for(int i = 0; i < N; i++){
        arrayToSave[i] = randomNatural();
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


