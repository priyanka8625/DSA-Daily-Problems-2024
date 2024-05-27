class Solution {
public:
    int specialArray(vector<int>& nums) {
        //x must be a value such that there are exact x eles in nums thar are >= x
        //hence x can range between 0 to nums.size() in order to have exact x elements
        sort(nums.begin(), nums.end());
        int start=0, end=nums.size(), x=0;
        while(start <= end){
            x = start + (end-start)/2;
            int count = 0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] >= x)//update no. of >= x elements
                    count++;
            }
            if(count == x)
                return x;
            else if(count > x)//if no. of eles >= x are > x, then we need to make them smaller
                start=x+1;
            else
                end=x-1;
        }
        return -1;
    }
};