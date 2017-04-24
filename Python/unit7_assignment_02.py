__author__ = 'Kalyan'

from placeholders import *


profiling_timeit = '''
Python also gives a helpful timeit module that can be used for benchmarking a given piece of code

Reading material:
 http://docs.python.org/2/library/timeit.html
 http://stackoverflow.com/questions/8220801/how-to-use-timeit-correctly
 http://www.dreamincode.net/forums/topic/288071-timeit-module/

Try out on sample code snippets from above links on your own before you get to the assignment.

Generally you will study performance as you vary the input across a range e.g. count = 10, 100, 1000, 10000

profile the 4 methods in unit7_conversion_methods.py using timeit in this assignment.

for each value of count, execute the method 5 times using timeit and print out the min value and the actual 5 values.
output should look like (a total of 16 lines):
numbers_string1, count = 10, min = 0.0001, actuals = [0.0001, 0.0002, 0.0001, ...]
numbers_string1, count = 100, min = 0.002, actuals = [0.002, 0.002, 0.003, ...]
....
numbers_string4, count = 10000, min = 0.1 actuals = [....]

'''

from unit7_conversion_methods import *
import timeit


def profile_timeit():

    Func = [numbers_string1, numbers_string2, numbers_string3, num_strings4]
    for i in range(0,4):    #Four Functions
        Count = 1
        for j in range(0,4):    #4Counts 10,100,1000,10000
            Count = Count*10
            Actuals = []
            for k in range(0,5):    #5Times , just to get Actuals = []
                timer = timeit.Timer(lambda : Func[i](Count))
                Actuals.append("%.6f" % timer.timeit(number=1))
            print Func[i].__name__ + ", Count = " + str(Count) + ", Min = " + str(min(Actuals)) + ", actuals = ", \
            Actuals





# write your findings on what you learnt about timeit, measuring perf and how the results here compare to
# values in assignment1
summary = '''
    We can run the code for 'repeated' no of times and caliculate the total time taken,
    it is used to caliculate average run time of a specific function.

    Learnt the differences between time.clock() and time.time()
    Its CPU time vs Clock time, some processes can interfere with CPU and increase clock time.
    Garbage collection is off now, so it will decrease time compared to previous assignment.

    Unix and Windows have different time granuality.

    timeit creates its own separate scope, so we can pass the locals and globals using join(locals()) and join(globals())
    in the setup string.

    Instead we can use a function , and import that function in the setup which brings all variables into the timeit
    Hence i used lambda which is because its an anonymous functions

'''

if __name__ == "__main__":
    profile_timeit()
