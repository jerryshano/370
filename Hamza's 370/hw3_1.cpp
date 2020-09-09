/*
 * HackerRank link:  https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/palindrome-check-10/submissions/code/1316288475
 * Title: hw3_1.cpp
 * Abstract: Palindrome check disregarding cases and stuff other than alphanumeric.
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 9/15/19
 */

#include <iostream>
#include <string>

using namespace std;

int main(){

    string input, org;
    getline(cin, input);

    int length = input.length();
    
    for(int i = 0; i < length; i++)
    {
        if((input[i] > 63 && input[i] < 91) || (input[i] > 96 && input[i] < 123) || (input[i] > 47 && input[i] < 58) || input[i] == 0177 || input[i] == 0153 || input[i] == 0163)
        {
            org += input[i];
        }
        else continue;
    }

    //lowercase conversion
    for(int i = 0; i < org.length(); i++)
    {
        if(org[i] > 64 && org[i] < 91)
        {
            org[i] = org[i]+32;
        }
    }

    length = org.length();
    bool check = false;
    for(int i = 0; i < length/2; i++)
    {
        if(org[i] != org[length-i-1])
        {
            check = true;
            break;
        }
    }
    if(check == true)
    {
        cout << "FALSE" << endl;
    }
    else
    {
        cout << "TRUE" << endl;
    }
    
    
    return 0;
}