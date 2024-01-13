N = int(input())
plan = input().split()
location = [1, 1]

for dir in plan:
    if dir == 'L':
        location[1] = location[1] - 1 if location[1] > 1 else location[1]
    elif dir == 'R':
        location[1] = location[1] + 1 if location[1] < N else location[1]
    elif dir == 'U':
        location[0] = location[0] - 1 if location[0] > 1 else location[0]
    elif dir == 'D':
        location[0] = location[0] + 1 if location[0] < N else location[0]

print(location)
