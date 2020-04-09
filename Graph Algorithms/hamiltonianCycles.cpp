#include<iostream>
using namespace std;

bool isHamiltonian(int** adjMatrix, int n, int* path, int k, int src){
    path[k] = src;
    k++;
    if(k == n && adjMatrix[path[0]][src] == 1){
        for(int i = 0;i < n; ++i){
            cout<<path[i]<<" ";
        }
        cout<<path[0]<<endl;
        return true;
    }
    bool flag = false;
    for(int i = 0;i < n; ++i){
        if(adjMatrix[src][i] == 1){
            bool canGoToi = true;
            for(int j = 0;j < k; ++j){
                if(path[j] == i){
                    canGoToi = false;
                    break;
                }
            }
            if(canGoToi){
                bool temp = isHamiltonian(adjMatrix, n, path, k, i);
                if(temp == true){
                    flag = true;
                }
            }
        }
    }
    return flag;
}


int main(){
    int N, M;
    cin>>N>>M;
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
    int* path = new int[N];
    cout<<(isHamiltonian(adjMatrix, N, path, 0, 0)?"YES":"NO")<<endl;
}