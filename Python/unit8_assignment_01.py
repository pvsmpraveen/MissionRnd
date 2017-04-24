__author__ = 'Kalyan'

problem = """
 We are going to revisit unit6 assignment3 for this problem.

 Given an input file of words (mixed case). Group those words into anagram groups and write them
 into the destination file so that words in larger anagram groups come before words in smaller anagram sets.

 With in an anagram group, order them in case insensitive ascending sorting order.

 If 2 anagram groups have same count, then set with smaller starting word comes first.

 For e.g. if source contains (ant, Tan, cat, TAC, Act, bat, Tab), the anagram groups are (ant, Tan), (bat, Tab)
 and (Act, cat, TAC) and destination should contain Act, cat, TAC, ant, Tan, bat, Tab (one word in each line).
 the (ant, Tan) set comes before (bat, Tab) as ant < bat.

 At first sight, this looks like a big problem, but you can decompose into smaller problems and crack each one.

 This program should be written as a command line script. It takes one argument the input file of words and outputs
 <input>-results.txt where <input>.txt is the input file of words.
"""
import sys

def are_anagrams(first, second):
    if(first==None or second==None):
        return False
    first = first.lower()
    second = second.lower()

    count1 = [0]*27
    count2 = [0]*27

    for i in range(0,len(first)):
        if(first[i]>='a' and first[i]<='z'):
            count1[ord(first[i])-ord('a')]+= 1

    for i in range(0,len(second)):
        if (second[i]>= 'a' and second[i]<='z'):
            count2[ord(second[i]) - ord('a')] += 1

    for i in range(0,27):
        if(count1[i] != count2[i]):
            return False
    return True

def anagram_sort(source, destination):

    fread = open(source)
    fwrite = open(destination,"w")
    lines = [line.strip() for line in fread if len(line.strip().lower())!=0 and line.strip().lower()[0]!='#']

    anagram_tuples = []
    for line in lines:
        for i in range(0,len(anagram_tuples)):
            if(are_anagrams(anagram_tuples[i][0],line)):
                anagram_tuples[i] += (line,)
                break
        else:
            anagram_tuples.append((line,))

    for i in range(len(anagram_tuples)):
        li = list(anagram_tuples[i])
        li.sort(key=lambda x: x.upper())
        anagram_tuples[i] = li

    anagram_tuples.sort(key=lambda x: x[0].upper())
    anagram_tuples.sort(key = lambda x : (-len(x)))

    to_file = []
    for i in range(len(anagram_tuples)):
        to_file = to_file+ anagram_tuples[i]

    for i in to_file:
        fwrite.write(i+'\n')



if __name__ == "__main__":
    try:
        source = sys.argv[1]
        idx  = source.find(".txt")
        destination = sys.argv[1][:idx]+"-results.txt"
        #print source,destination

        anagram_sort(source,destination)

    except Exception as ex:
        print ex
    #sys.exit(main())