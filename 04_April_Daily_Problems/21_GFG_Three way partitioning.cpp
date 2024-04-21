class Solution{   
public:
    void threeWayPartition(vector<int>& array, int a, int b) {
        int n = array.size();
        int i = 0, j = n - 1;
        int curr = 0; // current index to traverse array
        
        while (curr <= j) {
            if (array[curr] < a) {
                swap(array[curr], array[i]);
                i++;
                curr++;
            } else if (array[curr] > b) {
                swap(array[curr], array[j]);
                j--;
            } else {
                curr++;
            }
        }
    }
};
