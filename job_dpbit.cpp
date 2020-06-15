#include<bits/stdc++.h>
using namespace std;
 // iterative 
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

// recursion + memoization
int minCost_r(int cost[][4],int n, int p , int mask , int dp[]){
    if(p>=n){
        return 0;

    }
    if(dp[mask]!=-1){
        return dp[mask];
    }
    int minimum = INT_MAX;

    for(int i=0;i<n;i++){
        if((mask & (1<<i))==0)
        {
            int ans = minCost_r(cost,n,p+1,mask | (1<<i),dp) + cost[p][i]; // pth person ith job
            minimum = min(minimum,ans);
        }
    }
    dp[mask] = minimum;
    return minimum;
}

int main(){

    int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
    cout<<"Iterative \n";
    cout<<minCost(cost,4)<<endl;

    int *dp = new int[(1<<4)];
    for(int i=0;i<=(1<<4);i++){
        dp[i] = -1;
    }

    cout<<"recursion + memoization \n";
    cout<<minCost_r(cost,4,0,0,dp)<<endl;




}