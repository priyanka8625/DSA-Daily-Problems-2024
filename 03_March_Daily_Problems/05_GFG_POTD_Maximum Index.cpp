class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) 
    { 
        // Your code here
         vector<pair<int, int>> v;
        for(int i=0; i<n; i++){
            v.push_back({a[i], i});
        }
        sort(v.begin(), v.end());
        
        int max_i = v[n-1].second;
        int diff = 0;
        
        for(int i = n-2; i>=0; i--){
            max_i = max(max_i, v[i+1].second);
            diff = max(diff, max_i - v[i].second);
        }
        
        return diff;
    }
};