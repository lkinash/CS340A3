//
//  sorter.h
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//

#ifndef sorter_h
#define sorter_h

using namespace std;

class OutOfBounds{};

class Sorter{
    public:
    
    Sorter();
    
    void insertionSort();
    void mergeSort();
    void quickSort(int left, int right);
    void quickInsertionSort(int left, int right);
    
    void promtUser();
    void takeUserInput();
    
    void fillArray();
    
    void timer();
    
    int medianThree(int left, int right);
    
    void swap(int index1, int index2);
    
    private:
    int arraySize, K, N;
    int array[];
    
};


#endif /* sorter_h */
