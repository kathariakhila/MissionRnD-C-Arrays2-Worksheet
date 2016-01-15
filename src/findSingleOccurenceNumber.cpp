/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include<iostream>

int check(int number, int *temp,int l){

	int i;
	

	if (l == 0){
		return -1;
	}
	else {
		for (i = 0; i < l; i++){
			if (number == temp[i])
				return i;
		}
		return -1;
	}

}

int findSingleOccurenceNumber(int *A, int len) {

	int res;
	int temp[10] = {0};
	int count[10] = { 0 };
	int l = 0;
	int i;
	int flag;

	if (A == NULL)
		return -1;
	
	else{
		
		for (i = 0; i < len; i++){
			flag = check(A[i], temp,l);
		
			if (flag == -1){
				temp[l] = A[i];
				count[l] = 1;
				l++;
			}
			else{
				count[flag] = count[flag] + 1;
			}
		}
		for (i = 0; i < l; i++)
			if (count[i] == 1)
				return temp[i];


	}
}