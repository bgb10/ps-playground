dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

N, M = map(int, input().split())
x, y, direction = map(int, input().split())
board = []
for i in range(N):
    row = list(map(int, input().split()))
    board.append(row)

vis = [[0] * M for _ in range(N)]
vis[x][y] = 1


def turn_left():
    global direction
    direction -= 1
    if direction == -1:
        direction = 3


count = 1
while True:
    moved = False
    for turn_time in range(4):
        turn_left()
        nx = x + dx[direction]
        ny = y + dy[direction]
        if vis[nx][ny] == 0 and board[nx][ny] == 0:
            x = nx
            y = ny
            vis[nx][ny] = 1
            moved = True
            break
    if moved:
        count += 1
    else:
        nx = x - dx[direction]
        ny = y - dy[direction]
        if board[nx][ny] == 1:
            break
        else:
            x = nx
            y = ny

print(count)
