def find_min_sp(mass):
    minimal_value = mass[0]
    for elem in mass:
        if elem[1] < minimal_value[1]:
            minimal_value = elem
    mass.remove(minimal_value)
    return minimal_value


def get_code_of_char(tree, character):
    answer = ''
    leaf = tree[0]
    if leaf[0] == character:
        return '0'
    while leaf[0] != character:
        if leaf[2][0][0].find(character) != -1:
            leaf = leaf[2][0]
            answer += '1'
        else:
            leaf = leaf[2][1]
            answer += '0'
    return answer


line = input()
characters = {}
for char in line:
    if characters.get(char):
        characters[char] += 1
    else:
        characters.update({char: 1})
# print(characters)
characters_list = []
for key in characters.keys():
    characters_list.append([key, characters.get(key)])
while len(characters_list) > 1:
    min_1 = find_min_sp(characters_list)
    min_2 = find_min_sp(characters_list)
    characters_list.append([min_2[0] + min_1[0], min_1[1] + min_2[1], [min_2, min_1]])
# print(characters_list)
for key in characters.keys():
    char_code = get_code_of_char(characters_list, key)
    characters.update({key: char_code})
# print(characters)
ans = ''
for char in line:
    ans += characters[char]
print(len(characters), len(ans))
for char in characters.keys():
    print(char + ': ' + characters[char])
print(ans)
