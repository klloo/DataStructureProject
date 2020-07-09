#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "pt_table.h"
typedef std::pair<int, char*> enrollname;

// PT�޴� �ο� �� �ִ�, �ּ� ���ɴ븦 ������ִ� �Լ�
void Q6(int num, member_info& table)
{
	std::priority_queue<enrollname, std::vector<enrollname>, std::greater<enrollname>> min_heap;
	char tmp[9];
	member* list = table.list;
	int cnt = table.cnt;
	for (int i = 0; i < cnt; i++)
	{
		int cnt = 0;
		for (int j = 0; j < 17; j++)
		{

			if (list[i].enroll_date[j] >= '0' && list[i].enroll_date[j] <= '9')
				tmp[cnt++] = list[i].enroll_date[j];
		}
		enrollname tmpn = std::pair<int, char*>(atoi(tmp), (char*)malloc(sizeof(char) * 16));
		strcpy(tmpn.second, list[i].name);
		min_heap.push(tmpn);
	}

	for (int i = 0; i < num; i++)
	{
		enrollname tmpe = min_heap.top();
		printf("���� ������ ȸ�� %d : %d���� ", i + 1, tmpe.first);
		std::locale::global(std::locale("ko_KR.UTF-8"));
		printf("%s\n", tmpe.second);
		std::locale::global(std::locale("korean"));
		min_heap.pop();
	}
}

// ���ɴ뺰 pt������ ���� ��ȯ���ִ� �Լ��̴�.
// 19�� �̸��� 1, 70�� �̻��� 7 �������� ���ɴ뺰 10���ڸ����� ��ȯ
int hash_func(int tm_year, int age_year)
{
	int idx = (tm_year + 1900 - age_year) / 10;
	if (idx <= 1) return 1;
	else if (idx >= 7) return 7;
	else return idx;
}

// 2�� 8��¥�� �迭�� 0, 1 ���� pt����, 1~7���� ���ɴ뺰 ȸ����, 0���� 1~7���� ������ �Ǿ��ִ�.
void pt(member_info &table)
{
	int** pt_age = (int**)malloc(sizeof(int*) * 8);
	for(int i = 0; i < 8; i++)
		pt_age[i] = (int*)calloc(2, sizeof(int) * 2);

	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);
	char age[3];
	int age_year;
	int age20s = 0;
	for (int i = 0; i < table.cnt; i++) // ���� ���ڿ��� ���ڷ� ��ȯ���ִ� �Լ�
	{
		age[0] = table.list[i].birthday[0];
		age[1] = table.list[i].birthday[1];
		age[2] = '\0';
		age_year = atoi(age);
		if (age_year > t->tm_year - 80) // ȸ���� 80�� �̻��̶�� �����Ǹ� 2000�� ���ϰ�(���� �״�) �ƴϸ� 1900�� ���Ͽ� �¿��� �⵵�� ���Ѵ�.
			age_year += 1900;
		else age_year += 2000;

		int idx = hash_func(t->tm_year, age_year); // ��Ŀ� �� ���� ����
		int pidx = (strcmp(table.list[i].pt_enroll, "N") == 0) ? 0 : 1; // pt���ο� ���� ��Ŀ� �� ���� ����
		pt_age[idx][pidx]++;
		pt_age[0][pidx]++;
	}
	table.pt_age = pt_age;
}
// ��ü ȸ���� 20���� ������ ������ִ� �Լ�
void Q12(member_info &table)
{
	double a = (double)(table.pt_age[2][0] + table.pt_age[2][1]) / (table.pt_age[0][0] + table.pt_age[0][1]);
	printf("ȸ�� �߿��� 20���� ������ %d%% �Դϴ�.\n", int(a * 100));
}
// PT�޴� �ο� �� �ִ�, �ּ� ���ɴ븦 ������ִ� �Լ�
void Q19(member_info &table)
{
	int max = 1, min = 1;
	for (int i = 1; i <= 7; i++)
	{
		if (table.pt_age[max][1] < table.pt_age[i][1])
			max = i;
		else if (table.pt_age[min][1] > table.pt_age[i][1])
			min = i;
	}
	printf("PT�� ���� ���� �̿��ϴ� ���ɴ�� %d0 ���̰�, ���� ���� �̿��ϴ� ���ɴ�� %d0 ���Դϴ�.\n", max, min);
	printf("#10��� 0������ 19������ ������ ����̰� 70��� 70������ ������ ����Դϴ�.\n");
}

