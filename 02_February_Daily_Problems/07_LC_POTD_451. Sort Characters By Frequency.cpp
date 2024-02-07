class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        multimap<int, char> multikeys;
        string result="";

        //count freq of each character
        for(char ch: s)
            freq[ch]++;
        
        //now convert the map into multimap 
        // Use a multimap r to associate each character with its frequency. 
        // The multimap allows multiple elements with the same key (frequency) 
        // and automatically sorts them in ascending order based on the key.
        for(auto pair : freq)
            multikeys.insert({pair.second, pair.first});
        
        //now insert the strings having the most freq count in result string
        //start from the end and go the begin as multimap inserts keys in ascending orders
        for(auto it=multikeys.rbegin(); it!= multikeys.rend(); it++)
            result += string(it->first, it->second);
        
        return result;
    }
};

// what is a multimap???
// Multimap is similar to a map with the addition that multiple elements can have the same keys. 
// Also, it is NOT required that the key-value and mapped value pair have to be unique in this case. 
// One important thing to note about multimap is that multimap keeps all the keys in sorted order always. 
// These properties of multimap make it very much useful in competitive programming.