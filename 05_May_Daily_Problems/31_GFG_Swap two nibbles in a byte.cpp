class Solution {
  public:
    int swapNibbles(int n) {
        // code here
        int left = (n & 0b11110000);
        int right = (n & 0b00001111);
        return (left>>4 | right<<4);
    }
};