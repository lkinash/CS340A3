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

class EmptySet{};

class Sorter{
    public:
    
    Sorter();
    
    void insertionSort(int start, int end);
    void quickSort(int left, int right);
    void quickInsertionSort(int left, int right);
    void mergeSort(int left, int right);
    
    void runInsertionSortTimed();
    void runMergeSortTimed();
    void runQuickSortTimed();
    void runQuickInsertionSortTimed();
    
    void promtUser();
    void takeUserInput();
    
    void copyArray();
    void printArray();
    void runTimerTests();
    
    int medianThree(int left, int right);
    
    void swap(int index1, int index2);
    
    void fillArrayWithRandomNaturals();
    int randomNatural();
    
    private:
    const static int arrayMax = 690000;
    int K, N;
    int array[arrayMax];
    int arrayToSave[arrayMax];
    int mergeB[arrayMax];
    
    
};


#endif /* sorter_h */
