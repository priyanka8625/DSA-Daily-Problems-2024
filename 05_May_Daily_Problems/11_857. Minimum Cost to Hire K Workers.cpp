class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        //create a vector to store wage/quality ratio and index 
        vector<pair<double, int>> ratio;
        int n = quality.size();
        
        for (int i = 0; i < n; ++i) {
            ratio.push_back(make_pair(((double)wage[i]/quality[i]), i));
        }
        // sort the vector according to wage/quality ratio
        sort(ratio.begin(), ratio.end());
        //create a maxheap to store the max quality so far
        priority_queue<int> maxHeap;
        int qualitySum = 0;//this stores the sum of qualities of k workers
        double maxRate = 0.0;//to store max ratio rate from the priority queue
        
        //get the sum of quality of first k workers who have minimum wage/quality ratio
        for (int i = 0; i < k; ++i) {
            double currRatio = ratio[i].first;
            int index = ratio[i].second;
            qualitySum += quality[index];
            maxRate = max(maxRate, currRatio);
            maxHeap.push(quality[index]);
        }

        double res = maxRate * qualitySum;
        for (int i = k; i < n; ++i) {
            double currRatio = ratio[i].first;
            int index = ratio[i].second;

            //update maxRate with maximum ratio till now
            maxRate = max(maxRate, currRatio);
            //remove the max quality from qualitySum and pq
            qualitySum -= maxHeap.top(); 
            maxHeap.pop();
            
            //update qualitySum with current quality and push it into maxHeap
            qualitySum += quality[index];
            maxHeap.push(quality[index]);

            //store the minimum result
            res = min(res, maxRate * qualitySum);
        }

        return res;
    }
};