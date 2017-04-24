__author__ = 'Kalyan'

profiling_timing = '''
This involves adding sufficient time.clock calls at appropriate places and then calculating difference to calculate
elapsed time.

http://docs.python.org/2/library/time.html?highlight=time.clock#time.clock

This is similar to print debugging, but once you have narrowed down code to a small code section by other means,
this can be very useful and precise.

Generally you will study performance as you vary the input across a range e.g. count = 10, 100, 1000, 10000

profile the 4 methods in unit7_conversion_methods.py using time.clock() in this assignment.

for each value of count, execute the method 5 times and print out the min value and the actual 5 values.
output should look like (a total of 16 lines):
numbers_string1, count = 10, min = 0.0001, actuals = [0.0001, 0.0002, 0.0001, ...]
numbers_string1, count = 100, min = 0.002, actuals = [0.002, 0.002, 0.003, ...]
....
numbers_string4, count = 10000, min = 0.1 actuals = [....]

 Note: This is a python script which can be run from command line (python.exe <script>.py) or from pycharm (Right click -> Run <script>
 and not the usual pytest tests we have been using so far.
'''

import time
from unit7_conversion_methods import *
# write clean code to run all the profiles in one go using loops, lists etc. Note that functions are first class objects
# in python so you can hold them in a list.
def profile_clock():

    Result = [[[0]*5 for i in range(4)] for j in range(4)]              # Matrix of [Method][Count][5] , 5Times.
    Func = [numbers_string1,numbers_string2,numbers_string3,num_strings4]


    for i in range(0,4):    #Each Method
        for k in range(0, 4):  # Count
            Count = 10 ** (k + 1)
            for j in range(0,5):    #5Times
                strt = time.clock()
                Func[i](Count)
                end = time.clock()
                Result[i][k][j] = "%.6f" % (end-strt)  #ith method ,jth time
            print Func[i].__name__+", Count = "+str(Count)+", Min = "+str(min(Result[i][k]))+", actuals = ", Result[i][k]




# write your findings on what is the most optimal method and what you learnt in the process.
summary = '''
On Different runs, the time varied at diff of 1e-6 ,
Among all the observations
    'numbers_string2' is the most optimal method.

To write the clean code, this is the first time i actually played with a 3D Array in python , cool!

Learnt about finding execution time using difference of start,end points of time.clock()

'''

if __name__ == "__main__":
    profile_clock()
