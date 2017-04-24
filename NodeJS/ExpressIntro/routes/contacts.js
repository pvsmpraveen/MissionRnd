/* This exercise is basically similar in content as the one written with http module.
   But here you will implement the same using express and as a different route.
   Once done, Compare both the works and try to understand the importance of express when writing high functional servers.
 */

/*
* OVERVIEW: In this activity, you will implement a route to manage contacts. The rest service will store/retrieve contacts
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
*/

var express = require('express');
var router = express.Router();

var arr = new Array();
router.get('/', function(req, res, next) {
    console.log("get1");
    var qs = req.query;
    console.log(qs);
    var id = 0;
    try{
        id = parseInt(qs.id);
        console.log(id);
        if(id>=arr.length){
            res.statusCode = 404;
            res.end();
        }
        else{
            res.statusCode = 200;
            res.send(JSON.stringify(arr[id]));            
        }
    }
    catch(e){
            res.statusCode = 404;
            res.end();
    }
});

router.get('/*', function(req, res, next) {
    console.log("get");
    var id = req.url.substring(1,req.url.length);
    try{
        id = parseInt(id);
        console.log(id);
        if(id>=arr.length){
            res.statusCode = 404;
            res.end();
        }
        else{
            res.statusCode = 200;
            console.log(arr[id]);
            res.send(JSON.stringify(arr[id]));            
        }
    }
    catch(e){
        res.statusCode = 404;
        res.send("404");
    
    }

});

router.put('/*', function(req, res, next) {
    console.log("put");
    var id = req.url.substring(1,req.url.length);
    try{
        id = parseInt(id);
    }
    catch(e){
        res.statusCode = 404;
        res.end();
    }
        var body='';
        req.on('data', function (data) {
            body += data;
        });
        req.on('end', function() {
                var jsn;
                try{     jsn = JSON.parse(body);
                }
                catch(e){
                    jsn = body;
                }
                var keys = Object.keys(jsn);
                console.log(keys);
                if(id >= arr.length){
                    res.statusCode = 404;
                    res.end();
                }
                else{
                    for(var i in keys){
                        arr[id][keys[i]] = jsn[keys[i]];
                    }
                    res.statusCode = 200;
                    var ret = {id:id};
                    res.send(ret);
                    res.end();
                }
        });    
});

router.post('/*', function(req, res, next) {
    console.log("post");
        var body='';
        req.on('data', function (data) {
            body += data;
        });
        req.on('end', function() {
                var jsn;
                try{
                    jsn = JSON.parse(body);
                }
                catch(e){
                    jsn = body;
                }
                console.log(jsn);
                arr.push(jsn);
                var ret = {id:arr.length-1};
                //console.log(ret);
                res.end(JSON.stringify(ret));
        });
    
});



module.exports = router;