#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_a_dice();
int rules(int, int, int, int, int, int);	//The function that calculates score for select rule
char start();	//The function that selects who'll start
int play_computer();
int play_user();
int computer_strategy_decider(int, int, int, int, int);
void scoresheet(int, int);

int main(){
	
	srand(time(NULL));
	int turn, userScore = 0, compScore = 0, userTotal = 0, compTotal = 0;
	char luckyOne = start();	//Variable that will hold who will start

	for (turn = 1; turn <= 12; turn++){
		printf("\nRound: %d\n",turn);
		printf("======================================\n");
		
		if (luckyOne == 'P'){
			userTotal += userScore = play_user();
			scoresheet(userScore,userTotal);
			compTotal += compScore = play_computer();
			scoresheet(compScore,compTotal);
		}else{
			compTotal += compScore = play_computer();
			scoresheet(compScore,compTotal);
			userTotal += userScore = play_user();
			scoresheet(userScore,userTotal);
		}	
	}

	if (userTotal > compTotal)
		printf("Winner is Player!");
	else if (compTotal > userTotal)
		printf("Winner is Computer!");
	else
		printf("Draw! :/");
		
	system("PAUSE");
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
char start(){
	
	int d1,d2;	//Dices
	char luckyOne = 'N';	//Variable that will hold who will start
	printf("Welcome to the Yacht game.\nLets see who is Lucky!\n");
	
	do{	//Chooses who will start
		d1=roll_a_dice();
		d2=roll_a_dice();
		if (d1>d2)
			luckyOne = 'P';
		else if (d2>d1)
			luckyOne = 'C';
//		printf("d1:%d - d2:%d - L:%c\n",d1,d2,luckyOne);	//DEBUG!!
	}while(luckyOne == 'N');
		
	printf("Player: %d - Machine: %d\n",d1,d2);
	if (luckyOne == 'P')
		printf("Player is the lucky one, lets get started!\n");
	else 
		printf("Computer is the lucky one, lets get started!\n");
		
	return luckyOne;
}
int play_computer(){
	int d1=roll_a_dice(),d2=roll_a_dice(),d3=roll_a_dice(),
		d4=roll_a_dice(),d5=roll_a_dice();
	int compRule;
	
	printf("Rolled the dice for computer:\n");
	printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d, Dice5: %d\n",d1,d2,d3,d4,d5);	
	compRule = computer_strategy_decider(d1,d2,d3,d4,d5);
	printf("Rule %d ",compRule);
	if(compRule == 1)
		printf("(ones) is used!\n");
	else if (compRule == 2)
		printf("(twos) is used!\n");
	else if (compRule == 3)
		printf("(threes) is used!\n");
	else if (compRule == 4)
		printf("(fours) is used!\n");
	else if (compRule == 5)
		printf("(fives) is used!\n");
	else if (compRule == 6)
		printf("(sixes) is used!\n");	
	else if (compRule == 7)
		printf("(full house) is used!\n");	
	else if (compRule == 8)
		printf("(four_of_a_kind) is used!\n");	
	else if (compRule == 9)
		printf("(little straight) is used!\n");	
	else if (compRule == 10)
		printf("(big straight) is used!\n");	
	else if (compRule == 11)
		printf("(choice) is used!\n");
	else if (compRule == 12)
		printf("(yacht) is used!\n");	
		
	return rules(compRule,d1,d2,d3,d4,d5);		
}
int play_user(){
	int d1=roll_a_dice(),d2=roll_a_dice(),d3=roll_a_dice(),
		d4=roll_a_dice(),d5=roll_a_dice();
	int reroll=2;	//The variable that holds how many rerolls do user left
	char retry = 'N';
	int score = 0, i=0;
	
	printf("Rolled the dice for you:\n");
	printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d, Dice5: %d\n",d1,d2,d3,d4,d5);
	
	do{
		printf("Do you want to roll or not (Y/N): ");
		scanf("%c",&retry);
		fflush(stdin);

		if(retry == 'Y' || retry == 'y'){
			d1=roll_a_dice(),d2=roll_a_dice(),d3=roll_a_dice(),d4=roll_a_dice(),d5=roll_a_dice();
			printf("Dice1: %d, Dice2: %d, Dice3: %d, Dice4: %d, Dice5: %d\n",d1,d2,d3,d4,d5);
			reroll--;
		}else if(retry == 'N' || retry == 'n')
			break;
		else{
			printf("Invalid input try again!\n");
			continue;
		}	
	}while(reroll>0);	//3 reroll 	
	
	static int ps1=0,ps2=0,ps3=0,ps4=0,ps5=0,ps6=0;	//Variables that will hold if Player
	static int ps7=0,ps8=0,ps9=0,ps10=0,ps11=0,ps12=0;	//used these strategies before
	
	do{
		printf("Which scoring rule you would like to use (1: ones, 2: twos, 3: threes, 4:\n");
		printf("fours, 5: fives, 6: sixes, 7: full house, 8: four_of_a_kind, 9: little\n");
		printf("straight, 10: big straight, 11: choice, 12: yacht): ");
		
		int selectRule;	//Which rule did user select?
		scanf("%d",&selectRule);
		fflush(stdin);
		i = 0;
		
		if (selectRule == 1){
			if(ps1 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps1 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 2){
			if(ps2 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps2 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 3){
			if(ps3 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps3 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 4){
			if(ps4 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps4 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 5){
			if(ps5 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps5 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 6){
			if(ps6 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps6 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 7){
			if(ps7 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps7 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 8){
			if(ps8 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps8 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 9){
			if(ps9 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps9 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 10){
			if(ps10 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps10 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 11){
			if(ps11 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps11 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else if (selectRule == 12){
			if(ps12 == 0){
				score = rules(selectRule,d1,d2,d3,d4,d5);
				i = 1;
				ps12 = 1;
			}else
				printf("You cannot use this, already used it!\n");
		}else
			printf("Invalid rule, try again!\n");
	}while(i == 0);
	
	return score;
}
int computer_strategy_decider(int d1, int d2, int d3, int d4, int d5){
	static int cs1=0,cs2=0,cs3=0,cs4=0,cs5=0,cs6=0;	//Variables that will hold if Computer
	static int cs7=0,cs8=0,cs9=0,cs10=0,cs11=0,cs12=0;	//used these strategies before
	int i, maxScore = -1, maxStrategy = 0;
	
	for (i=1; i<=12; i++){
		if(rules(i,d1,d2,d3,d4,d5) > maxScore){
			if(i == 1 && cs1 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 2 && cs2 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 3 && cs3 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 4 && cs4 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 5 && cs5 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 6 && cs6 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 7 && cs7 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 8 && cs8 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 9 && cs9 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 10 && cs10 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 11 && cs11 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}else if (i == 12 && cs12 == 0){
				maxScore = rules(i,d1,d2,d3,d4,d5);
				maxStrategy = i;
			}
		}
	}
	if(maxStrategy == 1)	cs1 = 1;
	else if(maxStrategy == 2)	cs2 = 1;
	else if(maxStrategy == 3)	cs3 = 1;
	else if(maxStrategy == 4)	cs4 = 1;
	else if(maxStrategy == 5)	cs5 = 1;
	else if(maxStrategy == 6)	cs6 = 1;
	else if(maxStrategy == 7)	cs7 = 1;
	else if(maxStrategy == 8)	cs8 = 1;
	else if(maxStrategy == 9)	cs9 = 1;
	else if(maxStrategy == 10)	cs10 = 1;
	else if(maxStrategy == 11)	cs11 = 1;
	else if(maxStrategy == 12)	cs12 = 1;
	
	return maxStrategy;
}
void scoresheet(int turnScore, int totalScore){
	printf("Your score is: %d, and your total is: %d\n\n",turnScore,totalScore);
}










































