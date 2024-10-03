class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        // Your code goes here.
        map<int, int> freq;
        vector<int> ans;
        int vote = nums.size()/3, n=nums.size();
        sort(nums.begin(), nums.end());
        int len=1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[i-1]){
                len++;
            }else{
                if(len > vote){
                    ans.push_back(nums[i-1]);
                }
                len = 1;
            }
        }
        if(len > vote){
            ans.push_back(nums[n-1]);
        }
        if(ans.size()==0)
            return {-1};
        return ans;
    }
};