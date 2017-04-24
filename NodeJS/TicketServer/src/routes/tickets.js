/**
 * Route all the requests to /tickets to this file....
 *
 * Use models/tickets.js to perform appropriate CRUD Operations.
 */

var express = require('express');
var app = express();
var body_parser = require('body-parser');
var ticket = require('./../models/tickets');
app.use(body_parser.json());
module.exports = app;
var ticketsDB = require('../models/tickets');

// for /?id=val pairs..

app.route('/')
    .post(function(req,res,next){
    	console.log("POST")
        var data = req.body;
        var dj = new Date(data.doj);
        var di = new Date();
        //ignored months >=4
        if(!(dj.getFullYear() >= di.getFullYear() && dj.getMonth()>=di.getMonth())){
            res.statusCode = 400;
            res.send("Error 400");
            return;
        }
		ticketsDB.createTicket(req.body,function(err,pnr){
                	if(err){
                		res.statusCode = 400;
                		res.send("Err");

                	}
                	else{
                		//console.log(pnr);
                		res.statusCode = 201;
                		res.send(pnr);
                	}
        })
    })
    .get(function(req,res,next){
        console.log("GET");
	    var qs = req.query;
	    console.log(qs);
	    var fulldata = qs.fulldata;
	    delete qs["fulldata"];
	    qs.status = 1;

	    //console.log(qs);
	    var id = 0;
	    
	    ticketsDB.getTickets(qs,fulldata,function(err,result){
	            if(err){
	                res.statusCode = 400;
	                res.send("Err");
	            }
	            else{
	                res.statusCode = 200;
	                res.send(result);
	            }
	    });
	       		
    })
    .put(function(req,res,next){
        console.log("PUT");
        console.log(req.body);
        res.send("PUT")
    })
    .delete(function(req,res,next){
        console.log("DELETE");
        console.log(req.body);
        res.send("DELETE")
    });




// for /xyz route

app.route('/cancelled')
    .post(function(req,res,next){
        console.log("POST - cancelled");
        console.log(req.body);

        res.send("POST- cancelled")
    })
    .get(function(req,res,next){
        console.log("GET - cancelled");
        var qs = req.query;
        console.log(req.query);
        qs.status = 0;
       // console.log(qs);
        ticketsDB.getTickets(qs,false,function(err,result){
            if(err){
                res.statusCode = err;
                res.end();
            }
            else{
                res.statusCode = 200;
                res.send(result);
            }
        });
    })
    .put(function(req,res,next){
        console.log("PUT - cancelled");
                console.log(req.body);

        res.send("PUT - cancelled")
    })
    .delete(function(req,res,next){
        console.log("DELETE - cancelled");
                console.log(req.body);

        res.send("DELETE - cancelled")
    });

// for /id 
app.route('/:pnr/:ok/:okwer/:oweiurwe/').get(function(req,res,next){
	res.send(req.params);

})
app.route('/:pnr')
    .post(function(req,res,next){
        console.log("POST - pnr");
    })
    .get(function(req,res,next){
    	var par = req.params;
    	var pnr = par.pnr;
    	console.log("GET - pnr");
    	ticketsDB.getTicket(pnr,function(err,result){
            if(err){
                res.statusCode = err;
                res.end();
            }
            else{
                res.statusCode = 200;
                res.send(result);
            }
        });       
     })
    .put(function(req,res,next){
        console.log("PUT - pnr");
        var pnr = req.params.pnr;
        var keyss = Object.keys(req.body);
        if(keyss.length != 1 || keyss[0]!='facilities'){
            res.statusCode = 400;
            res.send();
        }
        else{
            ticketsDB.updateTicket(req.body,pnr,function(err,result){
            if(err){
                res.statusCode = err;
                res.send("Err");
            }
            else{
                res.statusCode = 204;
                res.send("Sucess");
            	}
        	});
        }
    })
    .delete(function(req,res,next){
        console.log("DELETE - pnr");
        var pnr = req.params.pnr;
        ticketsDB.deleteTicket(pnr,function(err,result){
            if(err){
                res.statusCode = err;
                res.end();
            }
            else{
                res.statusCode = 200;
                res.send(result);
            }
        });
    });

app.all('/',function(req,res,next){
    res.statusCode = 404;
    res.send("Error Page Not Found");
})