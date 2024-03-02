class Solution{
    public:
    int firstElementKTime(int n, int k, int a[])
    {
        map<int, int> freq;
        for(int i=0; i<n; i++){
            freq[a[i]]++;
            if(freq[a[i]] == k)
                return a[i];
        }
        return -1;
    }
};