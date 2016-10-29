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


//define the point struct and cluster struct
typedef struct { int x, y; int group; int *distances; } point_t;
typedef struct { int points; int center_x, center_y; point_t *group;} Cluster;
//provide an appropiate metrics measure, 
//this will have only Euclidian distance for now in R^2

point_t* generate(int count, int radius, point_t center){
	point_t *points =(point_t *) malloc(sizeof(point_t)*count);
	int i, sign;
	point_t *a = points;
	int center_X = center.x;
	int center_Y = center.y;
	srand(time(NULL));
	for (i = 0; i< count; i++){
		points -> x = (long)malloc(sizeof(int));
		points -> y = (long)malloc(sizeof(int));
		sign = (rand()%2)*2 - 1;
		points -> x = sign*rand()%(radius+1) + center_X;
		sign = (rand()%2)*2 - 1;
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
	//idea: let the index be a specific cluster?
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
	//Generate random cluster centers
	//say 5
	Cluster* clusters = (Cluster *)(malloc(sizeof(Cluster *)*5));
	int i;
	Cluster* cluster_arr_holder = clusters;
	//now allocate memory for grouping points in clusters
	//and for cluster centers
	srand(time(NULL));
	for (i = 0; i < 5 ; i++){
		cluster_arr_holder->group = (point_t *)(malloc(sizeof(point_t *)*20));
		cluster_arr_holder->center_x = (long)(malloc(sizeof(int)));
		cluster_arr_holder->center_y = (long)(malloc(sizeof(int)));
		cluster_arr_holder->center_x = rand()%60;
		cluster_arr_holder->center_y = rand()%60;
		cluster_arr_holder += 1;
	}
	//print cluster centers
	cluster_arr_holder = clusters;
	for (i = 0; i < 5; i++){
		printf("Cluster center no: %i is: (%i, %i) \n",i+1, cluster_arr_holder->center_x, cluster_arr_holder->center_y);
		cluster_arr_holder += 1;
	}
	//remember to reset (to free memory later)
	cluster_arr_holder = clusters;
	//generate some points
	//say 25
	point_t *list_points = (point_t *)(malloc(sizeof(point_t *)*25));
	point_t *point_list_holder = list_points;
	//perhaps have 5 points as "cluster centers"
	//and generate 5 more around them
	int j;
	for (i = 0; i < 5 ; i++){
		point_list_holder->x = (long)(malloc(sizeof(int)));
		point_list_holder->y = (long)(malloc(sizeof(int)));
		for (j = 0 ; j < 5 ; j++){
			
			point_list_holder->y = (long)(malloc(sizeof(int)));
			point_list_holder->y = (long)(malloc(sizeof(int)));
		}
	}
	//or have, say, 5 groups
	point_t *group1 = (point_t *)(malloc(sizeof(point_t *)*5));	
	point_t *group2 = (point_t *)(malloc(sizeof(point_t *)*5));	
	point_t *group3 = (point_t *)(malloc(sizeof(point_t *)*5));	
	point_t *group4 = (point_t *)(malloc(sizeof(point_t *)*5));	
	point_t *group5 = (point_t *)(malloc(sizeof(point_t *)*5));	
	//these are centers of groups
	point_t a = {rand()%60, rand()%60};
	point_t b = {rand()%60, rand()%60};
	point_t c = {rand()%60, rand()%60};
	point_t d = {rand()%60, rand()%60};
	point_t e = {rand()%60, rand()%60};
	printf(" Hello point (%i, %i) \n", a.x, a.y);
	group1 = generate(5, 7, a);
	group2 = generate(5, 7, b);
	group3 = generate(5, 7, c);
	group4 = generate(5, 7, d);
	group5 = generate(5, 7, e);
	//control display group
	point_t *group_holder = group1;
	for (i = 0; i < 5; i ++){
		printf(" Member of A, no %i is: (%i, %i) \n", i+1, group_holder->x, group_holder->y);
		group_holder += 1;
	}
	//now pick up a distance table
	

	
	//int dist = distance(a,b);
	/*Cluster c1;
	c1.points = 2;
	c1.group[0] = a;
	c1.group[1] = b;
	c1.center_x = 11;
	c1.center_y = 32;
	*/
	//new_cluster_center(&c1);
	//cout<<c1.center_x<<"\n";
	//cout<<c1.center_y; 
	//int dist[5] = {22, 31, 15, 98, 12};
	//int m = min(dist,5);
	//cout<<m<<endl;
	/*
	Cluster c2;
	c2.points = 10;
	//t is an array of 10 points
	point_t* test = generate(10, 5, b);
	c2.group = (point_t *)(malloc(sizeof(point_t)*10));
	c2.group = test;
	int j;
	for (j = 0; j<10; j++){
		printf(" Point is: (%i,%i)  \n", c2.group->x, c2.group->y);
		c2.group = c2.group+1;	
	}
	c2.group = test;
	new_cluster_center(&c2);
	cout<<c2.center_x<<endl<<c2.center_y;
	*/
}
