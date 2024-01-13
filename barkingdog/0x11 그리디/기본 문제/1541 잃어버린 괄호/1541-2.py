sum = 0
a = input().split('-', 1)
for i in a[0].split('+'):
    sum += int(i)
if len(a) == 2: # 식에 -가 존재할 때에만
    a[1] = a[1].replace('-', '+')
    for i in a[1].split('+'):
        sum -= int(i)
print(sum)

