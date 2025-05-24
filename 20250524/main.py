class Solution(object):
    def findWordsContaining(self, words, x):
        """
        :type words: List[str]
        :type x: str
        :rtype: List[int]
        """
        result = []
        for i, word in enumerate(words):
            if x in word:
                result.append(i)
        return result
    
words = ["hello", "world", "python", "code"]
x = "o"
solution = Solution()
print(solution.findWordsContaining(words, x))
x1 = "z"
print(solution.findWordsContaining(words, x1))
x2 = "h"
print(solution.findWordsContaining(words, x2))