/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/dfs-4/submissions/code/1321572966
 * Title: dfs
 * Abstract: implements the Depth-First Search (DFS) algorithm
 * using a stack and a mark array
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 06MAR20
 */

#include <iostream>
#include <stack>
using namespace std;

int main() {

    stack<int> n;

    int num_vertices;
    cin >> num_vertices;

    int markArray[num_vertices];
    int visited[num_vertices];

    int num_edges;
    cin >> num_edges;
    int s[num_vertices][num_vertices];

    //initialize the 2d array to 0
    for (int k = 0; k < num_vertices; ++k) {
        for (int i = 0; i < num_vertices; ++i) {
            s[k][i] = 0;
        }
    }

    //pinging the edge locations
    for (int i = 0; i < num_edges; ++i) {
        int x, y;
        cin >> x >> y;
        s[x][y] = 1;
    }

    // load arrays
    for (int j = 0; j < num_vertices; ++j) {
        markArray[j] = 0;
        visited[j]=0;
    }

    n.push(0);

    int count = 1;
    while (n.size() > 0){
        int ridOf = n.top();
        n.pop();
        visited[ridOf] = 1;
        if (markArray[ridOf] == 0){
            markArray[ridOf] = count;
            count++;
        }

        for (int i = num_vertices -1; i >= 0; --i) {
            if (s[ridOf][i] == 1){
                if (visited[i] == 0){
                    n.push(i);
                }
            }
        }
    }//while

    for (int l = 0; l < num_vertices; ++l) {
        cout << "Mark[" << l << "]:" << markArray[l] << endl;
    }

    return 0;
}
