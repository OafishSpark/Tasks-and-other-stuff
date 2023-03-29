def editing_distance(string_1, string_2):
    d = []
    n = len(string_1)
    m = len(string_2)
    for i in range(n + 1):
        d.append([])
        for j in range(m + 1):
            if i == 0:
                d[i].append(j)
            elif j == 0:
                d[i].append(i)
            else:
                difference = (string_1[i - 1] != string_2[j - 1])
                d[i].append(min(d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + difference))
    return d[n][m]


if __name__ == "__main__":
    str1 = input()
    str2 = input()
    print(editing_distance(str1, str2))
