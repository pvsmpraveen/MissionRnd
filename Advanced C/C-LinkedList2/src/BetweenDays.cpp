/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

bool isLeap(int y){
	return (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0));
}

int DaysFrom1800(int d, int m, int y){
	int days = 0;
	int Months[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeap(y)) Months[2] = 29;
	for (int i = 1800; i < y; i++){
		days += (365 + isLeap(i));
	}
	for (int i = 1; i<m; i++){
		days += Months[i];
	}
	days += d;


	return days;

}
int between_days(struct node *date1head, struct node *date2head){
	if (date1head == NULL || date2head == NULL)
		return -1;
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0;
	int cnt = 1;
	node *temp1 = date1head, *temp2 = date2head;
	while (temp1 && temp2){
		if (cnt <= 2){

			d1 = d1 * 10 + temp1->data;
			d2 = d2 * 10 + temp2->data;
		}
		else if (cnt <= 4){
			m1 = m1 * 10 + temp1->data;
			m2 = m2 * 10 + temp2->data;
		}
		else{
			y1 = y1 * 10 + temp1->data;
			y2 = y2 * 10 + temp2->data;
		}
		cnt++;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}


	int Days1 = DaysFrom1800(d1, m1, y1);
	//cout << Days1 << endl;
	int Days2 = DaysFrom1800(d2, m2, y2);
	//cout << Days2 << endl;
	if (abs(Days1 - Days2) <= 1)
		return 0;
	return abs(Days1 - Days2) - 1;
}