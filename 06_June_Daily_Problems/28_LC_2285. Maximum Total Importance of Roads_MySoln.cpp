class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        //to get max total importance, we need to assign the maximum values to nodes that have 
        //maximum degrees
        vector<int> degrees(n, 0);
        for(int i=0; i<roads.size(); i++){
            degrees[roads[i][0]]++;
            degrees[roads[i][1]]++;
        }
        //sort degrees 
        sort(degrees.begin(), degrees.end());
        //assign lowest degree will be assigned with lowest value between 1->n
        long long sum=0;
        for(int i=0; i<n; i++){
            sum += (long long)(i+1)*degrees[i];//lowest degree*lowest value => i'th node's contri in total sum
        }
        return sum;
    }
};