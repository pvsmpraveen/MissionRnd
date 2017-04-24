/**
 * Created by sangu on 10/03/17.
 */
//node+express tutorial

var express = require('express');
var path = require('path');
var app = express();


/* F
 Defining routes in a dedicated folder and maintaining various routes for various flows helps in designing and writing rich functional servers.
 Figure out the way how you can use the below users route for this app
 */
var restaurants = require('./routes/restaurants.js');

var bodyParser = require('body-parser');
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({
    extended: false
}));

app.use("/restaurants", restaurants);

app.use(function (req, res) {
    res.status(404);
    res.send({
        "status": 404,
        "message": "The requested URL was not found"
    });
});

var server = app.listen(3001, function () {
    var port = server.address().port;

    console.log("Example app listening at port %s", port);
    console.log("Thanks for being part of MissionRnD till now ,Hope you have a successfull career. You are already better than most of the folks who dont know how to start an Express server \nAll the best \nAbhijith & Nikhil\n");
    console.log("Your Server has been started , you can run the testcases");
})
