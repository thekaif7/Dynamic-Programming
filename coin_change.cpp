#include<bits/stdc++.h>
using namespae std;

//Coin Change Problem DP



int get_coin(int coin[], int n ,int value,int **dp){

    if (value==0){return 1;}

    if (value<0){return 0;}

    if(n==0){return 0;}
    if (dp[value][n]>-1){return dp[value][n];}

    int first = get_coin(coin,n,value-coin[0],dp);
    int second = get_coin(coin+1,n-1,value,dp);
    dp[value][n]=first+second;

    return dp[value][n];
}


int solution(int coin[], int n, int sum){


    int **dp= new int*[sum+1];

    for(int i=0;i<sum+1;i++){
        dp[i] = new int[n+1];
    }
    for(int i=0;i<sum+1;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            dp[i][j]=-1;
        }
    }

    int ans = get_coin(coin,n,sum,dp);

    for(int i=0;i<sum+1;i++)
    {
        delete [] dp[i];
    }

    delete [] dp;


    return ans;

}



int main(){

  int numDenominations;
  cin >> numDenominations;
  int* denominations = new int[numDenominations];
  for(int i = 0; i < numDenominations; i++){
    cin >> denominations[i];
  }
  int value;
  cin >> value;

  cout << solution(denominations, numDenominations, value);

}
