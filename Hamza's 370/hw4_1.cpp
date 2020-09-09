/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/buy-two-one-free/submissions/code/1316541857
 * Title: hw4_1.cpp
 * Abstract: Buy one get one free program
 * Author: Hamza Saleem 
 * ID: 6969
 * Date: 9/25/19
 */
#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int array_num;
    cin >> array_num;

    int arr[array_num];
    for(int i = 0; i < array_num; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + array_num);
    /*for(int i = 0; i < array_num; i++)
    {
        cout << arr[i] << " ";
    }*/
    int sum = 0;
    int count = array_num;
    for(int i = 0; i < array_num; i++)
    {
        if(count % 2 == 0) array_num--;
        count++;
        sum += arr[i];
        
        
    }
    cout << sum;
}