/**
    ------------ ERROR CODES ------------   
    1001 - Invalid inputs
    1002 - Invalid filters
    1003 - Mandatory values not sent.
    1004 - Record already exists..
*/

/**
We assume the files that are used as data source for this activity reside in the file "files/students.txt"
*/

var Student = function(id, firstName, lastName, gender, totalMarks){
    this.id = id;
    this.firstName = firstName;
    this.lastName = lastName;
    this.gender = gender;
    this.totalMarks = totalMarks;
};

/**
Method used to read students data from the file..

If no filters are given, return list of all the students details. 

Else, apply all the given filters. 

------------------
Schema of a filter..
------------------

filters contains list of filters that have to be applied on the students data. 

Each filter contains the following properties.. 

"key", "value", "optype".

** key and value are mandatory properties. 
Throw error in case they are missing. (Refer error codes at Page Top!)

Default value for optype = "EQ". 

List of valid optype -> EQ, NE, GT, LT, GTE, LTE 
(Equals, NotEquals, GreaterThan, LessThan, GreaterThanEquals, LessThanEquals)

Example filter --- 
[{
    "key" : "gender",
    "value": "male"
},{
    "key" : "totalMarks",
    "value": 90,
    "optype": "GTE"
}]
Return all the male students having marks greater than or equal to 90!!
*/
exports.getStudents = function (filters, callback) {
    err = {};
    res = Array();
    fs = require('fs');
        var studs  = fs.readFileSync(__dirname + '/../files/students.txt').toString().trim().split("\n");
        for(var i in studs){
            try{
                 js = JSON.parse(studs[i].trim());
                 res.push(js);
            }
            catch(e){

            }
    }
    //console.log(res);
    if(filters == null) {callback(null,res); return;}
    for(var i = 0;i<filters.length;i++){
        curr = Array();
        try{
            for(var j = 0;j<res.length;j++){
                //console.log(filters[i].key+" "+filters[i].value);
                //console.log(res[j][filters[i].key]+" "+filters[i].value);
                if(filters[i].hasOwnProperty("optype")){
                    switch (filters[i].optype) {
                        case "EQ":
                            if(res[j][filters[i].key] == filters[i].value){   
                                curr.push(res[j]);
                            }
                            break;
                        case "NE": 
                            if(res[j][filters[i].key] != filters[i].value){   
                                curr.push(res[j]);
                            }
                            break;
                        case "GT":
                            if(res[j][filters[i].key] > filters[i].value){   
                                curr.push(res[j]);
                            }
                            break;
                        case "LT":
                            if(res[j][filters[i].key] < filters[i].value){   
                                curr.push(res[j]);
                            }
                            break;
                        case "GTE":
                            if(res[j][filters[i].key] >= filters[i].value){   
                                curr.push(res[j]);
                            }
                            break;
                        case "LTE":
                            if(res[j][filters[i].key] <= filters[i].value){   
                                    curr.push(res[j]);
                            }
                            break;
                    }
                }
                else if(res[j][filters[i].key] == filters[i].value){   
                    curr.push(res[j]);
                }
            }

            res = curr;
            //console.log(res);
        }
        catch(e){
            err.code = 1003;
            callback(err);
        }
    }
   // console.log(res);
    callback(null,res);

};

/**
Method is to create a new student in the data source (i.e, a file.)

student contains the required student's data. 

mandatory fields are id, lastName, firstName, gender and totalMarks. 

--valid values for gender are "male" and "female". 

--valid values for totalMarks is range 0 - 100. 

Throw appropriate errors for invalid values. (Refer error codes from the page top)
*/
exports.createStudent = function (student, callback) {
    var err = {};
    try{
        if(!((student.gender === "male") || (student.gender === "female"))) {
            err.code = 1001;
            callback(err); return; 
        }
        if(student.totalMarks <0 || student.totalMarks > 100) {callback(1001); return; }
        //console.log(student);
        var s = new Set();

        //Brutually written , sorry :) will change later!
        fs = require('fs');
        var studs  = fs.readFileSync(__dirname + '/../files/students.txt').toString().trim().split("\n");
        for(var i in studs){
            try{
                 js = JSON.parse(studs[i].trim());
                 s.add(js.id);
            }
            catch(e){

            }
        }
        //console.log(s);
        //console.log(student);
        if(s.has(student.id)) {err.code = 1004; callback(err); return; }
        //console.log(student);
        var fa = require('fs');
        fa.appendFileSync(__dirname + '/../files/students.txt', JSON.stringify(student)+"\n");
        callback(null);
    }
    catch(e){
        console.log(e);
        err.code = 1001;
         callback(err);
    }
};

