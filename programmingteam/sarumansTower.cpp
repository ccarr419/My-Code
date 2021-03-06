/*
*	Author:	Christian Carreras
*	File:	sarumansTower.cpp
*	Date:	10/23/2015
*	About:	Calculates the number of levels of Saruman's Tower by the given
*		day. For each day up to the given day that has a multiple of 3
*		for the total of 1's in its binary equivalent, the tower will
*		raise by one level. Assuming the tower level starts at zero.
*		http://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=579&page=show_problem&problem=4241
*/

#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int findLevels(int);
void toBinary(queue<int>&, int, int);
int count(queue<int>&);

int main()
{
	int day[3] = {2, 19, 64};
	int lvl[3];
	for(int i = 0; i < 3; i++)
		lvl[i] = findLevels(day[i]);
	
	for(int i = 0; i < 3; i++)
		cout << "Day " << day[i] << ": Level = " << lvl[i] << endl;
	
	return 0;
}

//Counts the number of levels the tower will be at the given day
int findLevels(int end_day)
{
	if(end_day < 7) //any day less than 3 will be zero
		return 0;
	
	queue<int> binary; //holds all 1's of a binary equivalent
	int day = 7, num = 0, lvl = 0;
	while(day <= end_day) //go from day 3 to given day
	{
		toBinary(binary, day, day-1); //get number of 1's
		num = count(binary); //count number of 1's
		if(num != 0 && num % 3 == 0)
			lvl++; //if the count is a multiple of 3, increment lvl
		day++; //go to next day
	}
	return lvl;
}

//Recursively finds the number of 1's in thebinary equivalent of the given number
void toBinary(queue<int>& binary, int num, int k)
{
	if(num == 0 || k < 0) //base case
		return;
	
	if(pow(2, k) <= num) //if 2^k is less than num
	{
		binary.push(1); //there will be a one in the binary equivalent
		toBinary(binary, num - pow(2, k), k-1);
	}
	
	else //keep searching for a power of 2 less than num
		toBinary(binary, num, k-1);
}

//Counts the total number of 1's in the queue
int count(queue<int>& binary)
{
	int binary_count = 0;
	while(!(binary.empty()))//go through each entry in the queue
	{	
		if(binary.front() == 1) //if there is a one,
			binary_count++; //increment the count
		binary.pop(); //go to next entry in the queue
	}
	return binary_count;
}