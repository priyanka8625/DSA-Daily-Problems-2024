class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count=0, diff=0;
        diff = start ^ goal;
        while(diff){
            count += diff&1;
            diff>>=1;
        }
        return count;
    }
};