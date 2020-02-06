#include<bits/stdc++.h>
using namespace std;

int solution(int* input,int n)
{
	int *output = new int[n];
	output[0]=1;

	//LIS from left
	for(int i=1;i<n;i++){
		output[i] = (input[i]>input[i-1])?output[i-1]+1:1;
	}
	//LIS from Right

	int *output2 = new int[n];
	output2[n-1]=1;
	for(int i=n-2;i>=0;i--)
	{
		output2[i]=(input[i]>=input[i+1])?output2[i+1]+1:1;
	}





	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(output[i]+output2[i]-1 >=max)
		{
			max = output[i]+output2[i]-1;
		}
	}

	delete [] output;
	delete [] output2;
	return max;
}
int main() {


	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr = new int[n];
		for(int i=0;i<n;i++)
		{
			cin>>arr[i];
		}

		int ans = solution(arr,n);


		cout<<ans<<endl;
		delete [] arr;
	}

	return 0;
}
