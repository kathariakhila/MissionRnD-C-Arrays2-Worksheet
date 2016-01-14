/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

struct transaction {
	int amount;
	char date[11];
	char description[20];
};


int compare(char *d, char *date){
	int i;
	int day1,day2;
	int month1,month2;
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

int binarySearch(struct transaction *Arr, int left, int right, char *date){

	int mid = (left + right) / 2;
	int cmp = compare(Arr[mid].date, date);

	if (left >right)
		return -1;

	else{
		if (cmp== 0)
			return mid;

		else if (cmp == -1)
			binarySearch(Arr, left, mid - 1, date);

		else if (cmp== 1)
			binarySearch(Arr, mid + 1, right, date);

	}
		

	
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {

	int position;
	int i;

	if (len == 0)
		return -1;

	else{
		position = binarySearch(Arr, 0, len - 1, date);
		if (position == -1)
			return 0;
		else{
			i = position + 1;
			while (i < len && compare(Arr[i].date, date) == 0){
				position++;
				i++;
			}
			return  len - position - 1;
		}

	}

}