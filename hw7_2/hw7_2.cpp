/*
 * website links: https://www.geeksforgeeks.org/merge-sort/
 * https://www.geeksforgeeks.org/insertion-sort/
 * https://www.geeksforgeeks.org/quick-sort/
 * Title: time performance
 * Abstract: displays the performance of three different sorting algorithms
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 27MAR20
 */

#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;

// A utility function to swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element
    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
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
    int n2 = r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

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

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

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
    cout << "Enter input size: ";
    int inputSize;
    cin >> inputSize;

    cout << "========== Select Order of Input Numbers ==========" << endl;
    cout << "1. Ascending Order" << endl;
    cout << "2. Descending Order" << endl;
    cout << "3. Random Order" << endl;
    int chooseOrder;
    cout << "Choose order: ";
    cin >> chooseOrder;
    cout << "============================================================" << endl;
    cout << endl;

    double totalQuick=0,totalMerge=0,totalInsertion=0;

    if (chooseOrder == 1) {
        cout << "Generate input data in Ascending order . . ." << endl;
        cout << "Done." << endl;
        cout << "============================================================" << endl;
        cout << endl;
    }
    else if (chooseOrder == 2) {
        cout << "Generate input data in Descending order . . ." << endl;
        cout << "Done." << endl;
        cout << "============================================================" << endl;
        cout << endl;
    }
    else if (chooseOrder == 3) {
        cout << "Generate input data in Random order . . ." << endl;
        cout << "Done." << endl;
        cout << "============================================================" << endl;
        cout << endl;
    }

    for (int j = 0; j < 3; ++j) {

        if (j == 0) {
            cout << "========================== 1st Run ========================="<<endl;
        } else if (j == 1) {
            cout << "========================== 2nd Run ========================="<<endl;
        } else {
            cout << "========================== 3rd Run ========================="<<endl;
        }

        for (int k = 0; k < 3; ++k) {

            int *foo;
            foo = new int[inputSize];
            if (chooseOrder == 1) {
                for (int i = 0; i < inputSize; ++i) {
                    foo[i] = i;
                }
            }
            else if (chooseOrder == 2) {
                int temp = inputSize;
                for (int i = 0; i < inputSize; ++i) {
                    foo[i] = --temp;
                }
            }

            else if (chooseOrder == 3) {
                for (int i = 0; i < inputSize; ++i) {
                    foo[i] = (rand()%inputSize)+1;
                }
            }
            if (k == 0) {
                auto start = std::chrono::high_resolution_clock::now();
                insertionSort(foo, inputSize);
                auto stop = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duration = (stop - start);
                cout <<"Insertion sort: ";
                cout <<fixed<< duration.count() <<setprecision(6);
                cout<<" milliseconds"<<endl;
                totalInsertion+=duration.count();
            }
            else if (k == 1) {
                auto start = std::chrono::high_resolution_clock::now();
                mergeSort(foo, 0, inputSize-1);
                auto stop = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duration = (stop - start);
                cout <<"Merge sort:     ";
                cout<<fixed << duration.count() << setprecision(6);
                cout<<" milliseconds"<<endl;
                totalMerge+=duration.count();
            }
            else if(k == 2){
                auto start = std::chrono::high_resolution_clock::now();
                quickSort(foo, 0, inputSize-1);
                auto stop = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double, std::milli> duration = (stop - start);
                cout <<"Quick sort:     ";
                cout << fixed << duration.count() << setprecision(6);
                cout<<" milliseconds"<<endl;
                totalQuick+=duration.count();
            }
        }

        if (j == 0) {
            cout << "============================================================"<<endl;
            cout << endl;
        } else if (j == 1) {
            cout << "============================================================"<<endl;
            cout << endl;
        } else {
            cout << "============================================================"<<endl;
            cout << endl;
        }
    }

    cout<<"========================== Ranking ========================="<<endl;
    cout<<"insert "<<totalInsertion<<endl;
    cout<<"merge "<<totalMerge<<endl;
    cout<<"quick "<<totalQuick<<endl;
    if(totalInsertion<totalMerge && totalInsertion<totalQuick){
        cout<<"(1) Insertion sort"<<endl;
        if(totalQuick<totalMerge){
            cout << "(2) Quick sort"<<endl;
        }
        if (totalMerge<totalQuick){
            cout<<"(2) Merge sort"<<endl;
        }
        if (totalQuick>totalMerge){
            cout <<"(3) Quick sort"<<endl;
        }
    }
    else if (totalMerge<totalInsertion && totalMerge<totalQuick){
        cout<<"(1) Merge Sort"<<endl;
        if(totalInsertion<totalQuick){
            cout<<"(2) Insertion sort"<<endl;
        }
        if(totalQuick>totalMerge&& totalQuick>totalInsertion){
            cout<<"(3) Quick sort"<<endl;
        }
    }
    else if (totalQuick<totalMerge && totalQuick<totalInsertion){
        cout<<"(1) Quick sort"<<endl;
        if (totalMerge<totalInsertion){
            cout<<"(2) Merge sort"<<endl;
        }
        if(totalInsertion<totalMerge){
            cout<<"(2) Insertion sort"<<endl;
        }
        if(totalMerge>totalInsertion && totalMerge>totalQuick){
            cout<<"(3) Merge sort"<<endl;
        }
        if (totalInsertion>totalMerge && totalInsertion>totalQuick){
            cout<<"(3) Insertion sort"<<endl;
        }
    }
    cout<<"============================================================"<<endl;
    return 0;
}
