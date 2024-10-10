class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        unordered_map<int, int> mp;
        int maxSize=0;
        for(int i=0; i<arr.size(); i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = i;
            }else{
                maxSize = max(maxSize, i - mp[arr[i]]);
            }
        }
        return maxSize;
    }
};