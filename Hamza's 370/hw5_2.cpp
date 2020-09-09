/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw5/challenges/bfs-hops/submissions/code/1316867620
 * Title: hw5_2.cpp
 * Abstract: Brute force search for graph
 * Author: Hamza Saleem 
 * ID: 6969
 * Date: 10/10/19
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int vertices, edges, hops;
    cin >> vertices;
    string vert[vertices];
    for (int i = 0; i < vertices; i++)
    {
        cin >> vert[i];
    }
    cin >> edges;
    string path[edges][2];
    for(int i = 0; i < edges; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cin >> path[i][j];
        }
    }

    string starting;
    cin >> starting;
    cin >> hops;
     
    string out[vertices];
    int count = 0, hop_count = 0;
    int index = 1;
    out[count] = starting;
    for(int i = 0; i < edges; i++)
    {
        if(hops == hop_count) break;
        for(int j = 0; j < edges; j++)
        {
            if(path[j][0] == starting)
            {
                count++;
                out[count] = path[j][1];
            }
        }
        hop_count++;
        starting = out[index];
        index++;
    }

    sort(out, out+count);

    for(int i = 0; i <= count; i++)
    {
        cout << out[i] << endl;
    }    

    return 0;
}