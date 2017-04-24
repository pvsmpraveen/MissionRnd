var http = require("http");
var url = require("url");

/**
 * This method will spin up a http request.
 *
 * All the requests hitting the server, will be processed by the callback of createServer.
 *
 * There are four type of requests that we are expected to hit the server with..
 *
 * These requests will essentially help you to perform CRUD operations on the student data. The student's data should be
 * stored in files/students.txt file.
 *
 * --> You can enhance the FilePersistence.js file to perform update and delete operations as well.
 *
 * --> Based on the type of HTTP request received, corresponding operation can be performed on the student's data.
 *
 * ----------------------------
 * 1) GET
 * ----------------------------
 * We hit the get request to the server say http://localhost:8080 to get the details of all the students..
 *
 * Pass the filters as part of query parameters.
 *
 * for example : http://localhost:8080?totalMarks=65&operator=GT
 *
 * The above request, responds with all the students whose total marks are greater than 65.
 *
 * **** NOTE **** The operator filter can take values EQ, NE, GT, LT, GTE, LTE. It is applicable only for totalMarks.
 *
 * To apply multiple filters, use http://localhost:8080?totalMarks=75&operator=GTE&firstName=nikhil
 *
 * The above request, responds with all the students whose first name is nikhil and whose total marks are >= 75.
 *
 * Sample response :
 * [{
 *      "id" : 32,
 *      "firstName" : "nikhil",
 *      "lastName" : "krishna" ,
 *      "gender" : "male",
 *      "totalMarks" : 80
 *
 * }, {
 *      "id" : 52,
 *      "firstName" : "nikhil",
 *      "lastName" : "joshi" ,
 *      "gender" : "male",
 *      "totalMarks" : 78
 * }]
 *
 * ----------------------------
 * 2) POST
 * ----------------------------
 * To create a new student, hit the server with a PoST request. Send the student information as a body param.
 *
 * Sample request body
 *{
*      "id" : 32,
*      "firstName" : "nikhil",
*      "lastName" : "krishna" ,
*      "gender" : "male",
*      "totalMarks" : 80
*
  * }
 *
 * Error cases : Should throw an error in case of invalid values, duplicate records. Please refer to FilePersistence lesson
 * of javascript-async lesson for the list of all the error scenarios.
 *
 * ----------------------------
 * 3) PUT
 * ----------------------------
 *
 * To update an existing record, make use of PUT request. Send the student information as a body param.
 *
 * Error cases: If student doesn't exist, throw an error.
 *
 * **** NOTE **** DO NOT UPDATE null / undefined values.
 *
 * for example : if lastName of a student is given as null, ignore it and update other properties of the student.
 *
 * * Sample request body
 *{
*      "id" : 32,
*      "firstName" : "nikhil_updated",
*
  * }
 *
 * ----------------------------
 * 4) DELETE
 * ----------------------------
 * To delete an existing record, use the DELETE request. Send the id of the student as a query param
 *
 * http://localhost:8080?id=32
 *
 * Error cases: If student doesn't exist, throw an error.
 *
 *              If query params are not send, throw an error. DELETE http://localhost:8080 should not delete all the students.
 *              it should throw an error.
 *
 * Note : In case of any error scenario, send the statusCode for response as 400 which stands for BAD REQUEST.
 */
var fp = require("./FilePersistence.js");
var getFilters = function(request,callback){
	var regex = /[?&]([^=#]+)=([^&#]*)/g, 
	            url = request.url,
	            params = {},
	            match;
	        while(match = regex.exec(url)) {
	            params[match[1]] = match[2];
	        }
	    var jsn;
	    

	    try		{  jsn = JSON.parse(params);  }
	    catch(e){  jsn = params;   }

	    filters = new Array();
	    if(jsn.hasOwnProperty("gender")){
	    	filters.push({key:"gender",value:jsn["gender"]});
	    }
	    if(jsn.hasOwnProperty("totalMarks")){
	    	if(jsn.hasOwnProperty("operator")){
	    		filters.push({key:"totalMarks",value:jsn["totalMarks"],optype:jsn["operator"]});
	    	}
	    	else{
	    		filters.push({key:"totalMarks",value:jsn["totalMarks"]});
	    	}
	    }
	    console.log(filters);
	 callback(null,filters,jsn);

}


var updateStudents = function(stud,callback){
    if(!((stud.gender === "male") || (stud.gender === "female"))) {
        callback(400); return;
    }
    fp.getStudents(null,function(err,res){
          var ok = false;
          for(var i=0;i<res.length;i++){
                if(res[i].id == stud.id){
                    ok = true;
                    if(stud.firstName) res[i].firstName = stud.firstName;
                    if(stud.lastName) res[i].lastName = stud.lastName;
                    if(stud.gender) res[i].gender = stud.gender;
                    if(stud.totalMarks) res[i].totalMarks = stud.totalMarks;
                    break;
                }
          }
          if(!ok){
            callback(400);
            return;
          }
          file = "";
          for(var i=0;i<res.length;i++){
                file += JSON.stringify(res[i])+"\n";
          }
          var fs = require('fs')
          fs.writeFile(__dirname + '/../files/students.txt', file);
          callback(null);
          console.log(file);
    });
}

var deleteStudent = function(stud,callback){
    fp.getStudents(null,function(err,res){
          var ok = false;
          for(var i=0;i<res.length;i++){
                if(res[i].id == stud.id){
                    ok = true;
                    res.splice(i, 1);
                    break;
                }
          }
          if(!ok){
            callback(400);
            return;
          }
          file = "";
          for(var i=0;i<res.length;i++){
                file += JSON.stringify(res[i])+"\n";
          }
          var fs = require('fs')
          fs.writeFile(__dirname + '/../files/students.txt', file);
          callback(null);
          console.log(file);
    });
}

var server = http.createServer(function(request, response) {
    console.log("request received ",request.method);
    
    var filters,jsn;
    getFilters(request,function(err,res1,res2){
    	filters = res1;
    	jsn = res2;
    });

    if(request.method == "GET"){
    		console.log("GET " +request.url);
    		fp.getStudents(filters,function(err,res){
    			console.log(res);
    			if(err) {
    				response.statusCode = 400;
    				response.end("err");
    			}
    			else{
    				response.statusCode = 200;
    				response.end(JSON.stringify(res));
    			}
    		});
    		console.log(filters);
    }
    else if(request.method == "POST"){
		console.log("POST " +request.url);
    	console.log(jsn);
    	        var body='';
        request.on('data', function (data) {
            body += data;
        });
        request.on('end', function() {
               // console.log("post : "+body);
                var stud;
		        try{ stud = JSON.parse(body); }
		        catch(e){  stud = body;   }
		        fp.createStudent(stud,function(err){
		        	if(err) {
		        		response.statusCode = 400;
		        		response.end("err");
		        	}
		        	else{
		        		response.statusCode = 200;
		        		response.end("sucess");
		        	}
		        })
		        console.log(stud);
        });
    }
    else if(request.method == "PUT"){
		console.log("PUT "+request.url);
        var body='';
        request.on('data', function (data) {
            body += data;
        });
        request.on('end', function() {
               // console.log("post : "+body);
                var stud;
                try{ stud = JSON.parse(body); }
                catch(e){  stud = body;   }
                console.log(stud);
                updateStudents(stud,function(err){
                    if(err){
                        response.statusCode = 400;
                        response.end("err");
                    }
                    else{
                        response.statusCode = 200;
                        response.end("sucess");
                    }
                });
        });
    }
    else if(request.method == "DELETE"){
		console.log("DELETE "+request.url);
        console.log(jsn);
        deleteStudent(jsn,function(err){
                   if(err){
                        response.statusCode = 400;
                        response.end("err");
                    }
                    else{
                        response.statusCode = 200;
                        response.end("sucess");
                    }
        });
    }
    else{
        response.statusCode = 405;
        response.end("err");
    }
});

server.listen(8080);



var fs = require('fs')
fs.writeFile(__dirname + '/../files/students.txt', '');
fp.getStudents(null,function(err,res){
	if(err) console.log("err");
	else console.log(res);
})
console.log("server running at localhost:8080");