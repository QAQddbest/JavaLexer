#include <stdio.h>
int main(){
	for(int i=0;i<26;i++){
		printf("            case '%c':\n", (char)((int)'a'+i));
		printf("            case '%c':\n", (char)((int)'A'+i));
	}
}
