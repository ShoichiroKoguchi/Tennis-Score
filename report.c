#include<stdio.h>

int main() {
	int sets, point_a = 0, point_b = 0, nowset = 0, seta = 0, setb = 0;
	char p;
	int game_a[100], game_b[100], i;

	for (i = 0; i < 100; i++) {
		game_a[i] = 0;
		game_b[i] = 0;
	}
	
	scanf(" %d", &sets);
	while (scanf(" %c", &p) != EOF) {
	    //printf("%cがポイントを取得", p);

		if (p == 'a') {
			point_a++;
		}
		else if (p == 'b') {
			point_b++;
		}
		if (game_b[nowset] == 6 && game_a[nowset] == 6) {
			if (point_a >= 7) {
				if (point_a - point_b >= 2) {
					game_a[nowset]++;
					seta++;
					/*nowset++;*/
					point_a = 0;
					point_b = 0;
				}

			}
			if (point_b >= 7) {
				if (point_b - point_a >= 2) {
					game_b[nowset]++;
					setb++;
					/*nowset++;*/
					point_a = 0;
					point_b = 0;
				}
			}
		}
		else {
			if (point_a >= 4) {
				if (point_a - point_b >= 2) {
					game_a[nowset]++;
					point_a = 0;
					point_b = 0;
				}
			}
			if (point_b >= 4) {
				if (point_b - point_a >= 2) {
					game_b[nowset]++;
					point_a = 0;
					point_b = 0;
				}
			}

			if (game_a[nowset] >= 6) {
				if (game_a[nowset] - game_b[nowset] >= 2) {
					seta++;
					/*nowset++;*/
				}
			}
			if (game_b[nowset] >= 6) {
				if (game_b[nowset] - game_a[nowset] >= 2) {
					setb++;
					/*nowset++;*/
				}
			}
		}
		/*if (sets - seta <= seta) {
			break;
		}
		else if (sets - setb <= setb) {
			break;
			}*/
		nowset = seta + setb;
		


		

	
	printf("\n");
		if (sets - seta <= seta) {
			printf("A |");
			for (i = 0; i < nowset;i++) {
				printf("%d ", game_a[i]);
			}
			printf("| W\n");
			printf("B |");
			for (i = 0; i < nowset;i++) {
				printf("%d ", game_b[i]);
			}
			printf("| L\n");
			break;
		}
		else if (sets - setb <= setb) {
			printf("A |");
			for (i = 0; i < nowset;i++) {
				printf("%d ", game_a[i]);
			}
			printf("| L\n");
			printf("B |");
			for (i = 0; i < nowset;i++) {
				printf("%d ", game_b[i]);
			}
			printf("| W\n");
			break;
		}
		else {
			printf("A |");
			for (i = 0; i <= nowset;i++) {
				printf("%d ", game_a[i]);
			}
			if (game_a[nowset] == 6 && game_b[nowset] == 6){
			    printf(" |%d",point_a);
			}
			else if (point_a == 0) {
				printf(" |0");
			}
			else if (point_a == 1) {
				printf(" |15");
			}
			else if (point_a == 2) {
				printf(" |30");
			}
			else if (point_a == 3) {
			    printf(" |40"); 
			}
			else if (point_a >= 4 && point_a - point_b == 1) {
				printf(" |Ad");
			}
			else if (point_a >= 4 && (point_a - point_b == 0||point_b - point_a == 1)) {
				printf(" |40");
			}
			
			printf("\n");
		    printf("B |");
			for (i = 0; i <= nowset;i++) {
					printf("%d ", game_b[i]);
			}
			if (game_a[nowset] == 6 && game_b[nowset] == 6){
			    printf(" |%d",point_b);
			}
			else if (point_b == 0) {
					printf(" |0");
				}
			else if (point_b == 1) {
					printf(" |15");
				}
			else if (point_b == 2) {
					printf(" |30");
				}
			else if (point_b == 3) {
			    printf(" |40");
			}
			else if (point_b >= 4 && point_b - point_a == 1) {
				printf(" |Ad");
			}
			else if (point_b >= 4 && (point_b - point_a == 0||point_a-point_b ==1)) {
					printf(" |40");
				}
		        
			printf("\n");
		}
		//	printf("%d%d", point_a, point_b);

	
	}
}
