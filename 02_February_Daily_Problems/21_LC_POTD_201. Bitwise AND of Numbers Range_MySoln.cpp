class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right)
            return left;

            
        int ans=left;
        for(long i=left+1; i<=right; i++){
            ans &= i;
            if(ans == 0)
                return 0;
        }
        return ans;
    }
};