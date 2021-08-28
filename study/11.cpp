//11. poker game : 문자열 다뤄보기

//각 카드는 suit와 rank를 가진다.
//suit: club, diamond, heart, spade
//rank: ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, jack, queen, king
//ace는 1 혹은 14로 사용됨. 하지만 1과 14로 동시에 사용될 수는 없음
//5장의 카드로 가능한 한 높은 패를 만드는 게임
// straight flush (straight이면서 flust)
// four cards (4장이 동일한 rank)
// full house (하나의 triple과 하나의 pair)
// flush (5장 모두 동일한 suit)
// straight (5장 모두 연속된 rank)
// triple (3장이 동일한 rank)
// two pairs (pair가 두개)
// pair (2장이 동일한 rank)
// high card (위의 어떤 경우에도 해당되지 않음)

//사용자가 5장의 카드를 입력하면 어떤 패인지 출력한다. s는 spade, h는 heart, c는 club, 그리고 d는 diamond를 나타낸다.
//ace는 a, 10은 t로 표시한다.
 

//일반적으로 프로그램을 설계할 때 가장 먼저 생각해야 할것은 자료구조, 즉 "데이터를 어떻게 표현하고 저장할 것인가" 이다.

//카드를 어떻게 표현할 것인가.?
//rank는 1에서 13까지의 정수로 표현한다. (Ace는 1, j,q,k는 각각 11, 12, 13으로 표현)
//suit는 0에서 3까지의 정수로 표현한다.
//각각의 rank와 suit 마다 몇 장의 카드가 있는지만 알면 된다.
//두 개의 배열을 사용하여 이 정보를 표현한다.
//	num_in_rank[r], r=1,...,13 에는 rank가 r인 카드의 개수를 저장한다.
//	num_in_suit[s], s=0,...,3에는 suit가 s인 카드의 개수를 저장한다.
//이 두 배열은 여러 함수가 읽어야하므로 전역변수로 만든다.

//프로그램이 하는 일은 크게 2가지이다.
//	5장의 카드를 사용자로부터 입력받는다.
//	입력된 카드를 분석하여 어떤 패인지 인식하여 출력한다.
//이 일들을 다음과 같은 두개의 함수들을 만들어 각각 출력한다.
//	read_cards
//	analyze_hand
//main함수는 무한루프를 돌면서 이 두 함수를 순서대로 호출해준다.
//사용자가 입력한 카드에 대한 정보는 두 함수 모두에게 필요하므로 전역변수에 저장하자.


#include <stdio.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/*전역변수*/
int num_in_rank[NUM_RANKS+1];
int num_in_suit[NUM_SUITS];

void read_cards(void);
void analyze_hand(void);

void init_data(); //게임을 여러번 반복할 것이므로 매번 두 배열 num_in_rank, num_in_suit를 0으로 초기화 해주어야한다.

int check_flush();
int check_straight();
int check_four_cards();
int check_three_cards();
int count_pairs();

int main()
{
	while(1){
		read_cards();
		analyze_hand();
	}	
}


void init_data(){
	int rank, suit;
	for(rank = 0; rank < NUM_RANKS; rank++)
		num_in_rank[rank] = 0;
	for(suit = 0; suit < NUM_SUITS; suit++)
		num_in_suit[suit] = 0;
}

void read_cards(void)
{
	char ch, rank_ch, suit_ch;
	int rank, suit;
	init_data();
	int cards_read = 0;
	
	while(cards_read < NUM_CARDS) {
		printf("Enter a card: ");
		scanf(" %c", &rank_ch);
		switch (rank_ch) {
			case 'a':  rank = 1; break;
			case '2':  rank = 2; break;
			case '3':  rank = 3; break;
			case '4':  rank = 4; break;
			case '5':  rank = 5; break;
			case '6':  rank = 6; break;
			case '7':  rank = 7; break;
			case '8':  rank = 8; break;
			case '9':  rank = 9; break;
			case 't':  rank = 10; break;
			case 'j':  rank = 11; break;
			case 'q':  rank = 12; break;
			case 'k':  rank = 13; break;
		}
		scanf(" %c", &suit_ch);
		switch(suit_ch) {
			case 'c':  suit = 0; break;
			case 'd':  suit = 1; break;
			case 'h':  suit = 2; break;
			case 's':  suit = 3; break;	
		}
		num_in_rank[rank]++;
		num_in_suit[suit]++;
		cards_read++;
	}
}


void analyze_hand(void)
{
	if(check_straight() == 1 && check_flush() == 1){
		printf("Straight Flush!");
	} else if(check_four_cards() == 1) {
		printf("Four Cards!");
	} else if(check_three_cards() == 1 && count_pairs() == 1) {
		printf("Full House!");
	} else if(check_flush() == 1) {
		printf("Flush!");
	} else if(check_straight() == 1) {
		printf("Straight!");
	} else if(check_three_cards() == 1) {
		printf("Triple!");
	} else if(count_pairs() == 2) {
		printf("Two pairs!");
	} else if(count_pairs() == 1) {
		printf("One pairs!");
	} else {
		printf("High Card");
	}
	printf("\n");
}



int check_flush()
{
	for(int i = 0; i < NUM_SUITS; i++){
		if(num_in_suit[i] == 5){
			return 1;
		}
	}
	return 0;
}

int check_straight()
{
	int tmp = 0;
	int cycle = 0;
	
	for(int i = 1; i < NUM_RANKS+1; i++){
		if(i == 13){
			if(num_in_rank[i] > 0){
				tmp++;
				i = 1;
				cycle = 1;
			}
		}
		
		if(num_in_rank[i]>0){
			tmp++;
		} else {
			tmp = 0;
			if(cycle == 1) return 0;
		}
		
		if(tmp == 5){
			return 1;
		}
	}
	return 0;
}

int check_four_cards()
{
	for(int i = 1; i < NUM_RANKS+1; i++){
		if(num_in_rank[i] == 4) return 1;
	}
	return 0;
}

int check_three_cards()
{
	for(int i = 1; i < NUM_RANKS+1; i++){
		if(num_in_rank[i] == 3) return 1;
	}
	return 0;
}

int count_pairs()
{
	int pairs = 0;
	for(int i = 1; i < NUM_RANKS+1; i++){
		if(num_in_rank[i] == 2) pairs++;
	}	
	
	return pairs;
}





//11-2 Brute-Force 기법
//2차원 배열에서 소수 찾기
//입력으로 n*n개의 음이 아닌 한자리 정수가 그림과 같이 주어진다. 이 정수들 중 가로, 세로, 대각선의 8방향으로 6개 이하의 연속된 숫자들을 합쳐서 만들 수 있는 모든 소수를 찾아서 나열하는 프로그램을 작성하라. 중복된 수를 출력해도 상관없다.
int n;
int grid[MAX][MAX];

int main() {
	FILE *fp = fopen("/workspace/problem_solving_C/study/input.txt", "r");
	
	fscanf(fp, "%d", &n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < n; j++){
			fscanf(fp, "%d", &grid[i][j]);
		}
	}
	
	fclose(fp);
	
	for(int x = 0; x < n; x++){
		for(int y = 0; y < n; y++) {
			for(int dir = 0; dir < 8; dir++) {
				for(int length = 1; length < 6; length++) {
					int value = computeValue(x, y, dir, length);
					if(value != -1 && isPrime(value))
						printf("%d\n", value);
				}
			}
		}
	}
}

int computeValue(int x, int y, int dir, int len){
	int value = 0;
	for(int i = 0; i < len; i++){
		int digit = getDigit(x, y , dir, i);
		if (digit == -1)
			return -1;
		value = value*10 + digit;
	}
	return value;
}

int getDigit(int x, int y, int dir, int k){
	int newX = x, newY = y;
	switch (dir) {
		case 0: newY -= k; break;
		case 1: newX += k; newY -= k; break;
		case 2: newX += k; break;
		case 3: newX += k; newY += k; break;
		case 4: newY += k; break;
		case 5: newX -= k; newY += k; break;
		case 6: newX -= k; break;
		case 7: newX -= k; newY -= k; break;
	}
	
	if(newX < 0 || newX >= n || newY < 0 || newY >=n)
		return -1;
	
	return grid[newX][newY];
	
}

int isPrime(int k){
	if(k == 1)
		return 0;
	for(int i = 2; i * i < k; i++){
		if(k%i == 0) return 0;
	}
	return 1;
}
