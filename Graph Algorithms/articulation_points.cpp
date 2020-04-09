#include<bits/stdc++.h>
using namespace std;

int DFS(int** G, int N, int s, int d, int* depth){
    int min = d;
    depth[s] = d;
    bool flag;
    if(d == 0){
        int count = 0;
        for(int i = 0;i < N; ++i){
            if(G[s][i] == 1 && depth[i] == -1){
                DFS(G, N, i, 1, depth);
                count++;
            }
        }
        if(count > 1){
            cout<<s<<endl;
        }
    }
    else{
        flag = true;
        for(int i = 0;i < N; ++i){
            if(G[s][i] == 1){
                if(depth[i] != -1){
                    min = std::min(min, depth[i]);
                }else{
                    int t = DFS(G, N, i, d + 1, depth);
                    min = std::min(min, t);
                    if(t >= d){
                        flag = false;
                    }
                }
            }
        }
        if(flag == false){
            cout<<s<<endl;
        }
    }
    return min;
}


void articulation(int** G, int N){
    int* depth = new int[N];
    fill(depth, depth + N, -1);
    DFS(G, N, 0, 0, depth);
}


int main(){
    int N, M;
    cin>>N>>M;
    int** G = new int*[N];
    for(int i = 0;i < N; ++i){
        G[i] = new int[N]();
    }
    int u, v;
    for(int i = 0;i < M; ++i){
        cin>>u>>v;
        G[u][v] = 1;
        G[v][u] = 1;
    }
    articulation(G, N);

}