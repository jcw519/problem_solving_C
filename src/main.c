#include <stdio.h>
//5-9[해결]
//우선 input9.txt파일로 부터 정수들을 읽는다. 정수의 개수는 따로 주어지지 않으며 파일의 끝까지 읽어야 한다. 정수의 개수는 100개 이하이다. 정수들 중에서 자신보다 먼저 나온 모든 정수들 보다 크거나 같은 정수를 리더라고 부른다. 그리고 첫 번째 정수는 무조건 리더이다. 리더가 아닌 모든 정수들은 무시하고 리더들만 입력된 순서대로 배열에 저장하는 프로그램을 작성하라. 리더들은 배열의 맨 앞에서 부터 빈 칸 없이 저장되어야 한다. 먼저 리더들의 개수를 출력하고 이어서 리더들을 순서대로 화면으로 출력하라.
int main(){
	
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input5-9.txt", "r");
	int data[100];
	int leader[100];
	int i = 0;
	
	while(fscanf(fp,"%d", &data[i]) != EOF){
		i++;
	}
	
	//i = 10
	
	// for(int j = 0; j < i; j++){
	// 	printf("%d", data[j]);
	// }
	
	leader[0] = data[0];
	//data[0] = 1, data[1] = 2 ... data[9] =10
	//leader[0] = 1, leader[8] = 9 laeader[9] = 10
	
	int k = 0;
	
	for(int j = 1; j < i; j++){
		if(data[j] >= leader[k]){
			k++;
			leader[k] = data[j];
		}
	}
	
	printf("%d: ", k+1);
	
	for(int i = 0; i < k+1; i++){
		printf("%d ", leader[i]);
	}
	
	fclose(fp);
	
	getchar(); getchar();
}