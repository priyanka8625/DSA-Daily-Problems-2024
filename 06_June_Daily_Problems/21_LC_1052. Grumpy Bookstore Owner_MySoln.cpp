class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int total=0;
        int start=0, end=0, n=customers.size();
        for(int i=0; i<n; i++){
            total += (grumpy[i]==0)? customers[i]:0;
        }
        //analyze the maximum customers we can get on minutes consecutive for grumpy == 1
        int grumpySum=0, sum=0;
        for(int i=0; i<minutes; i++){
            grumpySum += (grumpy[i]==1)? customers[i]:0;
        }
        end = minutes;
        sum = grumpySum;
        while(end<n){
            //get grumpy sum of window from start+1->end
            if(grumpy[start]==1)
                sum -= customers[start];
            if(grumpy[end]==1)
                sum += customers[end];
            grumpySum = max(sum, grumpySum);
            //move window to next minutes consecutive subarray
            start++;
            end++;
        }
        //max satisfied customers will be total non-grumpy + max grumpy
        return total+grumpySum;
    }
};