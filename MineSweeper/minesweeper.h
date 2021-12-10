#include "framework.h"

using namespace std;

class minesweeper
{
private:
	pair<int, bool> board[32][18]; // ���� ����. ���� = -1, ������ ���ڰ� �ִ� ���ڸ�ŭ ���� ���. bool���� TRUE ��� Visible True. ����̸� += 110���� �ص���.
	int numMine = 0; // ������ ��
	int numFlag = 0; // ����� ��
	int numDig = 0; // Dig�� ��
	int X = 0;
	int Y = 0;
public:
	void setLevel(int level); // ���̵��� ���� ���� �ʱ�ȭ
	void printBoard(); // ������ ���
	void printMine();
	void layMine(); // �ʱ⿡ ���� ��ġ ���ϱ�
	void setNum(); // ���� ����ĭ�� ���� +1 �� layMine�� ó���ع������� �Ƚ��϶��!
	bool dig(int x, int y); // �� �ı�. ���ڶ�� ����. �ƴ϶�� ���ڸ� �����ְ� ���ڰ� 0�̶�� ������ 0�� ���� ���޾� �̾ ��������Ѵ�. �����¿� ����Ǿ��ִ� ���� �� ��������ϱ� ������, BFSȰ�� �غ���. ����� ���������� ���� ���ϵ���.
	void flag(int x, int y); // ��� ǥ��. ��߷� ������ ���� +=110���� �Ѵ�.
	int getDig() const;
	int getFlag() const;
};