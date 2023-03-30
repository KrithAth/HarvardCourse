from cs50 import get_int

number = get_int("Input: ")
D1 = [1, 2, 3, 4, 5, 6]
D2 = [1, 2, 3, 4, 5, 6]
counter = 0
for i in range(6):
    for j in range(6):
        if D1[i] + D2[j] == number:
            counter += 1

print("Output: ", counter)