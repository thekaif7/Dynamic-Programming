#include <bits/stdc++.h>
using namespace std;



int max_rec_sum(int **rect,int n,int m){
    int *sum = new int[n];

    int maxx = INT_MIN;
    int curr_max = 0;


    for(int i=0;i<n;i++){
            sum[i]=0;
        }


    for(int l=0; l<m; l++)
    {
        for(int r=l; r<m; r++)
        {
            for(int k=0; k<n; k++)

            { // adding column column wise
                sum[k] = sum[k] + rect[k][r];
                // cout<<sum[k]<<" ";
            }


            curr_max = 0;
             for(int k=0;k<n;k++)
            {
            curr_max = curr_max + sum[k];


            if(curr_max>maxx){maxx = curr_max;}

            if(curr_max<0){ curr_max = 0;}
            }

        }






        // initialize 0 for next l and r
        for(int b=0;b<n;b++)
        {
            sum[b]=0;
        }




    }

    delete [] sum;

    return maxx;


}

int main()
{
    int row,col;
    cin>>row>>col;

    int** rect = new int*[row];

    for(int i=0;i<row;i++){
        rect[i] = new int[col];

        for(int j=0;j<col;j++){
            cin>>rect[i][j];
        }
    }

    int ans = max_rec_sum(rect,row,col);

    for(int i=0;i<row;i++){
        delete [] rect[i];
    }

    delete [] rect;

    cout<<ans<<endl;





    return 0;
}
