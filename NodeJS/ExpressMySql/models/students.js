/**
 * In this file write the code to handle the database operations on the student's table.
 *
 * Handle operations
 *
 * CREATE UPDATE READ and DELETE
 */
var mysql = require('mysql');
var theConnection = null;

var Student = function(id,firstName, lastName, gender,totalMarks){
 	this.id = id;
    this.firstName = firstName;
    this.lastName = lastName;
    this.gender = gender;
    this.totalMarks = totalMarks;
};

exports.GetConnection = function(){
	if(theConnection != null) return this.theConnection;
	var connection = mysql.createConnection({
	  host     : 'localhost',
	  user     : 'root',
	  password : 'root',
	  database : 'nodejs'
	});
	this.theConnection = connection;
	return this.theConnection;
};

exports.EndConnection = function(){
	this.theConnection.end();
	this.theConnection  = null;
};

validate = function(obj,callback){
	//console.log('here');
	//console.log(obj);
	if(obj.hasOwnProperty("id")){
		delete obj["id"];
	}
	if(obj.hasOwnProperty("firstName")){
		if(obj["firstName"] == null){
			delete obj["firstName"];
		}
	}
	if(obj.hasOwnProperty("lastName")){
		if(obj["lastName"] == null){
			delete obj["lastName"];
		}
	}
	if(obj.hasOwnProperty("totalMarks")){
		if(!Number.isInteger(obj["totalMarks"])){
			callback(400,null);
			return;
		}
	}
	callback(null,obj);
}

validate2 = function(obj,callback){
	if(obj.hasOwnProperty("gender")){
		if(obj["gender"]!='M' && obj['gender']!='F' ){
			callback(400,null);
			return;
		}
	}
	if(obj.hasOwnProperty("totalMarks")){
		if(!Number.isInteger(obj["totalMarks"])){
			callback(404,null);
			return;
		}
	}
	callback(null,obj);
}

exports.AddStudent = function(student, callback){
	var conn = this.GetConnection();
	validate2(student,function(err,student){
		    if(err){
		    	callback(400,null);
		    }
		    else{
				conn.query("insert into students SET ?",[student],function(err, result){
			     	 callback(err,result);
			     	 conn.end();
			    });
			}
		}
	)
};

exports.ReadStudent = function(id, callback){
	var conn = this.GetConnection();
	//console.log("read student");
	//console.log(id);
	conn.query("select * from students where id = "+id,function(err, result){
		 //console.log(err);
		 //console.log(result);
     	 callback(err,result);
     	 conn.end();
    });
};

exports.ReadStudents = function(qs,callback){
	var conn = this.GetConnection();
	try{
		var keys = Object.keys(qs);
		var q = 'select * from students ';

		for(i = 0;i<keys.length;i++){
			if(i==0){
				q+= 'where '; 
			}
			q+= keys[i]+" = '"+qs[keys[i]];
			if(i!=keys.length-1){
				q+="' and ";
			}
			else{
				q+="';";
			}
			
		}
		conn.query(q,function(err, result){
			if(err){
				callback(err,result);
			}
			else{


				var res = new Array();
				for(var i = 0; i<result.length;i++){
						id = result[i].id;
						fname = result[i].firstName;
						lname = result[i].lastName;
						gender = result[i].gender;
						totalmarks = result[i].totalMarks;
						var c = new Student(id,fname,lname,gender,totalmarks);
						res.push(c);
				}
				callback(err,res);
				conn.end();
	    	}
	    });
	}
	catch(e){
		this.ReadContacts(qs,callback);
	}
	
};


exports.UpdateStudent = function(id, qs, callback){
	//console.log("updating");
	//console.log(id);
	//console.log(qs);
	var conn = this.GetConnection();
	try{
			var q = "update students set ";
			validate(qs,function(err,obj){
					if(err){
						callback(err,null);
						return;
					}
					else{
						key = Object.keys(obj);
						if(key.length == 0) {
							callback(null,null);
							return;
						}
						for(var i = 0;i<key.length;i++){
							q+= key[i]+" = '"+qs[key[i]];
							if(i != key.length-1){
								q+= "' , ";
							}
							else{
								q+= "' ";
							}
						}
						q += " where id = '"+id+"'";
						//console.log(q);
						conn.query(q,function(err, result){
							if(result.affectedRows){
								callback(err,result);
							}
							else{
								callback(404,result);
							}
						});
					}

			});
	}
	catch(e){
		console.log(e);
		//this.UpdateContact(callback);
	}
};


exports.DeleteStudent = function(id, callback){
	//console.log("Deleting");

	var conn = this.GetConnection();
	try{
		conn.query("delete from students where id = "+id,function(err, result){
			if(result.affectedRows){
				callback(err,result);
			}
			else{
				callback(404,result);
			}
			conn.end();
	    });
	}
	catch(e){
		//console.log(e);
		this.DeleteContact(callback);
	}
};


var conn = this.GetConnection();
try{
	conn.query("truncate students",function(err, result){
    });
}
catch(e){
	console.log(e);
}
