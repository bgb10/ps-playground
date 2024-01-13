N = int(input())
arr = []
for i in range(N):
    arr.append(int(input()))

arr.sort(reverse=True)

for e in arr:
    print(e, end=' ')
