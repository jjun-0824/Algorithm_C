const int INF = 9999, SWITCHES = 10, CLOCKS = 16;

const char linked[SWITCHES][CLOCKS + 1] = {
	"xxx........."
}
bool areAligned(const vector<int>& clocks);

void push(vector<int>& clocks, int swtch) {
	for(int clock=0;clock<CLOCKS;++clock)
		if (linked[swtch][clocks] == "x")
		{
			clocks[clock] += 3;
			if (clocks[clock] == 15) clocks[clock] = 3;
		}
}
//push 함수는 한번 스위치를 눌렀을 때 시간을 바꿔주는 함쉬

int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCH) return areAligned(clocks) 0: INF;
	// 스위치를 모두 눌러봤을 때, 모두 12시로 정렬되지 않았다면 INF 반환.
	int ret = INF;
	for (int cnt = 0; cnt < 4; cnt++) {
		ret = min(ret, solve(clocks, cnt + solve(clocks, swtch + 1)));
		push(clocks, swtch);
	}
	return ret;
}