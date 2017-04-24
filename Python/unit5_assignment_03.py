__author__ = 'Kalyan'

notes = '''
Now we move on to writing both the function and the tests yourself.

In this assignment you have to write both the tests and the code. We will verify your code against our own tests
after you submit.
'''

# fill up this routine to test if the 2 given words given are anagrams of each other. http://en.wikipedia.org/wiki/Anagram
# your code should handle
#  - None inputs
#  - Case  (e.g Tip and Pit are anagrams)
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

# write your own exhaustive tests based on the spec given
def test_are_anagrams_student():
    assert True == are_anagrams("pit", "tip") #sample test.
    #Own Tests
    assert True == are_anagrams("Pit", "Tip")
    assert False == are_anagrams(None, "Tip")
    assert False == are_anagrams(None, None)
    assert True == are_anagrams("abcdef", "defcab")
    assert True == are_anagrams("ABCDEF", "defcab")
    assert False == are_anagrams("ABCDHEF", "defcab")
    assert True == are_anagrams("ACS pes", "spaces")
    assert True == are_anagrams("","")

    assert False == are_anagrams(None, None) #Failed in 1st Run : Because i returned None


    #From https://en.wikipedia.org/wiki/Anagram
    assert True == are_anagrams("Arrigo Boito", "Tobia Gorrio")
    assert True == are_anagrams("Edward Gorey", "Ogdred Weary")
    assert True == are_anagrams("Dave Barry", "Ray Adverb")
    assert True == are_anagrams("Buckethead","Death Cube K")


# these tests run only on our runs and will be skipped on your computers.
# DO NOT EDIT.
import pytest
def test_are_anagrams_server():
    servertests = pytest.importorskip("unit5_server_tests")
    servertests.test_are_anagrams(are_anagrams)
