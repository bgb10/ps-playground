# 뒤집는게 빈번하기 때문에 시간복잡도가 문제가 있음.
# 따라서 일일이 뒤집는게 아니라, 뒤집은 '효과' 를 내는 것이 필요.
# '양쪽'에서 원소를 뺄 수 있어야 하고, '끝' 에서만 빠지므로 덱을 사용하면 좋겠다.
from collections import deque

n = int(input())

for i in range(n):
    cmd = input()
    k = input()
    el = input()
    el = el[1:-1]
    ellist = el.split(',')
    DQ = deque()
    for els in ellist:
        DQ.append(els)
    reversed = False
    flag = False
    for c in cmd:
        if c == 'R':
            reversed = ~reversed
        else:
            if len(DQ) == 0 or DQ[0] == '':
                print("error")
                flag = True
                break
            else:
                if reversed:
                    DQ.pop()
                else:
                    DQ.popleft()
    if flag:
        continue
    if reversed:
        DQ.reverse()
    ans = list(DQ)
    print('[', end='')
    for idx, x in enumerate(ans):
        print(x, end='')
        if idx != len(ans) - 1:
            print(',', end='')
    print(']')
