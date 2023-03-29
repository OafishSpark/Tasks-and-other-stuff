from copy import copy


def plane_problem(num_of_items, plain_volume, plain_weight, item_volumes, item_weights, item_costs):
    assert num_of_items != 0, "Wrong input! Number of items = 0"
    vector = [0] * num_of_items
    max_value = 0
    if num_of_items == 1:
        vector[0] = min((plain_volume // item_volumes[0]), (plain_weight // item_weights[0]))
        max_value = item_costs[0] * vector[0]
        return max_value, copy(vector)
    else:
        num_of_last_item = min((plain_volume // item_volumes[-1]), (plain_weight // item_weights[-1]))
        for i in range(0, num_of_last_item + 1):
            bellman_func_val, temp_vector = plane_problem(
                num_of_items - 1,
                plain_volume - i * item_volumes[-1],
                plain_weight - i * item_weights[-1],
                item_volumes[:-1],
                item_weights[:-1],
                item_costs[:-1]
            )
            temp_val = item_costs[-1] * i + bellman_func_val
            if temp_val > max_value:
                max_value = temp_val
                temp_vector.append(i)
                vector = copy(temp_vector)
        return max_value, vector


'''
    The input of the task is:
        1st line: n V W                 --- number of things; maximum value; maximum weight
        2nd line: V1 V2 ... Vi ... Vn   --- values of things
        3rd line: W1 W2 ... Wi ... Wn   --- weights of things
        4th line: C1 C2 ... Ci ... Cn   --- costs of things
'''

if __name__ == "__main__":
    n, V, W = list(map(int, input().split()))
    v = list(map(int, input().split()))
    assert len(v) == n, "Wrong input! Number of Vi must be equal to n"
    w = list(map(int, input().split()))
    assert len(w) == n, "Wrong input! Number of Wi must be equal to n"
    c = list(map(int, input().split()))
    assert len(c) == n, "Wrong input! Number of Ci must be equal to n"
    value, num_vector = plane_problem(n, V, W, v, w, c)
    print(value, num_vector)
