class Solution(object):
    def vowelStrings(self, words, queries):
        """
        :type words: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        n = len(words)
        qn = len(queries)
        vowels = ['a','e','i','o','u']
        cumSum = [0] * n
        result = [0] * qn
        if words[0][0] in vowels and words[0][-1] in vowels:
            cumSum[0] = 1
        else:
            cumSum[0] = 0
        for i in range(1,n):
            cumSum[i] = cumSum[i - 1]
            if (words[i][0] in vowels) and (words[i][-1] in vowels):
                cumSum[i] += 1
        for i in range(qn):
            result[i] = cumSum[queries[i][1]] - cumSum[queries[i][0]]
            if (words[queries[i][0]][0] in vowels) and (words[queries[i][0]][-1] in vowels):
                result[i] += 1
        return result
