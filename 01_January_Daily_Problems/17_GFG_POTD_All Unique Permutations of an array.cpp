class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        set<vector<int>> unique;
        permutations(arr, 0, n, unique);
        vector<vector<int>> ans(unique.begin(), unique.end());
        return ans;
    }
    void permutations(vector<int>& arr, int index, int n, set<vector<int>>& unique){
        if(index == n){
            unique.insert(arr);
            return;
        }
        
        //swap arr[i] with i=index to n-1 indices and generate permutation for the next index
        for(int i=index; i<n; i++){
            swap(arr[i], arr[index]);
            permutations(arr, index+1, n, unique);
            swap(arr[i], arr[index]);
        }
    }
};