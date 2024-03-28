class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int i=0, j=0, n=nums.size();
        int maxLen=INT_MIN, len=0;
        while(i<=j && j<n){
            freq[nums[j]]++;//increase the freq of j'th ele
            if(freq[nums[j]] <= k){
                //store the length of the subarray 
                maxLen = max(maxLen, (j-i)+1);
                //move j to next element
                j++;
            }else{
                //we will move i forward and decrese i'th freq by 1
                freq[nums[i]]--;
                i++;
                //and keep j at the same index 
                freq[nums[j]]--;
            }
        }
        return maxLen;
    }
};