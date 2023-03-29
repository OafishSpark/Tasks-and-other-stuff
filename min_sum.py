a = int(input())
nums = []
temp_num = 0
while a != 0:
    temp_num += 1
    a -= temp_num
    if a < 0:
        nums[-1] = a + temp_num + temp_num - 1
        a = 0
    else:
        nums.append(temp_num)
m = len(nums)
print(m)
ans = ''
for elem in nums:
    ans += str(elem) + ' '
print(ans)
