#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int dice_face();
int betting();

int main(void)
{
	int w[3] = {1000, 1000, 1000} ;
	int A_betting = 0, B_betting = 0, C_betting = 0;
	int A_dice = 0, B_dice = 0, C_dice = 0;
	int dice = 0;
	int i = 0;
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++) {
		A_betting = betting(w[0]);
		B_betting = betting(w[1]);
		C_betting = betting(w[2]);

		A_dice = dice_face();
		B_dice = dice_face();
		C_dice = dice_face();

		w[0] -= A_betting;
		w[1] -= B_betting;
		w[2] -= C_betting;
		
		printf("A의 주사위 면 = %d, 배팅금액 = %d\n", A_dice, A_betting);
		printf("B의 주사위 면 = %d, 배팅금액 = %d\n", B_dice, B_betting);
		printf("C의 주사위 면 = %d, 배팅금액 = %d\n\n", B_dice, B_betting);

		dice = dice_face();
		printf("나온 주사위의 면 = %d\n", dice);

		w[0] += (A_dice == dice) ? 2 * A_betting : 0;
		w[1] += (B_dice == dice) ? 2 * B_betting : 0;
		w[2] += (C_dice == dice) ? 2 * C_betting : 0;

		printf("A의 남은돈 = %d\n", w[0]);
		printf("B의 남은돈 = %d\n", w[1]);
		printf("C의 남은돈 = %d\n", w[2]);
	}
 	
}
int dice_face() {
	return 1 + rand() % 6;
}
int betting() {
	return 100 * (1 + rand() % (2) / 100);
}