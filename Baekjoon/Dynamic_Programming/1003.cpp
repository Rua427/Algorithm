#include <iostream>

using namespace std;
int sum[2] = {0,};
void Fibonacci(int num1, int num2, int N){
	if(N <= 1){
		if(N == 0){
			sum[0] = 1;
			sum[1] = 0;
		}
		else{		
			sum[0] = num1;
			sum[1] = num2;
		}
		return;
	}
	
	return Fibonacci(num2, num1 + num2, N - 1);

}

int main(){
	
	int N =0;
	int T = 0;
	cin >> T;
	for(int i = 0; i < T ; ++i){
	
		cin >> N;

		Fibonacci(0,1, N);
	
	
		printf("%d %d\n",sum[0], sum[1]);
	}
}
