class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> hash;
        set<int> uniqueNums(hand.begin(), hand.end());
        for(int ele : hand)
            hash[ele]++;
        
        while(!uniqueNums.empty()){
            //get the smallest card 
            auto card = *uniqueNums.begin();
            //get all the unique cards to make group of groupSize
            int k = groupSize;
            while(k != 0 && uniqueNums.count(card)){
                k--;
                //decrease freq of card 
                hash[card]--;
                if(hash[card]==0) //if all occurances of a card are used then erase it from set
                    uniqueNums.erase(card);//to avoid using it repeatitively
                card++;
            }
            if(k != 0){
                //cards can't be rearranged in groupSize 
                return false;
            }
        }
        return true;
    }
};