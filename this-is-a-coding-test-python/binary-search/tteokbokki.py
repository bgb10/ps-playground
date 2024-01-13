def calculate_tteok(array, mid):
    tteok_len = 0
    for i in array:
        tteok_len += i - mid if i > mid else 0
    return tteok_len


def binary_search(array, target, start, end):
    while start < end:
        mid = (start + end + 1) // 2
        tteok_len = calculate_tteok(array, mid)
        if tteok_len >= target:
            start = mid
        else:
            end = mid - 1
    return (start + end + 1) // 2


N, M = map(int, input().split())
rice_cakes = list(map(int, input().split()))

ans = binary_search(rice_cakes, M, 0, 2000000000)
print(ans)
