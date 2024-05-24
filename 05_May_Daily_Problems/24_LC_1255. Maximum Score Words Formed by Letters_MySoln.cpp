class Solution {
private:
    int mp[26] = {0}, subset[26] = {0};
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        for(char ch : letters)
            mp[ch-'a']++;

        //iterate over the power set of words array and get max score8
        return getMaxScore(words, score, 0);
    }
    int getMaxScore(vector<string>& words, vector<int>& score, int index){
        if(index == words.size()){
            //calculate score of the combintion of words i.e. subset
            int sum=0;
            for(int i=0; i<26; i++){
                //if subset any chars which is not in provided letters
                if(subset[i]>mp[i])
                    return 0;
                sum += (score[i] * subset[i]);//add score of all occurances of i
            }
            return sum;
        }

        int left=0, right=0;
        //not include current word
        left = getMaxScore(words, score, index+1);

        //include all chars of current word in subset
        for(char ch : words[index]){
            subset[ch-'a']++;
        }
        right = getMaxScore(words, score, index+1);
        //backtrack
        for(char ch : words[index]){
            subset[ch-'a']--;
        }
        
        return max(left, right);
    }
};