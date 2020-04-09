// For RMQ
class SegTree{
    private:
    int* a;
    int* T; // Main array that stores f(a[l]..a[r])
    int* U;  // Stores whether to update 
    int* V;  // Stores the update values
    int size;
    public:
    SegTree(int N, int* a){
        this->a = a;
        T = new int[4 * N]();
        U = new int[4 * N]();
        V = new int[4 * N]();
        size = N;
        build(a, 0, 0, N - 1);
    }
    void build(int* a, int root, int l, int r){
        if(l > r) return;
        if(l == r){
            // Changeable line
            T[root] = l;
        }
        else{
            build(a, root * 2 + 1, l, (l + r)/ 2);
            build(a, root * 2 + 2, (l + r)/ 2 + 1, r);
            if(a[T[root * 2 + 1]] <= a[T[root * 2 + 2]]){
                T[root] = T[root * 2 + 1];
            }else{
                T[root] = T[root * 2 + 2];
            }
        }
    }
    void update(int root, int x, int l, int r, int i, int j){
        if(i > r || j < l) return;  // No overlap in range
        if(l == r){
            T[root] = l;
            return;
        }
        if(U[root]){ // If previous update is pending
            update(root * 2 + 1, V[root], l, (l + r) / 2, i, j);
            update(root * 2 + 2, V[root],(l + r) / 2 + 1, r, i, j);
            U[root] = 0;
        }
        if(i <= l && r <= j){   // Completely covered
            U[root] = 1;
            V[root] = x;
        }
        else{
            update(root * 2 + 1, x, l, (l + r) / 2, i, j);
            update(root * 2 + 2, x, (l + r) / 2 + 1, r, i, j);
            if(a[T[root * 2 + 1]] <= a[T[root * 2 + 2]]){
                T[root] = T[root * 2 + 1];
            }else{
                T[root] = T[root * 2 + 2];
            }
        }
    }
    void update(int x, int l, int r){
        update(0, x, 0 , size - 1, l , r);
    }
    int query(int root, int l, int r, int i, int j){
        if(i > r || j < l){
            return -1;
        }
        // Check if query pending
        if(U[root]){
            update(root * 2 + 1, V[root], l, (l +r) / 2, i, j);
            update(root * 2 + 2, V[root], (l +r) / 2 + 1, r, i, j);
            U[root] = 0;
        }
        if(i <= l && r <= j){
            return T[root];
        }else{
            int p1 = query(root * 2 + 1, l, (l + r) / 2, i , j);
            int p2 = query(root * 2 + 2, (l + r) / 2 + 1, r, i , j);
            if(a[p1] <= a[p2]){
                return p1;
            }
            return p2;
        }
    }
    int query(int l, int r){
        return query(0, 0, size - 1, l , r);
    }
};