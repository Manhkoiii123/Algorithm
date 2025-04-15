#include <bits/stdc++.h>
#define N 100
#define M 26
using namespace std;
vector<int> graph[M];
string s[N];
bool hasIn[M];
bool visited[M];
bool inPath[M];
char res[M + 1];

void dfs(int u, vector<int> graph[], bool visited[], bool inPath[], char res[], int& id) {
	if (inPath[u]) {
		printf("Impossible"); // detected a cycle
		exit(0);
	}
	if (visited[u])
		return;
	inPath[u] = true;
	visited[u] = true;
	for (int v: graph[u])
		dfs(v, graph, visited, inPath, res, id);
	res[--id] = u + 'a';
	inPath[u] = false;
}
int main() {
	int n;
	cin >> n;
		for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n - 1; i++) {
		unsigned long j = 0;
		while (j < s[i].length() && j < s[i + 1].length() && s[i][j] == s[i + 1][j])
			j++;
		if (j == s[i + 1].length() && j < s[i].length())
			return printf("Impossible"), 0;
		if (j < s[i].length() && j < s[i + 1].length()) {
			graph[s[i][j] - 'a'].push_back(s[i + 1][j] - 'a');
			hasIn[s[i + 1][j] - 'a'] = true;
		}
	}
	int id = 26;
	for (int i = 0; i < 26; i++)
		if (!hasIn[i])
			dfs(i, graph, visited, inPath, res, id);
	if (id == 0)
		printf("%s", res);
	else
		printf("Impossible");
}
