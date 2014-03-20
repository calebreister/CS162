'''
 PROGRAM: Strings
 AUTHOR: Caleb Reister
 DATE: 2014-03-18
 DESCRIPTION: Python version of Strings.cpp
'''

def checkVowels(inStr):
    #Expects inStr to be 1 character long
    vowels = ['A','a','E','e','I','i','O','o','U','u']
    for v in range(len(vowels)):
        if inStr == vowels[v]:
            return True
    return False

def rmVowels(inStr):
    out = []
    for i in range(len(inStr)):
        if not (checkVowels(inStr[i])):
            out.append(inStr[i])
        else: out.append('')
    return ''.join(out)#convert list to a string, drops list formatting

myName = "Caleb Reister"
userGuess = input("Guess what my name is: ")

#Print guess results
print("You chose: ", end='')
if userGuess == myName:
    print("wisely")
else:
    print("poorly")
        
#remove vowels from the user's guess
print("You Entered:", userGuess)
print("Without vowels, that is:", rmVowels(userGuess))

#append "the Barbarian"
print("In less civilized times (such as the times CS162 class has",
      "recreated very accurately), you might be known as:",
      userGuess, "the Barbarian")