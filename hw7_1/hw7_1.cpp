/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw7/challenges/apple-collection/submissions/code/1322879284
 * Title: Max apples
 * Abstract: that collects the maximum number of apples in boxes
 * Author:jerry kankelborg
 * ID:8404
 * Date:27MAR20
 */

#include<iostream>
using namespace std;

int main() {
    int n;
    cin>>n;

    int boxes[n];

    //populate array boxes with n indices of i values
    for(int i=0; i<n; i++) {
        cin>>boxes[i];
    }

    int tempo[n];
    tempo[0] = boxes[0];

    for(int i=1; i<n; i++) {
        if(i==1) {
            tempo[1] = max(boxes[0], boxes[1]);
        }
        else {
            tempo[i] = max(tempo[i-1], tempo[i-2]+boxes[i]);
        }
    }

    int maxApples = tempo[n-1];
    cout<<"Max Apples: "<<maxApples<<endl;
}