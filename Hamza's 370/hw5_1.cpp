/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/recursive-exponents/submissions/code/1316867717
 * Title: hw5_1.cpp
 * Abstract: Power calculator using recurssion  
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 10/10/19
 */

#include <iostream>

using namespace std;

int calculatePower(int base, int power)
{
    if (power != 0)
        return (base*calculatePower(base, power-1));
    else
        return 1;
}

int main()
{
    int base = 2, power, result;
    cin >> power;
    result = calculatePower(base, power);
    cout << result;
    return 0;
}
