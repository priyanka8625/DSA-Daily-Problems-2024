
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int, int>> meetings(n);
        for(int i=0; i<n; i++){
            meetings[i] = {end[i], start[i]};
        }
        sort(meetings.begin(), meetings.end());
        int ans=1;
        int prevEnd = meetings[0].first;
        for(int i=1; i<n; i++){
            if(prevEnd<meetings[i].second){
                ans++;
                prevEnd = meetings[i].first;
            }
        }
        return ans;
    }
};