class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        set<int> people;
        int townJudge=-1;
        int size = trust.size();

        //first find that one person who do not trust any one in the vector
        for(int i=0; i<size; i++)
            people.insert(trust[i][0]);
            
        int sumWithoutJudge=0;
        int sumWithJudge = n*(n+1)/2;
        for(int i : people)
            sumWithoutJudge += i;
        townJudge = sumWithJudge - sumWithoutJudge;

        //second, check if the townJudge is trusted by everyone from 1 to n (except townJudge)
        int count=0;
        for(int i=0; i<size; i++){
            if(trust[i][1] == townJudge)
                count++;
        }
        //if count == n-1, it means everybody trusts the townJudge else return -1
        if(count == n-1)
            return townJudge;
        return -1;
    }
};