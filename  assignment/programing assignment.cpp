#include <stdio.h>


//1-5
//padovan 수열은 다음과 같이 정의된다. 입력으로 정수 n>2을 받아서 Pn을 계산하여 출력하는 프로그램을 작성하라
//p0 = p1 = p2 =1
// pn = pn-2 +pn-3, n>2

int main(){
	
	int p0 = 1, p1 = 1, p2 =1, pn = 2;
	
	int n;
	scanf("%d", &n);
	
	for(int i = 3; i < n; i++){
		p0 = p1;
		p1 = p2;
		p2 = pn;
		pn = p0 + p1;
	}
	
	printf("%d", pn);
	
	getchar(); getchar();
	
	

}


//1-7
//입력으로 하나의 양의 정수 n을 받은 후 다음의 합을 구하여 출력하는 프로그램을 작성하라.
// 1 - 1/2 + 1/2^2 - 1/2^3 + ...+ (-1)^n * 1/2^n

int main(){
	
	double sum = 1.0;
	double k = -1.0/2.0;
	
	// double sum = 1;
	//double k = -1/2;  이 두개의 차이점???
	
	
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		sum += k;
		k *= k;
	}
	
	printf("%f", sum);
}





//1-11
//입력으로 하나의 양의 정수를 받은 후 1이될때 까지 연속적으로 2로 나눈 몫을 출력하는 프로그램을 착성하라.
//예를 들어 입력된 정수가 51이면 25,12,6,3,1 을 순서대로 출력하면 된다.
//가령 입력된 정수가 127이면 63,31,15,7,3,1을 출력하면 된다.

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	while(n != 1){
		n = n/2;
		printf("%d, ",n);
	}
	
	getchar(); getchar();

}




//1-12 [해결]
//키보드로 부터 10개의 정수들을 연속해서 입력 받는다. 하나의 정수를 입력 받을 떄 마다 
//현재까지 입력된 정수들의 평균을 계산하여 출력하는 프로그램을 작성하라.
#define MAX 10

int main(){
	
	int sum = 0;
	
	for(int i = 1; i <= MAX; i++){
		int n = 0;
		scanf("%d", &n);	
		sum += n;
		
		printf("%f\n", (double)sum/i);
	}

}



//1-13[해결]
int main() {
	
	double r; //이율
	int inout;
	
	double money = 0.0 ;
	
	scanf("%lf", &r); // 변수를 double로 선언했다면 scanf에는 서식 지정자로 %lf를 넣고, long double로 선언했다면 %Lf를 넣습니다(double은 printf로 출력할 때 %f를 써도 되지만 scanf는 %lf를 써야 합니다).
	
	for(int i = 0; i < 12; i++){
		scanf("%d", &inout);
		money += inout;
		money += money*r;
		printf("%f\n", money);
	}
	

}





//1-13[미해결]
int main() {
	
	double sinx = 0.0;
	double cosx = 0.0;
	
	double an = 1;
	double x;
	
	scanf("%lf", &x);
	cosx += an;
	
	for(int i = 1; i <= 200; i+=2){
		an = an*(x/i);
		sinx += an;
		an = an*(-x/i+1);
		cosx += an;
	}
	
	printf("sinx = %f, cosx = %f\n", sinx, cosx);
	
	getchar();
	
	//sin과 cos인 번갈아 나온다!!!

}



//2-4[해결]
//10개의 정수를 키보드로 부터 입력받는다. 입력된 정수들 중에서 음이 아닌 정수들 중에서 최소값을 찾아서 출력하는 프로그램을 작성하라.

int main(){
	int n;
	int minNum;
	int i = 0;
	
	for(int i = 0 ; i < 10; i++){
		scanf("%d", &n);
		if(i == 0){ //첫번째 입력시
			minNum = n;
		}else if(minNum < 0){ //입력이 음수만 들어오는 경우
			minNum = n;
		}else if(n >= 0 && n < minNum){
			minNum = n;
		}
	}
	
	if(minNum < 0){
		printf("input error");
	}else{
		printf("%d", minNum);	
	}
	
	
	return 0;
}





//2-6[해결]
//두 개의 날짜를 입력받은 후 그 중 첫 번째 날짜가 더 이르면 -1, 두번째 날짜가 더 이르면 1, 두날짜가 동일하면 0을 출력하는 프로그램을 작성하라.

int main(){
	int year, month, day;
	int year2, month2, day2;
	
	scanf("%d %d %d", &year, &month, &day);
	scanf("%d %d %d", &year2, &month2, &day2);
	
	if(year > year2){
		printf("1");
	}else if( year < year2){
		printf("-1");
	}else{
		if(month > month2){
		printf("1");
		}else if( month < month2){
		printf("-1");
		}else{
			if(day > day2){
			printf("1");
			}else if( day < day2){
			printf("-1");
			}else{
				printf("0");
			}
		}
	}
	
	
}





//2-8[해결]
//두 개의 폐구간[a, b]와 [c, d]를 입력받는다. a<=b이고 c<=d이다. 두 구간이 겹치는지 판단하여 yes 혹은 no로 출력하는 프로그램을 작성하라. 두 구간이 겹친다는 것은 교집합이 공집합이 아니라는 의미이다.

int main(){
	int a,b,c,d;
	int tmp = 0;
	
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(a > b || c > d){
		printf("input error");
		tmp = 1;
	} 
	else {
		for(int i = a; i <= b; i++){
			if(tmp == 1){
				break;
			}
			for(int j = c; j <= d; j++){
				if(i == j){
					printf("yes");
					tmp = 1;
				}
			}
		}
	}
	
	
	if(tmp == 0){
		printf("no");
	}
}





//2-10[해결]
//평면 상의 n개의 점의 좌표가 순서대로 주어진다. 단, 임의의 연속된 두 점은 동일한 x좌표를 갖거나 혹은 동일한 y좌표를 가진다. 만약 그렇지 않으면 Input error라고 출력하고 종료한다. 입력된 점을 순서대로 연결하여 만들어지는 polyline의 길이를 구하여 출력하는 프로그램을 작성하라. 입력은 먼저 점의 개수 n이 주어지고, 이어서 n개의 점의 x좌표와 y좌표의 쌍이 순서대로 주어진다. 가령 아래의 첫 번째 예에서는 n=4이고, 점의 좌표는 (10,10), (20,10), (30,40), (50,40)이다.

int main(){
	int n;
	int polylineLength = 0;
	int x1, y1, x2, y2;
	int error = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		if(i == 0){
			scanf("%d %d", &x1, &y1);
		}else{
			scanf("%d %d", &x2, &y2);
			if(x1 == x2 || y1 == y2){
				if(x1 == x2){
					if(y2 - y1 < 0){
						polylineLength += -(y2 - y1);
					}else{
						polylineLength += y2 - y1;
					}
				}else if(y1 == y2){
					if(x2 - x1 < 0){
						polylineLength += -(x2 - x1);
					}else{
						polylineLength += x2 - x1;
					}
				}
				
				x1 = x2;
				y1 = y2;
				
			}else{
				error = 1;
			}
		}
	}
	
	if(error = 0){
		printf("%d", polylineLength);	
	}else{
		printf("Input error");
	}
	
	
	return 0;
	
}






//2-11[해결]
//평면 상의 3개의 점의 좌표가 순서대로 주어진다. 단, 임의의 연속된 두 점은 동일한 x좌표를 갖거나 혹은 동일한 y좌표를 가진다. 만약 그렇지 않으면 Input error라고 출력하고 종료한다. 입력된 점을 순서대로 방문할때 2번째 점에서 3번째 점으로 이동하는 것이 직진인지, 좌회전인지, 우회전인지, u턴인지 판단하는 프로그램을 작성하라.

int main(){
	int direction;
	
	int x1, y1, x2, y2, x3, y3;
	
	scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);
	
	if((x1 == x2 || y1 == y2) && (x2 == x3 || y2 == y3)){
		//1
		if(x1 == x2 && y1 < y2){
			if(x2 == x3 && y2 < y3){
				printf("Straight");
			}else if(y2 == y3 && x2 < x3){
				printf("Right");
			}else if(x2 == x3 && y2 > y3){
				printf("U-turn");
			}else if(y2 == y3 && x2 > x3){
				printf("Left");
			}
		} else if (y1 == y2 && x1 < x2){ //2
			if(x2 == x3 && y2 < y3){ // s
				printf("Left");
			}else if(y2 == y3 && x2 < x3){
				printf("Straight");
			}else if(x2 == x3 && y2 > y3){
				printf("Right");
			}else if(y2 == y3 && x2 > x3){
				printf("U-turn");
			}
		} else if (x1 == x2 && y1 > y2){ //3
			if(x2 == x3 && y2 < y3){ // s
				printf("U-turn");
			}else if(y2 == y3 && x2 < x3){
				printf("Left");
			}else if(x2 == x3 && y2 > y3){
				printf("Straight");
			}else if(y2 == y3 && x2 > x3){
				printf("Right");
			}
		} else if (y1 == y2 && x1 > x2){ //4
			if(x2 == x3 && y2 < y3){ // s
				printf("Right");
			}else if(y2 == y3 && x2 < x3){
				printf("U-turn");
			}else if(x2 == x3 && y2 > y3){
				printf("Left");
			}else if(y2 == y3 && x2 > x3){
				printf("Straight");
			}
		}
		
	}else{
		printf("Input error");
	}
}








//2-12[해결]
//평면 상의 n개의 점의 좌표가 순서대로 주어진다. 단, 임의의 연속된 두 점은 동일한 x좌표를 갖거나 혹은 동일한 y좌표를 가진다. 만약 그렇지 않으면 input error라고 출력하고 종료한다. 입력된 점들을 순서대로 방문할 때 좌회전, 직진, 우회전, 그리고 u-턴의 획수를 카운트하여 순서대로 출력하는 프로그램을 작성하라. 입력은 먼저 n의 값이 주어지고, 이어서 n개의 점의 x좌표와 y좌표가 순서대로 주어진다. 가령 아래의 첫 번째 예는 n = 3이고, 점의 좌표는 (0,0), (2,0), (2,2)이며, 출력 1 0 0 0은 좌회전은 1번이고 나머지는 0회임을 의미한다. 출력되는 회수의 총합은 항상 n -2가 될 것이다.

int main(){
	int countL = 0, countS = 0, countR = 0, countU = 0;
	int n;
	int x1, y1, x2, y2, x3, y3;
	int error = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		if(i == 0){
			scanf("%d %d", &x1, &y1);
		} else if( i == 1){
			scanf("%d %d", &x2, &y2);
		} else{
			scanf("%d %d", &x3, &y3);
			
			if((x1 == x2 || y1 == y2) && (x2 == x3 || y2 == y3)){
				if(x1 == x2 && y1 < y2){ //1
					if(x2 == x3 && y2 < y3){
						countS++;//printf("Straight");
					}else if(y2 == y3 && x2 < x3){
						countR++;//printf("Right");
					}else if(x2 == x3 && y2 > y3){
						countU++;//printf("U-turn");
					}else if(y2 == y3 && x2 > x3){
						countL++;//printf("Left");
					}
					
					x1 = x2; x2 = x3;
					y1 = y2; y2 = y3;
					
				} else if (y1 == y2 && x1 < x2){ //2
					if(x2 == x3 && y2 < y3){ // s
						countL++;//printf("Left");
					}else if(y2 == y3 && x2 < x3){
						countS++;//printf("Straight");
					}else if(x2 == x3 && y2 > y3){
						countR++;//printf("Right");
					}else if(y2 == y3 && x2 > x3){
						countU++;//printf("U-turn");
					}
					
					x1 = x2; x2 = x3;
					y1 = y2; y2 = y3;
					
				} else if (x1 == x2 && y1 > y2){ //3
					if(x2 == x3 && y2 < y3){ // s
						countU++;//printf("U-turn");
					}else if(y2 == y3 && x2 < x3){
						countL++;//printf("Left");
					}else if(x2 == x3 && y2 > y3){
						countS++;//printf("Straight");
					}else if(y2 == y3 && x2 > x3){
						countR++;//printf("Right");
					}
					
					x1 = x2; x2 = x3;
					y1 = y2; y2 = y3;
					
				} else if (y1 == y2 && x1 > x2){ //4
					if(x2 == x3 && y2 < y3){ // s
						countR++;//printf("Right");
					}else if(y2 == y3 && x2 < x3){
						countU++;//printf("U-turn");
					}else if(x2 == x3 && y2 > y3){
						countL++;//printf("Left");
					}else if(y2 == y3 && x2 > x3){
						countS++;//printf("Straight");
					}
					
					x1 = x2; x2 = x3;
					y1 = y2; y2 = y3;
					
				}
				
			} else {
				error = 1;
			}
		}
	}
	
	if(error == 1){
		printf("Input error");
	}else{
		printf("%d %d %d %d", countL, countS, countR, countU);
	}
	
}






//3-1[해결]
//키보드로 부터 양의 정수들을 연속해서 입력받는다. 입력으로 들어온 홀수의 합과 짝수의 합이 동일해지면 그때까지 입력된 정수의 개수를 출력하고 종료한다. 단, 적어도 하나 이상의 입력을 받아야 한다.

int main(){
	
	int count = 0;
	int n;
	int evenNum = 0;
	int oddNum = 0;
	
	while(1){
		if(count > 0 && evenNum == oddNum){
			break;
		}
		scanf("%d", &n);
		
		if(n%2 == 0){
			evenNum += n;
		}else{
			oddNum += n;
		}
		
		count++;
	}
	
	printf("%d", count);
	
	
}





//3-3[해결]
//입력으로 두 양의 정수를 받은 후 두 정수의 최대공약수(GDC)를 구해서 출력하는 프로그램을 작성하라. GCD를 구하기 위해서 Euclid 알고리즘을 사용하라. Eucllid 알고리즘은 다음의 성질을 이용한다 : 두 정수 x,y중에 크거나 같은 쪽을 x라고하자. 만약 x가 y로 나누어 떨어지면 GCD는 y이다. 그렇지 않다면 x와 y의 GCD는 x%y 와 y의 GCD와 같다
	
int main(){
	
	int x, y, GCD;
	int tmp;
	
	scanf("%d %d", &x, &y);
	
	if(x<y){
		tmp =x;
		x = y;
		y = tmp;
	}
	
	while(x%y != 0){
		tmp = y;
		y = x%y;
		x = tmp;
	}
	
	printf("GCD is %d", y);
	
	
}







//3-5[해결]
//입력으로 -1이 들어올 때 까지 연속해서 정수들을 입력받는다. -1이 입력되면 그때까지 입력된 정수들 중에서 가장 큰 수와 2번째로 큰 수를 출력하라.

int main(){
	
	int n;
	
	int firstNum;
	int secondNum;
	
	for(int i = 0; 1 ; i++){
		scanf("%d", &n);
		if(i == 0){
			firstNum = n;
		} else if(i == 1){
			secondNum = n;
			if(firstNum < secondNum){
				int tmp;
				tmp = firstNum;
				firstNum = secondNum;
				secondNum = tmp;
			}
			
		} else{
			if(n == -1){
				break;
			} else {
				if(n > firstNum){
					secondNum = firstNum;
					firstNum = n;
				} else if(n > secondNum){
					secondNum = n;
				}
			} 
		}
	}
	
	printf("%d %d", firstNum, secondNum);
	
}






//3-7[해결]
//키보드로 부터 2개 이상의 정수들을 연속해서 입력받는다. -1은 입력의 끝을 의미한다 (즉 -1 자체는 입력된 정수로 간주하지 않는다.) 입력된 정수들 중에서 local minima의 개수를 카운트하여 출력하라. 여기서 local minima란 바로 직전에 입력된 정수보다 작거나 같고, 바로 다음에 입력된 정수보다도 작거나 같은 정수를 의미한다. 단, 첫 번째 정수는 2번째 정수보다 작거나 같으면  local minima로 간주하고, 마지막 정수는 바로 이전의 정수보다 작거나 같으면 local minima로 간주한다.

int main(){
	
	int a, b;
	int n;
	int countLocalminima = 0;
	
	for(int i = 0; 1 ; i++){
		scanf("%d", &n);
		if(i == 0){
			a = n;
		}else if(i == 1){
			b = n;
			if(a <= b){
				countLocalminima++;
			}
		} else {
			if(n == -1){
				if(a >= b){
					countLocalminima++;
				}
				break;
			}
			
			if(a >= b && n >= b){
				countLocalminima++;
			}
			a = b;
			b = n;
		}
	}
	
	printf("%d", countLocalminima);
	
	
	
}






//3-8[해결]
// 아래의 표는 우리 나라의 소득 구간별 근로소득세율이다. 가령 소득이 1억원이면 소득세는 다음과 같이 계산된다.
int main(){
	int tax = 0;
	int income;
	
	scanf("%d", &income);
	
	while(1){
		if(income > 500000000) {
			tax += (income - 500000000)*0.4;
			income -= (income - 500000000);
		} else if (income > 150000000) {
			tax += (income - 150000000)*0.38;
			income -= (income - 150000000);
		} else if (income > 88000000) {
			tax += (income - 88000000)*0.35;
			income -= (income - 88000000);
		} else if (income > 46000000) {
			tax += (income - 46000000)*0.24;
			income -= (income - 46000000);
		} else if (income > 12000000) {
			tax += (income - 12000000)*0.15;
			income -= (income - 12000000);
		} else {
			tax += income*0.06;
			break;
		}
	}
	
	printf("%d", tax);
}






//4-3[해결]
int main(){
	
	int N;
	
	scanf("%d", &N);
	
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= N; j++){
			
			if(i%2 == 0){
				printf("%d %d\n",j, i);
			}else if(i%2 == 1){
				printf("%d %d\n",N-j,i);
			}
			
		}
	}
	
	
	
}









//4-7
//원점에서 출발하여 매 스텝마다 동서남북 4방향 중 한 방향을 각각 1/4확률로 랜덤하게 선택하여 1만큼 움직인다. x좌표나 y좌표가 N이나 -N에 도달하면 종료한다. 종료할 떄까지 몇 스텝이 걸리는지 실험적으로 판단하는 프로그램을 작성하라. 즉 동일한 실험을 T번 반복하여 가장자리에 도달하는데 걸린 스텝 수의 평균을 구하라. N은 입력으로 주어지고 T는 1000으로 하라.
#include <stdlib.h>
#include <time.h>

#define T 1000

int main(){
	
	int N;
	srand((unsigned int)time(NULL));
	
	scanf("%d", &N);
	
	
	int sum = 0;
	
	for(int i = 0; i < T; i++){
		int countStep = 0;
		int x = 0;
		int y = 0;
		while(x != N && x != -N && y != N && y != -N){
			int direction  = rand()%4;
			if(direction == 0){
				x++;
			} else if ( direction == 1){
				x--;
			} else if (direction == 2){
				y++;
			} else {
				y--;
			}
			countStep++;
		}
		sum += countStep;
	}
	
	printf("%d", sum/T);
	
	
	getchar(); getchar();
	
}








//4-8
//주사위를 6번 던져서 1이 적어도 한번나올 확률, 주사위를 12번 던져서 1이 적어도 두번나올 확률
#include <stdlib.h>
#include <time.h>
#define T 1000000


int main(){
	int sum1 = 0;
	int sum2 = 0;
	
	srand((unsigned int)time(NULL));
	
	for(int i = 0; i < T; i++){
		int count1 = 0;
		for(int j = 0; j < 6; j++){
			int dice = rand() % 6;
			if(dice == 0){
				count1++;
			}			
		}
		if(count1 >= 1){
			sum1++;
		}
		
		count1 = 0;
		for(int j = 0; j < 12; j++){
			int dice = rand()%6;
			if(dice == 0){
				count1++;
			}
		}
		if(count1 >= 2){
			sum2++;
		}
	}
		
	
	printf("%f %f", (double)sum1/T, (double)sum2/T);
	
		
}






//4-10[해결]
//평면상에서 좌표축에 평행한 2개의 직사각형이 입력으로 주어진다. 두 사각형이 교차하는 영역, 즉 두 사각형에 공통으로 포함되는 영역의 면적을 구하는 프로그램을 작성하라. 각각의 사각형은 대각 방향의 두 꼭지점의 좌표로 주어진다. 꼭지점의 좌표값은 -1,000,000 이상이고 1,000,000이하의 정수이다.
int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int x_length = 0;
	int y_length = 0;
	
	scanf("%d %d %d %d %d %d %d %d",
		  &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	
	if(x1 > x2){
		int tmp;
		tmp = x1;
		x1 = x2;
		x2 = tmp;
	}
	
	if(y1 > y2){
		int tmp;
		tmp = y1;
		y1 = y2;
		y2 = tmp;
	}
	
	if(x3 > x4){
		int tmp;
		tmp = x3;
		x3 = x4;
		x4 = tmp;
	}
	
	if(y3 > y4){
		int tmp;
		tmp = y3;
		y3 = y4;
		y4 = tmp;
	}
	
	for(int i = x1; i <= x2; i++){
		for(int j = x3; j <= x4; j++){
			if(i == j){
				x_length++;
			}
		}
	}
	
	for(int i = y1; i <= y2; i++){
		for(int j = y3; j <= y4; j++){
			if(i == j){
				y_length++;
			}
		}
	}
	
	
	printf("%d", (x_length-1)*(y_length-1));
	
	getchar(); getchar();
	
}








//5-1[해결]
//먼저 입력될 정수의 개수 n<= 100을 입력받고, 이어서 n개의 정수를 입력받아 순서대로 배열에 저장한다. 추가로 하나의 정수 K를 입력받은 후 n개의 정수들 중에 K보다 작거나 같으면서 가장 큰정수를 찾아 그 정수의 배열 인덱스, 찾은 정수의 값, 그리고 K와의 차이의 절대값을 출력하는 프로그램을 작성하라. 답이 여럿일 때는 그 중 가장 먼저 나온 값을 찾고, 답이 존재하지 않을 때는 -1을 출력하라.
int main(){
	
	int n;
	int data[100];
	int K;
	int max_index;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	
	
	scanf("%d", &K);
	
	int tmp = 0;
	
	for(int i = 0; i <n; i++){
		if(data[i] <= K && tmp == 0){
			max_index = i;
			tmp = 1;
		} else if(data[i] <= K && data[i] > data[max_index]){
			max_index = i;
		}
	}
	
	
	
	if(tmp == 1){
		printf("%d %d %d", max_index, data[max_index],
			   K-data[max_index]);
	} else {
		printf("-1");
	}
	
	getchar(); getchar();
	
}






//5-3[해결]
//먼저 입력될 정수의 개수 n <= 100을 입력받고, 이어서 n개의 정수를 받아 평균과 표준편차를 계산하여 출력하는 프로그램을 작성하라. 표준편차는 다음과 같이 정의된다. 루트를 계산하기 위해서 math.h를 include하고 sqrt함수를 사용하라.
#include <math.h>

int main(){
	double avg = 0;
	double var = 0;
	int n;
	int data[100];
	
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	
	for(int i = 0; i < n; i++){
		avg += data[i];
	}
	
	avg /= n;
	
	for(int i = 0; i < n; i++){
		var += (data[i] - avg)*(data[i] - avg);
	}
	
	var /= n;
	
	printf("%f  %f", avg, sqrt(var));
	
	getchar(); getchar();
}








//5-4[해결]
//하나의 양의 정수 N을 입력 받은 후 정수 N에 0에서 9까지의 digit가 각각 몇 번씩 등장하는지 카운트하여 순서대로 출력하는 프로그램을 작성하라.
int main(){
	
	int data[10] = {0};
	int N;
	
	scanf("%d", &N);
	while(N>0){
		data[N%10]++;		
		N /= 10;
	};
	
	for(int i = 0; i < 10; i++){
		printf("%d ", data[i]);
	}
	
	getchar(); getchar();
}








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









//5-10[해결]
//input5-10.txt 파일에 매일 매일의 주식 가격을 표현하는 N개의 양의 정수가 주어진다. 정수의 개수 N은 따로 주어지지 않으며 파일의 끝까지 읽어야 한다. 주식 거래로 얻을 수 있는 최대 이익을 계산하는 프로그램을 작성하라.
int main(){
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input5-10.txt", "r");
	int data[100];
	int income = 0;
	int purchasePrice;
	int position = 0;
	int i = 0;
	
	
	while(fscanf(fp,"%d",&data[i]) != EOF){
		i++;
	}
	
	fclose(fp);
	
	for(int j = 0; j < i; j++){
		if(position == 0 && data[j]<data[j+1]){
			purchasePrice = data[j];
			position = 1;
		}
		
		if(position == 1 && data[j]>data[j+1]){
			income += data[j] - purchasePrice;
			position = 0;
		}
	}
	
	printf("%d", income);
	
	getchar();
	
	
}





//6-1[해결]
//키보드로 부터 연속해서 정수들을 입력받는다. 정수가 하나 씩 입력될 때 마다 현재까지 입력된 정수들을 오름차순으로 정렬하여 화면에 출력한다. 단, 새로 입력된 정수가 이미 배열에 저장되어 있다면 추가하는 대신 "duplicate entry"라고 출력한다. 사용자가 -1을 입력하면 프로그램을 종료한다.
 
int main(){
	int data[MAX];
	int n = 0;
	int val;
	while(1){
		scanf("%d", &val);
		if(val == -1)
			break;
		
		int duplicate = 0;
		for(int i = 0; i < n; i++){
			if(data[i] == val)
				duplicate = 1;
		}
		
		if(duplicate == 1){
			printf("duplicate entry\n");
			continue;
		}
		int i = n - 1;
		while(i >= 0 && data[i] > val){
			data[i+1] = data[i];
			i--;
		}
		
		data[i+1] = val;
		n++;
		
		for(int i = 0; i < n; i++){
			printf("%d ", data[i]);
		}
		printf("\n");
	}
	
}









//6-3[해결]
//input6-3.txt에 저장된 정수들을 읽어서 선택정렬 알고리즘으로 정렬하여 출력하는 프로그램을 작성하라.

int main(){
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input6-3.txt", "r");
	int data[MAX];
	
	int n = 0;
	while(fscanf(fp, "%d", &data[n]) != EOF){
		n++;
	}
	
	fclose(fp);
	
	//printf("%d", n);
	
	for(int i = n - 1; i > 0; i--){
		int maxIndex = 0;
		for(int j = 0; j <= i; j++){			
			if(data[j] > data[maxIndex]){
				maxIndex = j;
			}
		}
		
		int tmp = data[i];
		data[i] = data[maxIndex];
		data[maxIndex] = tmp;
	}
		
	
	for(int i = 0 ; i < n; i++){
		printf("%d ", data[i]);
	}
	
	getchar();
}







//6-5[해결]
//입력으로 n개의 구간(interval)이 주어진다. 각 구간의 시작점과 끝점으로 표현된다. 이 구간들을 시작점이 빠른 순서대로 정렬하여 출력하는 프로그램을 작성하라. 시작점이 같은 경우 끝점이 빠른 것을 먼저 출력한다. 입력 형식은 먼저 n의 값이 주어지고, 이어서 각 구가느이 시작점과 끝점이 차례대로 주어진다. 각 구간의 시작점과 끝점은 정수이고, 끝점은 항상 시작점보다 크거나 같다.

int main(){
	int begin[MAX];
	int end[MAX];
	
	int n;
	
	
	
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &begin[i], &end[i]);
	}
	
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(begin[j]>begin[j+1]){
				int tmp = begin[j];
				begin[j] = begin[j+1];
				begin[j+1] = tmp;
				tmp = end[j];
				end[j] = end[j+1];
				end[j+1] = tmp;
			} else if(begin[j] == begin[j+1]){
				if(end[j] > end[j+1]){
				int tmp = begin[j];
				begin[j] = begin[j+1];
				begin[j+1] = tmp;
				tmp = end[j];
				end[j] = end[j+1];
				end[j+1] = tmp;
				}
			}
		}
	}
	
	for(int i = 0; i < n; i++){
		printf("%d %d\n", begin[i], end[i]);
	}
	
	getchar(); getchar();
}







//6-6[해결]
//정수 집합 {0,1,2, ... , N-1}의 임의의 순열이 저장된 배열 A가 있다. 이 배열의 인덱스의 수열 (a1,a2,a3, ... ,ak)에 대해서 A[a1] = a2, A[a2] = a3, A[a3] = a4, ... , A[ak] = a1이 성립할 때 이 수열을 사이클이라고 부른다. 입력으로 정수 N과 이어서 {0,1,2, ... ,N-1}의 임의의 순열이 주어질 때 사이클의 개수를 찾아 출력하는 프로그램을 작성하라.
int main(){
	int flag[MAX] = {0};
	int data[MAX];
	int n;
	int count = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	for(int i = 0;i<n;i++){
		if(flag[i] == 0){
			int start = i;
			while(1){
				flag[start] += 1;		
				if(flag[start] == 2){
					count++;
					break;
				}
				start = data[start];
			}
		}
		
	}
	
	printf("%d", count);
	
	getchar(); getchar();
	
}



//6-7[해결]
//입력으로 두 개의 양의 정수를 받는다. 그런 다음 두 정수를 사전식 순서(lexicographic order)로 출력하는 프로그램을 작성하라. 예를 들어 두 정수가 75와 111이라면 75는 사전식 순서에서는 1로 시작하는 111보다 나중에 나와야 한다. 즉 111, 75의 순서로 출력해야 한다.
int main(){
	double a, b;
	int K;
	
	scanf("%lf %lf", &a, &b);
	
	int A = a;
	int B = b;
	
	while(a>1){
		a/=10;
	}

	while(b>1){
		b/=10;
	}

	
	if(a<b){
		printf("%d %d", A, B);
	} else {
		printf("%d %d", B, A);
	}
	
	getchar();
}







//7-2[해결]
//어떤 수열에서 역전된 삼중쌍의 개수를 구하는 프로그램을 작성하라. 먼저 수열의 길이 N이 주어지고 이어서 N개의 정수가 입력으로 주어진다.

int main(){
	int n;
	int data[MAX];
	int count = 0;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i + 1; j < n; j++){
			for(int k = j + 1; k < n; k++){
				if(data[i] > data[j] && data[j] > data[k])
					count++;
			}
		}
	}
	
	printf("%d", count);
	
	getchar(); getchar();
	
}






//7-4[해결]
//입력으로 하나의 수열이 주어진다. 이 중 오름차순으로 정렬되어 있는 가장 긴 구간을 찾아서 그 구간의 길이를 출력하는 프로그램을 작성하라. 입력은 키보드로부터 받으며 먼저 수열의 길이 N이 주어지고 이어서 N개의 정수들이 주어진다.

int main(){
	int n;
	int length = 1;
	int maxLength = 1;
	int data[MAX];
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	
	for(int i = 0; i < n - 1; i++){
		if(data[i] <= data[i+1]){
			length++;
			if(length > maxLength){
				maxLength = length;
			}
		}
		else {
			length = 1;
		}
	}
	
	printf("%d", maxLength);
	
	getchar();
	
}






//7-7[해결]
//입력으로 N개의 폐구간이 주어진다. 이중 겹치는 길이가 가장 긴 두 구간을 찾아서 출력하는 프로그램을작성하라.각 구간의 끝점은 항상 시작점보다 크거나 같다.
int main(){
	int begin[MAX];
	int end[MAX];
	
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input7-7.txt", "r");
	int n = 0;
	while(fscanf(fp,"%d %d", &begin[n], &end[n]) != EOF){
		n++;
	}
	
	// for(int i = 0; i < n; i++){
	// 	printf("%d %d",begin[i], end[i]);
	// }
	int maxLength = 0;
	int maxIndex_1;
	int maxIndex_2;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j <= n; j++ ){
			int length = 0;
			for(int k = begin[i]; k <= end[i]; k++){
				for(int u = begin[j]; u <= end[j]; u++){
					if(k == u){
						length++;
					}
					
					if(length > maxLength){
						maxLength = length;
						maxIndex_1 = i;
						maxIndex_2 = j;
					}
				}
			}
		}
	}
	
	printf("[%d, %d], [%d, %d]",begin[maxIndex_1], end[maxIndex_1]
		  ,begin[maxIndex_2], end[maxIndex_2]);
	
	getchar();
	
}







//7-10[미해결]












//7-11[해결]
//0혹은 1로 이루어진 길이가 N인 수열이 주어진다. 이 중 최대 하나의 0을 1로 교체해서 만들 수 있는 가장 긴 연속된 1의 개수를 구하는 프로그램을 작성하라.
int main(){
	int n;
	int data[MAX];
	int zeroIndex[MAX];
	
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &data[i]);
	}
	
	int maxLength = 0;
	
	int k = 0;
	for(int i = 0; i < n; i++){
		if(data[i] == 0){
			zeroIndex[k] = i;
			k++;
		}	
	}
	
	for(int i = 0; i < k; i++){
		data[zeroIndex[i]] = 1;
		int length = 0;
		for(int j = 0; j < n; j++){
			if(data[j] == 1){
				length++;
			}else{
				length = 0;
			}
			
			if(length > maxLength){
				maxLength = length;
			}
		}
		data[zeroIndex[i]] = 0;
	}
	
	printf("%d", maxLength);
	getchar();
	
}










#include <stdlib.h>
#include <time.h>

#define MAX 100
#define T 10000
//8-1[미해결]
int main(){
	int mat[MAX][MAX] = {0};
	
	int directionOfMovement[][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //상하좌우
	int moveableDirection[4];
	int n;
	int success = 0;
	
	
	scanf("%d", &n);
	
	
	int recentColumn;
	int recentRow;
	
	// // mat[3][4] = 1;
	// mat[4][5] = 1;
	// mat[5][4] = 1;
	// mat[4][3] = 1;
	
	
	for(int i = 0; i < T; i++){
		int recentRow = (n-1)/2; //행
		int recentColumn = (n-1)/2; //열
		
		
		while(1){
			
			
			int moveableDirection_count = 0;
			mat[recentRow][recentColumn] = 1;
			//이동가능방향 탐색
			for(int j = 0; j < 4; j++){
				int r = recentRow + directionOfMovement[j][0];
				int c = recentColumn + directionOfMovement[j][1];
				
				if(mat[r][c] == 0){ //가고자 하는 방향에 0이 있다면
					moveableDirection[moveableDirection_count] = j;
					moveableDirection_count++;
				}				
			}
			
			if(moveableDirection_count == 0){
				break;
			} else if(moveableDirection_count == 1){
				recentRow += directionOfMovement[moveableDirection[0]][0];
				recentColumn += directionOfMovement[moveableDirection[0]][1];
			} else {
				srand((unsigned int)time(NULL));
				int dir = rand()%moveableDirection_count;
				recentRow += directionOfMovement[moveableDirection[dir]][0];
				recentRow += directionOfMovement[moveableDirection[dir]][1];
			}
			
			if(recentRow == 0 || recentRow == n-1 || 
			   recentColumn == 0 || recentColumn == n-1 ){
				success++;
				break;
			}
			
			
		}
			
	}
	
	printf("%f", (double)success/T);
	getchar(); getchar();
}

//8-1
//[puppy's escape]
int main(){
	int mat[MAX][MAX] = { 0 };
	int offset[][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}}; //상하좌우
	int emptyLoad[4];
	int n;
	int succes = 0;
	
	srand((unsigned int)time(NULL));
	
	scanf("%d", &n);
	
	// mat[3][4] = 1;
	// mat[4][5] = 1;
	// mat[5][4] = 1;
	// mat[4][3] = 1;
	
	for(int i = 0; i < T; i++){
		int dirX = (n-1)/2;
		int dirY = (n-1)/2;
		mat[dirX][dirY] = 1;
		
		while(1){
			int emptyLoadIndex = 0;
			
			for(int j = 0; j < 4; j++){				
				if(mat[dirX+offset[j][0]][dirY+offset[j][1]] == 0){
					emptyLoad[emptyLoadIndex] = j;
					emptyLoadIndex++;
				}
			}
			
			//4방향 모두 막힌경우 1회차 종료
			if(emptyLoadIndex == 0){
				break;
			}
			int direction;
			if(emptyLoadIndex == 1){
				direction = 0;
			} else if(emptyLoadIndex == 2){
				direction = rand()%2;
			} else if(emptyLoadIndex == 3){
				direction = rand()%3;
			} else if(emptyLoadIndex == 4){
				direction = rand()%4;
			}
			
			dirX += offset[emptyLoad[direction]][0];
			dirY += offset[emptyLoad[direction]][1];
			
			if(dirX == 0 || dirX == n-1 || dirY == 0 || dirY == n-1 ){
				succes++;
				break;
			}
			
			mat[dirX][dirY] = 1;
				
		}
	}
	
	printf("%f", (double)succes/T);
	
	getchar(); getchar();
		
		
}










int main(){
	int mat[MAX][MAX] = {0};
	int offset[][2] = {{0, -1},
					   {0, 1},
					   {-1, 0},
					   {1, 0}};
	int n;
	int success = 0;
	
	scanf("%d", &n);
	
	for(int i = 0 ; i < T; i++){
		int recentRow = (n-1)/2;
		int recentColunm = (n-1)/2;
		
		while(1){
			int movable[4];
			int movableIndex = 0;
			
			mat[recentRow][recentColunm] = 1;
			//현재 위치에서 이동 가능한 방향 탐색
			for(int j = 0; i < 4; j++){
				int r = recentRow + offset[j][0];
				int c = recentColunm + offset[j][1];
				if(mat[r][c] == 0){
					movable[movableIndex] = j;
					movableIndex++;
				}
			}
			
			//이동 가능한 경우가 없을때
			if(movableIndex == 0){
				break;
			}
			
			
			//이동
			srand((unsigned int)time(NULL));
			int randomIndex = rand()%movableIndex;
			recentRow += offset[movable[randomIndex]][0];
			recentColunm += offset[movable[randomIndex]][1];
			
			if(recentRow == 0 || recentRow == n-1 || recentColunm == 0 || recentColunm == n-1){
				success++;
				break;
			}     
			  
			  
			  
		}
	}  
	
	printf("%f", (double)success/T);
	
	
}











//8-3[해결]
//2차원 배열을 이용한 이항계수 계산문제

int main(){
	int binomial[MAX][MAX];
	int n, k;
	
	scanf("%d %d", &n, &k);
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= i; j++){
			if(j == 0 || j == i){
				binomial[i][j] = 1;
			} else {
				binomial[i][j] = binomial[i-1][j-1] + binomial[i-1][j];
			}
		}
	}
	
	printf("%d", binomial[n][k]);	
}









//8-4[해결]
//데이터 파일 input4.txt에는 하나의 N*N 행렬이 저장되어 있다. 파일의 첫 줄에는 행렬의 크기 N이 저장되어 있고, 이어진 N줄에는 각 줄마다 N개의 정수가 저장되어 있다. 이 파일을 읽어서 각 행의 평균과 표준편차, 각 열의 평균과 표준편차를 구해서 출력하는 프로그램을 작성하라.
int main(){
	int mat[MAX][MAX];
	int n;
	
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input8-4.txt", "r");
	fscanf(fp, "%d ",&n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fscanf(fp, "%d ", &mat[i][j]);
		}
	}
	fclose(fp);
	
	
	
	for(int i = 0; i < n; i++){
		double avg;
		int sum = 0;
		double var = 0;
		for(int j = 0; j < n; j++){
			sum += mat[i][j];
		}
		avg = (double)sum/n;
		for(int j = 0; j < n; j++){
			var += (mat[i][j] - avg)*(mat[i][j] - avg);
		}
		for(int j = 0; j < n; j++){
			printf("%d ", mat[i][j]);
		}
		printf("%f %f\n", avg, sqrt(var/n));
		
	}
	
	
}








//8-6[해결]
//파일의 첫 줄에는 행렬의 크기 N <= 100이 저장되어 있고, 이어진 N줄에는 각 줄마다 N개의 정수가 저자오디어 있다. 이 행렬의 원소를 아래 그림의 화살표 순서대로 출력하는 프로그램을 작성하라.
int main(){
	int mat[MAX][MAX];
	int flag[MAX][MAX] = {0};
	int offset[][2] = {{0, 1},
					   {1, 0},
					   {0, -1},
					   {-1, 0}};
	int n;
	
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input8-6.txt", "r");
	fscanf(fp, "%d ",&n);
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fscanf(fp, "%d ", &mat[i][j]);
		}
	}
	fclose(fp);
	
	int index = 0;
	int r = 0;
	int c = 0;
	
	for(int i = 0; i < n*n; i++){
		printf("%d ", mat[r][c]);
		flag[r][c] = 1;
		r += offset[index][0];
		c += offset[index][1];
		//flag[r][c] = 1; error code
		if(r == n || c == n || r < 0 || c < 0 || flag[r][c] == 1){
			r -= offset[index][0];
			c -= offset[index][1];
			index++;
			if(index == 4){
				index = 0;
			}
			r += offset[index][0];
			c += offset[index][1];
		}
		
		
	}
	
	getchar();	
}










//8-7[해결]
//N <= 1,000,000개의 음이 아닌 정수가 입력으로 주어진다. 각 정수는 벽돌의 개수를 나타낸다. 가령 입력 정수가 3,0,0,2,0,4라면 아래 그림과 같이 왼쪽에서 오른쪽 순서로 해당하는 개수 만큼의 벽돌이 쌓여 있다는 의미이다. 모든 벽돌의 높이와 너비는 1로 동일하다. 비가 내렸을 때 이 벽돌들에 의해서 고이는 물의 총량을 계산하는 프로그램을 작성하라.
int main(){
	int n;
	int data[MAX];
	int waterSum = 0;
	
	scanf("%d", &n);
	for(int i = 0 ; i < n; i++){
		scanf("%d", &data[i]);
	}
	
	
	//배열의 양끝값의 인덱스 찾기
	while(1){
		
		int startIndex = 0;
		int endIndex = 0;
		int tmp = 0;
		for(int i = 0 ; i < n; i++){
			if(data[i] > 0 && tmp == 0){
				startIndex = i;
				tmp = 1;
			}
			if(data[i] > 0 && tmp == 1){
				endIndex = i;
			}
		}
		
		if(startIndex == endIndex) break;
		
		for(int i = startIndex; i <= endIndex; i++){
			if(data[i] > 0){
				data[i]--;
			}
			else if(data[i] == 0){
				waterSum++;
			}
		}	
	}
	
	printf("%d ", waterSum);
	
}










//9-3[헤결]
//평면상에서 좌표축에 평행한 2개의 직사각형이 입력으로 주어진다. 두 사각형이 교차하는 영역, 즉 두 사각형에 공통으로 포함되는 영역의 면적을 구하는 프로그램을 작성하라. 각각의 사각형은 대각 방향의 두 꼭지점의 좌표로 주어진다. 이 문제를 해결하기 위해서 임의의 두 구간에 대해서 두 구간이 겹치는 영역의 길이를 구하는 함수 int lenOfOverlap(int sa, int ta, int sb, int tb)를 작성하여 이용하라. 이 함수의 구간 [sa, ta]와 [sb, tb]의 겹치는 영역의 길이를 계산하여 반환한다.

int lenOfOverlap(int sa, int ta, int sb, int tb);
void coordinate_alignment(int* x1,int* y1,int* x2,int* y2,int* x3,int* y3,int* x4,int* y4);
void swap(int* a, int* b);

int main(){
	int x1, y1, x2, y2, x3, y3, x4, y4;
	int lenOfOverlap_x;
	int lenOfOverlap_y;
	
	scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	coordinate_alignment(&x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	
	lenOfOverlap_x = lenOfOverlap(x1, x2, x3, x4);
	lenOfOverlap_y = lenOfOverlap(y1, y2, y3, y4);
	
	printf("%d", lenOfOverlap_x*lenOfOverlap_y);

}

int lenOfOverlap(int sa, int ta, int sb, int tb)
{
	int result = 0;
	
	for(int i = sa; i <= ta; i++){
		for(int j = sb; j <= tb; j++){
			if(i == j){
				result++;
			}
		}
	}
	
	return result-1;
	
}

void coordinate_alignment(int* x1,int* y1,int* x2,int* y2,int* x3,int* y3,int* x4,int* y4)
{
	if(*x1 > *x2) swap(x1, x2);	
	if(*y1 > *y2) swap(y1, y2);
	if(*x3 > *x4) swap(x3, x4);	
	if(*y3 > *y4) swap(y1, y2);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}















#define MAX 100
//9-5[해결]
//입력으로 양의 정수들이 주어진다. 각 정수들은 8자리 이내의 정수들이다. 이 정수들을 사전식 순서(lexicographic order)로 정렬하여 출력하는 프로그램을 작성하라. 입력은 input9-5.txt 파일에서 읽는다. 정수의 개수는 따로 주어지지 않고 파일의 끝까지 읽어야 한다. 이 문제를 해결하기 위해서 두 정수를 매개변수로 받아서 사전식 순서를 비교하는 함수 int compareLexicographic(int a, intb) 이 함수는 정수 a와 b를 비교하여 a 가 사전식 순서로 앞설 경우에는 -1 b가 사전식 순서로 앞설 경우에는 1, 그리고 두 정수가 동일한 경우에는 0을 반환한다.
int compareLexicographic(int a, int b);
int read_file(int* arr); //파일에 입력된 정수를 배열에 저장하고 배열의 크기를 반환하는 함수
void sortLexicographic(int* arr, int n);
void swap(int* a, int* b);
void print_arr(int *a, int n);


int main(){
	int data[MAX];
	int n = read_file(data);
	sortLexicographic(data, n);
	print_arr(data, n);
	
	getchar(); getchar();
}


int compareLexicographic(int a, int b)
{
	double A = (double)a;
	double B = (double)b;
	int countZeroA = 0, countZeroB = 0;
	
	while(A > 1){
		A /= 10;
		countZeroA++;
	}
	
	while(B > 1){
		B /= 10;
		countZeroB++;
	}
	
	if(A > B) {
		return 1;
	} else if(A < B) {
		return -1;
	} else {
		if(countZeroA > countZeroB) {
			return 1;
		} else if(countZeroA < countZeroB) {
			return -1;
		} else {
			return 0;
		}
	}	
}

void sortLexicographic(int* arr, int n)
{
	for(int i = n - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(compareLexicographic(*(arr+j), *(arr+(j+1))) == 1){
				swap((arr+j), (arr+(j+1)));
			}
		}
	}
}

void print_arr(int *a, int n)
{
	for(int i = 0; i < n; i++){
		printf("%d ", *(a+i));
	}
}

int read_file(int* arr)
{
	int n = 0;
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input9-5.txt", "r");
	while(fscanf(fp, "%d", (arr+n)) != EOF){
		n++;
	}
	return n;
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}













//9-6[해결]
//사용자로부터 하나의 다항식을 입력받고 이어서 변수 x의 값을 입력받아 다항식의 값을 계산하여 출력하는 프로그램을 작성하라.
int polynomial_search(int* arr, int n, int x); //다항식을 계산하여 그값을 반환
int power(int a, int x, int b);

int main(){
	int data[MAX];
	int n; //항의 갯수
	int x; // x의 값;
	int result;
	
	scanf("%d", &n);
	for(int i = 0; i < 2*n; i++){
		scanf("%d", &data[i]);
	}
	scanf("%d", &x);
	result = polynomial_search(data, n, x);
	
	printf("%d", result);
	
}

int power(int a, int x, int b)
{
	if (b == 0){
		return a;
	}
	int result = 1;
	for(int i = 0; i < b; i++){
		result *= x;
	}
	
	return result*a;
}


int polynomial_search(int* arr, int n, int x)
{
	int result = 0;
	for(int i = 0; i < 2*n; i += 2){
		result += power(*(arr+i), x, *(arr+i+1));	
	}
	
	
	
	return result;
}












//10-2[해결]
//키보드로 부터 연속해서 정수들을 입력받는다. 정수가 하나 씩 입력될 때 마다 현재까지 입력된 정수들을 오름차순으로 정렬하여 화면에 출력한다. 단, 새로 입력된 정수가 이미 배열에 저장되어 있다면 추가하는 대시 "duplicate entry"라고 출력한다. 사용자가 -1을 입력하면 프로그램을 종료한다. 이 일을 하기 위해서 다음과 같은 두 함수를 작성하라. 먼저 현재까지 입력된 정수들이 저장되어 있는 배열에 새로 입력된 정수가 이미 존재하는지 검사하여 만약 있으면 그 위치(배열 인덱스)를 반환하고, 없으면 -1을 반환하는 함수 find를 작성하라. 또한 새로 입력된 정수가 duplicate entry가 아닌 경우에 이 정수를 배열에 오름차순으로 정렬되도록 삽입하는 함수 insert를 작성하라. 그리고 main 함수에서는 이 두 함수를 적절히 이용하여 문제를 해결하라. duplicate entry라고 출력할 때 그 배열에서 그 정수의 위치를 함께 출력하라. 어떤 전역 변수도 사용해서는 안된다.

int find(int arr[], int n, int arrSize);
int insert(int arr[], int n, int arrSize);

int main(){
	int data[MAX];
	int arrSize = 0;
	int n;
	
	while(1){
		scanf("%d", &n);
		int indexOfDuplicate = find(data, n, arrSize);
		
		if(n == -1) break;
		
		if(indexOfDuplicate == -1){
			arrSize = insert(data, n, arrSize);
		} else if(indexOfDuplicate != -1) {
			printf("duplicate entry: %d\n", indexOfDuplicate);
		}
		
		
	}
}

int find(int arr[], int n, int arrSize)
{
	for(int i = 0; i < arrSize; i++){
		if(arr[i] == n) return i;
	}
	
	return -1;
}

//복습 point
int insert(int arr[], int n, int arrSize)
{
	int i;
	if(arrSize == 0){
		arr[0] = n;
	} else {
		//삽입 정렬
		for(i = arrSize; i > 0; i--){
			if(arr[i-1] > n){
				arr[i] = arr[i-1];
			} else {
				break;
			}
		}
		arr[i] = n;
	}
	arrSize++;
	
	for(int i = 0 ; i < arrSize; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	return arrSize;
}














//10-3[미해결]
//입력으로 N개의 수직 혹은 수평 선분이 주어진다. 선분들간의 교차점의 좌표를 모두 계산하여 x좌표에대한 오름차순으로 정렬하여 출력하는 프로그램을 작성하라. x좌표가 동일한 경우에는 y좌표가 작은 점을 먼저 출력한다. 입력은 input10-3.txt 파일로부터 받는다. 파일의 첫 줄에는 선분의 개숫 N이 주어지고, 이어진 N줄에는 각 줄마다 하나의 선분의 시작점과 끝점의 좌표가 주어진다. 수평 선분의 경우 x좌표가 작은 점이 먼저 주어지고, 수직 선분의 경우 y좌표가 작은 점이 항상 먼저 주어진다.  수직이나 수평이 아닌 선분이 주어지는 경우는 없다. 수평 선분끼리 만나거나 혹은 수직 선분끼리 만나는 경우는 교차점으로 간주하지 않는다. 이 문제를 해결하기 위해서 두 선분이 교차하는지 검사하는 함수 intersect를 만들어 사용하라. 하나의 수평선분 L과 수직성분 V가 교차하는지 검사하는 한 가지 방법은 L의 양 끝점이 V의 좌우에 나누어져 있고, 또한 V의 양 끝점이 L의 상하에 나누어져 있으면 교차하고 그렇지 않으면 교차하지 않는다. 매개 변수로 두 선분을 받아서 교차하면 1, 그렇지 않으면 0을 반환하라. 어떤 전역변수도 사용해서는 안된다.
int intersect();
void lineSort(int line[][4], int lineNum); //배열에 저장되어있는 선분의 좌표를 

int main(){
	int n; //선분의 객수
	int line_L[MAX][4]; //수평선분
	int line_V[MAX][4]; //수직선분
	int result[MAX][4];
	int result_index = 0;
	int line_L_num = 0;
	int line_V_num = 0;
	
	FILE *fp = fopen("/workspace/problem_solving_C/fileEx/input10-3.txt", "r");
	fscanf(fp, "%d", &n);
	
	for(int i = 0; i < n; i++){
		int x1, y1, x2, y2;
		fscanf(fp, "%d %d %d %d", &x1, &y1, &x2, &y2);
		
		if(y1 == y2 && x1 != x2) { /*수평성분*/
			line_L[line_L_num][0] = x1;
			line_L[line_L_num][1] = y1;
			line_L[line_L_num][2] = x2;
			line_L[line_L_num][3] = y2;
			line_L_num++;
		} else if(x1 == x2) { /*수직성분*/
			line_V[line_V_num][0] = x1;
			line_V[line_V_num][1] = y1;
			line_V[line_V_num][2] = x2;
			line_V[line_V_num][3] = y2;
			line_V_num++;
		}		
	}
	
	fclose(fp);
	
	lineSort(line_L,line_L_num);
	lineSort(line_V,line_V_num);
	
	for(int i = 0; i < line_L_num; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", line_L[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(int i = 0; i < line_V_num; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", line_V[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
	
	for(int i = 0; i < line_L_num; i++){
		for(int j = 0; j < line_V_num; j++){
			int judg = intersect(line_L, line_V, j, i);
			if(judg == 1){
				result[result_index][0] = line_V[j][0];
				result[result_index][1] = line_L[i][1];
				result[result_index][2] = j;
				result[result_index][3] = i;
				result_index++;
			}	
		}
	}	
	
	for(int i = 0; i < result_index; i++){
		for(int j = 0; j < 4; j++){
			printf("%d ", result[i][j]);
		}
		printf("\n");
	}
	
	getchar();
	
}



int intersect(int line_L[][4], int line_V[][4], int line_L_index, int line_V_index)
{
	if(line_V[line_V_index][0] >= line_L[line_L_index][0] && line_V[line_V_index][0] <= line_L[line_L_index][2]
	  && line_L[line_L_index][1] >= line_V[line_V_index][1] && line_L[line_L_index][1] <= line_V[line_V_index][4]){
		return 1;
	}
	return 0;
}


//2차원 행렬의 swap 고민해보기
void lineSort(int line[][4], int lineNum)
{
	for(int i = lineNum - 1; i > 0; i--){
		for(int j = 0; j < i; j++){
			if(line[j][0] > line[j+1][0]){
				for(int k = 0; k < 4; k++){
					int tmp = line[i][k];
					line[i][k] = line[j][k];
					line[j][k] = tmp;
				}
			}
		}
	}
}















//10-5[해결]
//[Self avoiding walk] 2차원 평면에서 원점 (0,0)에서 출발한다. 사용자가 현재의 위치에서 상하좌우 어떤 한 방햐으로 얼마 만큼 이동하라는 명령을 내리면 그렇게 이동한다. 명령은 두 음이 아닌 정수로 표현 된다. 우선 방향은 0,1,2,3으로 표시하고 0은 y좌표가 증가하는 방향, 1은 x좌표가 증가하는 방향, 2는 y좌표가 감소하는 방향, 그리고 3은 x좌표가 감소하는 방향이다. 예를 들어 2 7은 y좌표가 7만큼 감소하는 위치로 이동하라는 명령이다. 프로그램은 사용자가 현재까지 이동한 궤적을 기억하고 있어야 한다. 사용자가 내린 명령대로 이동했을 때 만약 지금까지 이동한 궤적과 교차하면 invalid move라고 출력하고 이동 명령을 거부한다. 만양 그렇지 않으면 명령대로 이동하고 이동한 점의 좌표를 출력한다. 사용자가 -1 -1을 입력할 때 까지 이 일을 계속한다. 사용자가 -1 -1을 입력하면 프로그램을 종료한다. 이 문제를 해결하기 위해 사용자가 내린 명령이 invalid move인지 아닌지 검사하는 함수 check를 작성하라. 전역변수를 사용해서는 안된다.

int check();

int main(){
	int flag[MAX][MAX] = {0};
	int x = (MAX-1)/2;
	int y = (MAX-1)/2;
	int offset[][2] = {{0, 1},
					   {1, 0},
					   {0, -1},
					   {-1, 0}};
					   
	
	flag[x][y] = 1;
	
	
	while(1){
		int dir;
		int distance;
		scanf("%d %d", &dir, &distance);
		
		if(dir == -1 && distance -1) break;
		
		if(check(flag, x, y, dir, distance) == 0){
			for(int i = 0; i < distance; i++){
				x += offset[dir][0];
				y += offset[dir][1];
				flag[x][y] = 1;
			}
			printf("%d %d\n", x - (MAX-1)/2, y - (MAX-1)/2);
		} else {
			printf("invalid move\n");
		}
		
		
	}
	
	// for(int i = 0; i < MAX; i++){
	// 	for(int j = 0; j < MAX; j++){
	// 		printf("%d", flag[i][j]);
	// 	}
	// 	printf("\n");
	// }
	
}




int check(int flag[][MAX], int x, int y, int dir, int distance){
	int offset[][2] = {{0, 1},
					   {1, 0},
					   {0, -1},
					   {-1, 0}};
	
	for(int i = 0; i < distance; i++){
		if(flag[x += offset[dir][0]][y += offset[dir][1]] == 1){
			return 1;
		}
	}
	return 0;	
}










//12-1[해결]
//입력으로 하나의 문자열을 받은 후 뒤집어서 추력하는 프로그램을 작성하라. 예를 들어 hello를 입력하면 olleh가 출력된다.
int main(void) {
	char word[10];
	int wordLength;
	scanf("%s", word);
	wordLength = strlen(word);
	
	for(int i = wordLength - 1; i >=0; i--){
		printf("%c",word[i]);
	}
	printf("\n");
}







//12-2[해결]
//하나의 영문 소문자로 구성된 문자열을 입력받은 후 문자열을 구성하는 문자들을 알파벳 순으로 정렬하여 만들어지는 문자열을 출력하라. 예를 들어 hello가 입력되면 ehllo를 출력한다.
#include <string.h>

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

int main(void) {
	char str[10];
	scanf("%s", str);
	stringSort(str);
	printf("%s\n",str);
}









//12-3[해결]
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