d = [0] * 100


def fibo(x):
    global d

    if x == 1 or x == 2:
        return 1

    if d[x] != 0:
        return d[x]
    else:
        d[x] = fibo(x-1) + fibo(x-2)
        return d[x]


# 2^40 가량 연산해야 함 -> dp 사용시 O(N) 으로 줄일 수 있음 (40번 가량 연산)
print(fibo(99))
