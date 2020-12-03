#include <stdio.h>

void main(){
	int firshInput, secundInput;
	scanf("%d %d", &firshInput, &secundInput);

	secundInput = firshInput * secundInput;
	firshInput = secundInput / firshInput;
	secundInput = secundInput / firshInput;

	printf("%d %d", firshInput, secundInput);
}