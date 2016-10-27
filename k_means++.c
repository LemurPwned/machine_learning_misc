#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

using namespace std;

//frame for clustering and points is rectangle
//[-50,-50], [50,50], [-50,50], [50,-50]
//5 clusters


//define the point struct
typedef struct { int x, y; int group;} point_t;
typedef struct { int points; int center_x, center_y; point_t group[100];} Cluster;
//provide an appropiate metrics measure, 
//this will have only Euclidian distance for now in R^2
/*
point_t* generate(int count, int radius, point_t center){
	//point_t* points = malloc(point_t)*count;
	int i;
	int center_X = center.x;
	int center_Y = center.y;
	srand(time(NULL));
	for (i = 0; i< count; i++){
		point_t sig;
		sig.x = rand()%radius + center_X;
		sig.y = rand()%radius + center_Y;
		points[i] = sig;
	}
	return points;
}
*/
/*
double** cluster_center(usigned p_num){
	double** cc = 0;
	cc = new double*[p_num];
	for (int i = 0; i< p_num; i++){
		cc[i] = new double[p_num];
	}
}*/

int min(int distance){
	//TODO:
	//calculate the minimum distance between any two points
	//in the distance array, find good representation
	//idea: let the index be the a specific cluster?
	int i,j;
	int min = 0;
	//int size = (int) (sizeof(distance))/ sizeof(distance[0]);
	for(i = 0; i<distance.size; i++){
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
	int distance = {22, 31, 15, 98, 12};
	int m = min(distance);
}
