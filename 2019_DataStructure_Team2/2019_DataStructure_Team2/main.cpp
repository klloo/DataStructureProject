#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include "member.h"
#include "pt_table.h"
#include "forest.h"
#include "trainer.h"

member memarr[200];
void most_addr(member_info& table); //q4���� �ذ��� ���� �Լ� ���� ����
void most_recommender(member_info& list);
member_info table;

atrain t_arr; // class trainer�迭�� ���� Ŭ����
int main()
{
	table.init(1000);
	table.load();

	/* �ֿ��� ���� */
	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��        **  Q01          ��\n");
	printf("������������������������������������������������������\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));

	t_arr.init(); // class trainer 100ĭ�� ����
	t_arr.loading(table.cnt); // �迭�� ������ Ʈ���̳� ����
	t_arr.best1(); // ���� ȸ���� ���� ���� Ʈ���̳ʴ� �����ΰ�

	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��      ***   Q02          ��\n");
	printf("������������������������������������������������������\n");
	t_arr.best2(); // ����Ʈ�� ���� ���� Ʈ���̳ʴ� �����ΰ�
//t_arr.deb(); // (����׿�) ������ Ʈ���̴� �� ����Ʈ�� ���� �ִ°�?
   /* �ֿ��� �� */


	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��       **   Q04          ��\n");
	printf("������������������������������������������������������\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 ���

	// 6, 12, 19 ����� ���� �ڵ�
	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��        *   Q06          ��\n");
	printf("������������������������������������������������������\n");
	Q6(10, table);


	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��     ****   Q09          ��\n");
	printf("������������������������������������������������������\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_recommender(table);

	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��       **   Q11          ��\n");
	printf("������������������������������������������������������\n");
	Q11(table, memarr);

	std::locale::global(std::locale("korean"));
	printf("������������������������������������������������������\n");
	printf("��        *   Q12          ��\n");
	printf("������������������������������������������������������\n");
	pt(table);
	Q12(table);

	printf("������������������������������������������������������\n");
	printf("��       **   Q19          ��\n");
	printf("������������������������������������������������������\n");
	Q19(table);


	return 0;
}