#include <stdio.h>
#include <string.h>

#define MAX 101

int main() {
	/*C언어에서 문자열 다루기*/
	char text[MAX] = "asdfsadgsadfsadfafwqefsdafas";
	int i;
	
	char message[] = "hello, i am a string";
	printf("Orignal message : %s\n", message);
	
	i = 0;
	while(message[i] != '\0') {
		text[i] = message[i];
		i++;
	}
	
	
	text[i] = '\0';
	printf("Copied message : %s\n", text);
	
	
	
	/*문자열 입력받기*/
	char buffer[100];
	scanf("%s", buffer); //delimited by white characters
	//scanf로 입력받은 단어뒤에는 자동으로 null character가 삽입
	printf("%s\n", buffer);
}










/*string.h*/
#include <stdio.h>
#include <string.h>

#define MAX 101

int main() {
	char word[50], line[100];
	int len;
	
	scanf("%s", word);
	//strlen(e); null character을 제외한 문자열의 길이를 반환한다
	printf("The length of %s is %ld\n", word, strlen(word));
	
	
	
	
	strcpy(line, word);
	printf("%s\n", line);
	
	
	
	
	
	scanf("%s", word);
	int result = strcmp(word, line); // == : 0, > : positive, < : negative
	if(result == 0)
		printf("Equal\n");
	else if(result > 0)
		printf("%s\n", word);
	else
		printf("%s\n", line);
	//positive라는 것은 사전식으로 더 뒤에 나온다는 뜻이다.
	
	
	
	
	strcat(line, word);
	printf("The length of %s is %ld\n", line, strlen(line));
	
	return 0;
}







//palindrome
int isPalindrome(char str[]);

int main() {
	char word[50];
	scanf("%s", word);
	int result = isPalindrome(word);
	if(result)
		printf("Palindrome.\n");
	else
		printf("not palindrome.\n");
	
	return 0;
}

int isPalindrome(char str[]) {
	int len = strlen(str);
	for(int i = 0; i < len/2 ; i++){
		if(str[i] != str[len-1-i])
			return 0;
	}
	return 1;
}








//데이터 파일에서 문자열 읽고 쓰기
int main() {
	char word[50];
	
	FILE *in_fp = fopen("input.txt", "r");
	FILE *out_fp = fopen("output.txt", "w");
	
	while(fscanf(in_fp, "%s", word) != EOF){
		fprintf(out_fp, "%s ", word);
	}
	
	
	fclose(in_fp);
	fclose(out_fp);	
	
	return 0;
}