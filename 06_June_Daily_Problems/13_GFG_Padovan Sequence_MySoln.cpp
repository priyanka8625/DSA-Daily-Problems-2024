class Solution {
  public:
    int padovanSequence(int n) {
        // code here.
        if(n <= 2)
            return 1;
            
        int n0=1, n1=1, n2=1, curr=0, mod=1e9+7;
        for(int i=3; i<=n; i++){
            curr = (n1 + n0)%mod;
            //update the padovan seq
            n0 = n1;
            n1 = n2;
            n2 = curr;
        }
        return curr;
    }
};