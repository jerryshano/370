/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/intersection-4
 * Title: hw1_2
 * Abstract: This code will find intersection of ranges
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 9/5/19
 */

#include <iostream> 
using namespace std; 

int main() 
{ 
    bool check = true;
    int n;
    cin >> n;

    int** intervals = new int*[n];
    for(int i = 0; i < n; ++i)
    {
        intervals[i] = new int[2];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> intervals[i][j];
        }
    } 
    int l = intervals[0][0]; 
    int r = intervals[0][1]; 
  
    for (int i = 1; i < n; i++) 
    { 
        if (intervals[i][0] > r || intervals[i][1] < l) 
        { 
            check = false; 
        } 
        else 
        { 
            l = max(l, intervals[i][0]); 
            r = min(r, intervals[i][1]); 
        } 
    } 
    if(check == false)
    {
        cout << -1;
    }
    else
    {
        cout << l << " " << r;
    }
    
    for(int i = 0; i < 2; ++i) 
    {
        delete [] intervals[i];
    }
    delete [] intervals;
} 