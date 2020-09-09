/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/dfs-4/submissions/code/1316845217
 * Title: hw5_3.cpp
 * Abstract: Depth first search of the graph
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 10/09/2019
 */

#include<iostream> 
#include<list> 
using namespace std; 

int vertices, edges, a, b, mark[20]; 
int j = 0; 

class Graph 
{ 
    int V;
    list<int> *adj; 
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V);
    void addEdge(int v, int w); 
    void DFS(int v); 
}; 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{  
    visited[v] = true;
    //cout << v << " "; 
    mark[j] = v;
    j++;
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i]) 
            DFSUtil(*i, visited); 
} 

void Graph::DFS(int v) 
{ 
    bool *visited = new bool[V]; 
    for (int i = 0; i < V; i++)
    {
        visited[i] = false; 
    }     
    DFSUtil(v, visited); 
} 

int main() 
{  
    cin >> vertices;
    Graph g(vertices);

    cin >> edges;
    for(int i = 0; i < edges; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b); 
    }
    g.DFS(0);
    for(int i = 0; i < vertices; i++)
    {
       //cout << mark[i] << " ";
        for(int j = 0; j < vertices; j++)
        {
            if(i == mark[j])
            {
                cout << "Mark[" << i << "]:" << j+1 << endl;
                break;
            }
        }
    }
    return 0; 
}