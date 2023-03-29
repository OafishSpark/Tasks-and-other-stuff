def number_of_inversions(mass):
    answer = 0
    length = len(mass)
    if length > 1:
        massive = [[elem] for elem in mass]
        massive.append(False)
        while len(massive) > 2:
            first = massive.pop(0)
            if not first:
                massive.append(False)
                continue
            second = massive.pop(0)
            if not second:
                massive.append(first)
                massive.append(False)
                continue
            temp = []
            while first:
                if second:
                    if second[0] >= first[0]:
                        temp.append(first.pop(0))
                    else:
                        answer += len(first)
                        temp.append(second.pop(0))
                else:
                    temp.extend(first)
                    first = []
            if second:
                temp.extend(second)
            massive.append(temp)
    return answer


'''
n = int(input())
massive = list(map(int, input().split()))
print(number_of_inversions(massive))
'''
# tests


tests = [[[2, 3, 9, 2, 9], 2],
         [[4, 5, 1, 6, 7, 8, 9, 1, 3, 2, 7], 23],
         [[1, 2, 3, 4, 5], 0],
         [[5, 3, 2, 1], 6],
         [[10000], 0],
         [[10000000000 - i for i in range(10000)], 49995000]]

for i in range(len(tests)):
    num_of_inv = number_of_inversions(tests[i][0])
    if tests[i][1] == num_of_inv:
        print(f"Test #{i + 1} passed")
    else:
        print(f"Test #{i + 1} not passed. Got: {num_of_inv}. Needed: {tests[i][1]}.")
