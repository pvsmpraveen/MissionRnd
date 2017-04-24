var mysql = require('mysql');

var theConnection = null;

/*
 OVERVIEW: 	Implement GetConnection so it connects to the mysql db containing
 the contacts table. Read up http://mission-rnd.github.io/nodejs_mysql.htm
 to know what the contacts table schema should be.

 OUTPUT:		The function should set theConnection variable to a valid connection.

 ERROR CASES: Return null in case of an error connecting to the db.

 NOTES: 		1) Ensure you'e started mysql server and created the contacts table before running the tests.
 2) Ensure connection is opened only if theConnection is null.
 */

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

/*
 OVERVIEW: 	AddContact function takes a contact object and inserts it into the contacts table in mysql db.

 INPUTS:		contact - Javascript object with properties (firstName, lastName, phone)
 callback(err, result) - Function to invoke after insertion where err and result are the mysql err
 and result objects respectively

 OUTPUT:		None

 ERROR CASES: error object should be passed to callback().

 NOTES: 		  Pay attention to the casing of contact object properties (firstName, lastName, phone). If these are different from the casing
 of the fields in the contacts table, ensure you are doing the needed mapping/conversions.

 */
 var Contact = function(firstName, lastName, phone){
    this.firstName = firstName;
    this.lastName = lastName;
    this.phone = phone;
};


exports.AddContact = function(contact, callback){
	conn = this.GetConnection();
	//console.log(contact);
	conn.query("insert into contacts SET ?",[contact],function(err, result){
     	 callback(err,result);
     	 conn.end();
    });
};

/*
 OVERVIEW: 	ReadContact function takes a contact id and reads the contact record from mysql

 INPUTS:		id - integer id representing contact id

 callback(err, contact) - Function to invoke after reading

 OUTPUT:		callback() should be invoked with a Javascript object reprsenting the contact record read from the db.

 ERROR CASES: error object should be passed to callback().


 */
exports.ReadContact = function(id, callback){
	var conn = this.GetConnection();
	conn.query("select * from contacts where id = "+id,contact,function(err, result){
     	 callback(err,result);
     	 conn.end();
    });
};

/*
 OVERVIEW: 	ReadContacts function reads all the records from contacts table.

 INPUTS:		callback(err, contacts) - Function to invoke after reading

 OUTPUT:		callback() should be invoked with a Javascript array reprsenting all the contact records read from the db.

 ERROR CASES: error object should be passed to callback().


 */
exports.ReadContacts = function(callback){
	
	console.log("reading");
	
	var conn = this.GetConnection();
	try{
		conn.query("select * from contacts",function(err, result){
			//console.log(result);
				var res = new Array();
				for(var i = 0; i<result.length;i++){
						fname = result[i].firstname;
						lname = result[i].lastname;
						phone = result[i].phone;
						var c = new Contact(fname,lname,phone);
						res.push(c);
				}
				callback(err,res);
				conn.end();
	    });
	}
	catch(e){
		//console.log(e);
		this.ReadContacts(callback);
	}
	
};

/*
 OVERVIEW: 	UpdateContact function updates a specified contact record..

 INPUTS:		id - contact id tht needs to be updated.
 newPhoneNumber - new phone number for the contact
 callback(err, result) - Callback to be invoked.

 OUTPUT:		callback() should be invoked with a Javascript object representing the UPDATED row (ie read the updated row and pass that
 to the callback).

 ERROR CASES: error object should be passed to callback().


 */
exports.UpdateContact = function(id, newPhoneNumber, callback){
	console.log("updating");
	
	var conn = this.GetConnection();
	try{
		conn.query("update contacts set phone = '"+newPhoneNumber+"' where id = "+id,function(err, result){
				conn.query("select * from contacts where id = "+id,function(err, result1){
					//console.log(result1);
						fname = result1[0].firstname;
						lname = result1[0].lastname;
						phone = result1[0].phone;
						var res = new Contact(fname,lname,phone);
						callback(err,res);
	   					conn.end();
	   			});

	    });
	}
	catch(e){
		//console.log(e);
		this.UpdateContact(callback);
	}
};

/*
 OVERVIEW: 	DeleteContact function deletes a specified contact record..

 INPUTS:		id - contact id tht needs to be deleted.
 callback(err, result) - Callback to be invoked.

 OUTPUT:		callback() should be invoked with the corresponding err,result objects from mysql.

 ERROR CASES: error object should be passed to callback().


 */
exports.DeleteContact = function(id, callback){
	console.log("Deleting");

	var conn = this.GetConnection();
	try{
		conn.query("delete from contacts where id = "+id,function(err, result){
			callback(err,result);
			conn.end();
	    });
	}
	catch(e){
		//console.log(e);
		this.DeleteContact(callback);
	}
};


