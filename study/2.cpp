
int main(){
	
	int s, t;
	
	scanf("%d", &s);
	scanf("%d", &t);
	
	int count1 = 0;
	int count2 = 0;
	
	for(int i = s; i <= t; i++){
		if(i%2 == 0 || i%3 == 0){
			count1 += 1;
		}else{
			count2 +=1;
		}
		
	}
	
	printf("%d %d", count1, count2);
	
	getchar();
	getchar();
}