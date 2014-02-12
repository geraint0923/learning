#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gradient_descent(float *src, int count, float alpha, float *output) {
    float la = 10, lb = 10, a = 20, b = 20;
    float sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0, sum_y2 = 0;
    int i;
    for(i = 0; i < count; i++) {
	float x = src[2 * i], y = src[2 * i + 1];
	sum_x += x;
	sum_y += y;
	sum_x2 += x * x;
	sum_xy += x * y;
	sum_y2 += y * y;
    }
    while(fabsf(la - a) > 0.000001 || fabsf(lb - b) > 0.000001) {
//    while(1) {
	la = a;
	lb = b;
	float slope_a = (a * sum_x2 + b * sum_x - sum_xy) / count;
	float slope_b = b + (a * sum_x - sum_y) / count;
	a = a - alpha * slope_a;
	b = b - alpha * slope_b;
	printf("curent value : a = %3f, b = %3f, last_a = %3f, last_b = %3f\n", a, b, la, lb);
    }
    output[0] = a;
    output[1] = b;
    return 0;
}

int read_input(char *filename, float **val_list) {
    FILE *f = fopen(filename, "r");
    int count, i;
    if(f != NULL) {
	fscanf(f, "%d", &count);
	*val_list = (float*) malloc(sizeof(float) * 2 * count);
	for(i = 0; i < count; i++)
	    fscanf(f, "%f %f", *val_list + 2 * i, *val_list + 2 * i + 1);
	return count;	
    }
    return -1;
}


int main() {
    float *val_list;
    float res[2];
    int val_count = read_input("input.txt", &val_list);
    gradient_descent(val_list, val_count, 0.1, res);
    printf("final result: a = %3f, b = %3f\n", res[0], res[1]);
    return 0;
}
