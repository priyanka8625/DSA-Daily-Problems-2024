class Solution {
public:
    bool judgeSquareSum(int c) {
        long long start=0, end = sqrt(c);
        long long sum=0;
        while(start<=end){
            sum = (start*start) + (end*end);
            if(sum == c){
                return true;
            }else if(sum < c)
                start ++;
            else
                end --;
        }
        return false;
    }
};