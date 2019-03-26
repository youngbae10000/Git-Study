#include <iostream>
#include <vector>
#include <cstring>
#include <queue>


using namespace std;

struct Node{

	int H_x = 0;
	int H_y = 0;
	int eat = 0;
	int size = 0;
	int time = 0;

	int flag = 0;
};

int N;

int map[21][21];
int visit[21][21];

queue <Node> q;


int dx[4] =  { 0,  0, -1, 1};
int dy[4] =  { -1, 1, 0, 0 };



Node BFS(int value){


	Node goal;
	goal.H_x = 987654321;
	goal.H_y = 987654321;
	goal.time = 987654321;
	
	int flag = 0;
	while (!q.empty())
	{
		Node node = q.front();
		q.pop();

		for (int i = 0; i < 4; i++){
			int m_x = node.H_x + dx[i];
			int m_y = node.H_y + dy[i];

			if (m_x < 0 || m_y < 0 || m_x > N - 1 || m_y > N - 1 || visit[m_y][m_x] == 1 || value < map[m_y][m_x])
				continue;

			if (map[m_y][m_x] == 0 || map[m_y][m_x] == value){ //0, 같은때 이동
				visit[m_y][m_x] = 1;

				Node tmp;
				tmp.H_x = m_x;
				tmp.H_y = m_y;
				tmp.time = node.time + 1;
				q.push(tmp);
				continue;
			}

			else if (value > map[m_y][m_x] ){
				visit[m_y][m_x] = 1;
				flag = 1;
				if (goal.time >= node.time + 1){

					if (goal.H_y > m_y){
						goal.H_x = m_x;
						goal.H_y = m_y;
						goal.time = node.time + 1;
					}
					else if (goal.H_y == m_y && goal.H_x > m_x){
						Node tmp;
						goal.H_x = m_x;
						goal.H_y = m_y;
						goal.time = node.time + 1;
					}
				}

			}

		}

	}

	if (flag == 1)
		return goal;
	else{
		goal.flag = -1;
		return goal;
	}

}
int main(){


	cin >> N;

	Node start;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> map[i][j];

			if (map[i][j] == 9){
				start.H_y = i;
				start.H_x = j;
				start.size = 2;
			}
		}
	}

	while (true)
	{
			
		visit[start.H_y][start.H_x] = 1;
		q.push(start);

		Node node = BFS(start.size);

		if (node.flag == -1)
			break;

		start.eat++;
		if (start.eat == start.size){
			start.size++;
			start.eat = 0;
		}

		map[start.H_y][start.H_x] = 0;
		start.H_x = node.H_x;
		start.H_y = node.H_y;
		start.time = node.time;
		map[start.H_y][start.H_x] = 0;
		memset(visit,0,sizeof(visit));
	}

	cout << start.time << endl;
	return 0;


}