class Solution {
public:
    int passThePillow(int n, int time) {
        int passes = time/(n-1);
        return (passes&1)? (n - time%(n-1)) : (1 + (time%(n-1)));
    }
};