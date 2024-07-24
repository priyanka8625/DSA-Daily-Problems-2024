class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<pair<int, int>> mappedNums;
        for(int i=0; i<n; i++){
            int mappedNum = mapNums(nums[i], mapping);
            mappedNums.push_back({mappedNum, i});
        }
        sort(mappedNums.begin(), mappedNums.end(), [&](pair<int, int> &a, pair<int, int> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            return a.first < b.first;
        });

        for(int i=0; i<n; i++){
            ans.push_back(nums[mappedNums[i].second]);
        }
        return ans;
    }
    int mapNums(int num, vector<int>& mapping){
        if(num==0){
            return mapping[0];
        }
        int power=1, ans=0;
        while(num){
            int last = num%10;
            ans = mapping[last]*power + ans;
            num /=10;
            power*=10;
        }
        return ans;
    }
};