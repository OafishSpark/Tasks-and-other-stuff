def ordered_insert(massive, elem):
    if massive:
        first = 0
        last = len(massive) - 1
        if elem < massive[first]:
            massive.insert(0, elem)
        elif elem >= massive[last]:
            massive.insert(len(massive), elem)
        else:
            while last - first > 1:
                if elem >= massive[(last + first) // 2]:
                    first = (last + first) // 2
                else:
                    last = (last + first) // 2
            massive.insert(first + 1, elem)
    else:
        massive.append(elem)


def find_position(massive, elem):
    if massive:
        first = 0
        last = len(massive) - 1
        if elem < massive[first]:
            return 0
        elif elem >= massive[last]:
            return len(massive)
        else:
            while last - first > 1:
                if elem >= massive[(last + first) // 2]:
                    first = (last + first) // 2
                else:
                    last = (last + first) // 2
            return first + 1
    else:
        return 0


def number_of_segments(start_points, end_points, point):
    number_of_start_points = find_position(start_points, point)
    number_of_end_points = find_position(end_points, point - 1)
    return number_of_start_points - number_of_end_points


if __name__ == "__main__":
    line = input().split()
    n = int(line[0])
    m = int(line[1])
    start_points = []
    end_points = []
    for i in range(n):
        temp = list(map(int, input().split()))
        ordered_insert(start_points, temp[0])
        ordered_insert(end_points, temp[1])
    points = list(map(int, input().split()))
    answer = ''
    for point in points:
        answer += str(number_of_segments(start_points, end_points, point)) + ' '
    print(answer)
