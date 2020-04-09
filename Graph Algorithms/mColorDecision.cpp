#include<iostream>
using namespace std;

bool mColorable(int** adjMatrix, int n, int m, int* colors, int k){
    if(k == n){
        for(int i = 0;i < n; ++i){
            cout<<colors[i]<<" ";
        }
        cout<<endl;
        return true;
    }
    int* poss = new int[m];
    fill(poss, poss + m, 1);
    for(int i = 0;i < k; ++i){
        if(adjMatrix[k][i] == 1){
            poss[colors[i]] = 0;
        }
    }
    for(int i = 0;i < m; ++i){
        if(poss[i] == 1){
            colors[k] = i;
            if(mColorable(adjMatrix, n, m, colors, k + 1) == true){
                delete[] poss;
                return true;
            }
        }
    }
    delete[] poss;
    return false;
}


int main(){
    int N, M, m;
    cin>>N>>M>>m;
    int** adjMatrix = new int*[N];
    for(int i = 0;i < N; ++i){
        adjMatrix[i] = new int[N]();
    }
    int u, v;
    for(int i = 0;i < M; ++i){
        cin>>u>>v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
    } 
    int* colors = new int[N];
    cout<<(mColorable(adjMatrix, N, m, colors, 0)?"YES\n":"NO\n");
}