class Solution(object):
    
    def validateCode(self, code):
        if not code:
            return False
        for ch in code:
            if ch == '_' or ('a' <= ch <= 'z') or ('A' <= ch <= 'Z') or ('0' <= ch <= '9'):
                continue
            return False
        return True
    
    def validateCoupons(self, code, businessLine, isActive):
        """
        :type code: List[str]
        :type businessLine: List[str]
        :type isActive: List[bool]
        :rtype: List[str]
        """
        n = len(code)
        validBusinessLines = ["electronics", "grocery", "pharmacy", "restaurant"]
        validIDs = []
        for i in range(n):
            if not isActive[i]:
                continue
            if not businessLine[i] in validBusinessLines:
                continue
            if self.validateCode(code[i]):
                validIDs.append(i)
        order = {v: idx for idx, v in enumerate(validBusinessLines)}
        validIDs.sort(key=lambda x: (order[businessLine[x]], code[x]))
        return [code[i] for i in validIDs]
        