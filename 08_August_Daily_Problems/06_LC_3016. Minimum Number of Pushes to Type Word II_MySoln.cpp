class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for(char ch : word)
            freq[ch-'a']++;

        //sort freq in descending order of characterfrequency
        sort(freq.rbegin(), freq.rend());

        int pushCount=0, keyIndex=2, charPosition=1, i=0;
        while(i<26){
            if(freq[i]!=0){
                pushCount += (freq[i]*charPosition);
                keyIndex++;
                if(keyIndex==10){
                    keyIndex=2;
                    charPosition++;
                }
            }
            i++;
        }
        return pushCount;
    }
};