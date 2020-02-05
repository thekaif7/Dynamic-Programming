// AlphaCode
// Dynamic Programming
//Problem
//https://www.hackerearth.com/problem/algorithm/acode-alphacode-3/

#include<bits/stdc++.h>

using namespace std;

// recursion way

int AlphaCodeR(int *n,int size){
  if (size==1){return 1;}
  if (size==0){return 1;} //for empty string possibilities
  int output = AlphaCodeR(n,size-1);

  if(n[size-2]*10+n[size-1]<=26){
    output+=AlphaCodeR(n,size-2);
  }
  return output;
}

//Dynamic Way Storing
// Initially fill arr with 0 with size+1
int AlphaCodeDP(int *n,int size, int *arr){
  if (size==1){return 1;}
  if (size==0){return 1;} //for empty string possibilities
  if (arr[size]>0){return arr[size];}
  int output = AlphaCodeR(n,size-1);

  if(n[size-2]*10+n[size-1]<=26){
    output+=AlphaCodeR(n,size-2);
  }
  arr[size]=output;
  return output;
}


//best Method

int Alpha_code(string s, int n)
{
    int count[n+1];
    count[0] = 1;
    count[1] =1;
   for (int i = 2; i <= n; i++)
    {
        count[i] = 0;

        // If the last digit is not 0,
        // then last digit must add to the number of words
        if (s[i-1] > '0')
            count[i] = count[i-1]%m;

        // If second last digit is smaller
        // than 2 and last digit is smaller than 7,
        // then last two digits form a valid character
        if (s[i-2] == '1' ||
              (s[i-2] == '2' && s[i-1] < '7') )
            count[i] += count[i-2]%m;
    }
    return count[n]%m;
}




int main(){
  string s;
  cin>>s;

  int ans = Alpha_code(s,s.length());
  cout<<"possibilities: "<<ans<<endl;



}
