#include<bits/stdc++.h>
using namespace std;

double probWin(int n, double p){
    double** dp = new double*[n + 1];
    for(int i = 0;i <= n; ++i){
        dp[i] = new double[n + 1];
    }
    for(int i = 1;i <= n; ++i){
        dp[0][i] = 1;
        dp[i][0] = 0;
    }
    for(int i = 1;i <= n; ++i){
        for(int j = 1;j <= n; ++j){
            dp[i][j] = p * dp[i - 1][j] + (1 - p) * dp[i][j - 1];
        }
    }
    double ans = dp[n][n];
    for(int i = 0;i <= n; ++i){
        delete [] dp[i];
    }
    delete [] dp;
    return ans;
}


int main(){
    int n;
    cin>>n;
    double p;
    cin>>p;
    cout<<probWin(n, p)<<endlJOKNYVIU9L,;KJOI09HU-=8[=-\
    
    ];
}