var Ticket = function(src, dest, name, doj, facilities) {
    this.src = src;
    this.dest = dest;
    this.name = name;
    this.doj = doj;
    this.facilities = facilities;
};

var tickets = require("./../../src/models/tickets");
var dbHelper = require("./../../src/models/databaseHelper");

var request = require("request");

describe("Mock test server test cases ", function() {

    var ticketsUrl = "http://localhost:3001/tickets";

    var pnr;

    it("should setup the database table", function(done) {
        var connection = dbHelper.getConnection();
        expect(connection).not.toBe(null);
        tickets.setupTicketsTable(function(err, result) {
            expect(err).toBe(null);
            dbHelper.endConnection();
            done();
        });
    });

    it("should create ticket", function(done) {
        var self = this;
        var ticket = new Ticket("Hyderabad", "Bangalore", "nikhil", "2017-12-12", {});
        request.post({
                url: ticketsUrl,
                body: ticket,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(201);
                    pnr = "" + body;
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should get all the set of tickets ", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.length).toBe(1);
                    var pnr1 = body[0];
                    expect(typeof(pnr1)).toBe("string");
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should get all the set of tickets with full data ", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl + "/?fulldata=true",
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.length).toBe(1);
                    var ticket = body[0];
                    expect(Object.keys(ticket).length).toBe(6);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should retrieve ticket 1", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl + "/" + pnr,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.src).toBe("Hyderabad");
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    //here..

    it("should update ticket 1", function(done) {
        var self = this;
        var updatedTicket = {};
        updatedTicket.facilities = {
            "food": "non-veg"
        };

        request.put({
                url: ticketsUrl + "/" + pnr,
                body: updatedTicket,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(204);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should retrieve updated ticket 1", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl + "/" + pnr,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);

                    expect(body.facilities.food).toBe("non-veg");
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should delete the ticket id 1", function(done) {
        var self = this;
        request.del({
            url: ticketsUrl + "/" + pnr,
            json: true
        }, function(err, response, body) {
            try {
                expect(response.statusCode).toBe(204);
                done();
            } catch (e) {
                self.fail(Error(e));
                done();
            }
        });
    });

    it("should retrieve cancelled ticket 1", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl + "/cancelled",
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    //console.log("body is ",body, " pnr ",pnr, typeof pnr);
                    expect(body.length > 0).toBeTruthy();
                    expect(body.indexOf(pnr)).not.toBe(-1);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should retrieve cancelled tickets for 2017-12-12", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl + "/cancelled?doj=2017-12-12",
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(200);
                    expect(body.length > 0).toBeTruthy();
                    expect(body.indexOf(pnr)).not.toBe(-1);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should not create ticket invalid date ", function(done) {
        var self = this;
        var ticket = new Ticket("Hyderabad", "Bangalore", "nikhil", "1994-07-14", {});
        request.post({
                url: ticketsUrl,
                body: ticket,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("fetch should return 404 for invalid pnr", function(done) {
        var self = this;
        request.get({
                url: ticketsUrl + "/" + "123673783",
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(404);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("delete should return 404 for invalid pnr", function(done) {
        var self = this;
        request.del({
                url: ticketsUrl + "/" + "123673783",
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(404);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("delete should return 404 for already cancelled pnr", function(done) {
        var self = this;
        request.del({
                url: ticketsUrl + "/" + pnr,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(404);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("post should return 400 for null input values", function(done) {
        var self = this;
        var ticket = new Ticket("Hyderabad", null, null, "2017-12-12", {});
        request.post({
                url: ticketsUrl,
                body: ticket,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should return 400 for update with wrong fields", function(done) {
        var self = this;
        var updatedTicket = {};
        updatedTicket.name = "mani";

        request.put({
                url: ticketsUrl + "/" + pnr,
                body: updatedTicket,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

    it("should return 400 for update with other fields along with facilities", function(done) {
        var self = this;
        var updatedTicket = {};
        updatedTicket.facilities = {
            "food": "non-veg"
        };
        updatedTicket.name = "mani";

        request.put({
                url: ticketsUrl + "/" + pnr,
                body: updatedTicket,
                json: true
            },
            function(error, response, body) {
                try {
                    expect(response.statusCode).toBe(400);
                    done();
                } catch (e) {
                    self.fail(Error(e));
                    done();
                }
            });
    });

});