#include<iostream>
using namespace std;



long staircase(int n){
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    long *output=new long[n+1];

    output[0]=1;
    output[1]=1;
    output[2]=2;

    for(int i=3;i<n+1;i++)
    {
        output[i]=output[i-1]+output[i-2]+output[i-3];
    }

    return output[n];
}

int main(){


  int n;
  cin >> n ;
  cout << staircase(n) << endl;

}
