/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/binary-numbs/submissions/code/1316201358
 * Title: hw2_1.cpp
 * Abstract: Number to Binary conversion with range
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 9/12/19
 */

#include<bits/stdc++.h> 
using namespace std; 
  
void bin(int n) 
{ 
    if (n > 1)
    {
        bin(n/2);
    }  
    cout << n % 2; 
} 
  
int main() 
{ 
    int input;
    cin >> input;
    if(input > 3)
    {
        for (int i = 0; i <= input; i++)
        {
            if(i < 2)
            {
                cout << 00;
            }
            if(i < 4)
            {
                cout << 0;
            }
            bin(i);
            cout << endl;
        }
    }
    else if (input < 4 && input > 1)
    {
        for (int i = 0; i <= input; i++)
        {
            if(i < 2)
            {
                cout << 0;
            }
            bin(i);
            cout << endl;
        }
    }
    else
    {
        for (int i = 0; i <= input; i++)
        {
            bin(i);
            cout << endl;
        }
    }
} 