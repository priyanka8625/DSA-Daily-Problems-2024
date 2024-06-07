class Solution {
  public:
    // l and r are input array
    // maxx : maximum in r[]
    // n: size of array
    // arr[] : declared globally with size equal to maximum in l[] and r[]
    // Function to find the maximum occurred integer in all ranges.
    int maxOccured(int n, int l[], int r[], int maxx) {        
        vector<int>temp(maxx+2,0);
        for(int i=0;i<n;i++)
        {
            temp[l[i]]++;
            temp[r[i]+1]--;
        }
        int count=0;
        for(int i=0;i<=maxx;i++)
        {
            count+=temp[i];
            temp[i]=count;
        }
        int ans,maxr=0;
        for(int i=0;i<=maxx;i++)
        {
            if(temp[i]>maxr)
            {
                ans=i;
                maxr=temp[i];
            }
        }
        return ans;
    }
};