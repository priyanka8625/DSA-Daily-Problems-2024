class Solution {
public:
    int findComplement(int num) {
        int mask = 1;
        while((mask&num) != num){
            mask <<= 1;
            mask += 1;
        }
        return (mask ^ num);
    }
};