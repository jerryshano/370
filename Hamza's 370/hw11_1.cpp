/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-row/submissions/code/1318193013
 * Title: hw11_1.cpp
 * Abstract: Coin row problem solving with easy implementation
 * Author: Hamza Saleem  
 * ID: 6969
 * Date: 12/5/19
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int num;
    cin >> num;
    num +=2;
    int coins[num];
    coins[0] = 0;
    coins[num-1] = 0;

    for(int i = 1; i < num-1; i++)
    {
        cin >> coins[i];
    }

    if(num-2 == 1)
    {
        cout << "Best set:1" << endl;
        cout<< "Max value:" << coins[1];
    }
    else
    {
    int max = 0, sum = 0, size = 0, index = 0;
    int best_set[12] = {0};

    for(int i = 1; i <= (num-1)/2; i++)
    {
        max = 0;
        for(int j = 1; j < num-1; j++)
        {
            if(max < coins[j])
            {
                max = coins[j];
                index = j; 
            }
        }
        sum += coins[index];
        coins[index] = 0;
        coins[index+1] = 0;
        coins[index-1] = 0;
        best_set[size] = index;
        size++;
    }

    cout << "Best set:";
    sort(best_set, best_set+size);
    for(int i = 0; i < size; i++)
    {
        cout << best_set[i] << " ";
    }

    cout << endl;
    cout << "Max value:" << sum << endl;
    }
}