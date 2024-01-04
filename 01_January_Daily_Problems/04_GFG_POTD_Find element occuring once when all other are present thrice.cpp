class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        unordered_map<int, int> freq;
        for(int i=0; i<N; i++){
            freq[arr[i]]++;
        }
        //now check which number has freq = 1 return it
        int ans=-1;
        for(auto i:freq){
            ans = i.second;//get the count of element in nums
            if(ans == 1){
                return i.first;
            }
        }
        return ans;
    }
};
