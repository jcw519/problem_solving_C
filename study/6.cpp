#include <stdio.h>
#define MAX 100

//키보드로 부터 연속해서 정수들을 입력받는다. 정수가 하나 씩 입력될 떄 마다 현재까지 입력된 정수들을 오름차순으로 정렬하여 화면에 출력한다. 사용자가 -1을 입력하면 프로그램을 종료한다.
int main(){
	int data[MAX];
	int n = 0, value;
	
	while(1){
		scanf("%d", &value);
		if(value == -1)
			break;
		
		int i = n - 1;
		while(i >= 0 && data[i] > value){
			data[i+1] = data[i];
			i--;
		}
		
		data[i+1] = value;
		n++;
		
		for(int i = 0; i < n; i++){
			printf("%d ", data[i]);
		}
		printf("\n");
		
	}
	

}








//bubble sort
//input.txt파일에서 정수들을 입력받아 순서대로 배열에 저장한다. 그런 다음 오름차순으로 정렬하여 출력하라.

int main(){
	FILE *fp = fopen("/workspace/problem_solving_C/study/input.txt", "r");
	int data[MAX];
	
	int n = 0;
	while(fscanf(fp,"%d", &data[n]) != EOF){
		n++;
	}
	
	
	for(int i = n-1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(data[j] > data[j+1]){
				int tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%d ", data[i]);
	}
	
	getchar();
	
	
}