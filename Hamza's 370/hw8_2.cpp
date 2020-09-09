/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw8/challenges/kahns-topological-sort/submissions/code/1317368862
 * Title: hw8_2.cpp
 * Abstract: DAG graph order and in-degree display
 * Author: Hamza Saleem 
 * ID: 6969
 * Date: 10/30/19
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  
  int vert, edge, num1, num2;
  bool check = true;

  cin >> vert;
  cin >> edge;

  int arr[vert];
  for(int i = 0; i < vert; i++)
  {
      arr[i] = 0;
  }

  for(int i = 0; i < edge; i++)
  {
      
        cin >> num1 >> num2;
        arr[num2] += 1;
      
  }

  for(int i = 0; i < vert; i++)
  {
      cout << "In-degree[" << i << "]:" << arr[i] << endl;
  }

  int *max;
  max = max_element(arr, arr+vert);

  if(arr[0] > 0)
  {
      check = false;
  }

  if(check == false)
  {
      cout << "No Order:" << endl;
  }
  else
  {
      cout << "Order:";
      int x = 0;
      for(int i = 0; i <= (*max); i++)
      {
          if(x < edge && i < (*max))
          for(int j = 0; j < vert; j++)
          {
              if(arr[j] == x)
              {
                  cout << j << "->";
              }
          }
          else if(i == *(max))
          {
            for(int j = 0; j < vert; j++)
            {
              if(arr[j] == x)
              {
                  cout << j << endl;
              }
            }
          }
          x++;
      }
      cout << endl;
  }

}