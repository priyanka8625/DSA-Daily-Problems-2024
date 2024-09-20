class Solution {
  public:
    // Returns count buildings that can see sunlight
    int countBuildings(vector<int> &height) {
        // code here
        int maxBuilding = INT_MIN, count=0;
        for(int i=0; i<height.size(); i++){
            if(height[i]>maxBuilding){
                maxBuilding = height[i];
                count++;
            }
        }
        return count;
    }
};