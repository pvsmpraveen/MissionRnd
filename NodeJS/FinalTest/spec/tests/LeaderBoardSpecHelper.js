var ABHIJITH = "abhijith";
var NIKHIL = "nikhil";
var VINEETHA = "vineetha";
var SACHIN = "sachin";
var SOURAV = "sourav";
var DRAVID = "dravid";
var LUFFY = "luffy";
var ZORO = "zoro";
var SASUKE = "sasuke";
var NARUTO = "naruto";
var LIGHT = "light";
var VALLI = "valli";
var ARCHANA = "archana";
var GALI = "galiprem";

function checkHeaderLine(line, isSmall) {
    var smallHeaderLine = "name,college,gender,lesson1,total";
    var largeHeaderLine = "name,college,gender,lesson1,lesson2,total";
    if (isSmall) {
        expect(line).toEqual(smallHeaderLine);
    } else {
        expect(line).toEqual(largeHeaderLine);
    }
}

function getDictionarySmall(fileContent) {
    var lines = fileContent.split("\r\n");
    var users = {};
    for (var line in lines) {
        if (line == 0) {
            //CHECK AND SKIP HEADER LINE
            checkHeaderLine(lines[line], true);
            continue;
        }
        var rowArray = lines[line].split(',');
        var name = rowArray[0];
        rowArray[3] = parseInt(rowArray[3]);
        rowArray[4] = parseInt(rowArray[4]);

        users[name] = rowArray;
    }
    return users;
}

function getDictionaryLarge(fileContent) {
    var lines = fileContent.split("\r\n");
    var users = {};
    for (var line in lines) {
        if (line == 0) {
            //CHECK AND SKIP HEADER LINE
            checkHeaderLine(lines[line], false);
            continue;
        }
        var rowArray = lines[line].split(',');
        var name = rowArray[0];
        rowArray[3] = parseInt(rowArray[3]);
        rowArray[4] = parseInt(rowArray[4]);
        rowArray[5] = parseInt(rowArray[5]);

        users[name] = rowArray;
    }
    return users;
}
/*
Converts "abhijith,stmartins,male,20,45,65"
into an Array ["abhijith", "stmartins", "male", 20, 45, 65]
*/
function getStudentAnswerArray(correctAnswer) {
    var studentArray = correctAnswer.split(',');
    studentArray[3] = parseInt(studentArray[3]);
    studentArray[4] = parseInt(studentArray[4]);
    studentArray[5] = parseInt(studentArray[5]);
    return studentArray;
}

function getTestCaseAnswer(number, isSmall) {
    var expectedData = {};

    if (number == 1) {
        //Here the data is shown for large leaderboard .Small data can be extracted from it.
        expectedData[ABHIJITH] = ["abhijith", "stmartins", "male", 90, 30, 120];
        expectedData[NIKHIL] = ["nikhil", "cvr", "male", 54, 74, 128];
        expectedData[VINEETHA] = ["vineetha", "bvrit", "female", 0, 34, 34];
        expectedData[SACHIN] = ["sachin", "iit", "male", 0, 0, 0];
    } else if (number == 2) {
        //Here the data is shown for large leaderboard .Small data can be extracted from it.
        expectedData[ABHIJITH] = getStudentAnswerArray("abhijith,stmartins,male,20,45,65");
        expectedData[NIKHIL] = getStudentAnswerArray("nikhil,cvr,male,0,34,34");
        expectedData[VINEETHA] = getStudentAnswerArray("vineetha,bvrit,female,1,14,15");
        expectedData[SACHIN] = getStudentAnswerArray("sachin,iit,male,3,39,42");
        expectedData[LUFFY] = getStudentAnswerArray("luffy,iip,male,100,10,110");
        expectedData[ZORO] = getStudentAnswerArray("zoro,iip,male,99,29,128");
        expectedData[NARUTO] = getStudentAnswerArray("naruto,leafvillage,male,45,58,103");
        expectedData[SASUKE] = getStudentAnswerArray("sasuke,leafvillage,male,53,83,136");
        expectedData[LIGHT] = getStudentAnswerArray("light,deathschool,male,0,99,99");
        expectedData[ARCHANA] = getStudentAnswerArray("archana,gitam,female,0,45,45");
        expectedData[GALI] = getStudentAnswerArray("galiprem,gitam,male,99,99,198");
        expectedData[VALLI] = getStudentAnswerArray("valli,gvp,female,0,76,76");

    }
    //Remove last but second element from the array
    if (isSmall) {
        for (var name in expectedData) {
            var studentData = expectedData[name];
            var totalScore = studentData.pop();
            var lesson2Score = studentData.pop();
            studentData.push(totalScore - lesson2Score);
        }
    }
    //You can uncomment for checking
    //console.log("Leaderboard Data should be");
    //console.log(expectedData);
    return expectedData;
}

function validateLeaderBoard(isSmall, expectedData, actualData) {
    if (isSmall) {
        var names = Object.keys(expectedData);
        var students = Object.keys(actualData).length;

        //Compare number of student in leaderboard
        expect(students).toBe(names.length);
        //Test all names are present in the leaderboard or not 
        for (var nameIndex in names) {
            var name = names[nameIndex];
            expect(actualData[name]).not.toBeUndefined();
            expect(actualData[name]).toEqual(expectedData[name]);
            //console.log(expectedData[name]);
        }
    } else {
        var names = Object.keys(expectedData);
        var students = Object.keys(actualData).length;
        expect(students).toBe(names.length);
        //Test all names are present in the leaderboard or not 
        for (var nameIndex in names) {
            var name = names[nameIndex];
            expect(actualData[name]).not.toBeUndefined();
            expect(actualData[name]).toEqual(expectedData[name]);
            //console.log(expectedData[name]);
        }
    }
}

exports.validateTestCase = function (number, fileContent, isSmall) {
    var actualData = {};
    if (isSmall) {
        actualData = getDictionarySmall(fileContent);
    } else {
        actualData = getDictionaryLarge(fileContent);
    }
    var expectedData = getTestCaseAnswer(number, isSmall);
    validateLeaderBoard(isSmall, expectedData, actualData);
}
