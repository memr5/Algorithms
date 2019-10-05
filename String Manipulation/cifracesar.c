#include <stdio.h>
#include <string.h>

int main(){

	int mist, repeat, num, i = 1, j;
	char letter[50];

	printf("Type one number and one phrase");
	scanf("%d", &mist);

	while(i <= mist){
		scanf("%s", letter);
		scanf("%d", &num);

		for(j = 0; j < strlen(letter); j++){
			if(letter[j] < 'A' + num){
				letter[j] = 'Z' - num + (letter[j] - 'A') + 1;
			}else{
				letter[j] -= num;
			}
		}

		i++;
		printf("%s\n", letter);
	}

	return 0;
}
