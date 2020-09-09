/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw4/challenges/matching-form/submissions/code/1321072940
 * Title: well formed
 * Abstract: that reads a string and check if it’s well-formed or not.
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 21 feb 20
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main() {
    string h;
    cin >> h;
    stack<char> dude;
    stack<char> dudette;
    stack<char> burrito;
    vector<char> hello(h.begin(), h.end());

    bool balanced = true;
    for (int i=0; i < hello.size() && balanced; i++) {
        switch(hello[i]){
            case '(' :
                dude.push(hello[i]);
                break;
            case '{' :
                dudette.push(hello[i]);
                break;
            case '[' :
                burrito.push(hello[i]);
                break;
            case ')' : {
                if (dude.empty()) {
                    balanced = false;
                    break;
                }
                dude.pop();
                break;
            }
            case '}' : {
                if (dudette.empty()) {
                    balanced = false;
                    break;
                }
                dudette.pop();
                break;
            }
            case ']' : {
                if (burrito.empty()) {
                    balanced = false;
                    break;
                }
                burrito.pop();
                break;
            }
        }
    }
    if ( dude.empty() && dudette.empty() && burrito.empty() && balanced){
        cout << "TRUE" << endl;
    } else {
        cout << "FALSE" << endl;
    }
    return 0;
}
