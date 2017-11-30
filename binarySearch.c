#import <stdio.h>
#import <stdlib.h>

int binarySearch(int*, int, int, int); 

int main(int argc, char* argv[]){

	if(argc > 2){

		int element = atoi(argv[1]);
		int* list = malloc(4*(argc-2));

		for(int i = 2; i < argc; i++){
			*(list+(i-2)*4) = atoi(argv[i]);			
		}

		int index = binarySearch(list, element, 0, argc-3);		
		
		free(list);
	
		if(index == -1){
			printf("%d does not exist in the list provided\n", element);
		}else{
			printf("%d appears in the list at index %d\n", element, index);
		}

	}else{
		printf("Error: Incorrect number of arguments.\nPlease enter space seperated list of integers where the first element is the integer you are trying to search for.\n");
	
		return -1;
	}

	return 0;

}

//Returns the index of the element in the sorted list list
//If element doesn't exist in list then returns -1
int binarySearch(int* list, int element, int left, int right){

	int mid = (left+right)/2;
	int mid_element = *list+mid;
		
	if(mid_element == element){
		return mid;
	}else if(mid_element > element && left != right){
		return binarySearch(list, element, left, mid-1);
	}else if(left != right){
		return binarySearch(list, element, mid+1, right);
	}	

	return -1;

}

