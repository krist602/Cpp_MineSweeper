#include "framework.h"

using namespace std;

class minesweeper
{
private:
	pair<int, bool> board[32][18]; // ���� ����. ���� = -1, ������ ���ڰ� �ִ� ���ڸ�ŭ ���� ���. bool���� TRUE ��� Visible True. ����̸� += 110���� �ص���.
	int timer; // Ŭ���� �ð�
	int numMine; // ������ ��
	int X;
	int Y;
public:
	minesweeper(int level); // ���̵��� ���� ���� �ʱ�ȭ
	void printBoard(); // ������ ���
	void layMine(); // �ʱ⿡ ���� ��ġ ���ϱ�
	void setNum(); // ���� ����ĭ�� ���� +1 �� layMine�� ó���ع������� �Ƚ��϶��!
	void dig(int x, int y); // �� �ı�. ���ڶ�� ����. �ƴ϶�� ���ڸ� �����ְ� ���ڰ� 0�̶�� ������ 0�� ���� ���޾� �̾ ��������Ѵ�. �����¿� ����Ǿ��ִ� ���� �� ��������ϱ� ������, BFSȰ�� �غ���. ����� ���������� ���� ���ϵ���.
	void flag(int x, int y); // ��� ǥ��. ��߷� ������ ���� +=110���� �Ѵ�.

};