__author__ = 'Kalyan'

profiling_cprofile = '''
This is the tool of choice for analyzing large programs (parallel to the debugger). The profiler adds its own overhead
but for relative comparison of time spent, it is very very useful.

http://pysnippet.blogspot.in/2009/12/profiling-your-python-code.html
http://docs.python.org/2/library/profile.html in particular
http://docs.python.org/2/library/profile.html#instant-user-s-manual

In particular, make sure you learn how to use pstats and running cProfile from command line as described in the
first post using a sample program before doing this assignment.

python -m cProfile [-o output_file] [-s sort_order] myscript.py

For this assignment learn to use the cProfile and pstats modules from the command line.
1. run the cprofile and collect a stats file
2. learn to use the stats file separately.
3. bypass the stats creation and directly print the output to console.

compare the cumulative times of these methods and then calculate per call times.
'''

from unit7_conversion_methods import *
#invoke each of the 4 methods 5 times in a loop for count=10000. Then run this in the profiler.
def profile_profiler():
    Func = [numbers_string1, numbers_string2, numbers_string3, num_strings4]

    for i in range(0,4):
        for j in range(0,5):
            Func[i](10000)


# compare the times taken per call using this method to what you found in the previous methods.
# when would you use the profiler over other methods, what additional data did you get from the profiler easily
# that would have taken more work in other methods?

# what did you learn about cProfile and pstats?

summary = '''

    We use,
    cProfile - the application that collects profiling data
    pstats - the application that makes the profling data human readable

    cProfile can be used in the command line,
    and as well as in the python script by,

    import cProfile
    import re        re - Support for regular expressions (RE).


    Here we used Command Line.
    In profiler we get information about,

    ncalls - How many times the function is called
    tottime - Total time taken for n top calls
    percall - Time take for a single top call
    cumtime - Cummulative Time taken for n topcalls+subcalls
    percall - Time take for a single topcall+subcalls

    We use this when we have so many methods and so many subcalls to profile, so it gives complete
    information about which module is using how much time,
    we can sort it using -s time and see which function takes more time per call
    and try to optimise it accordingly.


    Basic Profiling.                                    :   http://screencast.com/t/q5PS8RCs
    Storing the stats to the outputfile unit7_stats     :   http://screencast.com/t/psGZ0LSGu
    pstats to convert the stats to human readable       :   http://screencast.com/t/Yiqv8mc9lXOx
    sorting the stats based on time                     :   http://screencast.com/t/Em1cqnsobvm
    pstats -s arguments, ordering type                  :   http://screencast.com/t/PPZe1Tz2DhJq

    Apart from the command line, cProfile can be used in the script,
    if we are to profile the functions many times this will be useful.
    
'''

if __name__ == "__main__":
    profile_profiler()
