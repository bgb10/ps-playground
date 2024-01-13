N = int(input())
parts = [0] * 1000000

for i in input().split():
    parts[int(i)] = 1

M = int(input())
find_list = list(map(int, input().split()))

for i in find_list:
    if parts[i] == 1:
        print('yes', end=' ')
    else:
        print('no', end=' ')
