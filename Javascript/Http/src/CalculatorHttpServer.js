/**
* OVERVIEW: Implement a CalculatorService that supports the following http operations:
*       GET /calculator?op=<operation>op1=<num>&op2=<num>
*       POST /calculator and request body is a json object {"op":"<operation>","op1":"<num1>","op2":"<num2>"}
*       
*       Both GET/POST opertions should return 200 code on success and the response body should be the
*       sum of the 2 numbers
*
*       Supported Operations:add,sub,mul,div
*
* ERROR CASES: Handle all error cases including:
*       Any Url other than /calculator/sum should return 404. 
*       Return status code for "bad request" if op1 and op2 are not numbers.
*       Return status code for "method not allowed" if the request method is neither GET or POST
*       LookUp the error code for bad request and method not allowed

* NOTES: Ensure you are starting the nodejs http server by running node CalculatorHttpServer.js before running the tests.
*/

var http = require('http');
var querystring = require('querystring');
var url = require('url');
var PORT = 3000;

// Add your code to startup http server and process request here.
var getResults = function(obj,callback){
    //console.log("getresults : " );

    
    //console.log(jsn);
    try{
        console.log(obj);
        var jsn;
        try{
            jsn = JSON.parse(obj);
        }
        catch(e){
            jsn = obj;
        }
        var op = jsn["op"];
        if(!jsn.hasOwnProperty('op') || !jsn.hasOwnProperty('op1') || !jsn.hasOwnProperty('op2')) {
            throw err;
        }
        var a = parseInt(jsn["op1"]);
        var b = parseInt(jsn["op2"]);
        if(isNaN(a) || isNaN(b)) throw err;
        console.log(op+" "+a+" "+b);
        var ret;
        if(op=='mul')      ret = a*b;
        else if(op=='sub') ret = a-b;
        else if(op=='add') ret = a+b;
        else if(op=='div'){ if(b==0) ret = Infinity; else ret = a/b;}
        console.log("return : "+ret);
        return ret;
    }
    catch(e){
        console.log("err");
        return null;
    }
    return;
}

http.createServer(function(req, res) {
    var jsn;
    var extracted = req.url.match(/^\/([^?\/]+)/)[1]
    if(extracted != "calculator"){
        res.statusCode = 404;
        res.end("err");
    }
    if(req.method == 'GET'){
        var regex = /[?&]([^=#]+)=([^&#]*)/g, 
            url = req.url,
            params = {},
            match;
        while(match = regex.exec(url)) {
            params[match[1]] = match[2];
        }
        jsn = params;   
        var ret = getResults(jsn);
        if(ret==null){
                    res.statusCode = 400;
                    res.end("err");
        }
        else{
            res.statusCode = 200;
            res.end(""+ret);
        }

    }
    else if(req.method == 'POST'){
        console.log("POST");
        var body='';
        req.on('data', function (data) {
            body += data;
        });
        req.on('end', function() {
                console.log("post : "+body);
                var ret = getResults(body);
                console.log(ret);
                if(ret==null){
                    res.statusCode = 400;
                    res.end("err");
                }
                else{
                    res.statusCode = 200;
                    res.end(""+ret);
                }
        });
    }
    else{
        res.statusCode = 405;
        res.end("err");
    }
    
    
}).listen(PORT, function(err){
    if (err) {
        return console.log('something bad happened', err)
    }

    console.log("server is listening on " + PORT);
});
var p = { op: 'sub', op1: '6', op2: '3' };
console.log(getResults(p,function(err,ans){
    if(err){
        console.log(err);
    }
    else{
        console.log("here"+ans);
    }
}));
var someString = '/articles?page=1';
var extracted = someString.match(/^\/([^?\/]+)/)[1]
console.log(extracted);
console.log("server running at port "+PORT);