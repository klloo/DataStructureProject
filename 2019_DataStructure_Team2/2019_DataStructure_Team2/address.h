//q4�� �ذ��ϱ����� �ʿ��� �ڷᱸ�� (map)
#include <stdio.h>
#include <string>

class element {
public:
	char* name; //�� �̸� 
	int n_mem; //�� ���� ��� ȸ�� ��
	void set(char* name_); //ó�������ϴ� �� �̸��� �����ϴ� �Լ�
};

class address {
	int n; //�迭�� �ִ� ���� ��
	int cnt; //�迭�� ���� ����� ������ ��
	element* addr; //address�� �迭
public:
	void init(int n); //�迭 �ʱ�ȭ �Լ�
	void insert(char* addr); //�� �̸��� insert�� �Լ� �̹� �����ϴ� ���� ��쿡�� �ش� adrress�� n_mem++
	void sort(); //n_mem�� �������� ����
	void print(); //����Ʈ,,Ȯ�ο�
	void result(); //���� ����,���� ���� ���� ����� ����� �� �Լ�
};
