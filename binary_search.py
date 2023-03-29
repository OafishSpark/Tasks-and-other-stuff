def binary_search(massive, elem, length):
    index = -1
    first = 0
    last = length - 1
    while last - first > 1:
        if massive[last] == elem:
            index = last + 1
            break
        elif massive[first] == elem:
            index = first + 1
            break
        elif massive[(last + first) // 2] < elem:
            first = (last + first) // 2
        elif massive[(last + first) // 2] > elem:
            last = (last + first) // 2
        elif massive[(last + first) // 2] == elem:
            index = (last + first) // 2 + 1
            break
        else:
            break
    return index


line = list(map(int, input().split()))
n = line[0]
array = line[1:]
line = list(map(int, input().split()))
k = line[0]
answer = ''
for i in range(1, k + 1):
    answer += str(binary_search(array, line[i], n)) + ' '
print(answer)
