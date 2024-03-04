class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        //let's sort the given array and apply two pointer technique to find the power
        //we'll compare the power at each step with maxPower 
        sort(tokens.begin(), tokens.end());
        int n=tokens.size(), left=0, right=n-1;
        int maxScore=0, score=0;
        while(left<=right){
            //first check the condition for face up, so that we can increase the current value of score
            if(power >= tokens[left]){
                power -= tokens[left];
                score++;
                left++;
            }
            //second check if the condn for face down is true for right'th element becuase we'll 
            //increase the power with max value of the array at current iteration
            else if(score>=1){
                power += tokens[right];
                score--;
                right--;
            }else{
                //which means both the condn are not satisfied, then we'll break the loop 
                break;
            }
            maxScore = max(maxScore, score);
        }
        return maxScore;
    }
};