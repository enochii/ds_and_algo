def tsearch(key, arr):
    """
    key: the searched value
    arr: the src array

    return: the index if successful else -1
    """
    low = 0
    high = len(arr)
    while low < high:
        per_len = (high - low)//3
        sep1 = per_len + low
        sep2 = per_len + sep1
        
        # if key == arr[sep1]:
        #     return sep1
        if key < arr[sep1]:
            high = sep1
            # continue

        # if key == arr[sep2]:
        #     return sep2
        elif key < arr[sep2]:
            low = sep1
            high = sep2
        else:
            # handle the case per_len = 0..
            if key == arr[sep2]:
                return sep2
            low = sep2 + 1
    return key if low < len(arr) and arr[low] == key else -1

if __name__ == '__main__':
    arr = range(1, 1000)
    print(tsearch(5, arr))
    print(tsearch(39, arr))
    print(tsearch(100, arr))

    for i in range(1, 1000):
        if(tsearch(i, arr) != i - 1):
            print("Error!", i)

