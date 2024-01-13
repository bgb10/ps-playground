def binary_search(array, target, start, end):
    while start <= end:
        mid = (start + end) // 2
        if array[mid] == target:
            return mid
        elif array[mid] > target:
            end = mid - 1
        else:
            start = mid + 1
    return None


N = int(input())
parts = list(map(int, input().split()))
M = int(input())
find_list = list(map(int, input().split()))
find_list.sort()

for i in find_list:
    idx = binary_search(parts, i, 0, len(parts) - 1)
    if idx == None:
        print("no", end=' ')
    else:
        print("yes", end=' ')
