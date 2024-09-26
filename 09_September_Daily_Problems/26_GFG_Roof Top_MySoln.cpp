class Solution {
  public:
    // Function to find maximum number of consecutive steps
    // to gain an increase in altitude with each step.
    int maxStep(vector<int>& arr) {
        // Your code here
        int max_altitude=0, altitude=0;
        int i=1, j=0;
        while(i<arr.size()){
            while(i<arr.size() && arr[i]>arr[i-1]){
                i++;
                j++;
                altitude++;
            }
            max_altitude = max(max_altitude, altitude);
            altitude = 0;
            
            i++;
            j++;
        }
        return max_altitude;
    }
};