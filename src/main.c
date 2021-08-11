#include <stdio.h>

#define MAX 101

//10-5
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