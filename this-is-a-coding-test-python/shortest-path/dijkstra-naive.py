import sys
input = sys.stdin.readline
INF = int(1e9)

N, M = map(int, input().split())
start = int(input())
graph = [[] for _ in range(N+1)]
visited = [False] * (N+1)
distance = [INF] * (N+1)

for _ in range(M):
    a, b, c = map(int, input().split())
    graph[a].append((b, c))


def get_closest_node():
    min_idx = 0
    min_val = INF
    for idx in range(1, N + 1):
        if min_val > distance[idx] and not visited[idx]:
            min_val = distance[idx]
            min_idx = idx
    return min_idx


def dijkstra(start):
    global distance, visited

    # 시작 노드에 대해 초기화
    distance[start] = 0
    visited[start] = True

    # 시작 노드와 연결된 노드 거리 갱신
    for con in graph[start]:
        distance[con[0]] = con[1]

    # N - 1 개 노드에 대해 반복
    for _ in range(N - 1):
        # 가장 가까운 노드에 대해 방문 처리
        now = get_closest_node()
        visited[now] = True

        # 가장 가까운 노드를 거쳐가는 거리가 더 가까울 경우 거리 갱신
        for con in graph[now]:
            cost = distance[now] + con[1]
            if cost < distance[con[0]]:
                distance[con[0]] = cost


dijkstra(start)

for i in range(1, N+1):
    if i == start:
        print("START")
    elif distance[i] == INF:
        print("INFINITY")
    else:
        print(distance[i])
