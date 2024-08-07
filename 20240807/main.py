class Solution(object):
    def getString(self,num):
        if num=='0':
            return ""
        elif num=='1':
            return "One "
        elif num=='2':
            return "Two "
        elif num=='3':
            return "Three "
        elif num=='4':
            return "Four "
        elif num=='5':
            return "Five "
        elif num=='6':
            return "Six "
        elif num=='7':
            return "Seven "
        elif num=='8':
            return "Eight "
        elif num=='9' :
            return "Nine "
        else :
            return 'Error getString'

    def getDigitName(self,position):
        if position==7:
            return ""
        elif position==4:
            return "Thousand "
        elif position==1:
            return "Million "
        else :
            return "Error Digit Name"

    def getTenthDigit(self,number):
        if number=='2':
            return "Twenty"
        elif number=='3':
            return "Thirty"
        elif number=='4':
            return "Forty"
        elif number=='5':
            return 'Fifty'
        elif number=='6':
            return 'Sixty'
        elif number=='7':
            return 'Seventy'
        elif number=='8':
            return 'Eighty'
        elif number=='9':
            return 'Ninety'
        elif number=='0':
            return ""
        else :
            return "Error Tenth Digit"

    def getThreeDigits(self,startPosition,numString):
        result=''
        result+=self.getString(numString[startPosition])
        if startPosition==0:
            if numString[startPosition]!='0':
                return result+'Billion '
            return ""
        if numString[startPosition]=='0' and numString[startPosition+1]=='0' and numString[startPosition+2]=='0':
            return ''
        if numString[startPosition]!='0':
            result+='Hundred '
        if numString[startPosition+1]=='1':
            # add eleven, twelve etc.
            lastString=numString[startPosition+2]
            if lastString=='1':
                result+='Eleven '
            elif lastString=='2':
                result+='Twelve '
            elif lastString=='3':
                result+='Thirteen '
            elif lastString=='4':
                result+='Fourteen '
            elif lastString=='5':
                result+='Fifteen '
            elif lastString=='6':
                result+='Sixteen '
            elif lastString=='7':
                result+='Seventeen '
            elif lastString=='8':
                result+='Eighteen '
            elif lastString=='9':
                result+='Nineteen '
            elif lastString=='0':
                result+='Ten '
        else:
            result+=self.getTenthDigit(numString[startPosition+1])
            if numString[startPosition+1]!='0':
                result+=' '
            result+=self.getString(numString[startPosition+2])
        if result!='':
            result+=self.getDigitName(startPosition)
        return result

    def numberToWords(self, num):
        if (num==0):
            return "Zero"
        numString=str(num)
        result=""
        numString=numString.rjust(10,'0')
        result+=self.getThreeDigits(0,numString)
        result+=self.getThreeDigits(1,numString)
        result+=self.getThreeDigits(4,numString)
        result+=self.getThreeDigits(7,numString)
        return result[0:len(result)-1]
    
print(Solution().numberToWords(1000))