/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/divide-and-conquer-max/submissions/code/1321702698
 * Title: maxVal
 * Abstract: displays the biggest number
 * in an array with n integer numbers using a
 * divide-and-conquer technique
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 11MAR20
 */

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int divideAndConkahh(vector<int> array, int index, int n)
{
    int maxval1, maxval2, returnval;
    if ( n==1 ) return array[index];
    maxval1 = divideAndConkahh(array, index, n/2);
    maxval2 = divideAndConkahh(array, index+(n/2), n-(n/2));
    //cout << maxval1 << " "<< maxval2 << endl;
    if (maxval1 > maxval2) {
        returnval = maxval1;
    }
    else if (maxval1<maxval2){
        returnval = maxval2;
    }
    else if(maxval1 == maxval2){
        //cout << maxval2 << endl;
        returnval = maxval2;
    }
    return returnval;
}

int main() {
    bool isOdd=false;
    int middleElement;
    int userInput1;
    cin >> userInput1;

    vector<int> big;

    for (int i = 0; i < userInput1; ++i) {
        int tempInt;
        cin >> tempInt;
        big.push_back(tempInt);
    }

//checking if the array is odd and making it even.
    if(big.size()%2 == 1){
        int middleIndex = floor(big.size()/2);
        middleElement = big[middleIndex];
        big[middleIndex] = 0;
        big.erase(big.begin() + middleIndex);
        isOdd= true;
    }

    int biggest = divideAndConkahh(big, 0, big.size());

    if(isOdd){
        if(biggest>middleElement){
            cout << biggest<<endl;
        } else{
            cout << middleElement << endl;
        }
    } else{
        cout << biggest<<endl;
    }

    return 0;
}
