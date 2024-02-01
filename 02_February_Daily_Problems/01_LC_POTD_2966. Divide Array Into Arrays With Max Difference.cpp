class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> ans;
        //sort the array so that we can get the minimum difference between the elements of each subarray
        sort(nums.begin(), nums.end());

        vector<int> temp;
        // i will point to the first index of each subarray
        for(int i=0; i<=n-3; i+=3){
            //compare all the differences of the 3 elements in each subarray
            //if any of the 3 abs differences is > k then return []
            //else add them into ans
            int sub1 = abs(nums[i]-nums[i+1]);
            int sub2 = abs(nums[i+1]-nums[i+2]);
            int sub3 = abs(nums[i] - nums[i+2]);
            // if any of the two elements of subarray have diff > k return empty ans
            if(sub1 > k || sub2 > k || sub3 > k){
                vector<vector<int>> empty;
                return empty;
            }else{
                // if it satisfies the difference condition add it
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                ans.push_back(temp);
                //empty the array
                temp.pop_back(); temp.pop_back(); temp.pop_back();
            }
        }
        return ans;
    }
};