#include<bits/stdc++.h>
using namespace std;

int rod_cut(int n, int* p){
    int* dp = new int[n + 1];
    dp[0] = p[0];
    for(int i = 1;i <= n; ++i){
        int max = -1;
        for(int j = 1;j <= i; ++j){
            max = std::max(max, dp[i - j] + p[j]);
        }
        dp[i] = max;
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}


int main(){
    int n;
    cin>>n;
    int p[n + 1];
    for(int i = 0;i <= n; ++i){
        cin>>p[i];
    }
    cout<<rod_cut(n, p);
    return 0; 
}