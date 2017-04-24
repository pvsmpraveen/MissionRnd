var theConnection = null;
var mysql = require("mysql");
var fs = require('fs');

/**
 * Before running your application update your DBConfig in the config.json file
 */
var theDbConfig = {};

/*
DONOT CHANGE THIS METHOD .
*/
function setDBConfigFromFile() {
    var configJson = fs.readFileSync(__dirname + "/config.json").toString();
    console.log("USING DATA BASE CONFIG AS , IF INCORRECT MODIFY THE CONFIG.JSON FILE");
    console.log(configJson);
    theDbConfig = JSON.parse(configJson);
}

//DONOT REMOVE THIS LINE.
setDBConfigFromFile();
/**
 * Method is used to create a connection to the database.
 * @returns {*} connection
 */
exports.getConnection = function () {
    theConnection = mysql.createConnection(theDbConfig);
    return theConnection;
};

/**
 * Method is used to terminate the database connection
 */
exports.endConnection = function () {
    if (theConnection != null) {
        theConnection.end();
    }
    theConnection = null;
};
