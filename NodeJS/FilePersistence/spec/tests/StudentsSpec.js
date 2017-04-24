var request = require('request');

var serverURL = "http://localhost:8080/";

var Student = function(id, firstName, lastName, gender, totalMarks){
    this.id = id;
    this.firstName = firstName;
    this.lastName = lastName;
    this.gender = gender;
    this.totalMarks = totalMarks;
};

function getFilePath() {
    var path = require('path');
    return path.join(__dirname, '..', '..', 'files');
}

describe("Nodejs FilePersistence Spec", function() {

    try {
        console.log("Deleting the student's data.... ");
        var fileName = getFilePath() + "/students.txt";
        fs.truncateSync(fileName);
    } catch (e) {
        console.log("delete file exception -- ignore ",e);
    }

    it("should get not existing student", function(done) {
        var self = this;

        request.get({
            url: serverURL,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                expect(body.length).toBe(0);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });

    });

    it("should create a student", function(done) {
        var student = new Student(32, "FirstName", "LastName", "male", 60);

        var self = this;
        var options = {
            url: serverURL,
            json: true,
            body: student
        };
        request.post(options, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should get the student", function(done) {
        var self = this;

        request.get({
            url: serverURL,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                expect(body.length).toBe(1);
                console.log(body);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });

    });

    it("should not create a duplicate student", function(done) {
        var student = new Student(32, "FirstName", "LastName", "male", 60);

        var self = this;
        var options = {
            url: serverURL,
            json: true,
            body: student
        };
        request.post(options, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(400);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should not create a student with invalid values", function(done) {
        var student = new Student(32, "FirstName", "LastName", "boy", 60);

        var self = this;
        var options = {
            url: serverURL,
            json: true,
            body: student
        };
        request.post(options, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(400);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should update the student", function (done) {
        var self = this;

        var student = new Student(32, "UpdatedName", "LastName", "male", 60);

        request.put({
            url: serverURL,
            json: true,
            body: student
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should get the student after update", function(done) {
        var self = this;

        request.get({
            url: serverURL,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                expect(body[0].firstName).toBe("UpdatedName");
                console.log(body);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });

    });

    it("should not update the columns passed as null", function (done) {
        var self = this;

        var student = new Student(32, "UpdatedName", null, "male", 60);

        request.put({
            url: serverURL,
            json: true,
            body: student
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should not update the columns with invalid values", function (done) {
        var self = this;

        var student = new Student(32, "UpdatedName", null, "boy", 60);

        request.put({
            url: serverURL,
            json: true,
            body: student
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(400);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should get the student after update1", function(done) {
        var self = this;

        request.get({
            url: serverURL,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                expect(body[0].firstName).toBe("UpdatedName");
                expect(body[0].lastName).not.toBe(null);
                console.log(body);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });

    });

    it("should create another student", function(done) {
        var student = new Student(33, "Thirty", "Three", "male", 70);

        var self = this;
        var options = {
            url: serverURL,
            json: true,
            body: student
        };
        request.post(options, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should get the students with more than 65 marks..", function(done) {
        var self = this;

        var getUrl = serverURL + "?totalMarks=65&operator=GT";
        request.get({
            url: getUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(body.length).toBe(1);
                expect(res.statusCode).toBe(200);
                expect(body[0].firstName).toBe("Thirty");
                console.log(body);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should create female student", function(done) {
        var student = new Student(34, "Thirty", "Four", "female", 70);

        var self = this;
        var options = {
            url: serverURL,
            json: true,
            body: student
        };
        request.post(options, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should get the female students with more than 65 marks..", function(done) {
        var self = this;

        var getUrl = serverURL + "?totalMarks=65&operator=GT&gender=female";
        request.get({
            url: getUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(body.length).toBe(1);
                expect(res.statusCode).toBe(200);
                expect(body[0].firstName).toBe("Thirty");
                console.log(body);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should delete the student 32", function(done) {
        var self = this;

        var delUrl = serverURL + "?id=32";

        request.del({
            url: delUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should delete the student 33", function(done) {
        var self = this;

        var delUrl = serverURL + "?id=33";

        request.del({
            url: delUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should delete the student 34", function(done) {
        var self = this;

        var delUrl = serverURL + "?id=34";

        request.del({
            url: delUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(200);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should not delete the student 35", function(done) {
        var self = this;

        var delUrl = serverURL + "?id=35";

        request.del({
            url: delUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(400);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should not delete if no filters are passed ", function(done) {
        var self = this;

        var delUrl = serverURL;

        request.del({
            url: delUrl,
            json: true
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(400);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });

    it("should not update the student 35", function(done) {
        var self = this;

        var student = new Student(35, "UpdatedName", "LastName", "male", 60);

        request.put({
            url: serverURL,
            json: true,
            body: student
        }, function(err, res, body) {
            try {
                expect(err).toBe(null);
                expect(res.statusCode).toBe(400);
                done();
            } catch(e) {
                self.fail(Error("exception : "+JSON.stringify(e)));
                done();
            }
        });
    });


});