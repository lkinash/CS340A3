//
//  sorter.cpp
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#include <stdio.h>
#include "sorter.h"

void Sorter::insertionSort (){
    for(int i = 1; i < (N - 1); i++){
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


//void Sorter::mergeSort (a, b, bottomLeft, topRight){
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


void Sorter::promtUser(){
    
}

void Sorter::takeUserInput(){
    
}

void Sorter::fillArray(){
    
}

void Sorter::timer(){
    
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

void Sorter::swap(int index1, int index2){        //the swap function takes the index of two nodes in the heap and then switches the two values
    
    if(index1 > N || index2 > N)               //first it checks that the two values to be swapped are in bounds
        throw OutOfBounds();                    //throws and out of bounds error if they are not
    
    int temp = array[index1];                //it creates a temp to hold the first value
    array[index1] = array[index2];            //puts the second value in the first value
    array[index2] = temp;                    //then puts the first value in the second effictively swapping them
    
    return;
}


