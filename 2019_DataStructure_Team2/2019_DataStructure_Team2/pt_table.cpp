#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
#include "pt_table.h"
typedef std::pair<int, char*> enrollname;

// PT받는 인원 중 최대, 최소 연령대를 출력해주는 함수
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
		printf("가장 오래된 회원 %d : %d가입 ", i + 1, tmpe.first);
		std::locale::global(std::locale("ko_KR.UTF-8"));
		printf("%s\n", tmpe.second);
		std::locale::global(std::locale("korean"));
		min_heap.pop();
	}
}

// 연령대별 pt여부의 열을 반환해주는 함수이다.
// 19세 미만은 1, 70대 이상은 7 나머지는 연령대별 10의자리수를 반환
int hash_func(int tm_year, int age_year)
{
	int idx = (tm_year + 1900 - age_year) / 10;
	if (idx <= 1) return 1;
	else if (idx >= 7) return 7;
	else return idx;
}

// 2행 8열짜리 배열에 0, 1 행은 pt여부, 1~7열은 연령대별 회원수, 0열은 1~7열의 합으로 되어있다.
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
	for (int i = 0; i < table.cnt; i++) // 생년 문자열을 숫자로 변환해주는 함수
	{
		age[0] = table.list[i].birthday[0];
		age[1] = table.list[i].birthday[1];
		age[2] = '\0';
		age_year = atoi(age);
		if (age_year > t->tm_year - 80) // 회원이 80살 이상이라고 추정되면 2000을 더하고(없을 테니) 아니면 1900을 더하여 태여난 년도를 구한다.
			age_year += 1900;
		else age_year += 2000;

		int idx = hash_func(t->tm_year, age_year); // 행렬에 들어갈 열을 저장
		int pidx = (strcmp(table.list[i].pt_enroll, "N") == 0) ? 0 : 1; // pt여부에 따라 행렬에 들어갈 행을 저장
		pt_age[idx][pidx]++;
		pt_age[0][pidx]++;
	}
	table.pt_age = pt_age;
}
// 전체 회원중 20대의 비율을 출력해주는 함수
void Q12(member_info &table)
{
	double a = (double)(table.pt_age[2][0] + table.pt_age[2][1]) / (table.pt_age[0][0] + table.pt_age[0][1]);
	printf("회원 중에서 20대의 비율은 %d%% 입니다.\n", int(a * 100));
}
// PT받는 인원 중 최대, 최소 연령대를 출력해주는 함수
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
	printf("PT를 가장 많이 이용하는 연령대는 %d0 대이고, 가장 적게 이용하는 연령대는 %d0 대입니다.\n", max, min);
	printf("#10대는 0세부터 19세까지 집계한 결과이고 70대는 70세부터 집계한 결과입니다.\n");
}

