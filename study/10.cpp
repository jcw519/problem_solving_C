#include<stdio.h>
#define MAX 100

//10. 매개변수 전달

//10-1 bubblesort를 함수로 만들어 보자
void bubblesort(int n, int data[]);
void swap(int* a, int* b);

int main(){
	int n = 0;
	int data[MAX];
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	
	while(fscanf(fp, "%d", &data[n]) != EOF) n++;
	fclose(fp);
	
	bubblesort(n, data); //배열을 함수에 넘겨줄때에는 배열 이름을 넘겨준다
	
	for(int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	
	
}

void bubblesort(int n, int data[])
{
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(data[j] > data[j+1]) {
				swap(&data[j], &data[j+1]);
			}
		}
	}
}


void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}











//10-2 
//n개의 음이 아닌 한 자리 정수들을 입력받아 배열에 순서대로 저장한다. 임의의 6자리 이내의 연속된 숫자를 하나의 정수로 환산했을때 소수가 되는 모든 경우를 찾아서 소수값을 출력하는 프로그램을 작성하라.
int converToInt(int data[], int s, int t);
void printPrimesStartAt(int s, int data[], int n);
int isPrime(int k);

int main(){
	int n = 0;
	int data[MAX];
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	
	while(fscanf(fp, "%d", &data[n]) != EOF) n++;
	fclose(fp);
	
	for(int i = 0; i < n; i++){
		// for(int j = i; j < n && j < i + 6; j++){
		// 	int value = converToInt(data, i, j);
		// 	if(isPrime(value) == 1){
		// 		printf("%d\n", value);
		// 	}
		// }
		printPrimesStartAt(i, data, n);
	}
	
	getchar();getchar();
	
}


void printPrimesStartAt(int s, int data[], int n)
{
	int value = 0;
	if(data[s] == 0) return;
	for(int i = 0; i < 6; i++) {
		if(s+i >= n) return;
		value = value*10 + data[s + i];
		if(isPrime(value) == 1) printf("%d\n", value);
	}
}




int converToInt(int data[], int s, int t)
{
	int value = 0;
	for(int i = s; i <= t; i++){
		value = value*10 + data[i]; 
	}
	return value;	
}

int isPrime(int k)
{
	if(k <= 1) return 0;
	for(int i = 2; i*i <= k; i++){
		if(k%i == 0) return 0;
	}
	return 1;
}