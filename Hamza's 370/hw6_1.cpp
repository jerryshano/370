/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw6/challenges/apple-collection/submissions/code/1317014132
 * Title: hw6_1.cpp
 * Abstract: Count the sum of max apples with hops
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 10/16/19
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  int arr[n];

  for(int i = 0; i < n; i++)
  {
      cin >> arr[i];
  }

  int sum = 0;
  int maxind;

  for(int i = 0; i < n; i++)
  {
      int max = 0;
      for(int j = 0; j < n; j++)
      {
          if(arr[j] > max)
          {
              max = arr[j];
              maxind = j;
          }
      }
      sum += max;
      arr[maxind] = 0;
      arr[maxind-1] = 0;
      arr[maxind+1] = 0;
  }

  cout << "Max Apples: " << sum << endl;
}