/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/floyd-all-pairs-shortest-paths/submissions/code/1318386354
 * Title: hw12_2.cpp
 * Abstract: floyd algorithm
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 12/12/19
 */
#include <iostream>
#include<vector>
#include<climits>
using namespace std;

void f_algorithm(vector<vector<int> > arr)
{
    vector<vector<int> >f_arr(arr.size(),vector<int> (arr.size(),0));
    for(int i = 0; i < arr.size(); i++)
    {
        for(int j = 0; j < arr.size(); j++)
        {
            f_arr[i][j] = arr[i][j];
        }
    }
    for(int i = 0; i < f_arr.size(); i++)
    {
        for(int j = 0; j < f_arr.size(); j++)
        {
            for(int j = 0; j < f_arr.size(); j++)
            {
               if(f_arr[i][j] == INT_MAX || f_arr[j][i] == INT_MAX)
               {
                   continue;
               }
                if(f_arr[j][j] > f_arr[j][i]+f_arr[i][j])
                {
                    f_arr[j][j] = f_arr[j][i] + f_arr[i][j];
                }
            }
        }
    }
    for(int i = 0; i < f_arr.size(); i++ ) 
    {
        for (int j = 0; j < f_arr.size(); j++) 
        {
            if(f_arr[i][j]== INT_MAX)
            {
                cout << -1 << " ";
            }
            else
            {
                cout << f_arr[i][j] << " ";
            }   
        }
        cout << endl;
    }   
}
int main() {

    int n;
    cin >> n;
    vector<vector<int> > arr( n , vector<int> (n,0));
    for(int i = 0; i< n; i++ ) 
    {
        for (int j = 0; j< n; j++) 
        {
            cin >> arr[i][j];
            if(arr[i][j] == -1)
            {
                arr[i][j] = INT_MAX;
            }
        }
    }
    f_algorithm(arr);
}