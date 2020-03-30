/*
 * main.cpp
 *
 *  Created on: 2020. 3. 30.
 *      Author: kani3
 */
#include <iostream>
#include <queue>

using namespace std;

typedef struct{
	int x=0;
	int y=0;
}Pair;

bool bfs(int** arr, int** visit, int n, int min, int gap, int max);

int main(){
	int n;
	cin >> n;
	int min=201;
	int max=-1;
	int** arr = new int* [n];
	int** visit = new int* [n];
	for(int i=0; i<n; i++){
		arr[i] = new int[n];
		visit[i] = new int[n];
		for(int j=0; j<n; j++){
			visit[i][j]=0;
			cin >> arr[i][j];
			if(arr[i][j]>max)
				max=arr[i][j];
			if(arr[i][j]<min)
				min=arr[i][j];
		}
	}
	int start=0;
	int end=max-min;
	int gap;
	while(start<=end){
		gap = (start+end)/2;
		if(bfs(arr, visit, n, min, gap, max)){
			end = gap - 1;
		}
		else
			start = gap + 1;
	}
	cout << end+1;
}

bool bfs(int** arr, int** visit, int n, int min, int gap, int max){
	queue<Pair> q;
	for(int l=min; l+gap<=max; l++){
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				visit[i][j]=0;
			}
		}
		Pair start;
		start.x=0;
		start.y=0;
		Pair left;
		Pair right;
		Pair down;
		Pair up;
		q.push(start);
		while(!q.empty()){
			Pair u=q.front();
			q.pop();
			if(u.x<0||u.x>=n||u.y<0||u.y>=n||visit[u.y][u.x]==1||arr[u.y][u.x]>l+gap||arr[u.y][u.x]<l){
				continue;
			}
			if(u.y==n-1&&u.x==n-1){
				return true;
			}
			visit[u.y][u.x]=1;
			left.x = u.x-1;
			left.y = u.y;
			right.x = u.x+1;
			right.y = u.y;
			up.x = u.x;
			up.y = u.y-1;
			down.x = u.x;
			down.y = u.y+1;
			q.push(left);
			q.push(right);
			q.push(up);
			q.push(down);
		}
	}
	return false;
}
