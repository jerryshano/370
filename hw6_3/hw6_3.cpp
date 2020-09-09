/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw6/challenges/connect-components/submissions/code/1321768874
 * Title: edges
 * Abstract: connects several connected components
 * of a graph with minimum number of edges to create
 * a single connected component of the graph.
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: 11MAR20
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// all debug
void printGraph(vector<vector<int>> & g)
{
    for (int i = 0; i < g.size(); i++)
    {
        cout << i;
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << " -> " << g[i][j];
        }
        cout << endl;
    }
}

vector<vector<int>> bfs(vector<vector<int>> & g, vector<vector<int>> & v,int src)
{
    queue<int> q;
    int count = 0;
    vector<int> mark(g.size(), 0);

    mark[0] = ++count;
    q.push(0);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        //cout << "visiting: " << curr << endl;

        for (int i = 0; i < g[curr].size(); i++)
        {
            int neighbor = g[curr][i];
            if(mark[neighbor] == 0)
            {
                mark[neighbor] = ++count;
                q.push(neighbor);
            }
        }
    }

    for (int i = 0; i < g.size(); i++)
    {
        if(mark[i] == 0)
        {
            vector<int> tempNode;
            g[src].push_back(i);
            tempNode.push_back(src);
            tempNode.push_back(i);
            v.push_back(tempNode);
            src = i;
            //printGraph(g);
            v = bfs(g, v, src);
            break;
        }
    }

    return v;
}

int main() {

    //reading in graph
    int numOfVertices;
    int numOfEdges;

    cin >> numOfVertices;
    cin >> numOfEdges;

    vector<vector<int>> g, v;
    g.resize(numOfVertices);

    for (int i = 0; i < numOfEdges; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
    }
    //done with the read in

    //printGraph(g);
    v = bfs(g, v, 0);

    if(v.empty())
    {
        cout << "No new edge:"<< endl;
    } else {
        for (int i = 0; i < v.size(); i++) {
            cout << "Edge: " << v[i][0] << "-" << v[i][1] << endl;
        }
    }
    return 0;
}
