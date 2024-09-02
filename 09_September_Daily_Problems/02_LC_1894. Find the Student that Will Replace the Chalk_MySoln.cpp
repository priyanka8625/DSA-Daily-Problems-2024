class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalks = 0;
        for(int ele : chalk){
            totalChalks += ele;
        }
        if(k % totalChalks == 0)
            return 0;

        k %= totalChalks;
        for(int i=0; i<chalk.size(); i++){
            if(chalk[i] > k){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};