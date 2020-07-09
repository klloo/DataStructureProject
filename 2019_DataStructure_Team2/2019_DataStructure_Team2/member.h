#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>
#include <fstream>
#include <sstream>
#include <time.h>
#include<algorithm>
#include<queue>

class member {
public: // 18�� �׸�
	int ID; // ȸ����ȣ
	char* name; // �̸�
	char* addr; // �ְ���
	char* phone; // ��ȭ��ȣ
	char* recommender; // ��õ��
	char* birthday; //�������
	char* ticket; // ���Ż�ǰ
	char* pt_enroll; // pt��Ͽ���
	char* trainer; // ��� Ʈ���̳�
	double BMIfirst; // ù BMI����
	double BMInow; // ���� BMI����
	double BMIgoal; // ��ǥ BMI����
	char* locker; // ��� ��Ŀ
	char* enroll_date; // ���� �����
	int exer_cnt; // ���� �
	int pt_cnt; // ���� PT Ƚ��
	char* latest; // ���� �ֱ� ���
	char* finish; // ��ǰ�� ���� �ñ�

};

class member_info {
public:
	member* list; // ȸ�� ������ ����� ����Ʈ
	int** pt_age;
	int n; // �ִ� ȸ�� ���� ������ ��
	int cnt; // ȸ�� ��
	void init(int max_size);
	void load();
	int search(char* name);
};
// delemeter ������ ���ڿ� �ڸ��� �Լ�
std::vector<std::string> split(std::string str, char delimiter);
void Q11(member_info& table, member* arr);
