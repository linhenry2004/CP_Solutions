n = int(input())
cur = n
print(cur, end = ' ')
while cur != 1:
    if cur % 2 == 0:
        cur //= 2
    elif cur % 2 == 1:
        cur *= 3
        cur += 1
    print(cur, end = ' ')