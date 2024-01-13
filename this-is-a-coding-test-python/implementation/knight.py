location = input()
col = ord(location[0]) - ord('a') + 1
row = int(location[1])

ans = 0

# (col, row)
for dcol in [2, -2]:
    for drow in [1, -1]:
        ncol = col + dcol
        nrow = row + drow
        if ncol >= 1 and ncol <= 8 and nrow >= 1 and nrow <= 8:
            ans += 1

# (row, col)
for drow in [2, -2]:
    for dcol in [1, -1]:
        ncol = col + dcol
        nrow = row + drow
        if ncol >= 1 and ncol <= 8 and nrow >= 1 and nrow <= 8:
            ans += 1

print(ans)
