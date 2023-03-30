from cs50 import get_int

points = get_int("How much points did you lose? ")

if points < 2:
    print("you lost less points than me")
elif points > 2:
    print("you lost more points than me")
else:
    print("we lost same number of points")
    