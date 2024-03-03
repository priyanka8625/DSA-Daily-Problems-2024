class Solution{ 
public:
	// The main function that returns the arrangement with the largest value as
	// string.
	// The function accepts a vector of strings
	string printLargest(int n, vector<string> &arr) {
	    // code here
	    sort(arr.begin(), arr.end(), compareStrings);
	    string res="";
	    for(int i=0; i<n; i++){
	        res += arr[i];
	    }
	    return res;
	}
	//comparator for sorting
	static bool compareStrings(string &s1, string& s2){
	    string temp1 = s1 + s2;
	    string temp2 = s2 + s1;
	    return temp1>temp2;
	}
};