class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int> temp;
        return getBeautifulSubsets(nums, k, temp, 0);
    }
    int getBeautifulSubsets(vector<int>& nums, int &k, vector<int>& temp, int index){
        if(index == nums.size()){
            if(temp.size())
                return 1;
            return 0;
        }
        int left=-1, right=-1;
        //not include current index
        left = getBeautifulSubsets(nums, k, temp, index+1);
        //include current index if current element's diff is != k for all eles in temp
        for(int i=0; i<temp.size(); i++){
            if(abs(temp[i]-nums[index]) == k){
                right = 0;
                break;
            }
        }
        if(right != 0){
            temp.push_back(nums[index]);
            right = getBeautifulSubsets(nums, k, temp, index+1);
            temp.pop_back();
        }
        return left + right;
    }
};