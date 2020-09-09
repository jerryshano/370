/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw1/challenges/370-hw1-1/problem
 * Title: hw1_1.cpp
 * Abstract: This program will tell difference of two closest positive integers.
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 9/4/19
 */

#include <iostream>
#include<climits>

using namespace std;

int main() {

  int n, num1 = INT_MAX, num2= INT_MIN, dis = INT_MAX, minDis = INT_MAX;
  cin >> n;
  int *A;
  A = new int[n];
  for (int i = 0; i < n; i++)
  {
      cin >> A[i];
  }
  for(int i = 0; i < n; i++)
  {
      for(int j = 0; j < n; j++)
      {
          if(j == i) continue;
          dis = A[i] - A[j];
          if(dis < 0)
          {
            dis *= -1;
          }
            if(dis < minDis)
          {
            minDis = dis;
            num1 = A[i];
            num2 = A[j];
          }
      }
      /*dis = A[i] - A[i+1];
      if(dis < 0)
      {
            dis *= -1;
      }
      if(dis < minDis)
      {
          minDis = dis;
          num1 = A[i];
          num2 = A[i+1];
      }

      if(A[i] < num1 && A[i] >= 0)
      {
          num1 = A[i];
      }
      if(A[i] > num2 && A[i-1] < A[i])
      {
          num2 = A[i-1];
      }*/
  }
  cout << "Min distance: " << minDis << endl;
  if(num1 > num2)
  {
      cout << "Two numbers for min distance: " << num2 << " and " << num1 << endl;
  }
  else
  {
      cout << "Two numbers for min distance: " << num1 << " and " << num2 << endl;
  }

  delete[] A;

  return 0;

}