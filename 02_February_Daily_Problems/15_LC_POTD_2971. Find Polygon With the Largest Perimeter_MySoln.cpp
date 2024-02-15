class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long perimeter=-1;
        int n = nums.size();
        
        //sort nums
        sort(nums.begin(), nums.end());
        long long sum = nums[0]+nums[1];
        int j=2;
        while(j<n){
            if(sum>nums[j]){
                //then get the perimeter updated if needed
                sum += nums[j];
                perimeter = max(perimeter, sum);
                j++;
            }else{
                //add current j to sum so that we can get a larger sum
                sum += nums[j];
                j++; //move to j+1
            }
        }
        return perimeter;
    }
};