class Solution {
  public:
    long long reversedBits(long long x) {
        // code here
        long long power = pow(2, 31), reverse=0;
        while(x){
            int digit = x&1;
            reverse += digit * power;
            power>>=1;
            x>>=1;
        }
        return reverse;
    }
};