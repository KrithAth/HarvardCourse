from cs50 import get_string

# get text from the user
text = get_string("Text: ")
letters = 0
words = 0
sentences = 0
l = len(text)
for i in range(l):
    # checking whether its a alphabet
    if (text[i].isalpha()):
        letters += 1
    # checking whether its a space
    elif (text[i].isspace()):
        words += 1
    # checking whether it starts a new sentence
    elif (text[i] == "." or text[i] == "!" or text[i] == "?"):
        sentences += 1
words += 1
l = (letters / words) * 100
s = (sentences / words) * 100
# using the formula
grade = round(0.0588 * l - 0.296 * s - 15.8)

# printing the grade number according to the calculation
if grade >= 1 and grade <= 16:
    print("Grade ", grade)
if grade < 1:
    print("Before Grade 1")
if grade > 16:
    print("Grade 16+")