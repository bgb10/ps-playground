N = int(input())
parts = set(map(int, input().split()))

M = int(input())
find_list = list(map(int, input().split()))

for i in find_list:
    if i in parts:
        print('yes', end=' ')
    else:
        print('no', end=' ')
