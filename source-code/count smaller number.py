from sortedcontainers import SortedList, SortedSet, SortedDict 

nums = [1,9,7,8,5]

res, arr = [], SortedList()

for val in reversed(nums):
    idx = arr.bisect_left(val)
    arr.add(val)
    res.append(idx)
print(list(reversed(res)))