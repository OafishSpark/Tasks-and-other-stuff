def max_sequence(massive):
    answer = 0
    if massive:
        length = len(massive)
        values = []
        for i in range(length):
            t = 0
            for j in range(i):
                if (massive[i] % massive[j] == 0) and (values[j] > t):
                    t = values[j]
            values.append(t + 1)
        for i in range(length):
            if answer < values[i]:
                answer = values[i]
    return answer


if __name__ == "__main__":
    n = int(input())
    mass = list(map(int, input().split()))
    print(max_sequence(mass))
