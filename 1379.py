n = int(input())
class_time = []

for _ in range(n):
    e, t1, t2 = map(int, input().split())
    class_time.append([e, t1, t2])

class_time.sort(key=lambda x: x[1])
end_time = [0] * (n+1)
ret = [0] * (n+1)

for i in class_time:
    e, t1, t2 = i
    idx = 1
    while idx <= n and end_time[idx] > t1:
        idx += 1

    end_time[idx] = t2

    ret[e] = idx

max_idx = 0
for idx in ret:
    if idx > max_idx:
        max_idx = idx

print(max_idx)












for i in range(1, n+1):
    print(ret[i])
