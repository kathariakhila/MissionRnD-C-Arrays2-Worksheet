/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdbool.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int compare1(char *d, char *date){
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


bool binarySearch1(struct transaction *A, int left, int right, char *date){

	int mid = (left + right) / 2;
	int cmp = compare1(A[mid].date, date);

	if (left >right)
		return false;

	else{
		if (cmp == 0)
			return true;

		else if (cmp == -1)
			binarySearch1(A, left, mid - 1, date);

		else if (cmp == 1)
			binarySearch1(A, mid + 1, right, date);

	}

}


struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {

	int i,k;
	bool value;
	int index = 0;

	if (A == NULL || B == NULL)
		return NULL;

	else{
		struct transaction res[10];
		if (ALen <= BLen){
			for (i = 0; i < ALen; i++){
				value = binarySearch1(B, 0, BLen - 1, A[i].date);

				if (value){
					res[index].amount = A[i].amount;
					res[index].date[0] = A[i].date[0];
					res[index].date[1] = A[i].date[1];
					res[index].date[2] = A[i].date[2];
					res[index].date[3] = A[i].date[3];
					res[index].date[4] = A[i].date[4];
					res[index].date[5] = A[i].date[5];
					res[index].date[6] = A[i].date[6];
					res[index].date[7] = A[i].date[7];
					res[index].date[8] = A[i].date[8];
					res[index].date[9] = A[i].date[9];
					res[index].date[10] = A[i].date[10];
					k = 0;
					while (A[i].description[k] != '\0'){
						res[index].description[k] = A[i].description[k];
						k++;
					}
					res[index].description[k] = '\0';
					index++;

				}
			}

		}
		else{
			for (i = 0; i < BLen; i++){
				value = binarySearch1(A, 0, ALen - 1, B[i].date);

				if (value){
					res[index].amount = B[i].amount;
					res[index].date[0] = B[i].date[0];
					res[index].date[1] = B[i].date[1];
					res[index].date[2] = B[i].date[2];
					res[index].date[3] = B[i].date[3];
					res[index].date[4] = B[i].date[4];
					res[index].date[5] = B[i].date[5];
					res[index].date[6] = B[i].date[6];
					res[index].date[7] = B[i].date[7];
					res[index].date[8] = B[i].date[8];
					res[index].date[9] = B[i].date[9];
					res[index].date[10] = B[i].date[10];
					k = 0;
					while (B[i].description[k] != '\0'){
						res[index].description[k] = B[i].description[k];
						k++;
					}
					index++;

				}

			}
		}
		if (index == 0)
			return NULL;
		else
			return res;
	}

}