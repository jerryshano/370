/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw5/challenges/bfs-hops/submissions/code/1321582053
 * Title: bfs
 * Abstract: displays the city names in the range
 * of hop(s) from a starting city
 * Author: jerry kankelborg
 * ID: 8404
 * Date: 06MAR20
 */

#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

void bfs(map <string, vector<string>> & g, string src, int moves)
{
    queue<string> q;
    int count = 0;

    map<string,int> newLife;

    newLife[src] = ++count;
    q.push(src);
    while (!q.empty())
    {
        string curr = q.front();
        q.pop();

        //keeping track of visited nodes
        //and incrementing those nodes
        if (newLife[curr]) {
            count = newLife[curr] + 1;
        } else {
            ++count;
        }

        // checking if a node has been visited
        for (int i = 0; i < g[curr].size(); i++)
        {
            string neighbor = g[curr][i];
            if(newLife[neighbor] == false)
            {
                count = newLife[neighbor];
                q.push(neighbor);
            }
        }
    }

    //traversing the map using iterators
    for (auto it = newLife.begin(); it != newLife.end(); it++) {
        if ( it->second <= moves ) {
            cout << it->first << endl;
        }
    }

    return;
}

void read_graph(map <string, vector<string>> & g)
{
    int num_of_vertices;
    cin >> num_of_vertices;

    for(int i = 0; i < num_of_vertices; i++){
        string t;
        cin >> t;
    }

    int num_of_edges;
    cin >> num_of_edges;

    string from;
    string to;

    for (int i = 0; i < num_of_edges; i++)
    {
        cin >> from;
        cin >> to;
        g[from].push_back(to);
    }
}

int main()
{
    int wobble;
    string src;

    map <string, vector<string>> graph;

    read_graph(graph);

    cin >> src >> wobble;

    bfs(graph, src, (wobble +1));

    return 0;
}
