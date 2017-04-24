var fs = require('fs');
var path = require('path');

//USE THESE CONTANTS
var USERS_FILE_NAME = 'users.csv';
var LESSON1_FILE_NAME = "lesson1.csv";
var LESSON2_FILE_NAME = "lesson2.csv";
var LEADERBOARD_SMALL_FILE_NAME = "leaderboardsmall.csv";
var LEADERBOARD_LARGE_FILE_NAME = "leaderboardlarge.csv";

/*
40% of the test cases will be on LeaderBoard Small .
60% of the test cases will be on LeaderBoard Large.
*/
/*
USE relative paths only , we already provided the path till the folder
where the 3 files will be . you just need to constuct final path from there.
Dont hard code paths like
readFile("C\\Users\\ironman\\MissionRnDProjects\mrnd-final\src\data\testcase1.csv");
writeFile("C\\Users\\ironman\\MissionRnDProjects\mrnd-final\src\data\leaderboardsmall.csv");
DONT HARD CODE IT . YOU WILL GET 0 Marks .
*/

//This function is used to generate leaderboardsmall.csv in the same folde
var student = function (id,name,gitid,college,gender) {
    this.id = id;
    this.name = name;
    this.gitid = gitid;
    this.college = college;
    this.gender = gender;
    this.lesson1 = 0
    this.lesson2 = 0
    this.total = 0
};


exports.generateLeaderBoardSmall = function (folderPath, callback) {
	var users = path.join(folderPath,USERS_FILE_NAME);
	var lesson1 = path.join(folderPath,LESSON1_FILE_NAME)
	var lbsmall = path.join(folderPath,LEADERBOARD_SMALL_FILE_NAME)

	users = fs.readFileSync(users,'utf-8').toString().split('\r\n').filter(Boolean)
	students = new Object();
	for(var i = 0;i<users.length;i++){
		var details = users[i].split(',')
		var s = new student()
		s.id = details[0]
		s.name = details[1]
		s.gitid = details[2]
		s.college = details[3]
		s.gender = details[4]
		if(students.hasOwnProperty(s.gitid) || (s.gender !='male' && s.gender !='female')){
			callback({errorCode:101})
			return
		}
		students[s.gitid] = s
	}
	marks = fs.readFileSync(lesson1,'utf-8').toString().split('\r\n').filter(Boolean)
	for(var i = 0;i<marks.length;i++){
		var details = marks[i].split(',')
		if(Number(details[1])>100){
			callback({errorCode:102})
			return
		}
		students[details[0]].lesson1 = Number(details[1])
		students[details[0]].total = Number(details[1])
	}
	fs.writeFileSync(lbsmall,"")
	fs.appendFileSync(lbsmall,"name,college,gender,lesson1,total\r\n")
	for(gitid in students){
		fs.appendFileSync(lbsmall,students[gitid].name+","+students[gitid].college+","+students[gitid].gender
			+","+students[gitid].lesson1+","+students[gitid].total+"\r\n")
	}
	callback(null)
}


//This function is used to generate leaderboardlarge.csv in the same folder
exports.generateLeaderBoardLarge = function (folderPath, callback) {
	var users = [],leaders=[];
	var lines = fs.readFileSync(path.join(folderPath,USERS_FILE_NAME)).toString().split("\r\n");

	for (i=0;i<lines.length;i++){
		var line = lines[i].split(",");
		var user = new User(line[0],line[1],line[2],line[3],line[4]);
		for (i = 0;i<users.length;i++){
			if (users[i].github == user.github){ callback({errorCode:101});	return;	}
		}
		users.push(user);
	}

	var les1 = fs.readFileSync(path.join(folderPath+"/"+LESSON1_FILE_NAME)).toString().split("\r\n");
	
	for (i=0;i<les1.length;i++){
		if((parseInt(les1[i][1])>100)){
			callback({errorCode:102});
			return;
		}
	}	
	var sset1 = new Set();
	for(var i = 0;i<les1.length;i++){
		sset1.add(les1[i][0]);
	}


	if(sset1.length != les1.length) {
		callback({errorCode:102});
		return;
	}

	var users = [],leaders=[];
	var lines = fs.readFileSync(path.join(folderPath,USERS_FILE_NAME)).toString().split("\r\n");

	for (i=0;i<lines.length;i++){
		var line = lines[i].split(",");
		var user = new User(line[0],line[1],line[2],line[3],line[4]);
		for (i = 0;i<users.length;i++){
			if (users[i].github == user.github){ callback({errorCode:101});	return;	}
		}
		users.push(user);
	}

	var les2 = fs.readFileSync(path.join(folderPath+"/"+LESSON2_FILE_NAME)).toString().split("\r\n");
	
	for (i=0;i<les2.length;i++){
		if((parseInt(les2[i][1])>100)){
			callback({errorCode:102});
			return;
		}
	}	
	var sset2 = new Set();
	for(var i = 0;i<les2.length;i++){
		sset2.add(les2[i][0]);
	}


	if(sset2.length != les2.length) {
		callback({errorCode:102});
		return;
	}

}
