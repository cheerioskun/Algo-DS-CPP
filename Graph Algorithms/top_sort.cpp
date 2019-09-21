#include<bits/stdc++.h>
using namespace std;


vector<int> topSort(set<int>* adjList, int N){
    // Kahn's algorithm -- returns empty vector if not a DAG
    vector<int> finalOrder;
    int indegree[N] = {};
    // Calculate in-degrees
    for(int i = 0;i < N; ++i){
        for(auto j: adjList[i]){
            indegree[j]++;
        }
    }
    queue<int> processing;
    // Push all vertices with indegree 0 i.e. no dependency
    for(int i = 0;i < N; ++i){
        if(indegree[i] == 0){
            processing.push(i);
        }
    }
    while(!processing.empty()){
        int current = processing.front();
        processing.pop();
        finalOrder.push_back(current);
        for(auto j: adjList[current]){
            indegree[j]--;
            if(indegree[j] == 0){
                processing.push(j);
            }
        }
    }
    return finalOrder;

}


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
    int N, M;  //N = V number of vertices M = |E| number of edges
    cin>>N>>M;
    set<int> adjList[N];
    int u, v;
    for(int i = 0;i < M; ++i){
        cin>>u>>v;
        u--;v--;
        adjList[u].insert(v);
    }
    vector<int> order = topSort(adjList, N);
    if(!order.empty()){
        for(auto i: order){
           cout<<i+1<<" ";
        }
    }else{
        cout<<"Sandro fails.";
    }
    
    cout<<endl;
}