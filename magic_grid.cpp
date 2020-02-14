#include <bits/stdc++.h>
using namespace std;

//Iterative

int solution(int **HM,int row,int col){
    int **dp = new int*[row];
    for(int i=0;i<row;i++){
        dp[i] = new int[col];
    }

    dp[row-1][col-1] = 1;
    dp[row-1][col-2] = 1;
    dp[row-2][col-1] = 1;

    // filling last row ;
    for(int i=col-2;i>=0;i--){
        dp[row-1][i] = (dp[row-1][i+1]-HM[row-1][i+1]<1)?1:dp[row-1][i+1]-HM[row-1][i+1];

    }

    // filling last column

    for(int i=row-2;i>=0;i--){
        dp[i][col-1] = (dp[i+1][col-1]-HM[i+1][col-1]<1)?1:dp[i+1][col-1]-HM[i+1][col-1];

    }

    //Filling rest cells

    for(int i=row-2;i>=0;i--){
        for(int j=col-2;j>=0;j--){

            int option1 = dp[i+1][j] - HM[i+1][j];
            int option2 = dp[i][j+1] - HM[i][j+1];

            int ans = min(option1,option2);

            dp[i][j] = (ans<1)?1:ans;
        }
    }

    int f_ans = dp[0][0];

    for(int i=0;i<row;i++){
        delete [] dp[i];
    }

    delete [] dp;
    return f_ans;
}

    //Recursive
int magic_grid(int **HM, int si,int sj ,int ei,int ej,int **dp){
    if(si==ei && sj==ej){return 1;}

    if((si==ei-1 && sj==ej) || (si==ei && sj==ej-1)){return 1;}

    if (si+1>ei || sj+1>ej){ return INT_MAX;}

    if(dp[si][sj]>0){return dp[si][sj];}



    int option1 = magic_grid(HM,si+1,sj,ei,ej,dp)-HM[si+1][sj]; //Down
    int option2 = magic_grid(HM,si,sj+1,ei,ej,dp)-HM[si][sj+1]; //Forward

    int ans = (min(option2,option1)<1)?1:min(option1,option2);

    dp[si][sj] = ans;

    return dp[si][sj];



}

int main()
{
    int t;
    cin>>t;

    while(t--){
        int row,col;
        cin>>row>>col;

        int **HM = new int*[row];
        int** dp = new int*[row];

        for(int i = 0;i<row; i++){
            HM[i] = new int[col];
            dp[i] = new int[col];

            for(int j=0;j<col;j++){
                cin>>HM[i][j];
                dp[i][j] = 0;
            }
        }



        // int fAns = magic_grid(HM,0,0,row-1,col-1,dp);
        int f = solution(HM,row,col);

        for(int i=0;i<row;i++){
            delete [] dp[i];
            delete [] HM[i];
        }


        delete [] dp;
        delete [] HM;

        cout<<f<<endl;




    }


    return 0;
}
