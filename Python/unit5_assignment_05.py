__author__ = 'Kalyan'

notes = '''
1. Read instructions for the function carefully and constraints carefully.
2. Try to generate all possible combinations of tests which exhaustively test the given constraints.
3. If behavior in certain cases is unclear, you can ask on the forums
'''
from placeholders import *

# Convert a sentence which has either or to only the first choice.
# e.g we could either go to a movie or a hotel -> we could go to a movie.
# note: do not use intermediate lists (string.split), only use string functions
# assume words are separated by a single space. you can use control flow statements
# So sentence is of form <blah> either <something> or <somethingelse> and gets converted to <blah> <something>
# if it is not of the correct form, you just return the original sentence.
def prune_either_or(sentence):

    if(sentence == None):
        return None

    Either = sentence.find(" either ",0)
    Or = sentence.find(" or ",0)
    #print Either,Or

    if(sentence.find("either ")==0 or sentence.find("or ") ==0 ):
        return sentence

    if(Either == -1 or Or == -1 or Or < Either or (Or - Either <=7) or len(sentence) <= Or+4 or Either ==0 or Or <=9):
        return sentence

    return sentence[:Either]+sentence[Either+7:Or]

def test_prune_either_or_student():
    assert "we could go to a movie" == prune_either_or("we could either go to a movie or a hotel")
    assert "<blah> <something>" == prune_either_or("<blah> either <something> or <somethingelse>")
    assert "<blah> or <something> either <somethingelse>" == prune_either_or("<blah> or <something> either <somethingelse>")
    assert "He either or something" == prune_either_or("He either or something")
    assert "<blah> <something>" == prune_either_or("<blah> either <something> or <something> either <somethingelse>")
    assert "T H" == prune_either_or("T either H or P")
    assert "Teither H or P" == prune_either_or("Teither H or P")
    assert "T either H or " == prune_either_or("T either H or ")
    assert "we can play chess" == prune_either_or("we can either play chess or cricket")
    assert "we play chess or cricket" ==  prune_either_or("we play chess or cricket")
    assert "k i" == prune_either_or("k either i or pty")

# these tests run only on our runs and will be skipped on your computers.
# DO NOT EDIT.
import pytest
def test_prune_either_or_server():
    servertests = pytest.importorskip("unit5_server_tests")
    servertests.test_prune_either_or(prune_either_or)
