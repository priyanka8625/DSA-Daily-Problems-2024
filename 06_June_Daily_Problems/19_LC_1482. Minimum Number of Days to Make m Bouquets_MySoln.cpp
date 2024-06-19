class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
         if(bloomDay.size() < (long)m*k) return -1;

         int n=bloomDay.size();
         int start = INT_MAX, end=INT_MIN, mid=0, ans=-1;
         for(int i=0; i<n; i++){
            start = min(start, bloomDay[i]);
            end = max(end, bloomDay[i]);
         }
         while(start<=end){
            mid = start + (end-start)/2;
            //check if you can complete m bouquets in mid no. days
            int bouquets=0, flowers=0;
            for(int i=0; i<n; i++){
                if(bloomDay[i]<=mid){
                    flowers++;
                }else{
                    flowers=0;
                }
                if(flowers==k){
                    bouquets++;
                    flowers=0;
                }
            }
            if(bouquets>=m){
                ans = mid;
                end = mid-1;
            }else{
                start = mid+1;
            }
         }
         return ans;
    }
};