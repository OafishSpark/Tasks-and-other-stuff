def count_sort(massive, interval):
    counting_mass = dict([[i, 0] for i in range(interval[0], interval[1])])
    for elem in massive:
        counting_mass[elem] += 1
    massive = []
    for k in range(interval[0], interval[1]):
        if counting_mass[k] > 0:
            massive.extend([k for i in range(counting_mass[k])])
    return massive


if __name__ == "__main__":
    n = int(input())
    interval = [0, 10]
    nums = list(map(int, input().split()))
    nums = [(10000 - i) % 10 for i in range(1000)]
    nums = count_sort(nums, interval)
    ans = ''
    for num in nums:
        ans += str(num) + ' '
    print(ans)
