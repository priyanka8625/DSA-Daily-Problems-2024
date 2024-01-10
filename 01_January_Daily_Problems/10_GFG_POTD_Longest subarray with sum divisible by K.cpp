class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
    {
       vector<int> mp(k,-2);
       mp[0] = -1;
    /*initialise from -1 as rem=0 counts one element*/
       int sum = 0;
       int ans = 0;
       for(int i=0;i<n;i++)
       {
           sum += arr[i];
           sum = sum%k; //Taking reaminder of the sum
           
           if(sum<0)
           sum += k;
           
           if(mp[sum]!=-2)
           {
               ans = max(ans,i-mp[sum]);
           }
           else 
           mp[sum] = i;
       }
       return ans;
    }
};