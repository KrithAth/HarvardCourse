import string

userinput = input("Start Typing: ")
# correct words count
words = 1
# incorrect words count
iwords = 0
paragraph = "paragraphs are the building blocks of papers many students define paragraphs in terms of length a paragraph is a group of at least five sentences a paragraph is half a page long etc"
for i in range(len(userinput)):
    if (userinput[i].isspace()) == True:
        words += 1
print(words)

j = 0
print(paragraph[10])
for i in range(0, paragraph[j].isspace() == True):
    if userinput[i] == paragraph[i]:
        print(userinput[i])
        print(paragraph[i])
    j += 1