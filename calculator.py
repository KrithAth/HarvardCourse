from cs50 import get_int
try:
    x = int(input(("x : ")))
except:
    print("It is not an integer!")
    exit()
try:
    y = int(input(("y : ")))
except:
    print("It is not an integer!")
    exit()
print(x + y)
