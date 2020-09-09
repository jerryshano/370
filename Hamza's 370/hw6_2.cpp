/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/connect-components/submissions/code/1317040822
 * Title: hw6_2.cpp
 * Abstract: connect unconnected graphs
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 10/17/19
 */

#include<iostream> 
#include <list> 
using namespace std; 
int arr[10]={0}, count = 0;
bool check = false;
class Graph 
{ 
    int V; 
  
    list<int> *adj; 
  
    void DFSUtil(int v, bool visited[]); 
public: 
    Graph(int V); 
    void addEdge(int v, int w); 
    void connectedComponents(); 
}; 

void Graph::connectedComponents() 
{ 
    bool *visited = new bool[V]; 
    for(int v = 0; v < V; v++) 
        visited[v] = false; 
  
    for (int v=0; v<V; v++) 
    { 
        if (visited[v] == false) 
        { 
            check = false;
            DFSUtil(v, visited); 
            count++;
            //cout << "\n"; 
        } 
    } 
} 
  
void Graph::DFSUtil(int v, bool visited[]) 
{ 
    visited[v] = true;
    if(check == false) 
    arr[count] = v;
    check = true; 

    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSUtil(*i, visited); 
} 
  
Graph::Graph(int V) 
{ 
    this->V = V; 
    adj = new list<int>[V]; 
} 
  
void Graph::addEdge(int v, int w) 
{ 
    adj[v].push_back(w); 
    adj[w].push_back(v); 
} 
  
int main() 
{ 
    int vert, edg, a, b;
    cin >> vert >> edg;
    Graph g(vert); 
    for(int i = 0; i < edg; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    } 
    g.connectedComponents();

    int i=0;
    if(count < 2)
    {
        cout << "No new edge: " << endl;
    }
    else
    {
        while(i < count-1)
        {
            cout << "Edge: " << arr[i] << "-" << arr[i+1];
            cout << endl;
            i++;
        }
    }
    return 0; 
}