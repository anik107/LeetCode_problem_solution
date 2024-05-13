cnt = 0


def mergeSort(arr):
    if len(arr) == 1:
        return

    mid = len(arr) // 2
    leftArray = arr[:mid]
    rightArray = arr[mid:]

    mergeSort(leftArray)
    mergeSort(rightArray)

    global cnt
    i = j = k = 0
    while i < len(leftArray) and j < len(rightArray):
        if leftArray[i] > rightArray[j]:
            cnt += len(leftArray)-1
            arr[k] = rightArray[j]
            j += 1
        else:
            arr[k] = leftArray[i]
            i += 1
        k += 1

    while i < len(leftArray):
        arr[k] = leftArray[i]
        i += 1
        k += 1

    while j < len(rightArray):
        arr[k] = rightArray[j]
        j += 1
        k += 1


if __name__ == "__main__":
    
    t = int(input())
    for t_val in range(t):
        n = int(input())

        arr = input() 
        arr = list(map(int,arr.split(' ')))

        cnt = 0

        mergeSort(arr)

        print(cnt)
