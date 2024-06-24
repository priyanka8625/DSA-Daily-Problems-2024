class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        //we found this pattern
        if(q>n*2 || q==1) return 0;
        if(q<=n){
            return (q-1)%n;
        }
        else{
            return n-(q-1)%n;
        }
    }
};