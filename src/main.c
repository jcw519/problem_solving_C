#include <stdio.h>

#define MAX 101

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