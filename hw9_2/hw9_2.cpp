/*
 * HackerRank link:https://www.hackerrank.com/contests/cst370-s20-hw9/challenges/alien-alphabet/submissions/code/1323139251
 * Title: hw9_2
 * Abstract: displays the alphabetical order of
 * characters for an alien language.
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 26APR20
 */

#include<iostream>
#include <list>
#include <stack>
#include <cstring>
using namespace std;

// Class to represent a graph
class Graph
{
    int V;    // No. of vertices'
    int V2;
    // Pointer to an array containing adjacency listsList
    list<int> *adj;

    // A function used by topologicalSort
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);   // Constructor

    // function to add an edge to graph
    void addEdge(int v, int w);

    // prints a Topological Sort of the complete graph
    void topologicalSort();
};

Graph::Graph(int V)
{
    V2=0;
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w); // Add w to v’s list.
    V2++;
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack)
{
    // Mark the current node as visited.
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    }
    // Push current vertex to stack which stores result
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;

    // Mark all the vertices as not visited
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    // Call the recursive helper function to store Topological Sort
    // starting from all vertices one by one
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            topologicalSortUtil(i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false)
    {
        if(Stack.size() == 1)
        {
            cout << (char) ('a' + Stack.top());
            Stack.pop();
            break;
        }
        cout << (char) ('a' + Stack.top()) << "->";
        Stack.pop();
    }
}

void printOrder(string words[], int n, int alpha)
{
    // Create a graph with 'aplha' edges
    Graph g(alpha);

    // Process all adjacent pairs of words and create a graph
    for (int i = 0; i < n-1; i++) {
        // Take the current two words and find the first mismatching
        // character
        string word1 = words[i];
        string word2 = words[i + 1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++) {
            // If we find a mismatching character, then add an edge
            // from character of word1 to that of word2
            if (word1[j] != word2[j]) {
                g.addEdge(word1[j] - 'a', word2[j] - 'a');
                break;
            }
        }
    }
    // Print topological sort of the above created graph
    g.topologicalSort();
}

int main()
{
    int count;
    cin >> count;
    string words[count];

    char maxLetter='a';

    for(int i = 0; i < count; i++)
    {
        cin >> words[i];
        for (int j = 0; j < words[i].length(); ++j) {
            if (words[i][j] > maxLetter){
                maxLetter = words[i][j];
            }
        }
    }
    printOrder(words, count, (maxLetter-'a')+1);
    return 0;
}
