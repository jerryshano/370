/*
 * hackerrank link: https://www.hackerrank.com/contests/cst370-f19-hw0/challenges/370-hw0-1/problem
 * Title: hw0_1
 * Abstract: This program will sum 2 numbers and then give difference of 2 numbers.
 * Name: Hamza Saleem
 * ID: 6969
 * Date: 8/28/19
 */
#include <iostream>
using namespace std;

int main() {
    int num1, num2, key = 0;

    

    while(key < 3)
    {
        cin >> key;
        if (key == 1)
        {
            cin >> num1 >> num2;
            cout << num1+num2 << endl;
            continue;
        }
        else if (key == 2)
        {
            cin >> num1 >> num2;
            if(num1 < 0 || num2 < 0)
            {
                cout << -1*(num2-num1) << endl;
                continue;
            }
            cout << num2-num1 << endl;
            continue;
        }
        else break;
    }
}