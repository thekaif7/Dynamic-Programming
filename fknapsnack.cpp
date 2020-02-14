#include<bits/stdc++.h>
using namespace std;

struct data{
  int value,weight;
}

bool compare(struct data a, struct data b){
  double value1 = ((double)a.value/a.weight);
  double value2 = ((double)b.value/b.weight);

  return value1>value2;
};

double fKnapsnack(struct data arr[],int W, int n)
{
  sort(arr,arr+n,compare);

  int curr_weight = 0;
  double ans=0;

  for(int i=0;i<n;i++)
  {
    if(curr_weight+arr[i].weight<=W)
    {
      curr_weight +=arr[i].weight;
      ans +=arr[i].value;

    }
    else
    {
      int rem_weight = W-curr_weight;
      ans +=arr[i].value * ((double)rem_weight/arr[i].weight);
      break;
    }

  }
  return ans;
}
