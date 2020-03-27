/*
 * main.cpp
 *
 *  Created on: 2020. 3. 27.
 *      Author: kani3
 */
#include <iostream>
#include <queue>

using namespace std;

void bfs(int** arr, int visit[], int** result, int n, int start, int end);

int main(){
	int n=0;
	cin >> n;
	int** arr = new int* [n];
	int visit[n] = {0,};
	int** result = new int* [n];
	for(int i=0; i<n; i++){
		arr[i] = new int[n];
		result[i] = new int[n];
		for(int j=0; j<n; j++){
			cin >> arr[i][j];
			result[i][j]=0;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			bfs(arr, visit, result, n, i, j);
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void bfs(int** arr, int visit[], int** result, int n, int start, int end){
	for(int i=0; i<n; i++){
		visit[i]=0;
	}
	int u=0;
	queue<int> q;
	q.push(start);
	visit[start]=1;
	while(!q.empty()){
		u=q.front();
		q.pop();
		for(int i=0; i<n; i++){
			if(arr[u][i]==1){
				if(visit[i]==0){
					q.push(i);
					visit[i]=1;
				}
				if(i==end){
					result[start][end]=1;
					break;
				}
			}
		}
	}
}
