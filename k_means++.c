#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#define MAX_CLUSTER_SIZE 100
using namespace std;

//frame for clustering and points is rectangle
//[-50,-50], [50,50], [-50,50], [50,-50]
//5 clusters


//define the point struct
typedef struct { int x, y; int group;} point_t;
typedef struct { int points; int center_x, center_y; point_t group[MAX_CLUSTER_SIZE];} Cluster;
//provide an appropiate metrics measure, 
//this will have only Euclidian distance for now in R^2

point_t* generate(int count, int radius, point_t center){
	point_t *points =(point_t *) malloc(sizeof(point_t)*count);
	int i, sign;
	//sign = 0;
	point_t *a = points;
	int center_X = center.x;
	int center_Y = center.y;
	srand(time(NULL));
	for (i = 0; i< count; i++){
		points -> x = (long)malloc(sizeof(int));
		points -> y = (long)malloc(sizeof(int));
		sign = (rand()%2)*2 - 1;
		printf(" Sign is : %d \n", sign);
		points -> x = sign*rand()%(radius+1) + center_X;
		sign = (rand()%2)*2 - 1;
		printf(" Second sign : %d \n", sign);
		points -> y = sign*rand()%(radius+1) + center_Y;
		printf("There is that point: (%i,%i) \n", points->x, points->y);
		points += 1;
		
	}
	return a;
}

/*
double** cluster_center(usigned p_num){
	double** cc = 0;
	cc = new double*[p_num];
	for (int i = 0; i< p_num; i++){
		cc[i] = new double[p_num];
	}
}*/

int min(int distance[], int size_array){
	//TODO:
	//calculate the minimum distance between any two points
	//in the distance array, find good representation
	//idea: let the index be the a specific cluster?
	int i,j;
	int min = distance[0];
	int size = size_array;
	for(i = 0; i<size; i++){
		if(distance[i] < min){
			min = distance[i];
	}				
	}
	return min;
}
void new_cluster_center(Cluster* cluster){
	//TODO:
	//recalculate clusters
	int sum_x = 0;
	int sum_y = 0;
	for (int i = 0; i < cluster->points; i++){
		sum_x += cluster->group[i].x;
		sum_y += cluster->group[i].y;
	}
	int new_x = sum_x/cluster->points;
	int new_y = sum_y/cluster->points;
	cout<<"This is new x,y coordinate: "<<new_x<<"\n"<<new_y<<endl;
	cluster->center_x = new_x;
	cluster->center_y = new_y;
}
int distance(point_t a, point_t b){
	int dist = 0;
	dist = sqrt(pow(a.x - b.x, 2)+pow(a.y - b.y,2));
	return dist;
}

int main()
{
	point_t a;
	point_t b;
	a.x = 10;
	a.y = 12;
	b.x = 20;
	b.y = 30;
	//int dist = distance(a,b);
	Cluster c1;
	c1.points = 2;
	c1.group[0] = a;
	c1.group[1] = b;
	c1.center_x = 11;
	c1.center_y = 32;
	//new_cluster_center(&c1);
	//cout<<c1.center_x<<"\n";
	//cout<<c1.center_y; 
	//int dist[5] = {22, 31, 15, 98, 12};
	//int m = min(dist,5);
	//cout<<m<<endl;
	point_t* test = generate(10, 5, b);
	int j;
	for (j = 0; j<10; j++){
		printf(" Point is: (%i,%i)  \n", test->x, test->y);
		test = test+1;	
	}
}
