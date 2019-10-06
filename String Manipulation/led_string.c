#include <stdio.h>
#include <string.h>

int main(){

	int i, j, soma = 0, num;
	char led[1000];

    printf("Number of LEDs\n");
	scanf("%d", &num);

    printf("Leds:\n");
	for(i = 0; i < num; i++){ 
		scanf("%s", led);
		for(j = 0; j < strlen(led); j++){
			if(led[j] == '1'){
				soma += 2;
			}else if(led[j] == '2'){
				soma += 5;
			}else if(led[j] == '3'){
				soma += 5;
			}else if(led[j] == '4'){
				soma += 4;
			}else if(led[j] == '5'){
				soma += 5;
			}else if(led[j] == '6'){
				soma += 6;
			}else if(led[j] == '7'){
				soma += 3;
			}else if(led[j] == '8'){
				soma += 7;
			}else if(led[j] == '9'){
				soma += 6;
			}else if(led[j] == '0'){
				soma += 6;
			}
		}

		printf("%d leds\n", soma);
		soma = 0;
	}

	return 0;
}