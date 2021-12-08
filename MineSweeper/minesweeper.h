#include "framework.h"

using namespace std;

class minesweeper
{
private:
	pair<int, bool> board[32][18]; // 게임 보드. 지뢰 = -1, 주위에 지뢰가 있는 숫자만큼 숫자 배분. bool값이 TRUE 라면 Visible True. 깃발이면 += 110으로 해두자.
	int timer; // 클리어 시간
	int numMine; // 지뢰의 수
	int X;
	int Y;
public:
	minesweeper(int level); // 난이도에 따라서 변수 초기화
	void printBoard(); // 게임판 출력
	void layMine(); // 초기에 지뢰 위치 정하기
	void setNum(); // 지뢰 주위칸에 숫자 +1 은 layMine이 처리해버렸으니 안심하라고!
	void dig(int x, int y); // 땅 파기. 지뢰라면 폭발. 아니라면 숫자를 보여주고 숫자가 0이라면 주위에 0인 곳을 연달아 이어서 열어줘야한다. 상하좌우 연결되어있는 곳을 다 열어줘야하기 때문에, BFS활용 해보기. 깃발이 꽂혀있으면 열지 못하도록.
	void flag(int x, int y); // 깃발 표시. 깃발로 선택한 곳은 +=110으로 한다.

};