__author__ = 'Kalyan'

notes = '''
    Sets are  unordered collection of elements without duplicates. They are designed to be very efficient with respect to
    set operations like membership, union, intersection. Doing similar operations on lists will be very inefficient as lists
    are optimized for scenarios which require ordering.

    When should you use which data structure is an important consideration. Read this thread completely to understand the
    considerations involved: http://stackoverflow.com/questions/3489071/in-python-when-to-use-a-dictionary-list-or-set
'''

from placeholders import  *

def test_set_type():
    test_set = {"one", "two", "three"}   # note the new syntax
    assert 'set' == type(test_set).__name__

def test_set_empty():
    empty_set_wrong = {}  #curly braces are used for both sets and dicts, so how do you disambiguate?
                          # For empty :  set = () ,dict = {}
                          # set dont have key,value pair , so when using curly braces if key : value is there it is dictionary
    assert False == isinstance(empty_set_wrong, set)

    empty_set = set()
    assert True == isinstance(empty_set, set)
    assert 0== len(empty_set)

def test_set_length():
    fruits = {"apple", "apple", "apple"}
    assert 1 == len(fruits)  #are duplicates removed? , Ans : Yes!

    veggies = {"beetroot", "potato", "spinach"}
    assert 3 == len(veggies)

def test_set_creation():
    """
    sets can be created from any sequence like list or a tuple.
    """
    test_list = [1, 2, 1, 3]
    set1 = set(test_list)
    assert {1,2,3} == set1

    test_string = "apple"
    set2 = set(test_string)
    assert {'a','p','l','e'} == set2

    test_dict = { 1: "one", 2 : "two"}
    set3 = set(test_dict)
    assert {1,2} == set3

    set4 = set(test_dict.values())
    assert {"one","two"} == set4

    set5 = set(test_dict.items())
    assert {(1, 'one'), (2, 'two')} == set5

def test_set_membership():
    fruits = {"apple", "mango", "kiwi"}
    assert True == ("apple" in fruits)
    assert False == ("dog" in fruits)

def test_set_operations():
    set1 = {"one", "two", "three"}
    set2  =  {"three", "four"}

    all = set1 | set2 # union
    assert {"one", "two", "three", "four"} == all

    common = set1 & set2
    assert {"three"} == common

    diff1 = set1 - set2
    assert {"one", "two"} == diff1

    diff2 = set2 - set1
    assert {"four"} == diff2

    diff3 = set1 - set1
    assert set([]) == diff3

    diff4 = set1.symmetric_difference(set2)
    assert {"one","two","four"} == diff4

    #read up help on other methods using the help method in the python console.

def test_set_valid_members():
    test_set = set()
    test_set.add("hello")
    test_set.add(1)
    test_set.add((1,2))

    try:
        test_set.add([])
    except TypeError as te:
        print te
        assert True

    try:
        test_set.add((1,[]))
    except TypeError as te:
        print te
        assert True

    assert {"hello",1,(1,2)} == test_set


#apply what you have learnt here.
def common(input1, input2):
    """
    Given two lists, return the common elements in both the lists as a set
    """
    return set(input1) & set(input2) # write a single line of code

def test_common():
    assert {10} == common(range(11), range(10, 100))
    assert set() == common (range(10), range(10, 20))
    assert set(range(5,10)) == common (range(10), range(5, 15))


three_things_i_learnt = """
sets are unique collection of elements
Learned various set operations
Learned to typecast set() to get unique elements from other types
"""
