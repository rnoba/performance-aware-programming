#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define POINTS 10000000
#define MM_LAT 90.000000
#define MM_LONG 180.000000
#define FILENAME "_points.json"

#define randnum(min,max) \
    ((((rand()/(float)RAND_MAX)*max) - min) + min)

int main() {
    srand(time(NULL));
    FILE *f = NULL;
    char buffer[1024];
    f = fopen(FILENAME, "w");
    fputs("{\"pairs\": [", f);

    if(f == NULL) {
	printf("unable to open/create file\n");
	exit(EXIT_FAILURE);
    }

    int count = -1;
    while(++count != POINTS) {
	fputs("{", f);
	float y0 = randnum(1, MM_LAT*2)-MM_LAT;
	float x0 = randnum(1, MM_LONG*2)-MM_LONG;
	float y1 = randnum(1, MM_LAT*2)-MM_LAT;
	float x1 = randnum(1, MM_LONG*2)-MM_LONG;
	fputs("\"x0\":", f);
	sprintf(buffer, "%f,", x0);
	fputs(buffer, f);
	fputs("\"y0\":", f);
	sprintf(buffer, "%f,", y0);
	fputs(buffer, f);
	fputs("\"x1\":", f);
	sprintf(buffer, "%f,", x1);
	fputs(buffer, f);
	sprintf(buffer, "%f", y1);
	fputs("\"y1\":", f);
	fputs(buffer, f);
	fputs("}", f);
	if(count < POINTS-1) {
	    fputs(",", f);
	}
	printf("lat(%f %f) - long(%f %f)\n", x0, x1, y0, y1);
    }

    fputs("]}", f);
    fclose(f);
    return EXIT_SUCCESS;
}
