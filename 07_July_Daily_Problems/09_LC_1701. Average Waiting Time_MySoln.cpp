class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double sum=0;
        int currTime=0;
        for(int i=0; i<customers.size(); i++){
            if(customers[i][0]>currTime)
                currTime = customers[i][0];
            //calculate the timestamp at which i will recieve it's order
            currTime += customers[i][1];
            //get waiting time
            sum += (currTime-customers[i][0]);
        }
        return (sum/customers.size());
    }
};