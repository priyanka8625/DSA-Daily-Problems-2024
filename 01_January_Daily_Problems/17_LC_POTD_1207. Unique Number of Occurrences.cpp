class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> occurances;
        int n = arr.size();
        sort(arr.begin(), arr.end());
        //get occurances of each arr[i]
        int count=1;
        for(int i=0; i<n-1; i++){
            if(arr[i] == arr[i+1])
                count++;
            else{
                occurances.push_back(count);
                count = 1;
            }
        }
        //add count of last element
        occurances.push_back(count);

        sort(occurances.begin(), occurances.end());
        for(int i=0; i<occurances.size()-1; i++){
            if(occurances[i] == occurances[i+1])
                return false;
        }
        return true;
    }
};