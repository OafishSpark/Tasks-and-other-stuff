def max_non_growing_sequence_slow(massive):
    num = 0
    answer = []
    if massive:
        values = []
        sequence = []
        length = len(massive)
        for i in range(length):
            t = 0
            for j in range(i):
                if (massive[i] <= massive[j]) and (values[j] > t):
                    t = values[j]
            values.append(t + 1)
        temp = 0
        print(values)
        for i in range(length):
            if values[length - 1 - i] > num:
                num = values[length - 1 - i]
                temp = num
                sequence = [length - 1 - i]
            if (values[length - i - 1] == temp - 1) and (massive[length - 1 - i] >= massive[sequence[-1]]):
                sequence.append(length - 1 - i)
                temp -= 1
        print(num)
        print(sequence)
        for i in range(num):
            answer.append(sequence[num - i - 1] + 1)
    return [num, answer]


INF = 10 ** 10


def find_special_place(min_elems, elem, i):
    index = -1
    start = 0
    end = len(min_elems) - 1
    while end - start > 1:
        index = (end + start) // 2
        if (min_elems[index][0] < elem) and (min_elems[index - 1][0] >= elem):
            break
        if min_elems[index - 1][0] >= elem:
            start = index
        if min_elems[index][0] < elem:
            end = index
    min_elems[index] = [elem, i]
    return min_elems[index - 1][1]


def find_last(min_elems):
    for i in range(len(min_elems)):
        if min_elems[i][0] == -INF:
            return [min_elems[i - 1][1], i - 1]
    return [-1, -1]


def max_non_growing_sequence(massive):
    num = 0
    answer = []
    if massive:
        min_elems = []
        for i in range(len(massive) + 2):
            min_elems.append([-INF, -1])
        min_elems[0][0] = INF
        previous_indexes = [-1] * (len(massive))
        for i in range(len(massive)):
            previous_indexes[i] = find_special_place(min_elems, massive[i], i)
        [last, num] = find_last(min_elems)
        answer = [-1] * num
        for i in range(0, num):
            answer[num - i - 1] = last + 1
            last = previous_indexes[last]
    return [num, answer]


if __name__ == "__main__":
    n = int(input())
    mass = list(map(int, input().split()))
    [k, seq] = max_non_growing_sequence(mass)
    print(k)
    ans = list(map(str, seq))
    print(' '.join(ans))
