#include<stdio.h>

int main(void){
	int year = 2021; /*올해 년도*/
	
	int lastDayOfMonth[]={0,31,28,31,30,31,30,31,31,30,31,30,31}; /*각 월별 마지막 일*/
	int lastyear = year-1; /*지난 년도*/
	/*윤년 계산 : 올해가 윤년이면 2월의 마지막 날을 29일로 바꾼다.*/
	if(year%4 == 0 && (year%100 != 0 || year%400 == 0))
		lastDayOfMonth[2] = 29; 
	/*
	1년 1월 1일부터 지금까지 요일이 총 몇번 바뀐지 계산
	1년 1월 1일은 월요일이고 한해가 지날때 마다 요일은 하루씩 밀린다.
	윤년이 있으면 1년은 366일이므로 요일은 이틀 밀린다.
	위의 규칙을 통해서 올해 1월 1일의 요일은 아래와 같이 구한다.
	*/
	int firstDayOfMonth = (lastyear+(lastyear/4)-(lastyear/100)+(lastyear/400)+1)%7;
	/*
	firstDayOfMonth = 0 : 일요일
	firstDayOfMonth = 1 : 월요일
	firstDayOfMonth = 2 : 화요일
	.
	.
	.
	firstDayOfMonth = 6 : 토요일
	*/
	
	//아래부분은 반장님이 직접 수정하시면 됩니다.//
	printf("과제명 : 올해(2021)의 달력\n");
	printf("제출자 : 정채원\n");
	printf("제출일자 : 2021-09-04\n\n");

	
	
	for(int month = 1; month < 13; month++){
		printf("      %d년 %d월\n",year, month);
		printf("---------------------\n");
		printf(" 일 월 화 수 목 금 토\n");
		printf("---------------------\n");
		for(int day = -firstDayOfMonth; day < lastDayOfMonth[month]; day++) {
			if(day < 0){
				printf("   ");
			}
			else {
				printf(" %2d",day + 1);
				/*토요일의 날짜가 출력된 후 일요일 날짜는
				다음 행부터 날짜가 나와야 하므로 줄바꿈문자를 출력한다.*/
				if((firstDayOfMonth + day + 1)%7 == 0){
					printf("\n");
				}
			}
		}
		
		/*한달의 마지막 날짜까지 출력이 끝난 후 다음 달의 1일은 무슨 요일인지 구해준다.*/
		firstDayOfMonth = (firstDayOfMonth+lastDayOfMonth[month])%7;
		printf("\n");
	}
}