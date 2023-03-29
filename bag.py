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
                if second[0][0]/second[0][1] > first[0][0]/first[0][1]:
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


temp_line = input().split()
n = int(temp_line[0])
w = int(temp_line[1])
stuff = []
for i in range(n):
    stuff.append(list(map(int, input().split())))
stuff = mergesort(stuff)
ans = 0.0
while stuff and (w > 0):
    if stuff[-1][1] < w:
        ans += stuff[-1][0]
        w -= stuff[-1][1]
        stuff.pop(-1)
    else:
        ans += stuff[-1][0] / stuff[-1][1] * w
        w -= w
print(f'{ans:.3f}')
