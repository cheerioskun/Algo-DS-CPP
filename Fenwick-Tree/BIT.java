// All indexing is zero based for public functions
public class BIT{
    private int[] tree;
    
    // Construction of the Fenwick Tree -- O(n lg n)
    public BIT(int[] a){
        tree = new int[a.length + 1];
        tree[0] = a.length;
        
        // Initialize the BIT
        int sum = 0;
        for(int i = 1;i <= a.length; ++i){
            int sbit = 0;
            while((i & 1<<sbit) == 0){
                sbit++;
            }
            for(int j = 0;j < (1<<sbit); ++j){
                sum += a[i - 1 - j];
            }
            tree[i] = sum;
        }
    }

    // Calculate sum till index i [0, i] -- O(lg n)
    public int getSum(int i){
        i += 1;
        if(i == 0){     // Selecting nothing
            return 0;
        }
        int sum = 0;
        while(i != 0){
            sum += tree[i];
            i &= (i - 1);   //Remove last setbit - move down the tree
        }
        return sum;
    }

    //Calculate inclusive range sum [a, b] -- O(lg n)
    public int rangeSum(int a, int b){
        return getSum(b) - getSum(a - 1);
    }

    //Updation  -- O(lg n)
    public void update(int i, int delta){
        i += 1;
        while(i <= tree.length){
            tree[i] += delta;
            i +=  i & (~i + 1);
        }
    }
}