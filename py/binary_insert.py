"""
binarily search the inserted element, it will fail, and the final position of low or high is
where it should be inserted
"""

def binsert(element, sorted_arr):
    low, high = 0, len(sorted_arr)

    while(low < high):
        mid = (high + low) // 2
        if element == sorted_arr[mid]:
            return False
        elif element < sorted_arr[mid]:
            high = mid
        else:
            low = mid + 1
    sorted_arr.insert(low, element)
    return sorted_arr

#
print(binsert(3, [1,2,4,5,7,8,10]))
print(binsert(3, [1,2,3,4,5,7,8,10]))
print(binsert(3, [1,2,4,5,6,7,8,9,10,12,19,32]))
print(binsert(3, [1,2]))