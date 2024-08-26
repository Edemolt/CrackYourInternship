#include <bits/stdc++.h>
using namespace std;

#define N 9

bool isValid(set<pair<int, int> > visited,
			pair<int, int> pt)
{
	return (pt.first >= 0) && (pt.first < N) &&
		(pt.second >= 0) && (pt.second < N) &&
		(visited.find(pt) == visited.end());
}

void printPath(list<pair<int, int> > path)
{
	for (auto it = path.begin(); it != path.end(); it++)
		cout << "(" << it->first << ", "
			<< it->second << ") -> ";

	cout << "MID" << endl << endl;
}

int row[] = {-1, 1, 0, 0};
int col[] = { 0, 0, -1, 1};
int _row[] = { 0, 0, N-1, N-1};
int _col[] = { 0, N-1, 0, N-1};

void findPathInMazeUtil(int maze[N][N],
				list<pair<int, int> > &path,
				set<pair<int, int> > &visited,
				pair<int, int> &curr)
{
	if (curr.first == N / 2 && curr.second == N / 2){
		printPath(path);
		return;
	}

	for (int i = 0; i < 4; ++i){
		int n = maze[curr.first][curr.second];

		int x = curr.first + row[i]*n;
		int y = curr.second + col[i]*n;

		pair<int, int> next = make_pair(x, y);

		if (isValid(visited, next)){
			visited.insert(next);
			path.push_back(next);
			findPathInMazeUtil(maze, path, visited, next);
			path.pop_back();
			visited.erase(next);
		}
	}
}

void findPathInMaze(int maze[N][N]){
	list<pair<int, int> > path;
	set<pair<int, int> > visited;

	for (int i = 0; i < 4; ++i)
	{
		int x = _row[i];
		int y = _col[i];
		pair<int, int> pt = make_pair(x, y);

		visited.insert(pt);
		path.push_back(pt);
		findPathInMazeUtil(maze, path, visited, pt);
		path.pop_back();
		visited.erase(pt);
	}
}
