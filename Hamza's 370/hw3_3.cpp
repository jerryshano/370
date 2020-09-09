/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw3/challenges/adjacency-list/submissions/code/1316399012
 * Title: hw3_3.cpp
 * Abstract: Graph representation into adjacency list
 * Author: Hamza Saleem 
 * ID: 6969
 * Date: 09/19/19
 */
#include<bits/stdc++.h> 
using namespace std; 
  
void addEdge(vector<int> adj[], int u, int v) 
{ 
    adj[u].push_back(v);  
} 
  
void printGraph(vector<int> adj[], int V) 
{ 
    for (int v = 0; v < V; ++v) 
    { 
        cout << v; 
        for (auto x : adj[v]) 
           cout << "->" << x; 
        printf("\n"); 
    } 
} 
  
// Driver code 
int main() 
{ 
    int vert, edg;
    cin >> vert;
    cin >> edg;

    vector<int> adj[vert];
    for(int i = 0; i < edg; i++)
    {
        int v, e;
        cin >> v >> e;
        addEdge(adj, v, e); 
    }  
    printGraph(adj, vert); 
    return 0; 
}