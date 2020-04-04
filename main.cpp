#include "./include/tvs.h"

int main(int argc, char const *argv[]){
	if(argc == 1){
		fprintf(stderr, "%s\n", "error: Not enough arguments");
		return 1;
	}
	for (int i = 0; i < argc - 1; ++i)
		tvsMain(argv[i + 1]);
	return 0;
}