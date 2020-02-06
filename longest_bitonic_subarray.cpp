#include<bits/stdc++.h>
using namespace std;



int longestBitonicSubarray(int *input, int n)
{
  int *left_check = new int[n];
  left_check[0] = 1;

  for(int i=1;i<n;i++)
  {
      left_check[i] = 1;

      for(int j=0;j<i;j++)
      {
          left_check[i] = (input[i]>input[j] && left_check[i]<=left_check[j]+1)?left_check[j]+1:left_check[i];
      }
  }

  int *right_check = new int[n];
  right_check[n-1] = 1;

  for(int i=n-2;i>=0;i--)
  {
      right_check[i] = 1;

      for(int j=n-1;j>i;j--)
      {
          right_check[i] = (input[i]>input[j] && right_check[i]<=right_check[j]+1)?right_check[j]+1:right_check[i];
      }
  }

  int max = 0;
  for(int i=0;i<n;i++)
  {
      max = (left_check[i]+right_check[i]-1>=max)?left_check[i]+right_check[i]-1:max;
  }

  return max;
}






int main(){

}
