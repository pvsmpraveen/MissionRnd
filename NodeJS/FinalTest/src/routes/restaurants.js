/**
 * Created by vedurumu on 10/03/17.
 */
var express = require('express');
var router = express.Router();
var restaurant = require('./../models/restaurants');


//Some sample routes are provided , create more if needed.
//Use models/restaurants.js to perform appropriate CRUD Operations.
//require model file above .

/**
 * Creates routes here
 */

var express = require('express');
var app = express();
var body_parser = require('body-parser');
app.use(body_parser.json());
module.exports = app;
// for /?id=val pairs..

cities = ["hyderabad","vizag","bhimavaram"]
check = function(obj) {
	console.log(obj);
	if(obj.hasOwnProperty("budget") && obj.budget < 50 ) { return false; }
	if (obj.hasOwnProperty("cuisine") && (!(/^[a-zA-Z]+$/.test(obj.cuisine)) || obj.cuisine.length > 30)) {
		//console.log("cus failed");
   		return false;
	}
	if (obj.hasOwnProperty("name") && (!(/^[a-z A-Z]+$/.test(obj.name)) || obj.name.length > 30)){
   		//console.log("name failed");
   		return false;
	}
	if(obj.hasOwnProperty("phone") && (obj.phone.length > 10 || !(/^\d+$/.test(obj.phone)))) 
	{ 
		//console.log("phone failed");
	 	return false;
	}
	if(obj.hasOwnProperty("city")){
		var flag = false;
		var city = obj.city.toLowerCase();
		for(var i=0;i<3;i++){
			if(city == cities[i]) flag = true;
		}
		if(!flag) { 
			console.log("city Failed"); 
			return false; 
		}
	}
	if(obj.hasOwnProperty("colony") && obj.colony.length > 30) {
		console.log("conoly failed"); 
		return false; 
	}
	return true;
}

var Restaurant = function (name, phone, budget, cuisine, colony, city) {
    this.name = name;
    this.phone = phone;
    this.budget = budget;
    this.city = city;
    this.colony = colony;
    this.cuisine = cuisine;
};

//console.log(check( new Restaurant("Taj Mahal", "123", 500, "NorthIndian", "Banjara Hills", "Hyderabad")));
validparms = ["phone","budget","cuisine","colony","city"]

checkparams = function(obj){
	var keyss = Object.keys(obj);
	console.log(keyss);
	for(var i = 0;i<keyss.length;i++){
		if(validparms.indexOf(keyss[i]) == -1)
			return false;
	}
	return true;
}
app.route('/')
    .post(function(req,res,next){
    	//console.log("POST");
    	//console.log(req.body);
    	//console.log(check(req.body));
    	if(check(req.body) != true){
    		res.statusCode = 400;
    		res.send("Constraints Failed");
    		return;
    	}
    	else{
    		if(req.body.hasOwnProperty("cuisine")){
    			req.body.cuisine = req.body.cuisine.toLowerCase();
    		}
    		if(req.body.hasOwnProperty("colony")){
    			req.body.colony = req.body.colony.toLowerCase();
    		}
    		if(req.body.hasOwnProperty("city")){
    			req.body.city = req.body.city.toLowerCase();
    		}
	    	restaurant.createRestaurant(req.body, function(err,result){
	    		if(err){
	    			res.statusCode = 400;
	    			res.send("Error Occured");
	    		}
	    		else{
		    		res.statusCode = 201;
		    		res.send(""+result);
	    		}
	    	})
	    }
    })
    .get(function(req,res,next){
        console.log("GET");
        if(check(req.query) != true){
    		res.statusCode = 400;
    		res.send("Constraints Failed");
    		return;
    	}
        restaurant.getRestaurants(req.query,function(err,result){
        	if(err){
        		res.statusCode = 404;
        		res.send("Err");
        	}
        	else{
        		res.statusCode = 200;
        		res.send(result);
        	}
        })	       		
    })
    .delete(function(req,res,next){
        console.log("DELETE");
        if(check(req.query) != true){
    		res.statusCode = 400;
    		res.send("Constraints Failed");
    		return;
    	}        
    	restaurant.deleteRestaurants(req.query, function(err){
    		if(err) {
    			res.statusCode = err;
    			res.send("Failure");
    		}
    		else{
    			res.statusCode = 204;
    			res.send("Sucess")
    		}
   	 });
    });


// for /id 
app.route('/:id')
    .get(function(req,res,next){
		restaurant.getRestaurant(req.params.id,function(err,result){
        	if(err){
        		res.statusCode = 404;
        		res.send("Err");
        	}
        	else{
        		res.statusCode = 200;
        		res.send(result);
        	}
        });
   
     })
    .put(function(req,res,next){
        console.log("PUT - id");
        if(check(req.body) != true){
    		res.statusCode = 400;
    		res.send("Constraints Failed");
    		return;
    	}
    	if(checkparams(req.body) != true){
    		res.statusCode = 400;
    		res.send("Invalid Params");
    		return;
    	}
    	if(req.body.hasOwnProperty("name") || req.body.hasOwnProperty("id")){
    		res.statusCode = 400;
    		res.send("Name or Id cannot be updated");
    		return;
    	}
    	console.log(req.params);
		restaurant.updateRestaurant(req.params,req.body,function(err,result){
        	if(err !=200 ){
        		res.statusCode = 400;
        		res.send("Err");
        	}
        	else{
        		res.statusCode = 200;
        		restaurant.getRestaurant(req.params.id,function(err,bbdy){
        				res.send(bbdy);
        		})
        		
        	}
        });

    })
    .delete(function(req,res,next){
        console.log("DELETE - id");
    	restaurant.deleteRestaurant(req.params.id, function(err){
    		if(err) {
    			res.statusCode = err;
    			res.send("Failure");
    		}
    		else{
    			res.statusCode = 204;
    			res.send("Sucess")
    		}
   	 });
})

app.all('/',function(req,res,next){
    res.statusCode = 404;
    res.send("Error Page Not Found");
})
