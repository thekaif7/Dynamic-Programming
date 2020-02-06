#include<bits/stdc++.h>
using namespace std;

// problem : https://leetcode.com/problems/house-robber/


int getMaxMoney(int arr[], int n){

    int *output = new int[n];
    output[0] = arr[0];
    output[1] = arr[1];

    for(int i=2;i<n;i++){
        output[i] = output[i-2]+arr[i];
        for(int j=0;j<i-1;j++)

        output[i] = (output[j]+arr[i]>=output[i])?output[j]+arr[i]:output[i];
    }

    int max = 0;
    for(int i=0;i<n;i++)
    {
        max = (output[i]>=max)?output[i]:max;
    }

    delete [] output;

    return max;

}

int main(){

    int n;
    cin >> n;
    int arr[10000];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cout << getMaxMoney(arr, n);

  return 0;
}
