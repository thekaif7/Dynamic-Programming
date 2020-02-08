

//Weighted job schedule Problem Dynamic Programming and Greedy.


#include<bits/stdc++.h>
using namespace std;

struct job{
  int start ,finish,profit;
};

int binarySearch(job jobs[], int index)
{
    // Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = index - 1;

    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[index].start)
        {
            if (jobs[mid + 1].finish <= jobs[index].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }

    return -1;
}

bool compare(job a, job b){
  return a.finish<b.finish;
}

int findMprofit(job arr[] , int n){
  sort(arr,arr+n,compare);

  int *dp = new int[n];
  dp[0] = arr[0].profit;

  for(int i=1; i<n;i++)
  {
    int including  = arr[i].profit;
    int non_conflict = -1;

   non_conflict = binarySearch(arr, i);

    if(non_conflict!=-1)
    {
      including+=dp[non_conflict];

    }
    dp[i] = max(including,dp[i-1]);
  }
  int ans = dp[n-1];
  delete [] dp;
  return ans;
}


int main()
{
    //Write your code here
    int n;
    cin>>n;

    job arr[n];

    for(int i=0;i<n;i++)
    {
        int start,finish,profit;
        cin>>start>>finish>>profit;

        arr[i].start = start;
        arr[i].finish = finish;
        arr[i].profit = profit;

    }

    cout<<findMprofit(arr,n)<<endl;







    return 0;
}
