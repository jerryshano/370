/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/binary-numbs/submissions/code/1320804098
 * Title: h3_1
 * Abstract: reads a number of elements in a set
 * and then read the elements of the set
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 14FEB20
 */

#include <iostream>
#include <string>
using namespace std;

int main() {

    int readIn;
    cin >> readIn;

    string arr[readIn];
    int arrayNum[readIn];
    for (int i = 0; i < readIn; ++i) {
        cin >> arr[i];
        arrayNum[i] = 0;
    }

    for (int j = 0; j < readIn; ++j) {
        cout << arrayNum[j];
    }
    cout << "0:EMPTY" << endl;


    while (1){
        int carry=1;
        int column=0;
        for (int i = readIn-1; i >= 0; --i) {
            column = arrayNum[i] + carry;
            if (column==1){
                arrayNum[i] = 1;
                carry=0;
            } else {
                arrayNum[i] = 0;
                carry=1;
            }

        }
        if(carry>0){
            break;
        }
        for (int j = 0; j < readIn; ++j) {
            cout << arrayNum[j];
        }
        cout << ":";

        for (int k = 0; k < readIn; ++k) {
            if(arrayNum[k] == 1){
                cout << arr[k] << " ";
            }
        }
        cout << endl;
    }


    return 0;
}