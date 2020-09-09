/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw12/challenges/knapsack-7-1/submissions/code/1318384945
 * Title: hw12_1.cpp
 * Abstract: Knapsack problem o count best pair
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 12/12/19
 */
#include <iostream>
#include<vector>
using namespace std;

void ks(int val [], int weight [], int n, int cap, vector<vector<int> >&arr)
{
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= cap; j++)
        {
            arr[i][j] = arr[i -1][j];
            if((arr[i][j] < arr[i-1][j - val[i -1]]+ weight[i -1]) && (j >= val[i-1]))
            {
                arr[i][j] =  arr[i-1][j - val[i -1]]+ weight[i -1];
            }  
        }
    }
    cout << "Final step:";
    for(int i = 0; i < arr[0].size(); i++)
    {
        cout<<arr[arr.size()-1][i]<<" ";
    }
    cout << endl;
    cout << "Max value:" << arr[n][cap] << endl;
    vector<int>index;
    cout << "Items:";

    for(int i = arr.size()-1; i > 0; i--)
    {
        if(arr[i][cap] != arr[i-1][cap])
        {
            index.push_back(i);
        
            cap = cap - val[i-1];
        }
    }
    for(int i = index.size()-1; i>= 0; i--)
    {
        cout << index[i] << " ";
    }
}
int main() 
{
    int n, cap;
    cin >> n;
    int wei[n];
    int val[n];
    cin >> cap;
    for(int i = 0; i < n; i++)
    {
        cin >> val[i] >> wei[i];
    } 
    vector<vector<int> >arr(n+1, vector<int> (cap + 1,0));
    ks(val, wei, n, cap, arr);
  
  return 0;
}