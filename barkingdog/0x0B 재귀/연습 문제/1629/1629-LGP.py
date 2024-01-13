# 재귀와 분할정복을 이용해 시간복잡도 log 로 감소

def f(a, b, c):
    if b == 1:
        return a % c
    if b % 2 == 1:
        return (f(a, b-1, c) * a) % c
    else:
        k = f(a, b/2, c)
        return (k * k) % c


a, b, c = map(int, input().split())

print(f(a, b, c))
