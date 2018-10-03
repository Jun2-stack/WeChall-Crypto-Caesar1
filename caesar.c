#include <stdio.h>

int main(void) {

	char crypto_text[100] = { 0, };		// 입력 받을 암호문 배열
	char decrypt_text[100] = { 0, };	// 복호화 한 평문(flag)
	int crypto_ascii[100] = { 0, };		// 입력 받은 암호문을 ascii 코드로 변환하여 저장할 배열
	int decrypt_ascii[100] = { 0, };	// 복호화 한 ascii
	int key, i;							// key는 시저암호의 키, i는 for문에서 사용할 쓸모 없는 값

	printf("암호문 입력 : ");
	fgets(crypto_text, 100, stdin);
	printf("\n");

	// 암호문을 받아 ascii 코드로 변환하는 알고리즘
	for (i = 0; i < strlen(crypto_text) - 1; i++)		// 배열은 0부터 시작하므로 입력 받은 암호문 길이 -1까지
	{
		crypto_ascii[i] = crypto_text[i];				// 암호문을 ascii 값으로 변환
	}

	// 키 값에 따른 시저암호 복호화 알고리즘
	for (key = 1; key <= 25; key++)
	{
		for (i = 0; crypto_ascii[i] != NULL; i++)		// 암호문 ascii 값이 NULL이 아닐 때까지
		{
			decrypt_ascii[i] = crypto_ascii[i] - key;	// 암호문 ascii 값에서 key 값만큼 빼서 복호화 한 ascii 배열에 넣기

			if (decrypt_ascii[i] < 65)					// 복호화 한 ascii 배열 값이 A보다 작다면(A보다 작으면 Z로 가야 하기 때문)
			{
				if (decrypt_ascii[i] < 32)				// 복호화 한 ascii 배열이 공백보다 작다면(즉, 암호문 ascii 값이 공백이면)
					decrypt_ascii[i] = '_';				// _ 기호를 사용하여 공백을 구분
				else
					decrypt_ascii[i] += 26;				// 복호화 한 ascii 배열 값에 26(알파벳 수)를 더해 Z로 가게 함
			}

			decrypt_text[i] = decrypt_ascii[i];			// 복호화 한 ascii 값을 문자열로 바꿔줌(평문을 만드는 과정)
		}
		printf("key %d일 때, 복호화 문자열은 %s\n", key, decrypt_text);
	}

	return 0;
}
