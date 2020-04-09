#include<iostream>
using namespace std;

void solve(int N, int* board, int k){
    for(int i = 0;i < N; ++i){
        bool conflict = false;
        for(int j = 0;j < k; ++j){
            if(abs(k - j) == abs(i - board[j]) || i == board[j]){
                conflict = true;
                break;
            }
        }
        if(!conflict){
            board[k] = i;
            if(k == N - 1){
                for(int j = 0;j < N; ++j){
                    cout<<board[j]<<" ";
                }
                cout<<endl;
            }else{
                solve(N, board, k + 1);
            }
        }
    }
}


int main(){

    int N;
    cin>>N;
    int* board = new int[N];
    solve(N, board, 0);
}