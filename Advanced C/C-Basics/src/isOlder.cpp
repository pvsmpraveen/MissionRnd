/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
bool valid(int d, int m, int y){
	int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		days[1] = 29;
	bool ok = false;
	if (m <= 12 && d <= days[m - 1])
		ok = true;
	return ok;
}

int isOlder(char *dob1, char *dob2) {
	int len1, len2;
	for (len1 = 0; dob1[len1]; len1++);
	for (len2 = 0; dob2[len2]; len2++);
	int d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0;
	if (len1 != 10 || len2 != 10)
		return -1;

	for (int i = 0; i < 10; i++){
		if (i < 2){
			if (dob1[i] >= '0' && dob1[i] <= '9' && dob2[i] >= '0' && dob2[i] <= '9'){
				d1 = d1 * 10 + dob1[i] - '0';
				d2 = d2 * 10 + dob2[i] - '0';
			}
			else{
				return -1;
			}
			continue;
		}

		if ((i == 2 || i == 5)){
			if (dob1[i] != '-' || dob2[i] != '-')
				return -1;
			continue;
		}

		if (i >= 3 && i <= 4){
			if (dob1[i] >= '0' && dob1[i] <= '9' && dob2[i] >= '0' && dob2[i] <= '9'){
				m1 = m1 * 10 + dob1[i] - '0';
				m2 = m2 * 10 + dob2[i] - '0';
			}
			else{
				return -1;
			}
			continue;
		}

		if (dob1[i] >= '0' && dob1[i] <= '9' && dob2[i] >= '0' && dob2[i] <= '9'){
			y1 = y1 * 10 + dob1[i] - '0';
			y2 = y2 * 10 + dob2[i] - '0';
		}
		else{
			return -1;
		}
	}

	if (!valid(d1, m1, y1) || !valid(d2, m2, y2))
		return -1;

	if (y1 != y2){
		if (y1 < y2)
			return 1;
		else
			return 2;
	}

	if (m1 != m2){
		if (m1 < m2)
			return 1;
		else
			return 2;
	}

	if (d1 != d2){
		if (d1 < d2)
			return 1;
		else
			return 2;
	}


	return 0;
}
