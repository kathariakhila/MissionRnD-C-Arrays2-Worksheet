/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int compare2(char *d, char *date){
	int i;
	int day1, day2;
	int month1, month2;
	int year1, year2;

	day1 = d[0] - 48;
	day1 = day1 * 10 + d[1] - 48;

	day2 = date[0] - 48;
	day2 = day2 * 10 + date[1] - 48;

	month1 = d[3] - 48;
	month1 = month1 * 10 + d[4] - 48;


	month2 = date[3] - 48;
	month2 = month2 * 10 + date[4] - 48;

	year1 = d[6] - 48;
	year1 = year1 * 10 + (d[7] - 48);
	year1 = year1 * 10 + (d[8] - 48);
	year1 = year1 * 10 + (d[9] - 48);

	year2 = date[6] - 48;
	year2 = year2 * 10 + (date[7] - 48);
	year2 = year2 * 10 + (date[8] - 48);
	year2 = year2 * 10 + (date[9] - 48);


	if (year1 == year2 && month1 == month2 && day1 == day2)
		return 0;

	else{
		if (year1 == year2)
			if (month1 == month2)
				if (day1 < day2)
					return 1;
				else
					return -1;
			else if (month1 < month2)
				return 1;
			else
				return -1;

		else if (year1 < year2)
			return 1;
		else
			return -1;

	}


}

void copy(struct transaction *x, struct transaction *y){

	int i = 0;

	y->amount = x->amount;
	y->date[0] = x->date[0];
	y->date[1] = x->date[1];
	y->date[2] = x->date[2];
	y->date[3] = x->date[3];
	y->date[4] = x->date[4];
	y->date[5] = x->date[5];
	y->date[6] = x->date[6];
	y->date[7] = x->date[7];
	y->date[8] = x->date[8];
	y->date[9] = x->date[9];
	y->date[10] = x->date[10];
	
	while (x->description[i] != '\0'){
		y->description[i] = x->description[i];
		i++;
	}
	y->description[i] = '\0';

}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	
	int value;
	int i = 0;
	int j = 0;
	struct transaction *r = (struct transaction *)calloc(30,sizeof(struct transaction));
	int temp = 0;

	if (A == NULL || B == NULL)
		return NULL;

	else{
		while (i < ALen && j < BLen){
			value = compare2(A[i].date,B[j].date);
			
			if (value == 0){
				copy(&A[i],&r[temp]);
				copy(&A[i], &r[temp + 1]);
				temp = temp + 2;
				i = i + 1;
				j = j + 1;
			}
			else if (value == -1){
				copy(&B[j], &r[temp]);
				temp++;
				j++;
			}
			else{
				copy(&A[i], &r[temp]);
				temp++;
				i++;
			}
				
			
		}

		while (i < ALen){
			copy(&A[i], &r[temp]);
			temp++;
			i++;

		}

		while (j < BLen){
			copy(&B[j], &r[temp]);
			temp++;
			j++;
		}

		return r;

	}
}