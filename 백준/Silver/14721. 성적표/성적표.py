import sys

input = sys.stdin.readline

n = int(input())
v = [tuple(map(int, input().split())) for _ in range(n)]

rss = 1_000_000_000
a, b = 1, 1

for i in range(1, 101):
    for j in range(1, 101):
        r = 0
        for x, y in v:
            diff = y - (i * x + j)
            r += diff * diff
        if rss > r:
            rss = r
            a, b = i, j

print(a, b)