/**
 * Method is used to create a connection to the database.
 * @param dbconfig - contains host, port, database, user and password.
 * @returns {*} connection
 */
var mysql = require('mysql');
var connection = null;
exports.getConnection = function(dbconfig) {
    var kkeys = ["host","user","password","database","port"];
    for (var i in kkeys) {
        if(!dbconfig.hasOwnProperty(kkeys[i])) return null;
    }
    this.connection = mysql.createConnection(dbconfig);
    return this.connection;
};

/**
 * Method is used to terminate the database connection
 */
exports.endConnection = function() {
    this.connection.end();
};

/**
 * Method is used to retrieve the dbConfig used to connect to a database
 * @returns {{host: string, user: string, password: string, database: string, port: number}}
 */
exports.getDBConfig = function() {
    var details = {
        host: "localhost",
        user: "root",
        password: "root",
        database: "nodejs",
        port: 3306
    }
    return details;
};
