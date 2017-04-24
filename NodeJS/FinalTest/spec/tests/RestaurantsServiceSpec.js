var Restaurant = function (name, phone, budget, cuisine, colony, city) {
    this.name = name;
    this.phone = phone;
    this.budget = budget;
    this.city = city;
    this.colony = colony;
    this.cuisine = cuisine;
};

var restaurants = require("./../../src/models/restaurants");
var dbHelper = require("./../../src/models/databaseHelper");

var request = require("request");

//Load Sample data.
var restaurantsData = [];
restaurantsData.push(new Restaurant("Taj Mahal", "12345", 500, "NorthIndian", "Banjara Hills", "Hyderabad"));
restaurantsData.push(new Restaurant("Chutneys", "78547", 300, "SouthIndian", "Himayat Nagar", "hyderabad"));
restaurantsData.push(new Restaurant("Cozinha De Goa", "7720442239", 600, "seafood", "mvpcolony", "vizag"));

function validateRestaurant(actualRestaurant, expectedRestaurant) {
    var expectedKeys = Object.keys(expectedRestaurant);
    for (var i in expectedKeys) {
        var key = expectedKeys[i];
        expect(actualRestaurant[key].toString().toLowerCase()).toEqual(expectedRestaurant[key].toString().toLowerCase());
    }

}
/*
Checks whether body has all restaurents correctly or not.
Which restaurants are to be present are specified in restaurant indexes.
*/
function validateGetBody(body, restaurentIndexes) {
    var restaurantsDictionary = {};
    for (var i in restaurentIndexes) {
        restaurantsDictionary[restaurantsData[i].name] = restaurantsData[i];
    }
    for (var bodyIndex in body) {
        var restaurantBody = body[bodyIndex];
        delete restaurantBody.id;
        var name = restaurantBody.name;
        validateRestaurant(restaurantBody, restaurantsDictionary[name]);
    }
}

function validateGetBodySingle(body, index) {
    var restaurantBody = body;
    delete restaurantBody.id;
    var name = restaurantBody.name;
    validateRestaurant(restaurantBody, restaurantsData[index]);
}

console.log("TEST CASES MIGHT TAKE LOT OF TIME, as everything timesout ,USE XIT and run specific testcases");
//TEST CASES START
describe("Sample test server test cases ", function () {

    var restaurantsURL = "http://localhost:3001/restaurants";

    var id, secondId;

    var vizagId;

    it("should setup the database table", function (done) {
        var connection = dbHelper.getConnection();
        expect(connection).not.toBe(null);
        restaurants.setupRestaurantsTable(function (err, result) {
            expect(err).toBe(null);
            dbHelper.endConnection();
            done();
        });
    });
    
    //CREATE TEST CASES - SUCCESS ONES
    it("should create restaurant in hyderabad", function (done) {
        var self = this;
        var rest = restaurantsData[0];
        console.log(rest);
        request.post({
                url: restaurantsURL,
                body: rest,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(201);
                    id = "" + body;
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should create new restaurant in hyderabad", function (done) {
        var self = this;
        var rest = restaurantsData[1];
        request.post({
                url: restaurantsURL,
                body: rest,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(201);
                    secondId = "" + body;
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });



    it("should create new restaurant in vizag", function (done) {
        var self = this;
        var rest = restaurantsData[2];
        request.post({
                url: restaurantsURL,
                body: rest,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(201);
                    vizagId = "" + body;
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    //CREATE TEST CASES - ERROR .
    it("should not create restaurant invalid phone ", function (done) {
        var self = this;
        var rest = new Restaurant("Taj Mahal", "125object", 500, "SouthIndian", "Banjara Hills", "Hyderabad");
        request.post({
                url: restaurantsURL,
                body: rest,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    //GET TEST CASES  - SUCCESS ONES
    it("should get all the set of restaurants ", function (done) {
        var self = this;
        request.get({
                url: restaurantsURL,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.length).toBe(3);
                    validateGetBody(body, [0, 1, 2]);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should get all the set of restaurants in hyderabad ", function (done) {
        var self = this;
        request.get({
                url: restaurantsURL + "/?city=hyderabad",
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.length).toBe(2);
                    validateGetBody(body, [0, 1]);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });


    it("should retrieve restaurant 1", function (done) {
        var self = this;
        request.get({
                url: restaurantsURL + "/" + id,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.city.toLowerCase()).toBe("Hyderabad".toLowerCase());
                    validateGetBodySingle(body, [0]);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    }); 

    it("should retrieve restaurant by cuisine", function (done) {
        //THIS Should return a list ,even if there is only one restaurant
        var self = this;
        request.get({
                url: restaurantsURL + "/?cuisine=seafood",
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    //body[0] will get first restaurant, comparing it with vizag's.

                    expect(body.length).toEqual(1);
                    validateGetBodySingle(body[0], [2]);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should retrieve restaurant by cuisine and city", function (done) {
        //THIS Should return a list ,even if there is only one restaurant
        var self = this;
        request.get({
                url: restaurantsURL + "/?cuisine=northindian&city=hyderabad",
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);

                    expect(body.length).toEqual(1);
                    validateGetBodySingle(body[0], [0]);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should retrieve restaurant by budget", function (done) {
        //THIS Should return a list ,even if there is only one restaurant
        var self = this;
        request.get({
                url: restaurantsURL + "/?budget=510",
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    //validateGetBodySingle(body, [0, 1]);
                    console.log("BUDGET GET");
                    expect(body.length).toEqual(2);
                    console.log(body);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    //GET ERROR CASES
    it("fetch should return 404 for not existing restaurant id ", function (done) {
        var self = this;
        request.get({
                url: restaurantsURL + "/" + "123673783",
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(404);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("fetch should return 404 for not invalid cusinie ", function (done) {
        var self = this;
        request.get({
                url: restaurantsURL + "/" + "?cuisine=morethan30chars1234567890123456789012345678end",
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);

                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    //UPDATE FLOW TEST CASES - SUCCESS
    it("should update restaurant 1", function (done) {
        var self = this;
        var updatedRestaurant = {};
        updatedRestaurant.cuisine = "Tiffins";
        //the below line is for testcase.
        restaurantsData[0].cuisine = "Tiffins";
        request.put({
                url: restaurantsURL + "/" + id,
                body: updatedRestaurant,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    //console.log("UPDATED BODY");
                    //console.log(body);
                    validateGetBodySingle(body, 0);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should retrieve updated ticket 1", function (done) {
        var self = this;
        request.get({
                url: restaurantsURL + "/" + id,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.cuisine).toBe("Tiffins");
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should update restaurant 1 with budget", function (done) {
        var self = this;
        var updatedRestaurant = {};
        updatedRestaurant.budget = 1000;
        //the below line is for testcase.
        restaurantsData[0].budget = 1000;
        request.put({
                url: restaurantsURL + "/" + id,
                body: updatedRestaurant,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    //console.log("UPDATED BODY");
                    //console.log(body);
                    validateGetBodySingle(body, 0);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    //UPDATE ERROR CASES
    
    it("should update city of Taj Mahal hotel to invalid city", function (done) {
        var self = this;
        var updatedRestaurant = {};
        updatedRestaurant.city = "Chennai";

        request.put({
                url: restaurantsURL + "/" + id,
                body: updatedRestaurant,
                json: true
            },
            function (error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });


    //DELETE SUCCESS CASES - 204
    it("should delete the restaurant id 1", function (done) {
        var self = this;
        request.del({
            url: restaurantsURL + "/" + id,
            json: true
        }, function (err, response, body) {
            try {
                expect(response.statusCode).toBe(204);
                done();
            } catch (e) {
                self.fail(Error(e));
                done();
            }
        });
    });
    
    //get deleted restaurant
    it("should delete the restaurant id 1", function (done) {
        var self = this;
        request.get({
            url: restaurantsURL + "/" + id,
            json: true
        }, function (err, response, body) {
            try {
                expect(response.statusCode).toBe(404);
                done();
            } catch (e) {
                self.fail(Error(e));
                done();
            }
        });
    });

    it("should delete the restaurants in vizag", function (done) {
        var self = this;
        request.del({
            url: restaurantsURL + "/?city=vizag",
            json: true
        }, function (err, response, body) {
            try {
                expect(response.statusCode).toBe(204);
                done();
            } catch (e) {
                self.fail(Error(e));
                done();
            }
        });
    });

    //get deleted restaurant
    it("should delete the restaurant vizagID 1", function (done) {
        var self = this;
        request.get({
            url: restaurantsURL + "/" + vizagId,
            json: true
        }, function (err, response, body) {
            try {
                expect(response.statusCode).toBe(404);
                done();
            } catch (e) {
                self.fail(Error(e));
                done();
            }
        });
    });


    it("should again delete the restaurants in vizag", function (done) {
        var self = this;
        request.del({
            url: restaurantsURL + "/?city=vizag",
            json: true
        }, function (err, response, body) {
            try {
                expect(response.statusCode).toBe(204);
                done();
            } catch (e) {
                self.fail(Error(e));
                done();
            }
        });
    });
    
});
