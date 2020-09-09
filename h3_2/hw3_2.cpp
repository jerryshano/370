/*
 * HackerRank link: https://www.hackerrank.com/contests/cst370-s20-hw3/challenges/equal-groups/submissions/code/1320675204
 * Title: h3_2
 * Abstract: which partitions n positive integers
 * into two disjoint sets with the same sum.
 * Author: Jerry Kankelborg
 * ID: 8404
 * Date: Feb 12 2020
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll i,n,num,N,c,sum=0,s,flag,k;
//cout<<"Enter size of array:";
    cin>>n;
    ll a[n];
//cout<<"Enter elements of array:";
    for(i=0;i<n;i++)
        cin>>a[i];
    k=a[0];
    for(i=0;i<n;i++)
    {
        sum+=a[i];//to store sum of array
        if(a[i]<k)
            k=a[i];
    }
    N=1<<n;//to represent all numbers from 0 to 2^n-1
    N=N-1;
    flag=0;//to check if set contains smallest element
    for(i=0;i<=N;i++)
    {
        num=i;
        c=0;
        s=0;
        while(num>0)
        {
            if(num&1)// if rightmost set is set
            {
                s+=a[c]; // include the cth index element of array into set
                if(a[c]==k)
                    flag=1;
            }
            c++; //to point to cth index bit position
            num>>=1;// right shift num by 1
        }
        if((2*s==sum)&&(flag==1))// if current set has value half the total sum
            break;
        flag=0;
    }
    if(i==N+1)
        cout<<"Equal Set: 0";
    else
    {
        num=i;
        c=0;
        vector<ll>v;
        while(num>0)// to print the corresponding set containing smallest element
        {
            if(c==0)
                cout<<"Equal Set: ";
            if(num&1)
                v.push_back(a[c]);
            c++;
            num>>=1;
        }
        sort(v.begin(),v.end());
        for(i=0;i<v.size();i++)
            cout<<v[i]<<" ";
    }
}


