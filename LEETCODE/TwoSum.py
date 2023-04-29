

def twoSum(nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        
        myList = list()
        myDict = dict()
        index = 0
        
        for int in nums:
            if int not in myDict:
                myDict[int] = index
                index += 1
            else:
                myDict[int] = [myDict[int], index]
                index += 1
            
        for int in nums:
            complement = target - int
            
            if complement in myDict and type(myDict[int]) is list:
                myList.extend(myDict[int])
                break
            
            if complement in myDict and myDict[int] != myDict[complement]:
                myList.append(myDict[int])
                myList.append(myDict[complement])
                break
    
        return myList

myNumbers = [3, 3]
target = 6
print(twoSum(myNumbers, target))