/*
 * Source: https://www.geeksforgeeks.org/find-a-peak-in-a-given-array/
 * Title: hw7_1.cpp
 * Abstract: Finding index of maximum value using divide and conquer
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 10/24/2019
 */

#include <bits/stdc++.h> 
using namespace std;  
   
int findPeakUtil(int *arr, int low, int high, int n)  
{   
    int mid = low + (high - low)/2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&  
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))  
        return mid;  

    else if (mid > 0 && arr[mid - 1] > arr[mid])  
        return findPeakUtil(arr, low, (mid - 1), n);  

    else return findPeakUtil(arr, (mid + 1), high, n);  
}  

int findPeak(int arr[], int n)  
{  
    return findPeakUtil(arr, 0, n - 1, n);  
}  
  
// Driver Code 
int main()  
{  
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];

    for(int i = 0; i < n; i++)
    cin >> arr[i];
  
    cout << "Max index: " 
         << findPeak(arr, n); 

    delete []arr; 
    return 0;  
}  