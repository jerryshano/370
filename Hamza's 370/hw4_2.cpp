/*
 * HackerRank link:  https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/matching-form/submissions/code/1316568343  
 * Title: hw4_2
 * Abstract: Wellformed string check
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 9/26/19
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
 
    string x;
    cin >> x;

    int check = 0;
    for(int i = 0; i < x.length(); i++)
    {
        if(x[i] == '{' || x[i] == '('|| x[i] == '[')
        {
            check++;
        }
        if(x[i] == '}' || x[i] == ')'|| x[i] == ']')
        {
            check--;
        }  
    }
    if(check == 0)
    {
        cout << "TRUE" << endl;
    }
    else
    {
        cout << "FALSE" << endl;
    }
}