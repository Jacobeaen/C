import random

num_lst = []

# Чтобы поменять количество чисел меняйте range(n)
# Чтобы поменять генерируемы диапазон меняйте randint(a, b)
for i in range(15):
    num_lst.append(random.randint(-100, 100))

with open("numbers.txt", "w") as file:
    string = " ".join(list(map(str, num_lst)))
    file.write(string)