/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-f19-hw2/challenges/time-difference-2/submissions/code/1316207428
 * Title: hw2_2.cpp
 * Abstract: Difference between timestamps
 * Author: Hamza Saleem
 * ID: 6969
 * Date: 9/12/19
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
   int hour1, minute1, second1;
   int hour2, minute2, second2;
   int diff_hour, diff_minute, diff_second;
   string input1, input2;
   string hr, min, sec;
   
   cin >> input1;
   hr = input1[0];
   hr += input1[1];
   min = input1[3]; 
   min += input1[4];
   sec = input1[6];
   sec += input1[7];

   hour1 = stoi(hr);
   minute1 = stoi(min);
   second1 = stoi(sec);

   cin >> input2;
   hr = input2[0];
   hr += input2[1];
   min = input2[3]; 
   min += input2[4];
   sec = input2[6];
   sec += input2[7];

   hour2 = stoi(hr);
   minute2 = stoi(min);
   second2 = stoi(sec);

   if(hour2 < hour1)
   {
       hour2 += 24;
   }
   if(hour2 == hour1 && minute2 < minute1)
   {
       hour2 += 24;
   } 
   if(second1 > second2) {
      minute2--;
      second2 += 60;
   }
   
   diff_second = second2 - second1;
   
   if(minute1 > minute2) {
      hour2--;
      minute1 += 60;
   }
   diff_minute = minute2 - minute1;
   diff_hour = hour2 - hour1;

   cout << setfill ('0') << setw(2);
   cout << diff_hour <<":" << setfill ('0') << setw(2) << diff_minute <<":" << setfill ('0') << setw(2) <<diff_second;
   
   return 0;
}