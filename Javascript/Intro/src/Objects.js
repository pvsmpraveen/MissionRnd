/*
OVERVIEW: 	Javascript objects are essentially containers for named values. In this activity, you will write
			a function that inspects an object and returns its property names.
			Example: var car = {make: "Honda", model:"Civic", color:"Silver"}
			GetObjectPropertyNames() should return ["make","model","color"] 

INPUTS: 	obj - A javascript object

OUTPUT: 	array containing the property names of obj.

ERROR CASES: return null if obj is null or is not a Javascript object.
*/
exports.GetObjectPropertyNames = function(obj) {
	if(obj==null || !(obj instanceof Object)){
		return null;
	}
	var k = Object.keys(obj);
	return k;

}

/*
OVERVIEW: 	Javascript objects are essentially containers for named values. In this activity, you will write
			a function that inspects an object and returns its property values.
			Example: var car = {make: "Honda", model:"Civic", color:"Silver"}
			GetObjectPropertyValues() should return ["Honda","Civic","Silver"] 

INPUTS: 	obj - A javascript object

OUTPUT: 	array containing the property names of obj.

ERROR CASES: return null if obj is null or is not a Javascript object.
*/
exports.GetObjectPropertyValues = function(obj) {

	if(obj==null || !(obj instanceof Object)){
		return null;
	}
	var Ret = new Array();
	for(var i in obj){
		Ret.push(obj[i]);
	}
	return Ret;

}

