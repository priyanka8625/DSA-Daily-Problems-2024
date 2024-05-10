class Solution{
public:
    vector<vector<int>> CombinationSum2(vector<int> arr,int n,int k)
    {
        //code here
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        vector<int> temp;
        generateSum(arr, n, k, temp, ans, 0);
        return ans;
    }
    void generateSum(vector<int> &arr, int n, int k, vector<int> &temp, vector<vector<int>>& ans, int index){
        //base condns
        if(index == n){//end of array
            if(k == 0)
                ans.push_back(temp);
            return;
        }
        if(k == 0){//subarray sum == k found
            ans.push_back(temp);
            return;
        }
        if(k<0){//it shows there will be no answer
            return;
        }
        
        //at current index in temp, we can take any element of arr
        // such that at current index there should not be repeated element
        for(int i=index; i<n; i++){
            if(i>index && arr[i]==arr[i-1])
                continue;
            temp.push_back(arr[i]);
            generateSum(arr, n, k-arr[i], temp, ans, i+1);
            temp.pop_back();
        }
    }
};