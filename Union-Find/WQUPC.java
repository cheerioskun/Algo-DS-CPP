// Weighted quick union union-find with path compression

public class WQUPC {
    private final int[] id;
    private final int[] sz;

    // Initialization -- O(n)
    public WQUPC(int n) {
        if (n <= 0) {
            throw new IllegalArgumentException("Trying to initialize UF with non-positive size");
        }
        id = new int[n];
        sz = new int[n];
        for (int i = 0; i < n; ++i) {
            id[i] = i;
            sz[i] = 1;
        }
    }

    // Root-finding and path compression -- O(lg n)
    private int root(int p) {
        if (p <= 0 || p >= id.length) {
            throw new IllegalArgumentException("p does not exist in the data structure");
        }
        int r = p;
        // Find root
        while (r != id[r]) {
            r = id[r];
        }
        // Compress path
        while (p != id[p]) {
            int temp = id[p];
            id[p] = r;
            p = temp;
        }
        return r;
    }

    // Union operation -- O(lg n)
    public void union(int p, int q) {
        if (p <= 0 || p >= id.length || q <= 0 || q >= id.length) {
            throw new IllegalArgumentException("Either p or q does not exist in the data structure");
        }
        int proot = root(p);
        int qroot = root(q);
        if (proot != qroot) {
            // If p belongs to bigger tree then link q to p
            if (sz[proot] > sz[qroot]) {
                id[qroot] = proot;
                sz[proot] += sz[qroot];
            } else {
                id[proot] = qroot;
                sz[qroot] += sz[proot];
            }
        }
    }

    // Find operation -- O(lg n)
    public boolean connected(int p, int q) {
        if (p <= 0 || p >= id.length || q <= 0 || q >= id.length) {
            throw new IllegalArgumentException("Either p or q does not exist in the data structure");
        }
        return (root(p) == root(q));
    }

    // To find the size of the DS
    public int count() {
        return id.length;
    }

}