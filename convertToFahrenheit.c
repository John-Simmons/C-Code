#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){

	double celcius = 0;
	double fahrenheit = 0;

	if(argc == 2){
		celcius = atof(argv[1]);
		fahrenheit = (celcius*9/5)+32;

		printf("%.1f\n", fahrenheit);
	}else{
		printf("ERROR: Incorrect number of arguments, please enter only one number.\n");
		return -1;
	}

	return 0;

}
