#include<bits/stdc++.h>
using namespace std;


int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    long *dp = new long[n+1];

    for(int i=0;i<=n;i++){dp[i]=0;}


    long  mod =1000000007;

    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i]= dp[i]%mod + (dp[i-j]%mod)*(dp[j-1]%mod);
        }
    }
    long ans = dp[n]%mod;
    delete [] dp;

    return ans;


}


int main(){

  int n;
  cin>>n;

  cout<<countBST(n)<<endl;


}
