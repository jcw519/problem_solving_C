#include <stdio.h>
#include <string.h>

//12-3
//아나그램(anagram)이란 문자들의 순서를 재배열하여 동일하게 만들 수 있는 문자열을 말한다. 대소문자는 구분하지 않는다. 예를 들어서 Silent와 Listen은 아나그램이다. 입력으로 두 문자열을 받아서 아나그램인지 판단하는 프로그램을 작성하라.
void stringSort(char str[]){
	int strLength = strlen(str);
	
	for(int i = strLength - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(str[j] > str[j+1]){
				char tmp;
				tmp = str[j];
				str[j] = str[j+1];
				str[j+1] = tmp;
			}
		}
	}
}

void strLow(char str[]){
	for(int i = 0; i < strlen(str); i++){
		if('A' <= str[i] && 'Z' >= str[i])
			str[i] = str[i] + 32;
	}
}

int main(void) {
	char str1[10];
	char str2[10];
	scanf("%s", str1);
	scanf("%s", str2);
	strLow(str1);
	strLow(str2);
	stringSort(str1);
	stringSort(str2);
	//printf("%s %s", str1, str2);
	
	if(strcmp(str1, str2) == 0){
		printf("yes");
	} else {
		printf("no");
	}
}

