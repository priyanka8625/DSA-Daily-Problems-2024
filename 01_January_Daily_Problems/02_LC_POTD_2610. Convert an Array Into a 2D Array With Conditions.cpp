class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        map<int, int> count;
        //sort the given nums
        sort(nums.begin(), nums.end());
        //take the maximum occurance of any element in the array
        int rowCount = 0, count=0, i=0, j=0;
        while(j<n && i<=j){
            if(nums[i] == nums[j]){
                count++;
                j++;
            }else{
                rowCount = max(rowCount, count);
                count=0;
                i=j;
            }
            if(j==n && count>rowCount)
                rowCount = count;

            for(int i=0; i<rowCount; i++){
                for(int j=0; j<n-1; j++){
                    if(nums[j] != nums[j+1])
                        temp.push_back(nums[j]);
                }
                //insert last element
                temp.push_back(nums[])
            } 
        }
    }
};
