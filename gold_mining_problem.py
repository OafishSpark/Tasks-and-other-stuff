from copy import copy


def gold_mining_problem(time, mines, stock, year_prod, break_prob):
    assert mines != 0, "Wrong input! Number of mines = 0"
    assert time != 0, "Wrong input! Time should be > 0"
    vector = [0] * time
    answer = 0
    if time == 1:
        for i, s, prod, prob in zip(range(mines), stock, year_prod, break_prob):
            temp_val = s * prod * (1 - prob)
            if temp_val > answer:
                answer = temp_val
                vector[-1] = i + 1
        return answer, vector
    else:
        for i, s, prod, prob in zip(range(mines), stock, year_prod, break_prob):
            temp_stock = copy(stock)
            temp_stock[i] = (1 - prod) * s
            temp_val, temp_vec = gold_mining_problem(
                time - 1,
                mines,
                temp_stock,
                year_prod,
                break_prob
            )
            val = (1 - prob) * temp_val + s * prod * (1 - prob)
            if val > answer:
                answer = val
                temp_vec.append(i + 1)
                vector = temp_vec
        return answer, vector


'''
    The input of the task is:
        1st line: t, n                --- number of years and number of mines
        2nd line: A1 A2 ... Ai ... An --- stocks of the mines
        3rd line: X1 X2 ... Xi ... Xn --- doles of the mined gold
        4th line: P1 P2 ... Pi ... Pn --- break probabilities for each mine
'''

if __name__ == "__main__":
    t, n = list(map(int, input().split()))
    a = list(map(float, input().split()))
    assert len(a) == n, "Wrong input! Number of Ai must be equal to n"
    x = list(map(float, input().split()))
    assert len(x) == n, "Wrong input! Number of Xi must be equal to n"
    p = list(map(float, input().split()))
    assert len(p) == n, "Wrong input! Number of Pi must be equal to n"
    value, num_vector = gold_mining_problem(t, n, a, x, p)
    print(value, num_vector)
