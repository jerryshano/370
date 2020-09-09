/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw8/challenges/kahns-topological-sort/submissions/code/1322615662
 * Title: hw8_2
 * Abstract: This program conducts the topological
 * sorting based on the source removal algorithm
 * (= Kahn’s algorithm).
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 06APR20
 */

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {

    int userVertices;
    int userEdges;
    int numOfVisits;

    cin >> userVertices;
    cin >> userEdges;

    vector<int> In(userVertices);
    vector<vector<int>> Map(userVertices);
    vector<int> Order;
    queue<int> topSort;
    vector<int> visits(userVertices);

    for (int i = 0; i < userEdges; i++) {
        int vertex1;
        int vertex2;
        cin >> vertex1;
        cin >> vertex2;
        Map[vertex1].push_back(vertex2);
        In[vertex2]++;
    }

    for (int i = 0; i < In.size(); i++) {
        cout << "In-degree[" << i << "]:" << In[i] << "\n";
    }

    for (int i = 0; i < In.size(); i++) {
        if (In[i] == 0) {
            topSort.push(i);
            visits[i]++;
        }
    }

    while (!topSort.empty()) {
        int currentNode = topSort.front();
        topSort.pop();
        Order.push_back(currentNode);
        numOfVisits++;

        for (int neighbor : Map[currentNode]) {
            In[neighbor]--;

            if (In[neighbor] == 0 && visits[neighbor] == 0) {
                topSort.push(neighbor);
                visits[neighbor]++;
            }
        }
    }

    if (numOfVisits < In.size()) {
        cout << "No Order:" << "\n";
    } else {
        cout << "Order:";

        for (int i = 0; i < Order.size(); i++) {
            cout << Order[i];

            if (i != Order.size() - 1) {
                cout << "->";
            }
        }
    }
}