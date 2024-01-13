import sys
import heapq
input = sys.stdin.readline
INF = int(1e9)

N, M, C = map(int, input().split())

graph = [[] for _ in range(N+1)]
distance = [INF] * (N+1)
visited = [False] * (N+1)

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


def dijkstra(start):
    q = []

    heapq.heappush(q, (0, start))

    while q:
        dist, now = heapq.heappop(q)

        if visited[now]:
            continue

        distance[now] = dist
        visited[now] = True

        for con in graph[now]:
            cost = dist + con[1]
            if cost < distance[con[0]] and not visited[con[0]]:
                distance[con[0]] = cost
                heapq.heappush(q, (cost, con[0]))


dijkstra(C)

cnt = 0
t_max = 0
for i in range(1, N+1):
    if i != C and distance[i] != INF:
        cnt += 1
        t_max = max(t_max, distance[i])

print(cnt, t_max)
