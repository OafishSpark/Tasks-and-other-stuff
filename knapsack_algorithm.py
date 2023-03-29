def knapsack_algorithm(max_weight, things):
    cost_matrix = []
    number_of_things = len(things)
    for i in range(number_of_things + 1):
        cost_matrix.append([])
        for j in range(max_weight + 1):
            if i == 0:
                cost_matrix[i].append(0)
            elif j == 0:
                cost_matrix[i].append(0)
            elif j < things[i - 1]:
                cost_matrix[i].append(cost_matrix[i - 1][j])
            else:
                cost_matrix[i].append(max(cost_matrix[i - 1][j], cost_matrix[i - 1][j - things[i - 1]] + things[i - 1]))
    return cost_matrix[number_of_things][max_weight]


if __name__ == '__main__':
    [W, n] = list(map(int, input().split()))
    w = list(map(int, input().split()))
    print(knapsack_algorithm(W, w))
