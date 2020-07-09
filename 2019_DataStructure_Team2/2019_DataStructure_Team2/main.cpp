#define _CRT_SECURE_NO_WARNINGS
#include <locale>
#include "member.h"
#include "pt_table.h"
#include "forest.h"
#include "trainer.h"

member memarr[200];
void most_addr(member_info& table); //q4문제 해결을 위한 함수 원형 선언
void most_recommender(member_info& list);
member_info table;

atrain t_arr; // class trainer배열을 담을 클래스
int main()
{
	table.init(1000);
	table.load();

	/* 최영우 시작 */
	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│        **  Q01          │\n");
	printf("└─────────────────────────┘\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));

	t_arr.init(); // class trainer 100칸을 만듦
	t_arr.loading(table.cnt); // 배열을 읽으며 트레이너 생성
	t_arr.best1(); // 가장 회원을 많이 갖은 트레이너는 누구인가

	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│      ***   Q02          │\n");
	printf("└─────────────────────────┘\n");
	t_arr.best2(); // 포인트가 가장 높은 트레이너느 누구인가
//t_arr.deb(); // (디버그용) 각각의 트레이는 몇 포인트를 갖고 있는가?
   /* 최영우 끝 */


	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│       **   Q04          │\n");
	printf("└─────────────────────────┘\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_addr(table); //q4 출력

	// 6, 12, 19 출력을 위한 코드
	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│        *   Q06          │\n");
	printf("└─────────────────────────┘\n");
	Q6(10, table);


	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│     ****   Q09          │\n");
	printf("└─────────────────────────┘\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	most_recommender(table);

	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│       **   Q11          │\n");
	printf("└─────────────────────────┘\n");
	Q11(table, memarr);

	std::locale::global(std::locale("korean"));
	printf("┌─────────────────────────┐\n");
	printf("│        *   Q12          │\n");
	printf("└─────────────────────────┘\n");
	pt(table);
	Q12(table);

	printf("┌─────────────────────────┐\n");
	printf("│       **   Q19          │\n");
	printf("└─────────────────────────┘\n");
	Q19(table);


	return 0;
}