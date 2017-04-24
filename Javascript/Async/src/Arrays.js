var Arrays = function() {

    /**
     Utility function used to find the maximum element in the given array..

     The array is given as input.

     Return the max element of array in the callback in error first way.
     */
    this.findMax = function (array, callback) {
        if(array.length == 0){
            callback(null,null);
            return;
        }
        var maxx = Math.max.apply(Math,array);
        callback(null,maxx);
    };

    /**
     Utility function used to find maximum element of given arrays

     Each line in the file "files/arrays.txt" corresponds to a Array..

     Use the above mentioned function findMax to find max element in all the arrays..

     Test case fails if the findMax method is not used..

     Return list of max elements via the callback..

     Example input [[3, 6, 1], [5, 7, 8, 1], [5,8,3]] output [6, 8, 8]
     */
    this.getMaxArray = function (callback) {
        var fs = require('fs');
        var array = fs.readFileSync(__dirname + '/../files/arrays.txt').toString().trim().split("\n");
        var ret = Array();
        for(i in array) {
            var inp = array[i].trim();
            if(inp.length==0){
                ret.push(null);
                continue;
            }
            inp = inp.split(' ').map(Number);
            this.findMax(inp,function(err, maxEle) {
                ret.push(maxEle);
            });
        }
        callback(null,ret);
   };
};

module.exports = Arrays;

