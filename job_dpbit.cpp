#include<bits/stdc++.h>
using namespace std;

int minCost(int cost[][4], int n){

    int *dp = new int[(1<<n)];
    for(int i=0;i<=(1<<n);i++){
        dp[i] = INT_MAX;
    }

    dp[0] = 0;

    for(int mask = 0;mask<((1<<n)-1);mask++){
        int k=0;
        int temp = mask;

        //Counting set bits --> no. of assign person
        while(temp>0){
            if(temp%2==1){
                k++;
            }
            temp = temp/2;
        }

        //transverse through every bit

        for(int j=0;j<n;j++)
        {
            // cout<<(mask & (1<<j))<<" ";
            if((mask & (1<<j))==0) // if jth bit is unset
            {
                dp[mask | (1<<j)] = min(dp[mask | (1<<j)],dp[mask] + cost[k][j]);
            }
        }
    }
    
    int ans = dp[(1<<n)-1];
    delete dp;
    return ans;

}

int main(){

    int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};

    cout<<minCost(cost,4)<<endl;

}