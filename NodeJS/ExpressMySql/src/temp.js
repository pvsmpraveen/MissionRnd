var http = require("http");
var url = require("url");
var fs = require("fs");
var path = require("path");

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
 * for example : http://localhost:8080/?totalMarks=65&operator=GT
 *
 * The above request, responds with all the students whose total marks are greater than 65.
 *
 * **** NOTE **** The operator filter can take values EQ, NE, GT, LT, GTE, LTE. It is applicable only for totalMarks.
 *
 * To apply multiple filters, use http://localhost:8080/?totalMarks=75&operator=GTE&firstName=nikhil
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
 * http://localhost:8080/?id=32
 *
 * Error cases: If student doesn't exist, throw an error.
 *
 *              If query params are not send, throw an error. DELETE http://localhost:8080 should not delete all the students.
 *              it should throw an error.
 *
 * Note : In case of any error scenario, send the statusCode for response as 400 which stands for BAD REQUEST.
 */

 var pathname = path.join(__dirname,"..","files","students.txt");

var process_request = function(operation,operator_1,operator_2){
    // EQ, NE, GT, LT, GTE, LTE
    if(operation=="EQ"){
        if(operator_2==operator_1)
            return 0;
    }
    else if(operation=="NE"){
        if(operator_2!=operator_1)
            return 0;
    }
    else if(operation=="GT"){
        if(operator_2>operator_1)
            return 0;
    }
    else if(operation=="LT"){
        if(operator_2<operator_1)
            return 0;
    }
    else if(operation=="GTE"){
        if(operator_2>=operator_1)
            return 0;
    }
    else if(operation=="LTE"){
        if(operator_2<=operator_1)
            return 0;
    }
    return 1;
}

var server = http.createServer(function(request, response) {
    var details = url.parse(request.url,true);
    if(request.method == "GET"){
        fs.readFile(pathname,'utf8',function(err,data){
            var JSON_response = [];
            var dummy = new Array();
            if(data!=null){
                var string_allRecords = data.split('\n');
                var JSON_record = new Object();
                var Check_flagBit = 0;
                var JSON_request = details.query;
                for (var i= 0; i < string_allRecords.length-1; i++)  {
                    JSON_record = JSON.parse(string_allRecords[i]);
                    Check_flagBit = 0;
                    for (var variable in JSON_request) {
                        if(variable != "operator"){
                            if(variable=="totalMarks"){
                                if(!("operator" in JSON_request)){
                                    response.writeHead(200, {"Content-Type": "application/json"}); // hi ra run cheyyi
                                    response.end(JSON.stringify(JSON_response));
                                    return;
                                }
                                if (process_request(JSON_request["operator"],JSON_request[variable],JSON_record[variable])){
                                    Check_flagBit = 1;
                                }
                            }
                            else{
                                if (process_request("EQ",JSON_request[variable],JSON_record[variable]))
                                    Check_flagBit = 1;
                            }
                        }
                    }
                    if(Check_flagBit == 0)
                        JSON_response.push(JSON_record);
                }
            }
            response.writeHead(200, {"Content-Type": "application/json"});
            response.end(JSON.stringify(JSON_response));
        });
    }

    var body = '';
    request.on('data', function(data){
        body += data;
    });

    request.on('end',function(){
        if(request.method == 'POST'){
            var input_record = JSON.parse(body.toString());
            if(("id" in input_record) && ("lastName" in input_record) && ("firstName" in input_record) && ("gender" in input_record) && ("totalMarks" in input_record)){
                if((input_record.gender == "male" || input_record.gender=="female") && (input_record.totalMarks >=0 && input_record.totalMarks<=100)){
                    fs.readFile(pathname,'utf8',function(err,data){
                        var bit = 0;
                        if(data!=null){
                            var string_allrecord = data.split('\n');
                            for (var i = 0; i < string_allrecord.length-1; i++) {
                                if((JSON.parse(string_allrecord[i])).id == input_record.id)
                                    bit = 1;
                                }
                        }
                        if(bit == 0){
                            fs.appendFile(pathname,JSON.stringify(input_record)+"\n",'utf8',function(err){
                                if(err)
                                    throw(err);
                                response.statusCode = 200;
                                response.end();
                            });
                        }
                        else{
                            response.statusCode = 400;
                            response.end();
                        }
                    });

                }
                else{
                    response.statusCode = 400;
                    response.end();
                }
            }
            else {
                response.statusCode = 400;
                response.end();
            }
        }
        else if(request.method == 'PUT'){
            var update_record = JSON.parse(body.toString());
            if("totalMarks" in update_record){
                if(!(update_record["totalMarks"]>=0 && update_record["totalMarks"]<=100)){
                    response.statusCode = 400;
                    response.end();
                }
            }
            if("gender" in update_record){
                if(!(update_record["gender"]=="male" || update_record["gender"]=="female")){
                    response.statusCode = 400;
                    response.end();
                }
            }
            fs.readFile(pathname,'utf8',function(err,data){
                var string_allRecords = data.split('\n');
                var victim = new Object();
                var visit = 0;
                for (var i = 0; i < string_allRecords.length-1; i++) {
                    victim = JSON.parse(string_allRecords[i]);
                    if(victim.id == update_record.id){
                        visit = 1;
                        for(var variable in update_record){
                            if(variable in victim && update_record[variable]!=null){
                                victim[variable] = update_record[variable];
                            }
                        }
                        string_allRecords[i] = JSON.stringify(victim);
                        break;
                    }
                }
                if(visit == 0){
                    response.statusCode = 400;
                    response.end();
                }
                fs.writeFile(pathname,string_allRecords.join("\n"),'utf8',function(err){
                    if(err)
                        throw err;
                    response.statusCode = 200;
                    response.end();
                });
            });
        }
    });

    if(request.method == 'DELETE'){
        var request_query = details.query;
        if(!("id" in request_query)){
            response.statusCode = 400;
            response.end();
        }
        fs.readFile(pathname,'utf8',function(err,data){
            var delete_allRecords = data.split("\n");
            var sizebefore = delete_allRecords.length;
            var victim = new Object();
            for (var i = 0; i < delete_allRecords.length-1; i++) {
                if(request_query.id == (JSON.parse(delete_allRecords[i])).id){
                    delete_allRecords.splice(i,1);
                    i = i-1;
                }
            }
            if(sizebefore == delete_allRecords.length){
                response.statusCode = 400;
                response.end();
            }
            fs.writeFile(pathname,delete_allRecords.join("\n"),'utf8',function(err){
                if(err)
                    throw err;
                response.statusCode = 200;
                response.end();
            });
        });
    }
});

server.listen(8080);

console.log("server running at localhost:8080");
