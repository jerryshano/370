/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/palindrome-check-10/submissions/code/1321496789
 * Title: palindrome
 * Abstract: checks if an input string is a palindrome or not
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 04MAR20
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool checkIfPalindrome(int startUP, int ending, vector<char> rope) {
  //  cout << rope[startUP] << " "<< rope[ending] << endl;
    if (startUP >= ending) return true;

    if (rope[startUP] != rope[ending]) return false;
    return checkIfPalindrome(++startUP, --ending, rope);
}
//www.geeksforseats.com
string removeSpaces(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);

    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '.'), str.end());
    str.erase(remove(str.begin(), str.end(), '!'), str.end());
    str.erase(remove(str.begin(), str.end(), '?'), str.end());

    return str;
}

int main() {

    string j;
    bool makeSure;

    getline(cin, j);

    j = removeSpaces(j);

    vector<char> char_array(j.begin(), j.end());
    makeSure = checkIfPalindrome(0, char_array.size()-1, char_array);

    if (makeSure){
        cout << "TRUE";
    }else{
        cout << "FALSE";
    }

    return 0;
}
