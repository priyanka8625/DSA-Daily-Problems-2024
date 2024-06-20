class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int start=1, end=0, mid=0, ans=0, n=position.size();
        for(int i: position)
            end = max(end, i);
        
        while(start<=end){
            mid = start + (end-start)/2;
            //check if we can place all the m balls at distance of atleast mid
            int noOfBalls=1, i=1, basket=position[0];
            while(i<n){
                //find next basket at a distance of atleast mid
                if(position[i]-basket >= mid){
                    noOfBalls++;
                    basket = position[i];
                }
                i++;
            }
            if(noOfBalls >= m){
                ans = mid;
                start = mid + 1;//try to get maximum distance to place balls
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};