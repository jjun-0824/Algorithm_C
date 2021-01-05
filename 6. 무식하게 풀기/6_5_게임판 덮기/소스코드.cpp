const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
} //const 용도 알아보가

//겹치거나 검은 판을 덮을 때 false를 반환한다.
bool set(vector<vector(int)>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1) //여기서 delta는 
		{
			ok = false;
		}
	}
}
//이제는 덮을 수 있는 모든 경우의 수를 반환해주는 식
int cover(vector<vector<int>>& board) {
	int y = -1; x = -1;//시작은 y, x 모두 -1
	for (int i = 0; i < board.size(); ++i) { 
		for (int j = 0; j < board[i].size(); ++j) {
			if (board[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (y = -1)
			break;
	}
	//여기까지는 별칸을 찾는 것. 하나씩 쭉 돌아서 아직 채워지지 않은 칸을 선정
	if (y == -1) return 1;
	int ret = 0;
	//만약 별표를 선점했다면, 이제는 별표지점 부터 네가지 단계를 모두 돌 것!
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type,1)) {//1은 delta, 그리고 type만큼 모양을 선정함!
			ret += cover(board);
		}
		set(board, y, x, type, -1);//이부분은 덮었던 부분은 치우는 것?
	}
	return ret;
}

