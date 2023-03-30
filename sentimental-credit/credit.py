from cs50 import get_string
from cs50 import get_int

# function to verify the card number


def verifynumber(vnumber):
    L = len(vnumber)
    v2 = 0
    v3 = 0
    for i in range(L - 2, -1, -2):
        v1 = int(vnumber[i]) * 2
        v2 = v2 + (v1 % 10 + (((v1 % 100)-(v1 % 10)) / 10))

    for i in range(L - 1, -1, -2):
        v3 = v3 + int(vnumber[i])

    v4 = v2 + v3
    return v4


# get card number from the user
number = get_string("Number: ")
verify = verifynumber(number)
if verify % 10 == 0:
    if (int(number[0]) == 3 and int(number[1]) == 4 or int(number[1]) == 7) and len(number) == 15:
        print("AMEX")
    elif int(number[0]) == 4 and (len(number) == 13 or len(number) == 16):
        print("VISA")
    elif (int(number[1]) == 1 or int(number[1]) == 2 or int(number[1]) == 3 or int(number[1]) == 4 or int(number[1]) == 1 or int(number[1]) == 5 and int(number[0]) == 5) and len(number) == 16:
        print("MASTERCARD")
    else:
        print("INVALID")
else:
    print("INVALID")