#include <iostream>
using namespace std;
int count = 0;
int A[10][10] = {
	{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 0, 1, 0, 1},
	{0, 0, 1, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 1, 1, 1, 0, 1, 1, 0, 1},
	{0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 0, 0, 1, 1, 0},
	{0, 0, 0, 0, 1, 0, 0, 1, 0, 1},
	{0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 1, 0, 0, 1}
};
int shortest_path(int a[10][10], int i, int j, int x, int y, bool vis[10][10]);
int shortest_path(int a[10][10], int i, int j, int x, int y)
{
	bool vis[10][10];
	return shortest_path(a, i, j, x, y, vis);
}

bool isvalid(int a[10][10], int i, int j, bool vis[10][10])
{
	return i >= 0 && j >= 0 && i < 10 && j < 10 && a[i][j] == 1 && !vis[i][j];
}

int shortest_path(int a[10][10], int i, int j, int x, int y, bool vis[10][10])
{
	if (!isvalid(a, i, j, vis)) return 100000;
	if (i == x && j == y) return 0;
	vis[i][j] = true;
	int left = shortest_path(a, i, j - 1, x, y, vis) + 1;
	int down = shortest_path(a, i + 1, j, x, y, vis) + 1;
	int right = shortest_path(a, i, j + 1, x, y, vis) + 1;
	int up = shortest_path(a, i - 1, j, x, y, vis) + 1;
	vis[i][j] = false;			//backtracking -------------------------------

	return min(min(left, right), min(up, down));
}


void permutation(string s, int l, int r)
{
	count++;
	if (l == r) {cout << s << endl; return;}
	for (int i = l; i < r; i++)
	{
		swap(s[l], s[i]);
		permutation(s, l + 1, r);
		swap(s[l], s[i]);		//------backtracking-----
	}

}

void nqueens(int n)
{
	int result[n][n];
	solveNqueens(n, 0, , result)
}
void solveNqueens(int n , int row, int placements[], int result[])
{
	if (row == n)
	}

int main()
{
	permutation("vikas", 0, 5);
	cout << "\n" << count;

}