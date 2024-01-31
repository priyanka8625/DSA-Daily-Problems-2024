// Throws TLE for large input 
// not efficient solution 

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> answer(n, 0);
        for(int i=0; i<n-1; i++){
            int noOfDays = 0;
            for(int j=i+1; j<n; j++){
                if(temperatures[j] > temperatures[i]){
                    answer[i] = ++noOfDays;
                    break;
                }else
                    noOfDays++;
            }
        }
        return answer;
    }
};