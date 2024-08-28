class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
        vector<int> ans;
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>> pq;
        int n=arr.size();
        
        for(int i=0; i<n; i++){
            freq[arr[i]]++;
        }
        for(auto it: freq){
            pq.push({it.second, -it.first});
        }
        
        while(!pq.empty()){
            int ele = -pq.top().second;
            int count = pq.top().first;
            pq.pop();
            
            while(count--)
                ans.push_back(ele);
        }
        return ans;
    }
};