/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw11/challenges/coin-collection-1-1/submissions/code/1318196274
 * Title: hw11_2.cpp
 * Abstract: Counting maximum coin on mxn board with restrictions
 * Author: Hamza Saleem
 * ID: 6969 
 * Date: 12/5/19
 */
#include <iostream>

using namespace std;

int main() {
  int row, col;
  cin >> col >> row;

  int board[col][row];

  for(int i = 1; i <= row; i++)
  {
      for(int j = 1; j <= col; j++)
      {
          cin >> board[i][j];
      }
  }

  int coin = 0;
  int count = 1;
  for(int i = 1; i <= row; i++)
  {
      for(int j = count; j <= col; j++)
      {
          if(board[i][j] == 1)
          {
              coin++;
          }
          if(board[i][j+1] == 2)
          {
              count = j;
              break;
          } 
          //cout << board[i][j] << " ";
      }
      if(i == row && count < col && board[i][count+1] !=2)
      {
          if(row==col)
          coin++;
      }
  }
  cout << "Max coins:" << coin << endl;
  cout << "Path:";
  count = 1;
  for(int i = 1; i <= row; i++)
  {

      for(int j = count; j <= col; j++)
      {
          if(board[i][j] == 1 || board[i][j] == 0)
          {
              cout << "(" << j << "," << i << ")";
              if(j < col)
              {
                  cout << "->";
              }
              else break;
          }
          if(board[i][j+1] == 2)
          {
              count = j;
              break;
          } 
          //cout << board[i][j] << " ";
      }
      if(i == row && count < col && board[i][count+1] !=2)
      {
          if(row==col)
          cout << "(" << count+1 << "," << i << ")";
      }
      else if (count == col) break;
  }
}