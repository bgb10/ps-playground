# 시간복잡도 O(MN - N^2) 풀이

n = int(input())
m = int(input())
s = input()
cnt = 0

p = ""
for i in range(n):
    p += 'IO'
p += 'I'

while 2*n + 1 <= len(s):
    if s.startswith(p):
        cnt += 1
    s = s[1:]

print(cnt)