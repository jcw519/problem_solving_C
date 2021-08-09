#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//9-1 Guessing Game
void initalize_random_generator();
int choose_secret_number();
void play(int selected_number);


int main(){
	char ch;
	initalize_random_generator();
	printf("Welcome\n");
	
	while(1){
		int selected_number = choose_secret_number();
		play(selected_number);
		printf("Play again ?");
		scanf(" %c", &ch);
		if(ch != 'y' && ch != 'Y'){
			break;
		}
	}
	
	
}

void play(int selected_number)
{
	int guessed_number;
	int count = 0;
	while(1) {
		
		printf("Guess number: ");
		scanf("%d", &guessed_number);
		count++;
		if(guessed_number < selected_number) {
			printf("Too low...\n");
		} 
		else if (guessed_number > selected_number) {
			printf("Too High...\n");
		}
		else {
			printf("You won in %d guesses.\n", count);
			break;
		}
	}
}

int choose_secret_number()
{
	int selected_number = rand() % 100 + 1;
	return selected_number;
}


void initalize_random_generator()
{
	srand((unsigned int)time(NULL));
}
