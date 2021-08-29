#include <stdio.h>
#include <string.h>
#define MAX 100

//13-1 문자열 응용
//단어 찾기
//2차원 문자 배열을 파일로부터 읽는다. 입력으로 하나의 문자열을 받아서 배열의 행, 열 혹은 대각선에서 찾는다.

char getChar(int i, int j, int dir, int dist);

char grid[MAX][MAX];
int N;
char word[MAX];
int len;

int main() {
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &N);
	for(int i = 0; i < N; i++){
		fscanf(fp, "%s", grid[i]);
	}
	
	fclose(fp);
	scanf("%s", word);
	len = strlen(word);
	
	int wordExist = 0;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(grid[i][j] != word[0])
				continue;
			if(len == 1 && grid[i][j] == word[0]){
				printf("Found at %d %d.\n", i, j);
				wordExist = 1;
				continue;
			}
			
			for(int dir = 0; dir < 8; dir++){
				int dist = 1;
				for(; dist < len; dist++){
					char ch = getChar(i, j, dir, dist);
					if(ch == '\0' || ch != word[dist])
						break;
				}
				if(dist >= len){
					printf("Found at %d %d %d %d.\n", i, j, dir, dist);
					wordExist = 1;
				}
			}
		}
	}
	
	if(wordExist == 0)
		printf("단어를 찾을 수 없습니다.\n");
	return 0;
}


char getChar(int i, int j, int dir, int dist){
	int newI = i, newJ = j;
	int offSetI[] = {-1,-1,0,1,1,1,0,1};
	int offSetJ[] = {0,1,1,1,0,-1,-1,-1};
	
	newI += dist*offSetI[dir];
	newJ += dist*offSetJ[dir];
	
	if(newI < 0 || newI >= N || newJ < 0 || newJ >= N)
		return '\0';
	
	return grid[newI][newJ];
}

















//13-2 문자열 응용
#include <stdio.h>
#include <string.h>
#define MAX_WORD 4000
#define MAX_LEN 20

char getChar(int i, int j, int dir, int dist);
int search(int nTh);
void readGrid();
void readDictionary();

char dict[MAX_WORD][MAX_LEN];
char grid[MAX_LEN][MAX_LEN];
int n_words;
int gridSize;

int main(void) {
	readDictionary();
	readGrid();
	int i;
	for(i = 0; i < n_words; i++) {
		int result = search(i);
		if(result == 1)
			printf("%s\n", dict[i]);
	}
	
}

void readDictionary(){
	FILE *fp = fopen("dictionary.txt", "r");
	int i = 0;
	while(fscanf(fp,"%s", dict[i]) != EOF){
		i++;
	}
	n_words = i;
	fclose(fp);
	return;
}

void readGrid(){
	FILE *fp = fopen("input.txt", "r");
	fscanf(fp, "%d", &gridSize);
	
	for(int i = 0; i < gridSize; i++){
		fscanf(fp, "%s", grid[i]);
	}
	fclose(fp);
	return;
}

int search(int nTh){
	char word[MAX_LEN];
	
	//strcpy(1,2): 2->1으로 복사되어진다.
	strcpy(word, dict[nTh]);
	//printf("%s", word);
	
	int wordLength = strlen(word);
	
	for(int i = 0; i < gridSize; i++){
		for(int j = 0; j < gridSize; j++){
			if(grid[i][j] != word[0])
				continue;
			
			for(int dir = 0; dir < 8; dir++){
				int dist = 1;
				for(;dist < wordLength; dist++){
					char ch = getChar(i, j, dir, dist);
					if(ch == '\0' || ch != word[dist])
						break;
				}
				if(dist >= wordLength){
					return 1;
				}
				
			}
		}
	}
	return 0;
}

char getChar(int i, int j, int dir, int dist){
	int newI = i, newJ = j;
	int offSetI[] = {-1,-1,0,1,1,1,0,1};
	int offSetJ[] = {0,1,1,1,0,-1,-1,-1};
	
	newI += dist*offSetI[dir];
	newJ += dist*offSetJ[dir];
	
	if(newI < 0 || newI >= gridSize || newJ < 0 || newJ >= gridSize)
		return '\0';
	
	return grid[newI][newJ];
}
