var express = require('express');
var app = express();


/* Fill the code in routes/tickets.js so that it can help with ticket operations
 Defining routes in a dedicated folder and maintaining various routes for various flows helps in
 designing and writing rich functional servers.
 */
var tickets = require('./routes/tickets');
app.use("/tickets",tickets);


var server = app.listen(3001, function () {
    var port = server.address().port;
    console.log("Example app listening at port %s", port)
});

