class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        if(n==k) return 0;
        vector<pair<int,int>> prefix;
        vector<pair<int,int>> suffix;
        int maxi=INT_MIN,mini=INT_MAX;
        for(int i=0;i<n-k;i++){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
            prefix.push_back({maxi,mini});
        }
        maxi=INT_MIN;
        mini=INT_MAX;
        for(int i=n-1;i>=k;i--){
            maxi=max(maxi,arr[i]);
            mini=min(mini,arr[i]);
            suffix.push_back({maxi,mini});
        }
        reverse(suffix.begin(),suffix.end());
        int m=suffix.size();
        int ans=suffix[0].first-suffix[0].second;
        for(int i=0;i<m-1;i++)
        {
            maxi=max(suffix[i+1].first,prefix[i].first);
            mini=min(suffix[i+1].second,prefix[i].second);
            ans=min(ans,maxi-mini);
        }
        ans=min(ans,prefix[m-1].first-prefix[m-1].second);
        return ans;
    }
};