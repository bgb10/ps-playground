N = int(input())
students = []

for i in range(N):
    students.append(input().split())

ans = sorted(students, key=lambda s: s[1])

for e in ans:
    print(e[0], end=' ')
