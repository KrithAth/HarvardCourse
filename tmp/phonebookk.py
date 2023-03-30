import csv
from cs50 import get_string

with open("phonebook.csv", "a") as file:

    name = get_string("Name: ")
    number = get_string("Number: ")

    write = csv.writer(file)
    write.writerow([name, number])
