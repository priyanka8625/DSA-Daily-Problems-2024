class Solution {
public:
    int climbStairs(int n) {
        //nth stair climbing problem follows fibonnacci series
        // n=2 : steps=2  =>  1 + 1
        // n=3 : steps=3  
        // n=4 : steps=5
        // n=5 : steps=8
        // and so on...
        
        if(n==1)
        //we need just one jump to reach one from one, this is edge case
            return 1;
        
        int n1=1, n2=1, res = n1+n2;
        for(int i=3; i<=n; i++){
            n1 = n2;
            n2 = res;
            res = n1+n2;
        }
        return res;
    }
};