#include <stdio.h>
#define MAX 100

//7-1
//N개의 서로다른 정수들을 입력받는다. 그리고 추가로 다시 하나의 정수 K를 입력받는다. N개의 정수들 중에 합이 K가 되는 서로 다른 정수쌍의 개수를 구하여 출력하는 프로그램을 작성하라.

int main(){
	
	int data[MAX];
	int n = 0, count = 0, K;
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	while(fscanf(fp,"%d", &data[n]) != EOF){
		n++;
	}
	fclose(fp);
	
	scanf("%d", &K);
	
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(data[i]+data[j] == K)
				count++;
		}
	}
	
	printf("%d\n", count);
	
}



//7-2 최대 부분합 구하기
//입력으로 n개의 정수가 주어진다. 1개 이상의 연속된 정수들을 더하여 구할 수 있는 최대값을 찾아라.

//input : -2 3 5 -14 12 3 -9 8 -1 13 2 -5 4 
//output : 28
// 구간 == 순서쌍

int main(){
	int data[MAX];
	int n = 0;
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	while(fscanf(fp,"%d", &data[n]) != EOF){
		n++;
	}
	fclose(fp);
	
	int maxSum = data[0];
	
	for(int begin = 0; begin < n; begin++){
		for(int end = begin; end < n; end++){
			int sum = 0;
			for(int k = begin; k <= end; k++){
				sum += data[k];
			}
			
			if(sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	
	printf("%d\n", maxSum);
	
	getchar();
	
}

//7-2 개선ver
int main(){
	int data[MAX];
	int n = 0;
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	while(fscanf(fp,"%d", &data[n]) != EOF){
		n++;
	}
	fclose(fp);
	
	int maxSum = data[0];
	
	for(int begin = 0; begin < n; begin++){
		int sum = 0;
		for(int end = begin; end < n; end++){
			
			sum += data[end]; //개선점 1
			
			if(sum > maxSum) {
				maxSum = sum;
			}
		}
	}
	
	printf("%d\n", maxSum);
	
	getchar();
	
}


//7-3 가장 긴 평지
//N개의 정수를 input.txt 파일로 부터 입력받아 순서대로 배열에 저장한다. 연속해서 등장하는 동일한 값의 최대 개수를 세는 프로그램을 작성하라. 예를 들어 입력이 다음과 같다면 6 3 2 2 2 5 5 5 5 7 8 1 1 연속해서 등장하는 동일한 값의 최대 개수는 밑줄 친 4개이다.

int main(){
	int data[MAX];
	int n = 0;
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	while(fscanf(fp,"%d", &data[n]) != EOF){
		n++;
	}
	fclose(fp);
	
	int maxLength = 0;
	
	int lengthHere = 1;
	for(int i = 1; i < n; i++){
		if(data[i] == data[i-1]){
			lengthHere++;
			if(lengthHere > maxLength){
				maxLength = lengthHere;
			}
		}
		else
			lengthHere = 1;
		
	}
	
	printf("%d\n", maxLength);
	
}





//7-3 coupon collector
//0~5 사이의 정수들을 키보드로 부터 연속해서 입력받는다. 중복된 값들이 입력될 수 있다. 0~5까지의 모든 정수들이 각각 적어도 한 번 이상 입력되면 그때까지 입력된 정수의 개수를 출력하고 종료한다. 예를 들어서 다음과 같이 입력되면 12를 출력하고 종료한다. 5 5 2 2 1 0 0 2 5 2 3 4


//flag
int main(){
	int flag[6] = {0};
	int count = 0;
	int n = 0;
	int k;
	while(count < 6){
		scanf("%d", &k);
		n++;
		if(k>=0 && k<= 5 && flag[k] == 0){
			flag[k] = 1;
			count++;
		}
	}
	
	printf("%d", n);
}