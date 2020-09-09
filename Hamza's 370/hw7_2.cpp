/*
 * Source: https://www.geeksforgeeks.org/merge-sort/
 * Title: hw7_2.cpp
 * Abstract: find time complexity of different sorting algorithms
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 10/24/2019
 */

#include <bits/stdc++.h> 
#include <chrono> 

using namespace std;

void swap(int* a, int* b)  
{  
    int t = *a;  
    *a = *b;  
    *b = t;  
}  

int partition (int arr[], int low, int high)  
{  
    int pivot = arr[high]; 
    int i = (low - 1); 
  
    for (int j = low; j <= high - 1; j++)  
    {   
        if (arr[j] < pivot)  
        {  
            i++;
            swap(&arr[i], &arr[j]);  
        }  
    }  
    swap(&arr[i + 1], &arr[high]);  
    return (i + 1);  
}  

void quickSort(int arr[], int low, int high)  
{  
    if (low < high)  
    {  
        int pi = partition(arr, low, high);  
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);  
    }  
}

void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }   
} 

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r);
    } 
}

int main() {

    int size;
    int *arr;
    arr = new int[size];
    cout << "Enter input size: ";
    cin >> size;

    cout << "========== Select Order of Input Numbers ==========" << endl;
    cout << "1. Ascending Order" << endl;
    cout << "2. Descending Order" << endl;
    cout << "3. Random Order" << endl;
    cout << "Choose order: ";
    int order;
    cin >> order;  

    int Rand_Num;                    
    cout << "============================================================" << endl;
    if(order == 1)
    {
        cout << "Generate input data in ascending order . . ." << endl;
        for(int i = 0; i < size; i++)
         {
            Rand_Num = (rand() % size*2) + 1;
            arr[i] = Rand_Num;
         }
    }
    if(order == 2)
    {
        cout << "Generate input data in descending order . . ." << endl;
        for(int i = 0; i < size; i++)
         {
            Rand_Num = (rand() % size*2) + 1;
            arr[i] = Rand_Num;
         }
    } 
    if(order == 3)
    {
        cout << "Generate input data in random order . . ." << endl;
         
         for(int i = 0; i < size; i++)
         {
            Rand_Num = (rand() % size*2) + 1;
            arr[i] = Rand_Num;
         }
    }
    cout << "Done." << endl;
    cout << "============================================================" << endl;
    cout << endl;
    cout << "============================================================" << endl;
 
    clock_t t; 

    t = clock();
    insertionSort(arr, size);
    t = clock() - t; 
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << "Insertion sort:   " << time_taken/1000 << " milliseconds" << endl;

    t = clock();
    mergeSort(arr, 0, size-1);
    t = clock() - t; 
    double time_takenm = ((double)t)/CLOCKS_PER_SEC;
    cout << "Merge sort:   " << time_takenm/1000 << " milliseconds" << endl;

    t = clock();
    quickSort(arr, 0, size-1);
    t = clock() - t; 
    double time_takenq = ((double)t)/CLOCKS_PER_SEC;
    cout << "Quick sort:   " << time_takenq/1000 << " milliseconds" << endl;

    cout << "============================================================" << endl;

    delete[] arr;
    return 0;
}