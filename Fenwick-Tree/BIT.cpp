class Fenwick{
    private:
    long long int* a;
    int size;
    public:
    Fenwick(int n){
        a = new long long int[n + 1]();
        size = n;
    }
    Fenwick(int n, int* arr){
        a = new long long int[n + 1]();
        size = n;
        for(int i = 1;i < n + 1; ++i){
            int ssb = 0;
            while(!(i & (1<<ssb))) ssb++;
            int k = (1 << ssb);
            while(k){
                a[i] += arr[i - k];
                k--;
            }
        }
    }
    void increase(int pos, int val){
        pos++;
        if(pos > size) return;
        while(pos <= size){
            a[pos] += val;
            pos += pos - (pos & (pos - 1));
        }
    }
    long long int sum(int i){
        long long int ans = 0;
        int x = i;
        while(x != 0){
            ans += a[x];
            x &= (x - 1);
        }
        return ans;
    }
    long long int rsq(int i, int j){
        i++;
        j++;
        if(i > j) return -1;
        return sum(j) - sum(i - 1);
    } 
    
};
