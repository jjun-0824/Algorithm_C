const int coverType[4][3][2] = {
	{{0,0},{1,0},{0,1}},
	{{0,0},{0,1},{1,1}},
	{{0,0},{1,0},{1,1}},
	{{0,0},{1,0},{1,-1}}
} //const �뵵 �˾ƺ���

//��ġ�ų� ���� ���� ���� �� false�� ��ȯ�Ѵ�.
bool set(vector<vector(int)>& board, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board.size())
			ok = false;
		else if ((board[ny][nx] += delta) > 1) //���⼭ delta�� 
		{
			ok = false;
		}
	}
}
//������ ���� �� �ִ� ��� ����� ���� ��ȯ���ִ� ��
int cover(vector<vector<int>>& board) {
	int y = -1; x = -1;//������ y, x ��� -1
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
	//��������� ��ĭ�� ã�� ��. �ϳ��� �� ���Ƽ� ���� ä������ ���� ĭ�� ����
	if (y == -1) return 1;
	int ret = 0;
	//���� ��ǥ�� �����ߴٸ�, ������ ��ǥ���� ���� �װ��� �ܰ踦 ��� �� ��!
	for (int type = 0; type < 4; ++type) {
		if (set(board, y, x, type,1)) {//1�� delta, �׸��� type��ŭ ����� ������!
			ret += cover(board);
		}
		set(board, y, x, type, -1);//�̺κ��� ������ �κ��� ġ��� ��?
	}
	return ret;
}

