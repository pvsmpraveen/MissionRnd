/**
 * In this file write the code to handle the requests coming to the /students route
 *
 * Handle operations
 *
 * GET POST PUT and DELETE.
 *
 * Invoke CRUD operation on students model file from models/students.js
 */
var express = require('express');
var router = express.Router();

var studentsDB = require('../models/students');




router.get('/', function(req, res, next) {
   // console.log("get1");
    var qs = req.query;
    //console.log(qs);
    var id = 0;
    try{
        studentsDB.ReadStudents(qs,function(err,result){
            if(err){
                res.statusCode = 400;
                res.end();
            }
            else{
                res.statusCode = 200;
                res.send(result);
            }
        })
    }
    catch(e){
            res.statusCode = 400;
            res.end();
    }
});


router.get('/*', function(req, res, next) {
    console.log("get");
    console.log(req.url);
    try{
        var id = parseInt(req.params["0"]);
        var qs = {id:id}
        studentsDB.ReadStudents(qs,function(err,result){
            if(err){
                //console.log(err);
                res.statusCode = 400;
                res.end();
            }
            else{
                res.statusCode = 200;
                //c//onsole.log(result[0]);
                res.send(result[0]);
            }
        })
    }
    catch(e){
            res.statusCode = 400;
            res.end();
    }
});


router.put('/*',function(req,res,next){
        //console.log("put1");
        var body='';
        req.on('data', function (data) {
            body += data;
        });
        req.on('end', function() {
                var jsn;
                var id = parseInt(req.params["0"]);
                if(isNaN(id)){
                    res.statusCode = 404;
                    res.send("id not found");
                }
                else{
                    try{
                        jsn = JSON.parse(body);
                    }
                    catch(e){
                        jsn = body;
                    }
                    studentsDB.UpdateStudent(id,jsn,function(err,result){
                        if(!err){
                            //console.log(result);
                            res.statusCode = 204;
                            res.end();
                        }
                        else if(err==404){
                            res.statusCode = 404;
                            res.end();
                        }
                        else {
                            res.statusCode = 400;
                            res.end();
                        }
                    })
                    //res.end();
                }
        });
})


router.post('/*',function(req,res,next){
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
                studentsDB.AddStudent(jsn,function(err,result){
                	if(err){
                		res.statusCode = 400;
                		res.send("err");
                	}
                	else{
                		res.statusCode = 201;
                		res.send("sucess");
                	}
                });
        });
})

router.all('/',function(req,res,next){
    res.statusCode = 404;
    res.send();
})


router.delete('/*',function(req,res,next){
   // console.log('delete2');
    //console.log(req.url);
    var id = parseInt(req.params["0"]);
    if(isNaN(id)){
        res.statusCode = 404;
        res.send("id not found");
    }
    else{
        studentsDB.DeleteStudent(id,function(err,result){
            if(err){
                res.statusCode = 404;
                res.send();
            }
            else{
                res.statusCode = 204;
                res.send();
            }
        })
    }
})


module.exports = router;

