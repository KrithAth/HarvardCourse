from cs50 import get_int
# Get height from user
while True:
    h = get_int("Pyramid height = ")
    if h <= 8 and h >= 1:
        break

i = 0
while (i <= h-1):
    # print right aliged pyramid
    print(" " * (h-i-1) + "#" * (i+1), end="")
    # print spaces between pyramids
    print("  ", end="")
    # print left aligned pyramid
    print("#" * (i+1))
    i += 1