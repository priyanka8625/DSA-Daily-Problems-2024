
class Solution {
  public:
    long long findNth(long long n) {
        // code here.
        long long ans=0, power=1;
        //convert in base 9 integer like we do in other base
        //for ex: base 2 to convert 4 which is given in base 10
        //base 10 to 2 will be: 1*10^2 + 0*10^1 + 0*10^0
        //base 10 to 8 will be: 4*10^0
        while(n){
            int remainder = n%9;
            ans = remainder*power + ans;
            n /= 9;
            power *= 10;
        }
        return ans;
    }
};