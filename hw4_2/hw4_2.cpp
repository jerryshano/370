/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/partitioning-numbers/submissions/code/1321072917
 * Title: partitioning
 * Abstract: reads a number of input values
 * and the values themselves. Program puts all
 * negative numbers in front of all positive numbers.
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 21FEB20
 */

#include <iostream>
#include <vector>

using namespace std;

void approachOne(vector<int> c){
    int temp;

    for(int i=0; i < c.size(); ++i){
        for(int j = c.size(); j > 0; --j){
            if (c[i] != c[j]){
                if (c[i] >= 0){
                    if (c[j] < 0) {
                        temp = c[i];
                        c[i] = c[j];
                        c[j] = temp;
                    }
                }
            } else {
                break;
            }
        }
    }
    for (auto k : c){
        cout << k << " ";
    }
    cout << endl;
}
void approachTwo(vector<int> s){
    int temp;
    for (int i=0; i < s.size(); ++i) {
        for (int j = 0; j < s.size(); ++j) {
            if (s[i] <= 0){
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    for (int k = s.size() -1; k >= 0; --k) {
        if (s[k] < 0){
            cout << s[k] << " ";
        }
    }
    for (int l = 0; l < s.size(); ++l) {
        if (s[l]>0){
            cout << s[l] << " ";
        }
    }
    cout << endl;
}

int main() {

    int val, loopVal;
    cin >> val;

    vector<int> crispy;

    for (int i=0; i < val; i++ ){
        cin >> loopVal ;
        crispy.push_back(loopVal);
    }

    approachOne(crispy);
    approachTwo(crispy);

    return 0;
}
