var dbHelper = require('./databaseHelper');

//DROP OR DELETE TABLE AND THEN ONLY CREATE NEW TABLE.
exports.setupRestaurantsTable = function (callback) {
	var conn = dbHelper.getConnection();
	conn.query("drop table restaurants",function(err,result){
		conn.query("create table restaurants (id integer NOT NULL auto_increment,\
			name  char(31) NOT NULL,phone char(31) NOT NULL,budget integer NOT NULL,\
			cuisine char(31) NOT NULL,colony char(31) NOT NULL,city char(50) NOT NULL,primary KEY (id))",function(err, result){
     	 	callback(err,result);
    	});
	});
};

//Write other methods
exports.createRestaurant = function(restaurant, callback){
	var conn = dbHelper.getConnection();
	conn.query("insert into restaurants SET ?",[restaurant],function(err, result){
		if(err){
			callback(err,null);
			conn.end();
		}
		else{
			var keys = Object.keys(restaurant);
			var q = 'select * from restaurants ';
			for(i = 0;i<keys.length;i++){
				if(i==0){
					q+= 'where '; 
				}
				q+= keys[i]+" = '"+restaurant[keys[i]];
				if(i!=keys.length-1){
					q+="' and ";
				}
				else{
					q+="';";
				}
				
			}
			//console.log(q);
			conn.query(q,function(err,result){
				if(err) {
					callback(err,null);
					conn.end();
				}
				else{
					//console.log(result);
					callback(err,result[0].id);
					conn.end();
				}
			})
		}
	});
	
};

//done..
exports.getRestaurant = function(id, callback){
	var conn = dbHelper.getConnection();
	conn.query("select * from restaurants where id = "+id,function(err, result){
			     	if(err || result.length == 0){
			     		callback(404,null);
			     	}
			     	else{	
			     		callback(null,result[0]);
			     	}
			     	conn.end();
	});
};

//done..
exports.getRestaurants = function(qs,callback){
	var conn = dbHelper.getConnection();
	var keys = Object.keys(qs);
	var q = 'select * from restaurants ';
	for(i = 0;i<keys.length;i++){
			if(i==0){
					q+= 'where '; 
			}
			if(keys[i]=='budget'){
				q+= keys[i]+" <= '"+qs[keys[i]];
			}
			else{
				q+= keys[i]+" = '"+qs[keys[i]];	
			}
			if(i!=keys.length-1){
				q+="' and ";
			}
			else{
				q+="';";
			}
	}
	console.log(q);
	conn.query(q,function(err, result){
		res = [];
		if(err){
			callback(404,null);
		}
		else{	
			for (var i = 0;i<result.length;i++){
				res.push(result[i]);
			}
			callback(err,res);
			
		}
		conn.end();
	});
};

updateQuery = function(qs,wh){
	var keys = Object.keys(qs);
	var q = 'update restaurants set ';
	for(i = 0;i<keys.length;i++){
			q+= keys[i]+" = '"+qs[keys[i]];
			if(i!=keys.length-1){
				q+="' , ";
			}
			else{
				q+="'";
			}
	}
	var keyss = Object.keys(wh);
	q += " where "
	for(var i=0;i<keyss.length;i++){
			q+= keyss[i]+" = '"+wh[keyss[i]];
			if(i!=keyss.length-1){
				q+="' and ";
			}
			else{
				q+="';";
			}
	}
	return q;
}


exports.updateRestaurant = function(id,jsn, callback){
	var conn = dbHelper.getConnection();
		var q = updateQuery(jsn,id);
		console.log(q);
		conn.query(q,function(err,result){
			if(err){
				callback(404,null);
			}
			else{
				callback(200,"Sucess");
			}
		});


};

deleteQuery = function(wh){
	var q = 'delete from  restaurants ';
	var keyss = Object.keys(wh);
	q += " where "
	for(var i=0;i<keyss.length;i++){
			q+= keyss[i]+" = '"+wh[keyss[i]];
			if(i!=keyss.length-1){
				q+="' and ";
			}
			else{
				q+="';";
			}
	}
	return q;
}

exports.deleteRestaurant = function(id, callback){
	var conn = dbHelper.getConnection();
	conn.query("DELETE FROM restaurants where id = "+id,function(err,result){
		if(err){
			callback(404);
		}
		else{
			callback(null);
		}
	});
};

exports.deleteRestaurants = function(wh, callback){
	var conn = dbHelper.getConnection();
	var q = deleteQuery(wh);
	conn.query(q,function(err,result){
		if(err){
			callback(404);
		}
		else{
			callback(null);
		}
	});
};
