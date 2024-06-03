class Solution {
  public:
    int mod = 1e9 + 7;
    int numberOfConsecutiveOnes(int n) {
        // code here
        // The series is 0, 1, 3, 8, 19, 43, 94 ...
        // n = 2: 2 * 0  + 1 = 1
        // n = 3: 2 * 1  + 1 = 3
        // n = 4: 2 * 3  + 2 = 8
        // n = 5: 2 * 8  + 3 = 19
        // n = 6: 2 * 19 + 5 = 43
        // n = 7: 2 * 43 + 8
        
        long long prevPrev=0, prev=1, prevAns=1, add=0;
        for(int i=3; i<=n; i++){
            add = (prevPrev + prev)%mod;
            prevAns = (2 * prevAns + add)%mod;
            
            prevPrev = prev;
            prev = add;
        }
        return (int)prevAns%mod;
    }
};