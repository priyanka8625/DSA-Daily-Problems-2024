class Solution {
public:
    int minSteps(string s, string t) {
        //first find the no of occurances of chars in s
        map<int, int> freq;
        for(int i=0; i<s.length(); i++){
            freq[s[i]]++;
        }
        //decrease the value if the same char occurs in t as well
        //if char desn't occurs then also add it to freq, it will indicate the extra chars of t
        for(int i=0; i<t.length(); i++)
            freq[t[i]]--;
        
        int min_steps=0;
        //add up all the values of freq where value>0, cuz =0 indicates exact occurance
        // and -ve value indicates extra elements
        for (auto& [key, value] : freq) {
            if(value>0)
                min_steps += value;
        }
        return min_steps;
    }
};