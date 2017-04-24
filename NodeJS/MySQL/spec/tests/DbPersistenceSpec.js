
var Contact = function(firstName, lastName, phone){
    this.firstName = firstName;
    this.lastName = lastName;
    this.phone = phone;
};

describe("DbPersistence Test Suite", function(){

    var contactsDb = require('../../src/DbPersistence');
    var steveContact = new Contact("Steve", "Jobs", "23002300");
    var larryContact = new Contact("Larry", "Page", "23002300");
    var billContact = new Contact("Bill", "Gates", "23002300");


    it("Should clear the database ", function(done) {
        var connection = contactsDb.GetConnection();

        var self = this;
        connection.query("delete from contacts", function(err, result){
            if(err){
                self.fail(Error("Error in clearing the database "+JSON.stringify(err)));
            }
            expect(err).toBe(null);
            done();
        });

        connection.end();
    });

    it("should add contacts",function(done){

        contactsDb.AddContact(steveContact, function(err, result){

            console.log(result);
            steveContact.id = result.insertId;
            contactsDb.ReadContacts(function(err, result){

                readContacts = result;
                console.log(readContacts[0]);
                expect(readContacts.length).toBe(1);
                expect(readContacts[0].firstName).toBe("Steve");

                contactsDb.AddContact(larryContact, function(err, result){

                    console.log(result);
                    larryContact.id = result.insertId;
                    contactsDb.ReadContacts(function(err, result){

                        readContacts = result;
                        expect(readContacts.length).toBe(2);
                        expect(readContacts[1].firstName).toBe("Larry");

                        done();
                    });

                });

            });
        });
    });


    it("should add new contact",function(done){

        contactsDb.AddContact(billContact, function(err, result){
            billContact.id = result.insertId;

            contactsDb.ReadContacts(function(err, result){

                readContacts = result;
                expect(readContacts.length).toBe(3);
                expect(readContacts[2].firstName).toBe("Bill");
                done();

            });
        });
    });

    it("should update contact",function(done){

        contactsDb.UpdateContact(larryContact.id,"32003200", function(err, result){

            expect(result.firstName).toBe("Larry");
            expect(result.phone).toBe("32003200");

            done();
        });

    });

    it("should delete contact",function(done){

        contactsDb.DeleteContact(larryContact.id, function(err, result){
            contactsDb.ReadContacts(function(err, result){

                readContacts = result;
                expect(readContacts.length).toBe(2);
                expect(readContacts[1].firstName).toBe("Bill");
                done();
            });

        });
    });
});
