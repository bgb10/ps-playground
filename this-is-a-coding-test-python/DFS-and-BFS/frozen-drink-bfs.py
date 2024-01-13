from collections import deque

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())

board = []
vis = [[False] * M for _ in range(N)]

for _ in range(N):
    board.append(list(map(int, input())))

ans = 0


def flood_fill(x, y):
    global vis
    q = deque()
    q.append((x, y))
    vis[x][y] = True
    while q:
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or nx >= N or ny < 0 or ny >= M:
                continue
            if vis[nx][ny] or board[nx][ny] == 1:
                continue
            vis[nx][ny] = True
            q.append((nx, ny))


for i in range(N):
    for j in range(M):
        if board[i][j] == 0 and not vis[i][j]:
            ans += 1
            flood_fill(i, j)

print(ans)
