class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int differentBits=0, xorSum=0;
        for(int i:nums)
            xorSum ^= i;
        if(k == xorSum)
            return differentBits;//i.e. 0
        
        //else find the number of different bits in xor and k
        while(k || xorSum){
            int bit1 = k&1;
            int bit2 = xorSum&1;
            if(bit1 != bit2)//if both the correspndng bits are unequal, we need to incremen the count
                differentBits++;
            k>>=1;
            xorSum>>=1;
        }
        
        return differentBits;
    }
};