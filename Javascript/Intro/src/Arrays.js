/*
OVERVIEW: 	Implement a function that sums all the numbers in the given array.
			Example: SumOfArray([1,2,3]) should return a value of 6.

INPUTS: 	arrayOfNums: An array of numbers

OUTPUT: 	Sum of all the numbers

ERROR CASES: If arrayOfNums is null, return NaN.
			 If arrayOfNums is not an array, return NaN. Since Javascript is weakly typed, it is possible to
			 invoke calls such SumOfArray("hello").
			 You can use instanceof operator as described in the project page to check this.
*/
exports.SumOfArray = function(arrayOfNums){
	if(arrayOfNums==null || !(arrayOfNums instanceof Array)){
		return NaN;
	}
	var sum = 0;
	for(var i = 0;i<arrayOfNums.length;i++){
		sum += arrayOfNums[i];
	}
	return sum;

}

/*
OVERVIEW: 	Implement a function that sums only the unique umbers in the given array.
			Example: SumOfUniqueNumbers([2,3,3,2]) should return a value of 2+3=5.

INPUTS: 	arrayOfNums: An array of numbers

OUTPUT: 	Sum of the unique numbers

ERROR CASES: If arrayOfNums is null, return NaN.
			 If arrayOfNums is not an array, return NaN. Since Javascript is weakly typed, it is possible to
			 invoke calls such SumOfArray("hello").
			 You can use instanceof operator as described in the project page to check this.
*/

exports.SumOfUniqueNumbers = function(arrayOfNums){
	if(arrayOfNums==null || !(arrayOfNums instanceof Array)){
		return NaN;
	}

	var s = new Set(arrayOfNums);
	var sum = 0;
	for(value of s){
		sum += value;
	}
	return sum;

}

/*
OVERVIEW: 	Implement a function that sums the diagonal elements in the given array.
			Example: SumOfUniqueNumbers([[11,12,13],[12,13,14],[13,14,15]]) should sum the elements at indexes (1,1),(2,2),(3,3).
			This will be sum of 11 + 13 + 15 = 39

INPUTS: 	array2d: An array of numbers

OUTPUT: 	Sum of the diagonal cells of the array.

ERROR CASES: If array2d is null, return NaN.
			 If array2d is not an array, return NaN. 
			 If array2d is not a 2-d array, return NaN.
			 If array2d is a 2-d array with different dimensions, return NaN.
*/

exports.SumOfDiagonalCells = function(array2d){

	if(array2d==null || !(array2d instanceof Array)){
		return NaN;
	}
	var n = array2d.length;
	var s = new Set();
	for(var i = 0;i<n;i++){
		var m = array2d[i].length;
		if(!(array2d instanceof Array) || m!=n) return NaN;
		s.add(array2d[i][i]);
		s.add(array2d[i][n-i-1]);
	}
	var sum = 0;
	for(value of s){ sum += value; }
	return sum;
}
