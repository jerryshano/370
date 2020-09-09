/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/adjacency-list
 * Title: h3_3
 * Abstract: converts a directed graph data from a user
 * into a corresponding adjacency list format.
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 12 Feb 20
 */

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<bits/stdc++.h>

using namespace std;

int main(){
//adjacency list is represented using a vector of vectors
    vector< vector<int> > adjList;
    vector<int> l;
    l.clear();
    int n,a,b,e;
    cin >> n;
    for(int i=0;i<n;i++){
        adjList.push_back(l);
    }

    cin >> e;
    for(int j = 0;j<e;j++){
        cin >> a >> b;
        adjList[a].push_back(b);
    }

//sort each of the list in adjacency list
    for(int i=0;i<n;i++){
        sort(adjList[i].begin(), adjList[i].end());
    }

    for(int i=0;i<n;i++){
        int d = adjList[i].size();
        cout << i ;
        for(int j=0;j<d;j++){
            cout << "->" << adjList[i][j];
        }
        cout << endl;
    }

    return(0);
}


