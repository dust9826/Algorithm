#include <iostream>
#include <vector>
using namespace std;

#define INF 10000000

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int V, E, K;
	cin >> V >> E;
	cin >> K;

	vector<vector<pair<int, int>>> graph(V + 1);
	vector<int> dist(V + 1, INF);
	vector<bool> isVisit(V + 1, false);
	dist[1] = 0;

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}

	int visitCount = 0;
	while (visitCount++ < V)
	{
		int min_index = 1;
		for (int i = 1; i <= V; i++)
		{
			if (dist[min_index] > dist[i] && !isVisit[i])
			{
				min_index = i;
			}
		}

		isVisit[min_index] = true;

		for (int i = 0; i < graph[min_index].size(); i++)
		{
			int len = dist[min_index] + graph[min_index][i].second;
			int index = graph[min_index][i].first;
			if (len < dist[index])
			{
				dist[index] = len;
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		cout << dist[i] << "\n";
	}
}