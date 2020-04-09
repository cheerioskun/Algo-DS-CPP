#include<bits/stdc++.h>
using namespace std;

int rook_moves(int n){
    int** dp = new int*[n];
    for(int i = 0;i < n; ++i){
        dp[i] = new int[n]();
    }
    dp[0][0] = 1;
    for(int i = 1;i < n; ++i){
        dp[i][0] = 1 << (i - 1);
        dp[0][i] = 1 << (i - 1);
    }
    for(int i = 1;i <n; ++i){
        for(int j = 1;j < n; ++j){
            int sum = 0;
            for(int k = 0;k < i; ++k) sum += dp[k][j];
            for(int k = 0;k < j; ++k) sum += dp[i][k];
            dp[i][j] = sum;
        }
    }
    int ans = dp[n-1][n-1];
    for(int i = 0;i < n; ++i){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}



int main(){
    int n;
    cin>>n;
    cout<<rook_moves(n)<<endl;
}

