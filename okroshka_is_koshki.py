import numpy as np
from copy import deepcopy
from PIL import Image


def okroshka_is_bebsa(imag, n=300, size=150):
    answ = imag.copy()
    answer = answ.load()
    temp = imag.copy()
    px = temp.load()
    for t in range(0, n):
        for i in range(0, size):
            for k in range(0, size):
                answer[(i + k) % size, (i + 2 * k) % size] = px[i, k]
        temp = answ.copy()
        px = temp.load()
    return answ


if __name__ == '__main__':
    my_image = Image.open("000.jpg")
    size = 150
    temp_size = (size, size)
    my_image.thumbnail(temp_size)
    num_of_iters = [1, 2, 132, 155, 200, 240, 275, 299, 300]
    for itr in num_of_iters:
        ans_imag = okroshka_is_bebsa(my_image, itr, size)
        ans_imag.show()
        ans_imag.save(str(itr) + '.png', format='PNG')
