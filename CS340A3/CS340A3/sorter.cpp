//
//  sorter.cpp
//  CS340A3
//
//  Created by Lindsey Kinash on 2016-11-06.
//  Copyright © 2016 Lindsey. All rights reserved.
//


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

double Sorter::runInsertionSortTimed(){
    
    double startTime = myTime();

    insertionSort(0, N);
    
    double endTime = myTime();
    
    double duration = double((endTime - startTime))/CLOCKS_PER_SEC * 1000;
    
    return duration;
    
}

double Sorter::runMergeSortTimed(){
 
    double startTime = myTime();
    
    mergeSort(0, N-1);
    
    double endTime = myTime();
    
    double duration = double(endTime - startTime)/1000;
    
    return duration;
    
}

double Sorter::runQuickSortTimed(){
    
    double startTime = myTime();
    
    quickSort(0, N);
    
    double endTime = myTime();
    
    double duration = double(endTime - startTime)/ 1000;
    
    return duration;
    
}

double Sorter::runQuickInsertionSortTimed(){
    
    double startTime = myTime();
    
    quickInsertionSort(0, N);
    
    double endTime = myTime();
    
    double duration = double(endTime - startTime)/ 1000;
    
    return duration;
    
}

double Sorter::myTime(){
    gettimeofday(tp,tzp);
    return (( (double)  tp->tv_sec) * CLOCKS_PER_SEC )+ ( (double) tp->tv_usec );
}

void Sorter::promptUser(){
 
    int input;
    string extra;
    
    cout << "This program sorts arrays of randomly generated numbers using Quick Insertion Sort, Quick Sort, Merge Sort and Insertion Sort and times each sorting algorithm. The size of the array to be sorted is based on user input. " << endl;
    
    cout << "N is the number of random naturals to sorted. The maximum value for N in this system is 690000. Please enter a value for N: ";
    
    cin >> input;
    
    getline(cin, extra);
    
    while(1){
        if(input < 1 ){
            cout << "A value less than 1 is not valid for N, please enter a valid (between 1 and 690000) N value:";
        
            cin >> input;
            getline(cin, extra);
        }
        else if(input > 690000){
            cout << "A value greater than 690000 is not valid for N, this will cause an array that is too big and could cause overflow or other access errors. Please enter a valid (between 1 and 690000) N value:";
            
            cin >> input;
            getline(cin, extra);
        }
        else
            break;
    }
    
    N = input;
    
    
    cout << "K is the number used by quick insertion sort. The maximum value for K in this system is also 690000. Please enter a value for K: ";
    
    cin >> input;
    
    getline(cin, extra);
    
    while(1){
        if(input < 0 ){
            cout << "A value less than 0 is not valid for K, please enter a valid (between 1 and 690000) K value:";
            
            cin >> input;
            getline(cin, extra);
        }
        else if(input > N){
            cout << "A value greater than the N value entered is not valid for K, please enter a valid (between 1 and 690000 and less than N) K value:";
            
            cin >> input;
            getline(cin, extra);
        }
        else if(input > 690000){
            cout << "A value greater than 690000 is not valid for K, this will cause an array that is too big and could cause overflow or other access errors. Please enter a valid (between 1 and 690000) K value:";
            
            cin >> input;
            getline(cin, extra);
        }
        else
            break;
    }
    
    K = input;
    
    
}

void Sorter::copyArray(){
    
    for(int i = 0; i < N ; i++){
        array[i] = arrayToSave[i];
    }
}

void Sorter::runTimerTests(){
    
    double duration;
    
    promptUser();
    
    fillArrayWithRandomNaturals();
    copyArray();
    //printArray();
    
    duration = runQuickInsertionSortTimed();
    cout<<"Quick Insertion Sort Time: "<< duration << " ms" << endl;
    //printArray();
    
    copyArray();
    duration = runQuickSortTimed();
    cout<<"Quick Sort Time: "<< duration << " ms" << endl;
    //printArray();
    
    copyArray();
    duration = runMergeSortTimed();
    cout<<"Merge Sort Time: "<< duration << " ms" << endl;
    //printArray();
    
    copyArray();
    duration = runInsertionSortTimed();
    cout<<"Insertion Sort Time: "<< duration << " ms" << endl;
    //printArray();
    
}

void Sorter::findBestSorter(){
    
    int jMax = 8, iMax = 40;
    
    int testK[] = {1, 5, 10, 15, 20, 25, 50, 100};
    int testN[] = {2, 5, 10, 15, 20, 25, 50, 75, 100, 200,
                    300, 400, 500, 750, 1000, 1250, 1500, 1750, 2000, 2500,
                    3000, 4000, 5000, 6000, 7000, 8000, 9000, 10000, 12000, 14000,
                    15000, 17500, 20000, 30000, 50000, 65000, 70000, 90000,
                    100000, 150000, 250000, 300000};

    double bestQuick = 1000, bestQuickInsert = 1000, bestInsert = 1000;
    
    double quick = 1000, quickInsert = 1000, insert = 1000, merge = 1000, best = 1000;
    
    int bestQuickK = 0, bestQuickN = 0, bestQuickInsertK = 0, bestQuickInsertN = 0, bestInsertK = 0, bestInsertN = 0;
    
    N = arrayMax;
    
    
    for(int i = 0; i < iMax; i++){
        
        N = testN[i];
        
        fillArrayWithRandomNaturals();
        
        
        cout << "N: " << N << endl;
        
        copyArray();
        quick = runQuickSortTimed();
        
        copyArray();
        merge = runMergeSortTimed();
        
        copyArray();
        insert = runInsertionSortTimed();

        
        for(int j = 0; j < jMax; j++){

            K = testK[j];

            if(N >= K)
            {
                copyArray();
                quickInsert = runQuickInsertionSortTimed();

                best = minOfFour(quickInsert, quick, merge, insert);
                
                if(quickInsert == best && quickInsert < bestQuickInsert && quickInsert > 0){
                    bestQuickInsert = quickInsert;
                    bestQuickInsertK = K;
                    bestQuickInsertN = N;
                    cout << "Current Best Quick Insertion Sort Time: " << bestQuickInsert << " with N = " << bestQuickInsertN << " and K = " << bestQuickInsertK << endl;
                }
                else if(insert == best && insert < bestInsert && insert > 0){
                    bestInsert = insert;
                    bestInsertN = N;
                    cout << "Current Best Insertion Sort Time: " << bestInsert << " with N = " << bestInsertN << endl;
                }
                else if(quick == best && quick < bestQuick && quick > 0){
                    bestQuick = quick;
                    bestQuickN = N;
                    cout << "Current Best Quick Sort Time: " << bestQuick << " with N = " << bestQuickN << endl;
                }
            }
        }
    }
    
    for(int i = 2; i < 500000; i = (i * 2)){
        
        N = i;
        
        cout << "N: " << N << endl;
        
        fillArrayWithRandomNaturals();
        
        copyArray();
        quick = runQuickSortTimed();
        
        copyArray();
        merge = runMergeSortTimed();
        
        copyArray();
        insert = runInsertionSortTimed();
        
        
        for(int j = 1; j < 200; j = (j*2)){
            
            K = j;
            
            if(N >= K)
            {
                copyArray();
                quickInsert = runQuickInsertionSortTimed();
                
                best = minOfFour(quickInsert, quick, merge, insert);
                
                if(quickInsert == best && quickInsert < bestQuickInsert && quickInsert > 0){
                    bestQuickInsert = quickInsert;
                    bestQuickInsertK = K;
                    bestQuickInsertN = N;
                    cout << "Current Best Quick Insertion Sort Time: " << bestQuickInsert << " with N = " << bestQuickInsertN << " and K = " << bestQuickInsertK << endl;
                }
                else if(insert == best && insert < bestInsert && insert > 0){
                    bestInsert = insert;
                    bestInsertN = N;
                    cout << "Current Best Insertion Sort Time: " << bestInsert << " with N = " << bestInsertN << endl;
                }
                else if(quick == best && quick < bestQuick && quick > 0){
                    bestQuick = quick;
                    bestQuickN = N;
                    cout << "Current Best Quick Sort Time: " << bestQuick << " with N = " << bestQuickN << endl;
                }
            }
        }
        
       
    }
    
    cout << "Best Quick Insertion Sort Time: " << bestQuickInsert << " with N = " << bestQuickInsertN << " and K = " << bestQuickInsertK << endl;
    cout << "Best Quick Sort Time: " << bestQuick << " with N = " << bestQuickN << endl;
    cout << "Best Insertion Sort Time: " << bestInsert << " with N = " << bestInsertN << endl;
    
    
}

double Sorter::minOfFour(double a, double b, double c, double d){
    
    if(a < b && a < c && a < d)
        return a;
    else if(b < a && b < c && b < d)
        return b;
    else if(c < a && c < b && c < d)
        return c;
    else if(d < a && d < b && d < a)
        return d;
    else
        return 0;
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
    
    K = 10;
    N = 500;
    
    tp=(struct timeval *) calloc(1,sizeof(struct timeval));
    
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


