#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> directs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
long long m = 0, n = 0;

struct state {
    int x, y, step;
    state(int x, int y, int step): x(x), y(y), step(step) {}
    void set(int x, int y, int step) {
    	this->x = x; this->y = y; this->step = step;
    }
};

bool isVaild(int row, int col) {
	return row >= 0 && row < m && col >= 0 && col < n;
}

//record the position of person
queue<state> q_person;
//record the position of fire
queue<state> q_fire;

int getMin(vector<string> maze, state &person, state &fire) {
	if (maze.size() == 0 || maze[0].size() == 0) {return -1;}
    m = maze.size(), n = maze[0].size();

    // init poisition
    q_person.push(person);
    q_fire.push(fire);

    while(!q_person.empty()) {
    	auto cur_fire = q_fire.front(); q_fire.pop();
    	for (auto p : directs) {
    		int nx = cur_fire.x + p.first;
    		int ny = cur_fire.y + p.second;
    		
    		if (isVaild(nx, ny) && unordered_set<char>({'_', ' ', '|'}).count(maze[nx][ny]) ) {
    		    maze[nx][ny] = '*';
    		    q_fire.push(state(nx, ny, 0));	
    		}
    	}
    	auto cur_person = q_person.front(); q_person.pop();

    	if (unordered_set<char>({'_', '|'}).count(maze[cur_person.x][cur_person.y]))
    		return cur_person.step;

    	for (auto p : directs) {
    		int nx = cur_person.x + p.first;
    		int ny = cur_person.y + p.second;
    		if (isVaild(nx, ny) && unordered_set<char>({'_', ' ', '|'}).count(maze[nx][ny])) {
    		    q_person.push(state(nx, ny, cur_person.step + 1));	
    		}	
    	}
    }

    return -1;
}

int main() {
        vector<string> maze = {
        	"###############",
            "#    J        #",
            "###   #####   #",
            "|  #  #   #   #",
            "|     #*  #   #", 
            "|__#______#___|"
        };

    	state person(0,0,0);
    	state fire(0,0,0);
    	for (size_t i = 0; i < maze.size(); i++) {
    		for (size_t j = 0; j < maze[0].size(); j++) {
    			if (maze[i][j] == 'J') {
					person.set(i, j, 0);
					maze[i][j] = ' ';
    			}
    			if (maze[i][j] == '*') {
    				fire.set(i, j , 0);
    			}
    		}
    	}
    	//cout << person.x << person.y << endl;
    	//cout << fire.x << fire.y << endl;
    	cout << getMin(maze, person, fire);
        return 0;
}