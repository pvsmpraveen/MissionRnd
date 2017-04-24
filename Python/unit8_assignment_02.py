__author__ = 'Kalyan'

problem = """
Pig latin is an amusing game. The goal is to conceal the meaning of a sentence by a simple encryption.

Rules for converting a word to pig latin are as follows:

1. If word starts with a consonant, move all continuous consonants at the beginning to the end
   and add  "ay" at the end. e.g  happy becomes appyhay, trash becomes ashtray, dog becomes ogday etc.

2. If word starts with a vowel, you just add an ay. e.g. egg become eggay, eight becomes eightay etc.

You job is to write a program that takes a sentence from command line and convert that to pig latin and
print it back to console in a loop (till you hit Ctrl+C).

e.g "There is, however, no need for fear." should get converted to  "Erethay isay, oweverhay, onay eednay orfay earfay."
Note that punctuation and capitalization has to be preserved

You must write helper sub routines to make your code easy to read and write.

Constraints: only punctuation allowed is , and . and they will come immediately after a word and will be followed
by a space if there is a next word. Acronyms are not allowed in sentences. Some words may be capitalized
(first letter is capital like "There" in the above example) and you have to preserve its capitalization in the
final word too (Erethay)
"""

import sys
import string

def get_words_list(input):
    words = input.strip().split(" ")
    return words

def get_piglatin(input):
    if(len(input)==0):
        return input

    Punc = ".,"
    Vowels = "AEIOUaeiou"

    Capital = False
    Punctuation = False
    if(input[0]>='A' and input[0]<='Z'):
        Capital=True
    if(input[-1] in Punc ):
        Punctuation = True

    Idx = 0
    for i in range(0,len(input)):
        if input[i] in Vowels:
            Idx = i
            break

    input = input.lower()

    if(Punctuation==False):
        input = input[Idx:]+input[0:Idx]+"ay"
    else:
        input = input[Idx:-1]+input[0:Idx]+"ay"+input[-1]

    if(Capital):
        input = input.capitalize()
    return input


def sentence_converter(input):
    #print list(input)
    words = get_words_list(input)
    if(len(words)==0):
        return

    piglatin = map(get_piglatin,words)
    result = " ".join(piglatin)

    print result


if __name__ == "__main__":
    while True:
        try:
            input = sys.stdin.readline()
            if(list(input)==[]):
                raise KeyboardInterrupt("Ctrl+C Detected")
            sentence_converter(input)
        except KeyboardInterrupt as Ke:
            break