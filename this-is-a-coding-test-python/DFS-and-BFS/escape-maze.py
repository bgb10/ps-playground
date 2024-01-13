from collections import deque

INF = 999999999
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
board = []
dist = [[INF] * M for _ in range(N)]
for _ in range(N):
    board.append(list(map(int, input())))

dist[0][0] = 1
q = deque()
q.append((0, 0))
while q:
    cx, cy = q.popleft()
    for i in range(4):
        nx = cx + dx[i]
        ny = cy + dy[i]
        if nx < 0 or nx >= N or ny < 0 or ny >= M:
            continue
        if dist[nx][ny] != INF or board[nx][ny] == 0:
            continue
        dist[nx][ny] = dist[cx][cy] + 1
        if (nx, ny) == (N-1, M-1):
            print(dist[nx][ny])
            break
        q.append((nx, ny))
