#include <iostream>

using namespace std;


long getMin_chocolate(int *A, int n){

    int *dp = new int[n];

    dp[0] = 1;
    for(int i=1;i<n;i++){
        if (A[i]>A[i-1]){dp[i] =dp[i-1]+1;}

        else{ dp[i] = 1;}
    }
    for(int i=n-2;i>=0;i--){
        if (A[i]>A[i+1] && dp[i]<=dp[i+1]){dp[i] =dp[i+1]+1;}


    }

    long ans = 0;

    for(int i=0;i<n;i++){
        ans = ans + dp[i];

    }

    delete [] dp;

    return ans;
}

int main(){

    int n;
    cin >> n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << getMin_chocolate(arr, n);
    delete []arr;
}
