// Approach1:
class Solution {
public:
    bool isPowerOfTwo(int n) {
        //a number is a power of two if it has a single set bit in the binary form 
        //for example : 8 is a power of 2, it has a set bit at power 3-> 1000
        //3->0011-> has two set bits, not a power of 2, but 4 is-> 0100 and so on...

        // extract the bits from binary representation of n and check if it's 0
        //if it's 0, then continue until n becomes 1, hence the binary number is having a single 1, so return true
        //but if before n becomes 1, we get a 1 in between then it's not a power of 2
        if(n<=0)
            return false;
            
        while(n != 1){
            if((n&1) == 1)
                return false;
            n = n>>1;
        }
        return true;
    }
};


// Approach2:
// O(log30)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        int start = 0, end = 30;//int ranges between -2^31 to 2^31-1, but 2^31-1 isn't power of 2, so end will be 30
        int mid, power;
        while(start<=end){
            mid = start + (end-start)/2;
            power = pow(2, mid);
            
            if(power == n)
                return true;
            else if(power < n)//means we should increase the power
                start = mid+1;
            else //it means we should decrease the power
                end = mid-1;
        }
        return false;
    }
};
