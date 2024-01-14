class Solution:
    def closeStrings(self, word1: str, word2: str) -> bool:
        if len(word1)!=len(word2):
            return False
        # find the frequencies of each character of word1, word2
        freq1, freq2 = {}, {}
        for i in range(len(word1)):
            keys1 = freq1.keys()
            keys2 = freq2.keys()
            if word1[i] in keys1:
                freq1[word1[i]] += 1
            else:
                freq1[word1[i]] = 1

            if word2[i] in keys2:
                freq2[word2[i]] += 1
            else:
                freq2[word2[i]] = 1
        
        noOfChars1, noOfChars2 = len(freq1), len(freq2)
        if(noOfChars1 != noOfChars2): return False

        # check if the keys of both freqs are same
        for i in freq1.keys():
            if i not in freq2.keys():
                return False

        countOfChars = 0
        for i, j in freq1.items():
            for i2, j2 in freq2.items():
                if(j == j2):
                    freq1[i], freq2[i2] = 0, 0
                    countOfChars += 1
                    # once we get a pair with same values, move on to next pair of freq1
                    break
        if noOfChars1 == countOfChars:
            return True
        else:
            return False
