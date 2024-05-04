class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int weight=0, boats=0;
        //we will use two pointers approach 
        //pair the highest weight with the lowest one and check if it is ==limit
        //if yes we'll increase boat count and search for new pair
        //if no add the heaviest one into a single boat and search the next heaviest for the lowest one
        int left=0, right=people.size()-1;
        sort(people.begin(), people.end());
        while(left < right){
            //if the weihts of two people are <= limit we can add them into a boat
            if(people[left]+people[right] <= limit){
                boats++;
                //search for a new pair
                left++;
                right--;
            }else if(people[left]+people[right] > limit){
                boats++;
                right--;//add right into new boat
            }
        }
        //check if there's still any weight remained in the people
        if(left==right)
            boats++;
        return boats;
    }
};