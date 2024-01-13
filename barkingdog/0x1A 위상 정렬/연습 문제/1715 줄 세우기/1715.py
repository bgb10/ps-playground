from collections import deque
import sys

input = sys.stdin.readline

n, m = map(int, input().split())

adjacents = [[] for _ in range(32002)]
indegree = [0 for _ in range(32002)]
ans = []

queue = deque()

for i in range(m):
    a, b = map(int, input().split())
    adjacents[a].append(b)
    indegree[b] += 1
for i in range(n):
    if indegree[i+1] == 0:
        queue.append(i+1)
while len(queue) != 0:
    cur = queue.popleft()
    print(cur, end=' ')
    for adj in adjacents[cur]:
        indegree[adj] -= 1
        if indegree[adj] == 0:
            queue.append(adj)