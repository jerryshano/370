/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/knapsack-8/submissions/code/1321768689
 * Title: knapsack
 * Abstract: read the weight and value of each item
 * from a user and determine the best subset
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 11MAR20
 */

#include <iostream>
using namespace std;

int main() {
    
    int first, second;
    int totalValue = 0;
    int totalWeight = 0;

    cin >> first >> second;

    bool bArr[first];
    for (int j = 0; j < first; ++j) {
        bArr[j] = false;
    }

    int arr[first][2];

    for (int i = 0; i < first; ++i) {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    while (true) {
        int mostValue = -1;
        for (int l=0; l < first; l++){
               if(arr[l][0] <= second - totalWeight && !bArr[l]){
                    if (mostValue == -1 || arr[l][1] > arr[mostValue][1]){
                        mostValue = l;
                    }
               }
        }
        if(mostValue == -1) {
            break;
        } else {
            bArr[mostValue] = true;
            totalValue += arr[mostValue][1];
            totalWeight += arr[mostValue][0];
        }
    }

    cout << "Items:";
    int count = 0;
    for (int k = 0; k < first; ++k) {
        if(bArr[k]){
            cout << k + 1 << " ";
            count++;
        }
    }

    if (count == 0){
        cout << endl << "Capacity:" << endl;
        cout << "Value:" << endl;
    } else {
        cout << endl << "Capacity:" << totalWeight << endl;
        cout << "Value:" << totalValue << endl;
    }

    return 0;
}
