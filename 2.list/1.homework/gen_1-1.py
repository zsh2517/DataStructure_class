import random

x = input("input size: ") # 5
# option = input("1: incremental then decremental\n2: decremental then incremental")
pos = input("the the smallist/largist one's position. (first is 0)")
pos = int(pos)
x = int(x)
ans = []
num = 1000
for i in range(pos):
    num = random.randint(int(num * 0.9), num - 1)
    ans.append(num)
num = random.randint(int(num * 0.9), num - 1)
ans.append(num)
for i in range(pos + 1, x):
    num = random.randint(num + 1, int(num * 1.1))
    ans.append(num)

print("===================================")
print(x)
print(" ".join([str(x) for x in ans]))