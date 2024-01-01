class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        if(nums.size()%2==1) return false;
        
        map<int,int> m;
        for(int i=0; i<nums.size(); i++) 
            m[nums[i]%k]++;
        
        bool ans=true;
        for(int i=1; i<k; i++)  
            if(m[i]!=m[k-i]) {
                ans=false; 
                break;
            }
        
        return ans;
    }
    
};
