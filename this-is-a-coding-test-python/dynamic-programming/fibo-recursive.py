def fibo(x):
    if x == 1 or x == 2:
        return 1
    else:
        return fibo(x-1) + fibo(x-2)


# 2^40 가량 연산해야 함 -> dp 사용시 O(N) 으로 줄일 수 있음 (40번 가량 연산)
print(fibo(40))
