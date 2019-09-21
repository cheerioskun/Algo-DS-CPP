// Check whether a given directed graph is a DAG
#include<bits/stdc++.h>
using namespace std;

bool isDAG(set<int>* adjList, int N, int* visited = nullptr){
    if(visited == nullptr){
        visited = new int[N]();     // All white initially
    }
    stack<int> dfsStack;
    for(int i = 0;i < N; ++i){
        if(visited[i] == 0){
            dfsStack.push(i);
            visited[i] = 1;
        }
        while(true){    // Explore one DFS-tree
            int top = dfsStack.top();
            int temp = dfsStack.size();
            for(auto j: adjList[top]){
                if(visited[j] == 1) return false;   // If gray
                else if(visited[j] == 0){
                    dfsStack.push(j);  // If white
                    visited[j] = 1;
                }
            }
            if(temp == dfsStack.size()){
                while(!dfsStack.empty()){
                    visited[dfsStack.top()] = 2;
                    dfsStack.pop();
                }
                break;
            }
        }
    }
    return true;
}

int main(){
    
}