var tasks = require("./../models/tasks");

/**
 * This file will contain the methods to handle requests to /tasks url.
 *
 * Invoke appropriate methods from models/tasks file to perform corresponding DB operations.
 */
var express = require('express');
var router = express.Router();

var tasksM = require('../models/tasks');

//tasks?(filters...)
router.get('/', function(req, res, next) {
	res.end();
});

//tasks/id
router.get('/*', function(req, res, next) {
	res.end();
});


//tasks?(filters...)
router.put('/*',function(req,res,next){
	res.end();
})

//tasks/id
router.post('/*',function(req,res,next){
	console.log("POST");
	res.end();
})

//tasks?(filters...)
router.all('/',function(req,res,next){
    res.statusCode = 404;
    res.send();
})

//tasks/
router.delete('/*',function(req,res,next){
    console.log('delete2');
    res.send();

})


module.exports = router;
