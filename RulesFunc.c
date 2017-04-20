#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice();
int rules(int,int,int,int,int,int);

int main (){
	
	srand(time(NULL));
	
	int d1=roll_a_dice(),d2=roll_a_dice(),d3=roll_a_dice(),d4=roll_a_dice(),d5=roll_a_dice();
	//int d1=1,d2=5,d3=3,d4=4,d5=2;
	printf("%d %d %d %d %d\n",d1,d2,d3,d4,d5);
	int i;
	
	for (i=1;i<13;i++)
		printf("score for %d: %d\n",i,rules(i,d1,d2,d3,d4,d5));
	return 0;
}
int roll_a_dice(){
	return (rand()%6)+1;
}
int rules(int rule, int d1, int d2, int d3, int d4, int d5){
	
	int score=0,i;
	int temp1=0,temp2=0;
	int tempCounter1,tempCounter2;
	
	switch(rule){	
		case 1: case 2: case 3: case 4: case 5: case 6:	//Rules: Ones, Twos, Threes, Fours, Fives, Sixes
			if (d1 == rule)
				score += rule;
			if (d2 == rule)
				score += rule;
			if (d3 == rule)
				score += rule;
			if (d4 == rule)
				score += rule;
			if (d5 == rule)
				score += rule;
			break;
		
		case 7:	//Rule: Full House
			temp1 = d1;
			tempCounter1 = 1;
			//CHECKING d2
			if (d2 == temp1)
				tempCounter1++;
			else{
				temp2 = d2;
				tempCounter2 = 1;
			}
			//CHECKING d3
			if (temp2){	//If there is temp2
				if (d3 == temp1)	
					tempCounter1++;
				else if (d3 == temp2)
					tempCounter2++;
				else	// If d3 != temp1 or temp2, dices don't match with Full House rule	
					break;	
			}else{	//If there is no temp2 
				if (d3 == temp1)
					tempCounter1++;
				else{
					temp2 = d3;
					tempCounter2 = 1;
				}	
			}
			//CHECKING d4
			if (temp2){	//If there is temp2
				if (d4 == temp1)	
					tempCounter1++;
				else if (d4 == temp2)
					tempCounter2++;
				else	// If d4 != temp1 or temp2, dices don't match with Full House rule
					break;	
			}else{	//If there is no temp2
				temp2 = d4;
				tempCounter2 = 1;
			}
			//CHECKING d5
			if (d5 == temp1 && tempCounter1 <= 2)	//Checking if there are 4 same dice
				tempCounter1++;
			else if (d5 == temp2 && tempCounter2 <= 2)	//Checking if there are 4 same dice
				tempCounter2++;
			else	// If d5 != temp1 or temp2, dices don't match with Full House rule
				break;
			
			score = temp1 * tempCounter1 + temp2 * tempCounter2;
			break;
			
		case 8:	//Rule: Four of a kind //Basically doing same thing as Full House does
			temp1 = d1;
			tempCounter1 = 1;
			//CHECKING d2
			if (d2 == temp1)
				tempCounter1++;
			else{
				temp2 = d2;
				tempCounter2 = 1;
			}
			//CHECKING d3
			if (temp2){
				if (d3 == temp1)
					tempCounter1++;
				else if (d3 == temp2)
					tempCounter2++;
				else
					break;
			}else{
				if (d3 == temp1)
					tempCounter1++;
				else{
					temp2 == d3;
					tempCounter2 = 1;
				}
			}
			//CHECKING d4
			if (temp2){
				if (d4 == temp1)
					tempCounter1++;
				else if (d4 == temp2)
					tempCounter2++;
				else
					break;
			}else{
				if (d4 == temp1)
					tempCounter1++;
				else{
					temp2 == d4;
					tempCounter2 = 1;
				}
			}
			//CHECKING d5
			if (temp2){
				if (d5 == temp1)
					tempCounter1++;
				else if (d5 == temp2)
					tempCounter2++;
				else
					break;
			}else{
				if (d5 == temp1)
					tempCounter1++;
				else{
					temp2 == d5;
					tempCounter2 = 1;
				}
			}
			
			if ((tempCounter1 == 4 && tempCounter2 == 1) || tempCounter1 == 5)
				score = temp1*4;
			else if ((tempCounter1 == 1 && tempCounter2 == 4) || tempCounter2 == 5)
				score = temp2*4;
			else 
				break;
		
		case 9:	//Little Straight
			if((d1 == 1||d2 == 1||d3 == 1||d4 == 1||d5 == 1) && 
			(d1 == 2||d2 == 2||d3 == 2||d4 == 2||d5 == 2) && 
			(d1 == 3||d2 == 3||d3 == 3||d4 == 3||d5 == 3) && 
			(d1 == 4||d2 == 4||d3 == 4||d4 == 4||d5 == 4) &&
			(d1 == 5||d2 == 5||d3 == 5||d4 == 5||d5 == 5)){
				score = 30;
				break;
			}else
				break;
		
		case 10:	//Big Straight
			if((d1 == 2||d2 == 2||d3 == 2||d4 == 2||d5 == 2) && 
			(d1 == 3||d2 == 3||d3 == 3||d4 == 3||d5 == 3) && 
			(d1 == 4||d2 == 4||d3 == 4||d4 == 4||d5 == 4) &&
			(d1 == 5||d2 == 5||d3 == 5||d4 == 5||d5 == 5) &&
			(d1 == 6||d2 == 6||d3 == 6||d4 == 6||d5 == 6)){
				score = 30;
				break;
			}else
				break;
		
		case 11:	//Choice
			score = d1 + d2 + d3 + d4 + d5;	
			break;
		
		case 12:	//Yacht
			if(d1 == d2 && d1 == d2 && d1 == d3 && d1 == d4 && d1 == d5){
				score = 50;
				break;
			}else
				break;
		
		default:
			score = -1;
			break;
	}
	
	return score;
}

