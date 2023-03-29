line = list(map(int, input().split()))
k = line[0]
characters = {}
for i in range(k):
    line = input().split(': ')
    characters.update({line[1]: line[0]})
line = input()
code = ''
answer = ''
for char in line:
    code += char
    if characters.get(code):
        answer += characters[code]
        code = ''
print(answer)
