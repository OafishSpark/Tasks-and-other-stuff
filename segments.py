def mergesort(mass):
    massive = mass
    size = len(massive)
    if size >= 2:
        first = []
        second = []
        for i in range(size):
            if i < size // 2:
                first.append(massive[i])
            else:
                second.append(massive[i])
        first = mergesort(first)
        second = mergesort(second)
        answer = []
        while first:
            if second:
                if second[0][1] > first[0][1]:
                    answer.append(first.pop(0))
                else:
                    answer.append(second.pop(0))
            else:
                answer.append(first.pop(0))
        if second:
            answer.extend(second)
    else:
        answer = massive
    return answer


n = int(input())
segments = []
for k in range(n):
    temp = list(map(int, input().split()))
    segments.append(temp)
segments = mergesort(segments)
print(segments)
points = [segments[0][1]]
for segment in segments:
    if segment[0] > points[-1]:
        points.append(segment[0])
m = len(points)
print(m)
ans = ''
for point in points:
    ans += str(point) + ' '
print(ans)
