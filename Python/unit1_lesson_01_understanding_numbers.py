__author__ = 'Kalyan'

from placeholders import *

# For most of these tests use the interpreter to fill up the blanks.
# type(object) -> returns the object's type.

def test_numbers_types():
    assert "int" == type(7).__name__
    assert "float" == type(7.5).__name__
    assert "long" == type(10L).__name__

def test_numbers_int_arithmetic_operations():
    assert 30 == 10 + 20
    assert 200 == 10 * 20
    assert 32 == 2 ** 5
    assert -10 == 10 - 20
    assert 2.3333333333333335 == 7.0/3.0

def test_numbers_string_to_int():
    """hint: execute  print int.__doc__ in python console
       to find out what int(..) does"""
    assert 255 == int("FF", 16)
    assert 63 == int("77", 8)

def test_numbers_int_to_string():
    assert '012' == oct(10)
    assert '0x64' == hex(100)
    assert '0b11111111' == bin(255)

def test_numbers_long():
    """Long is not the long in c"""
    assert 1606938044258990275541962092341162602522202993782792835301376 == 2 ** 200

# Being comfortable with number bases mentally is important and it is routinely asked in interviews as quick test
# of a candidate.
#
# Replace the __ with the correct string representation by working it out on paper (don't use any code or console).
#
# Read the following links:
#           http://courses.cs.vt.edu/~cs1104/number_conversion/convexp.html
#           https://docs.python.org/2/library/functions.html#int
def test_numbers_base():
    assert 255 == int("11111111", 2)
    assert 254 == int("FE", 16)
    assert 121 == int("232", 7)
    assert 675 == int("PP", 26) # Base 26 : [0-9],[A-P]



three_things_i_learnt = """
type(object) function to check the type.
__name__ to convert into "str"
int and long in Python 2.7
Reading documentation in Python Console itself
"""
