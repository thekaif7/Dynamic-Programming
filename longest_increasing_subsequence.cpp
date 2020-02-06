//Dynamic Programming
//Longest increasing subsequence

#include<bits/stdc++.h>
using namespace std;



int long_inc_sub(int input[],int n)
{
  int* output = new int[n];
  output[0]=1; //first element itself a subsequence
//bottom up approach
  for(int i=1;i<n;i++)
  {
    output[i]=1; //worst case element itself subsequence
          for(int j=i-1;j>=0;j--)
    {
                  if(input[j]>input[i])
                  {
                    continue;
                  }

                int possibleAns = output[j]+1;
                if(possibleAns>=output[i])
                {
                  output[i]=possibleAns;
                }
    }
  }

  int m = 0;


  for(int i =0;i<n;i++)
  {
    if(output[i]>m){m=output[i];}
  }
  delete [] output;
  return m;

}

int main(){
  int n;
  cin>>n;
  int *arr = new int[n];

  for (int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int ans = long_inc_sub(arr,n);
  cout<<ans<<endl;
  delete [] arr;


}
