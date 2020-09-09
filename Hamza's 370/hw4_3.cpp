/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw4/challenges/tsp-2-1
 * Title: hw4_3.cpp
 * Abstract: Travelling salesman problem
 * Author: Hamza Saleem
 * ID: 6969 
 * Date: 9/26/19
 */
#include <bits/stdc++.h>
 
using namespace std;
 
int ary[30][30],completed[10],cost=0;
int vertices;
string a[20];
 
void takeInput()
{
    int i,j;
    cin >> vertices;
    for(int i = 0; i < vertices; i++)
    {
        cin >> a[i]; 
    }
    int edges;
    cin >> edges;
    for(int i = 0; i < vertices; i++)
    {
        for(int j = 0; j < vertices; j++)
        {
            ary[j][i] = 0;
        }
    }

    string city1, city2;
    int cost, i1, i2;
    for(int i = 0; i < edges; i++)
    {
        cin >> city1 >> city2 >> cost;
        for(int j = 0; j < vertices; j++)
        {
            if(city1 == a[j])
            {
                i1 = j;
            }
            if(city2 == a[j])
            {
                i2 = j;
            }
        }
        ary[i2][i1] = cost;
    }
}
 
int least(int c)
{
    int i,nc=999;
    int min=999,kmin;
 
    for(i=0;i < vertices;i++)
    {
        if((ary[c][i]!=0)&&(completed[i]==0))
            if(ary[c][i]+ary[i][c] < min)
            {
                min=ary[i][0]+ary[c][i];
                kmin=ary[c][i];
                nc=i;
            }
    }
 
    if(min!=999)
        cost+=kmin;
 
    return nc;
}
 
void mincost(int city)
{
    int i,ncity;
 
    completed[city]=1;
    cout<<a[city]<<"->";
    ncity=least(city);
 
    if(ncity==999)
    {
        ncity=0;
        cout<<a[ncity];
        cost+=ary[city][ncity];
 
        return;
    }
 
    mincost(ncity);
}
 
int main()
{
    takeInput();
 
    cout<<"Path:";
    mincost(0);
    cout << endl;
    int s = 0;
    vector<int> vertex; 
    for (int i = 0; i < vertices; i++) 
        if (i != s) 
            vertex.push_back(i); 
  
    int min_path = INT_MAX; 
    do { 
        int current_pathweight = 0; 
        int k = s; 
        for (int i = 0; i < vertex.size(); i++) { 
            current_pathweight += ary[k][vertex[i]]; 
            k = vertex[i]; 
        } 
        current_pathweight += ary[k][s];  
        min_path = min(min_path, current_pathweight); 
         
    } while (next_permutation(vertex.begin(), vertex.end()));
    cout << "Cost:" << min_path;
 
    return 0;
}