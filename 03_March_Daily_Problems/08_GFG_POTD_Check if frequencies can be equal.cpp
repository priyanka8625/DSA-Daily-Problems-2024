class Solution{
public:	
	bool sameFreq(string s)
    {
        unordered_map<char, int> freq;
        for(char ch : s){
            freq[ch]++;
        }
        
        unordered_map<int, int> countFreq;
        for(auto it = freq.begin(); it != freq.end(); ++it){
            countFreq[it->second]++;
        }
        
        if(countFreq.size() > 2) // If there are more than 2 different frequencies
            return false;
        
        if(countFreq.size() == 1) // If all frequencies are already equal
            return true;
        
        auto it1 = countFreq.begin();
        auto it2 = ++countFreq.begin();
        
        if((it1->first == 1 && it1->second == 1) || (it2->first == 1 && it2->second == 1)) // If one of the frequencies is only one occurrence
            return true;
        
        if(abs(it1->first - it2->first) > 1) // If the difference between frequencies is more than 1
            return false;
        
        if((it1->second == 1 && (it1->first - it2->first == 1)) || (it2->second == 1 && (it2->first - it1->first == 1))) // If one of the frequencies occurs only once and the other frequency is one more
            return true;
        
        return false;
    }
};