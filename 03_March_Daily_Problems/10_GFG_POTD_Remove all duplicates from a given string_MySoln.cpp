class Solution{
public:
	string removeDuplicates(string str) {
	    // code here
	    //let's create a map to keep tract no of occurances of each character in string
	    unordered_map<char, int> freq;
	    string res="";
	    for(char ch: str){
	        freq[ch]++;
	        if(freq[ch]==1){
	            //if it's occuraing only 1 time
	            //for the first time when any char occurs it's value in map will be 1, hence the first occurance 
	           // will always get inserted into res, but for the next occurances res won't hold such characters
	           res += ch;
	        }
	    }
	    return res;
	}
};