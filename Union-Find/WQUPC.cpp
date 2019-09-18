class UF{
    int* id;
    int* sz;
    public:
    UF(int n){
        id = new int[n];
        sz = new int[n];
        for(int i = 0;i < n; ++i){
            id[i] = i;
            sz[i] = 1;
        }
    }
    int root(int p){
        int r = p;
        while(r != id[r]) r = id[r];
        while(p != id[p]){
            int temp = id[p];
            id[p] = r;
            p = temp;
        }
        return r;
    }
    bool connected(int p, int q){
        return root(p) == root(q);
    }
    void Union(int p, int q){
        if(!connected(p, q)){
            int proot = root(p);
            int qroot = root(q);
            if(sz[proot] > sz[qroot]) {
                id[qroot] = proot;
                sz[proot] += sz[qroot];
            }else{
                id[proot] = qroot;
                sz[qroot] += sz[proot];
            }
        }
    }
};