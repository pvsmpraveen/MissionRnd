/**
 * Fill this method to create required tables for storing tickets.
 *
 * Also, this method should clear off any existing data.
 *
 * @param callback Send the err and result of the DDL operation appropriately
 */
var dbHelper = require("./../../src/models/databaseHelper");

exports.setupTicketsTable = function (callback) {
	var conn = dbHelper.getConnection();
	conn.query("drop table Tickets",function(err,result){
		console.log(err);
		conn.query("create table Tickets (pnr int(6) zerofill NOT NULL auto_increment,\
			src char(50) NOT NULL,dest char(50) NOT NULL,name char(50) NOT NULL,facilities\
			text,doj char(50) NOT NULL,status boolean,primary key(pnr))",function(err, result){
     	 callback(err,result);
    	});
	});
};


exports.createTicket = function(ticket, callback){
	var conn = dbHelper.getConnection();
	ticket.facilities = JSON.stringify(ticket.facilities);
	ticket.status = 1;
	conn.query("insert into tickets SET ?",[ticket],function(err, result){
		if(err){
			callback(err,result);
			conn.end();
		}
		else{
			var keys = Object.keys(ticket);
			var q = 'select * from tickets ';
			for(i = 0;i<keys.length;i++){
				if(i==0){
					q+= 'where '; 
				}
				q+= keys[i]+" = '"+ticket[keys[i]];
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
					callback(err,result[0].pnr);
					conn.end();
				}
			})
		}
	});
	
};

//done..
exports.getTicket = function(pnr, callback){
	var conn = dbHelper.getConnection();
	conn.query("select * from tickets where pnr = "+pnr,function(err, result){
			     	if(err || result.length == 0){
			     		callback(404,null);
			     	}
			     	else{	
			     		result[0].facilities = JSON.parse(result[0].facilities);
			     		callback(null,result[0]);
			     	}
			     	conn.end();
	});
};

//done..
exports.getTickets = function(qs,fulldata,callback){
	var conn = dbHelper.getConnection();
	
	var keys = Object.keys(qs);
	var q = 'select * from tickets ';
	for(i = 0;i<keys.length;i++){
			if(i==0){
					q+= 'where '; 
			}
			q+= keys[i]+" like '"+qs[keys[i]];
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
			if(fulldata == true){
				for (var i = 0;i<result.length;i++){
					result[i].facilities = JSON.parse(result[i].facilities);
					res.push(result[i]);
				}
			}
			else{
				for(var i = 0;i<result.length;i++){
					res.push(result[i].pnr);
				}
			}
			callback(err,res);
			
		}
		conn.end();
	});
};


exports.updateTicket = function(jsn,pnr, callback){
	var conn = dbHelper.getConnection();
	conn.query("select facilities from tickets where pnr = "+pnr,function(err,result){
			if(err || result.length==0){
				callback(404,null);
				return;
			}


			var newjsn;
			try{
				newjsn = JSON.parse(result[0].facilities);
			}
			catch(e){
				newjsn = result[0].facilities;
			}

			var add = jsn.facilities;
			var keyss = Object.keys(add);

			for (var key in add) { newjsn[key] = add[key]; }
			
			var upd = {facilities: JSON.stringify(newjsn)}

			//console.log(upd);
			
			conn.query("update tickets SET ? where PNR = '"+pnr+"'",[upd],function(err,result){
				if(err){
					callback(404,null);
				}
				else{
					callback(204,"Sucess");
				}
			});

	});
};


exports.deleteTicket = function(pnr, callback){
	var conn = dbHelper.getConnection();
	//console.log("Delete Ticket Db");

	conn.query("select * from tickets where status = 1 and pnr = "+pnr,function(err,result){
			//console.log(result);
			if(err || result.length==0){
				callback(404,null);
				return;
			}
			var q = "update tickets set status = 0 where pnr = "+pnr;
			//console.log(q);
			conn.query(q,function(err,result){
				if(err ){
					callback(404,null);
				}
				else{
					callback(204,"Sucess");
				}
			});
	});
};

