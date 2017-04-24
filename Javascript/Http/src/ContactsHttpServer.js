/**
 *
* OVERVIEW: In this activity, you will implement a REST service to manage contacts. The rest service will store/retrieve contacts
* in memory. The rest service will implement the following operations:

	GET /contacts/id  This will read the specified contact from in memory data structure and return it in the response.
	Format for the Response body is:
	{"firstName":"Bill","lastName":"Gates","phone":"32003200"}

	POST /contacts  This will accept a JSON payload, create the contact in memory data structure and return id in the response.
	Format of JSON request body is: {"firstName":"Bill","lastName":"Gates","phone":"32003200"}
	Format of the JSON response is: {id:<id-of-new-contact}

	PUT /contacts/id  This will update the specified contacts details with the details in the JSON payload.
	Only fields that are specified in the request body need to be updated. Other fields of that contact should
	remain unchanged.
	Format of JSON request body is: {"firstName":"Bill","lastName":"Gates","phone":"32003200"}
	Format of the JSON response is: {id:<id-of-updated-contact>}

* ERROR CASES: Handle all error cases including:
*		Any Url other than urls shown above should return 404
*		Return bad request if any query string parameters are passed.
*		Return 404 if a non-existent contact id is passed.

* NOTES:
      1) Ensure you are starting the nodejs http server by running node ContactsHttpServer.js before running the tests.
*/

var url = require('url');
var http = require('http');
var querystring = require('querystring');
var PORT = 3000;

// Add your code for the contact server below
arr = Array();

http.createServer(function(req, res) {
	if(req.method == 'GET'){
        //console.log("GET");
        var idx = req.url.indexOf("/contacts?id=");
       // console.log(req.url);
        //console.log(idx);
        if(idx != -1){
        	    var val = parseInt(req.url.substring(idx+"/contacts?id=".length,req.url.length));
        	   // console.log(val);
		       // console.log(idx+" : "+val + " "+arr.length);
		        if(val >= arr.length){
		        	res.statusCode = 404;
		        	res.end("err");
		        }
		        else{
		        	res.statusCode = 200;
		        	res.end(JSON.stringify(arr[val]));
		        }
        }
        idx = req.url.indexOf("/contacts/");
       // console.log(req.url);
       // console.log(idx);
        if( idx != -1){
        	var val = parseInt(req.url.substring(idx+"/contacts/".length,req.url.length));
        	    //console.log(val);
		        //console.log(idx+" : "+val + " "+arr.length);
		        if(val >= arr.length){
		        	res.statusCode = 404;
		        	res.end("err");
		        }
		        else{
		        	res.statusCode = 200;
		        	res.end(JSON.stringify(arr[val]));
		        }	
        }
        
        	res.statusCode = 404;
        	res.end("err");
        
    }
    else if(req.method == 'POST'){
        //console.log("POST");
        var body='';
        req.on('data', function (data) {
            body += data;
        });
        req.on('end', function() {
               // console.log("post : "+body);
                var jsn;
		        try{
		            jsn = JSON.parse(body);
		        }
		        catch(e){
		            jsn = body;
		        }
		        arr.push(jsn);
		        var ret = {id:arr.length-1};
		        //console.log(ret);
		        res.end(JSON.stringify(ret));
        });
        
    }
    else if(req.method == 'PUT'){
    	//console.log("put");
    	        var body='';
        req.on('data', function (data) {
            body += data;
        });
        req.on('end', function() {
                //console.log("post : "+body);
                var jsn;
		        try{
		            jsn = JSON.parse(body);
		        }
		        catch(e){
		            jsn = body;
		        }
		        idx = req.url.indexOf("/contacts/");
		        //console.log(req.url);
		       // console.log(idx);
		        if( idx != -1){
		        	var val = parseInt(req.url.substring(idx+"/contacts/".length,req.url.length));
		        	    //console.log(val);
				        //console.log(idx+" : "+val + " "+arr.length);
				        if(val >= arr.length){
				        	res.statusCode = 404;
				        	res.end("err");
				        }
				        else{
				        	res.statusCode = 200;
				        	Object.keys(jsn).forEach(function(key,index) {
				        		arr[val][key] = jsn[key];
							    // key: the name of the object key
							    // index: the ordinal position of the key within the object 
							});
				        	//arr[val]. = jsn;
				        	//console.log(arr);
				        	var ret = {id:arr.length-1};
				        	res.end(JSON.stringify(ret));
				        }	
		        }
        	res.statusCode = 404;
        	res.end("err");
        });
    	
    }
}).listen(PORT, function(err){
    if (err) {
        return console.log('something bad happened', err)
    }
    console.log("server is listening on " + PORT);
});


/*
var mysql      = require('mysql');
var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : 'pvsmpraveen',
  database : 'mrnd'
});
connection.connect();
	Mysql -> use mrnd; //database
	
	CREATE TABLE contacts
	(
	ID int NOT NULL AUTO_INCREMENT,
	firstName varchar(255),
	lastName varchar(255),
	PRIMARY KEY (ID)
	)

connection.query('SELECT * FROM contacts', function(err, rows, fields) {
  if (err) throw err;
  console.log(rows[0]);
});

*/