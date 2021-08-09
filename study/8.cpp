//2차원 배열

#include <stdio.h> 
#define MAX 100


//8-1
int main(){
	int mat[MAX][MAX];
	int m, n;
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	
	fscanf(fp, "%d", &m);
	fscanf(fp, "%d", &n);
	
	for(int i = 0; i < m; i++){
		for(int j = 0 ; j < n; j++){
			fscanf(fp, "%d", &mat[i][j]);
		}
	}
	
	int tmat[MAX][MAX];
	
	for(int i = 0; i < m; i++){
		for(int j = 0 ; j < n; j++){
			tmat[j][i] = mat[i][j];
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0 ; j < m; j++){
			printf("%d", tmat[i][j]);
		}
		printf("\n");
	}
	
}



//8-2
int main(){
	int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
	int p, q, r;
	FILE *fp = fopen("/workspace/sp_1/study/input.txt", "r");
	
	fscanf(fp, "%d", &p);
	fscanf(fp, "%d", &q);
	
	for(int i = 0; i < p; i++){
		for(int j = 0 ; j < q; j++){
			fscanf(fp, "%d", &A[i][j]);
		}
	}
	
	fscanf(fp, "%d", &q);
	fscanf(fp, "%d", &r);
	
	for(int i = 0; i < q; i++){
		for(int j = 0 ; j < r; j++){
			fscanf(fp, "%d", &B[i][j]);
		}
	}
	
	fclose(fp);
	
	for(int i = 0; i < p; i++){
		for(int j = 0; j < r; j++){
			C[i][j] = 0;
			for(int k = 0; k < q; k++){
				C[i][j] += A[i][k]*B[k][j];
			}
			
			
		}
	}
	
	for(int i = 0; i < p; i++){
		for(int j = 0 ; j < r; j++){
			printf("%d ", C[i][j]);
		}
		printf("\n");
	}
	
}








//8-3
//Minesweeper
int main(){
	int n;
	char grid[MAX][MAX];
	
	FILE *fp = fopen("/workspace/sp_1/study/input.txt","r");
	fscanf(fp, "%d ", &n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			fscanf(fp, "%c ", &grid[i][j]); //white space
		}
	}
	fclose(fp);
	
	int offset[][2] = {{-1, 0}, {0, 1}, {1, 1}, {-1, 1}, 
					   {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j] == '*'){
				printf("* ");
			}
			else {
				int count = 0;
				for(int dir = 0; dir < 8; dir++){
					int r = i + offset[dir][0];
					int c = j + offset[dir][1];
					if(r >= 0 && r < n && c >= 0 && c < n &&
					  grid[r][c] == '*'){
						count++;
					}
				}
				printf("%d ", count);
			}
		}
		printf("\n");
	}
	
}