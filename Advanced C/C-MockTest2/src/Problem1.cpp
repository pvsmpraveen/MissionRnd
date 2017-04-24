/*

In a college, there is a data centre where all the communications go on.
Like mails about Holidays, Schedules, Notices etc information.
The clerk at data centre used to ask students of every new batch to create new emails and submit through forms.
The clerk must know the name of the student by seeing the email.

But the students are mischevious. Their emails are unidentifiable.
For example: A student Manoj gave his email as iamironman123@gmail.com, Sunil as rockrocky143@gmail.co.in

The clerk is unable to find the name of the student just by seeing the email address.
So, he added a rule that email must contain the student name as prefix or suffix to email address

Example: Manoj has to create his email as "manojsomething@something.com" or "somethingmanoj@something.com"

Note: "abcmanojabc@live.com is invalid email address Since "manoj" is neither a prefix nor a suffix.

Help the clerk to check the following:

(1). Given email is Valid or not
ex: "manoj@gmail" is not a valid email address

(2). Given email satisfies the suffix/prefix condition
ex: student name: abc, email: "ab@c.com" is not valid
because even though it is valid email email address, it is not satisfying the clerk's new rule.


Given input is in the form of "name email" space seperated Name and email.
Return 1 if email condition (1) is only satisfied. Return 2 if both (1) and (2) are satisfied. Return 0 for all other cases
ex: INPUT: "Manoj iammanoj@gmail.com"
OUTPUT: 2

INPUT: "abc abc.com"
OUTPUT: 0


NOTE: (1) Do not use any string.h functions.
(2) Rules of a valid email address
a. should use only alphanumeric characters. That is, use only “a” through “z” and “0 (zero)” through “9”.
b. Use of the following characters: < > ( ) [ ] ; : , @ \ <space> is not allowed
c. As long as they are not the first character in the e-mail address, hyphens ( – ), underscores ( _ ), periods ( . ),
and numeric characters (“0” through “9”) are acceptable characters to use within the address.
d. Do not use null characters (spaces) between characters. However, as mentioned above, underscores are acceptable.
e. Email length must be less than or equal to 254 characters.
(3) MANoJ ,MaNoj all are same and to be treated as manoj in the name field
(4) Delimiter b/w name and email can be single or multiple spaces
(5) Input is in read only mode. you cannot edit it.
*/

#include <stdio.h>
#include <stdlib.h>
char name[1004], mail[1004];
char small(char ch){
	if (ch >= 'a' && ch <= 'z') return ch;
	else return ch - 'A' + 'a';
}
bool Valid(char ch){
	if (ch >= 'a' && ch <= 'z') return true;
	if (ch >= 'A' && ch <= 'Z') return true;
	if (ch >= '0' && ch <= '9') return true;
	if (ch == ' ') return true;
	if (ch == '[' || ch == ']') return false;
	if (ch == '(' || ch == ')') return false;
	if (ch == ':' || ch == ';') return false;
	if (ch == '<' || ch == '>') return false;
	if (ch == ',' || ch == '\\') return false;
	return true;
}

bool Check(char *name, char *email, int st, int Len){
	int k = 0;
	for (int i = st; i<Len; i++){
		if (small(name[k++]) != small(email[i]))
			return false;
	}
	return true;
}

bool CheckEmail(char *em, int len){
	if (len <= 4) return false;
	if (em[0] == '@') return false;
	if (em[len - 4] != '.') return false;
	int dot = 0, att = 0;
	for (int i = 0; i<len; i++){
		if (em[i] == '@') {
			if (att) return false;
			att = i;
		}
		if (em[i] == '.'){
			if (dot) return false;
			dot = i;
		}
	}
	if (!dot || !att || abs(dot - att) == 1) return false;
	return true;
}

int isValidEmail(char *email)
{
	if (email == NULL)
		return -1;
	int len = 0, i = 0;
	for (len = 0; email[len] != '\0'; len++);

	for (int i = 0; i <= len; i++) mail[i] = name[i] = '\0'; //init

	int emailLen = 0, nameLen = 0;
	int k = 0, x;
	for (int i = len - 1; i >= 0; i--){
		if (email[i] == ' '){
			for (int x = i + 1; x<len; x++){
				mail[k++] = email[x];
			}
			mail[k] = '\0';
			break;
		}
	}
	emailLen = k;


	k = 0;
	for (int i = 0; i<len; i++){
		if (email[i] == ' ') break;
		name[k++] = email[i];
	}
	name[k] = '\0';
	nameLen = k;



	int att = 0;
	for (int i = emailLen; i >= 0; i--)
		if (mail[i] == '@'){
			att = i;
			break;
		}

	if (nameLen >= emailLen)
		return -1;

	bool ok1 = Check(name, mail, 0, nameLen);
	bool ok2 = Check(name, mail, att - nameLen, nameLen);

	bool em = CheckEmail(mail, emailLen);

	if (em && (ok1 || ok2)) return 2;
	if (em) return 1;
	return 0;

}