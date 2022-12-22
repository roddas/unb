#include<stdio.h>
#include<stdlib.h>
 
int find_lru(int *, int );
 
int main(void)
{
    int no_of_frames, no_of_pages, counter = 0, time[1000], flag1, flag2, i, j, pos, faults = 0;
	scanf("%d", &no_of_frames);
	scanf("%d", &no_of_pages);
	
	int *pages = calloc(no_of_pages,sizeof(int));
	int *frames = calloc(no_of_frames,sizeof(int));
	
    for(i = 0; i < no_of_pages; ++i){
    	scanf("%d", &pages[i]);
    }
    
	for(i = 0; i < no_of_frames; ++i){
    	frames[i] = -1;
    }
    
    for(i = 0; i < no_of_pages; ++i){
    	flag1 = flag2 = 0;
    	
    	for(j = 0; j < no_of_frames; ++j){
    		if(frames[j] == pages[i]){
	    		counter++;
	    		time[j] = counter;
	   			flag1 = flag2 = 1;
	   			break;
   			}
    	}
    	
    	if(flag1 == 0){
			for(j = 0; j < no_of_frames; ++j){
	    		if(frames[j] == -1){
	    			counter++;
	    			faults++;
	    			frames[j] = pages[i];
	    			time[j] = counter;
	    			flag2 = 1;
	    			break;
	    		}
    		}	
    	}
    	
    	if(flag2 == 0){
    		pos = find_lru(time, no_of_frames);
    		counter++;
    		faults++;
    		frames[pos] = pages[i];
    		time[pos] = counter;
    	}
	}
	
	printf("%d\n", faults);
    
    free(pages);
    free(frames);
    return EXIT_SUCCESS;
}

int find_lru(int time[], int n){
	int i, minimum = time[0], pos = 0;
 
	for(i = 1; i < n; ++i){
		if(time[i] < minimum){
			minimum = time[i];
			pos = i;
		}
	}
	return pos;
}
