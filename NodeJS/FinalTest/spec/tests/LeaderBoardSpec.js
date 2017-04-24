var fs = require('fs');
var path = require('path');

var LeaderBoard = require("./../../src/Leaderboard.js");
var helper = require("./LeaderBoardSpecHelper.js");

var USERS_FILE_NAME = 'users.csv';
var LESSON1_FILE_NAME = "lesson1.csv";
var LESSON2_FILE_NAME = "lesson2.csv";
var LEADERBOARD_SMALL_FILE_NAME = "leaderboardsmall.csv";
var LEADERBOARD_LARGE_FILE_NAME = "leaderboardlarge.csv";


describe("Nodejs Small Leaderboard Spec", function () {


    it("testcase1 leaderboard small test", function (done) {
        var folderPath = path.resolve(__dirname, '..', '..', 'src', 'data', 'testcase1');
        LeaderBoard.generateLeaderBoardSmall(folderPath, function () {

            var fileContent = fs.readFileSync(path.join(folderPath, LEADERBOARD_SMALL_FILE_NAME)).toString().trim();
            console.log("TEST CASE");
            console.log(fileContent);
            helper.validateTestCase(1, fileContent, true);
            done();
        });
    });

    it("testcase2 leaderboard small test", function (done) {
        var folderPath = path.resolve(__dirname, '..', '..', 'src', 'data', 'testcase2');
        LeaderBoard.generateLeaderBoardSmall(folderPath, function () {

            var fileContent = fs.readFileSync(path.join(folderPath, LEADERBOARD_SMALL_FILE_NAME)).toString().trim();
            console.log("TEST CASE");
            helper.validateTestCase(2, fileContent, true);
            done();
        });
    });

});


describe("Nodejs Large Leaderboard Spec", function () {


    it("testcase1 leaderboard large test", function (done) {
        var folderPath = path.resolve(__dirname, '..', '..', 'src', 'data', 'testcase1');
        LeaderBoard.generateLeaderBoardLarge(folderPath, function () {

            var fileContent = fs.readFileSync(path.join(folderPath, LEADERBOARD_LARGE_FILE_NAME)).toString().trim();
            console.log("TEST CASE");
            helper.validateTestCase(1, fileContent, false);
            done();
        });
    });

    it("testcase2 leaderboard large test", function (done) {
        var folderPath = path.resolve(__dirname, '..', '..', 'src', 'data', 'testcase2');
        LeaderBoard.generateLeaderBoardLarge(folderPath, function () {

            var fileContent = fs.readFileSync(path.join(folderPath, LEADERBOARD_LARGE_FILE_NAME)).toString().trim();
            console.log("TEST CASE");
            helper.validateTestCase(2, fileContent, false);
            done();
        });
    });

});



describe("Nodejs Error Leaderboard Spec", function () {


    //Handle this error in both leaderboard small and large generation.
    // users.csv has 2 rows with same githubid
    it("error in users.csv", function (done) {
        var self = this;
        try {
            var folderPath = path.resolve(__dirname, '..', '..', 'src', 'data', 'errortestcase101');
            LeaderBoard.generateLeaderBoardSmall(folderPath, function (error) {

                if (!error) {
                    self.fail("Error should be thrown");
                } else {
                    expect(error.errorCode).toEqual(101);
                }
                //Should raise error for while generating large leaderboard also.
                LeaderBoard.generateLeaderBoardLarge(folderPath, function (error) {

                    if (!error) {
                        self.fail("Error should be thrown");
                    } else {
                        expect(error.errorCode).toEqual(101);
                    }
                    done();
                });
            });

        } catch (e) {
            self.fail(Error("exception : " + JSON.stringify(e)));
            done();
        }
    });

});
