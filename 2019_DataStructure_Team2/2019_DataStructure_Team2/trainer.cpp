#include"member.h"
#include<string.h>
#include"trainer.h"

extern member_info table;

void atrain::init(void) {
	t_cnt = 0;
	arr = new trainer[100];
}


int atrain::loading(int line) {
	int i = 0;
	int m;
	for (int j = 0; j < line; j++) {
		if (strcmp(table.list[j].trainer, "-") == 0) {
			continue;
		}
		if (i == 0) {
			arr[i].t_name = table.list[j].trainer;
			arr[i].m_cnt = 0;
			arr[i].m_arr = (int*)calloc(100, sizeof(int));
			arr[i].m_arr[arr[i].m_cnt] = j;
			arr[i].m_cnt++;
			i++;
			t_cnt++;
			continue;
		}
		m = i;
		int k;
		for (k = 0; k < m; k++) {
			if (strcmp(arr[k].t_name, table.list[j].trainer) == 0) {
				arr[k].m_arr[arr[k].m_cnt] = j;
				arr[k].m_cnt++;
				break;
			}
		}
		if (k == m) {
			arr[i].t_name = table.list[j].trainer;
			arr[i].m_cnt = 0;
			arr[i].m_arr = (int*)calloc(100, sizeof(int));
			arr[i].m_arr[arr[i].m_cnt] = j;
			arr[i].m_cnt++;
			i++;
			t_cnt++;
		}

	}
	return i;
}


void atrain::best1(void) {
	int* brr = (int*)calloc(t_cnt, sizeof(int));
	for (int i = 0; i < t_cnt; i++) brr[i] = i;
	quicksort1(0, t_cnt - 1, brr);

	std::locale::global(std::locale("korean"));
	std::cout << "가장 많은 회원을 확보한 트레이너는!" << '\n';
	std::locale::global(std::locale("ko_KR.UTF-8"));
	for (int i = 0; i < t_cnt; i++) printf("NO.%d : %s   count: %d\n", i + 1, arr[brr[t_cnt - 1 - i]].t_name, arr[brr[t_cnt - 1 - i]].m_cnt);

}

void atrain::quicksort1(int head, int tail, int* brr) {
	if (head >= tail) return;
	int start = head + 1;
	int end = tail;
	int swap;
	while (1) {
		while (start <= end && arr[brr[head]].m_cnt > arr[brr[start]].m_cnt) start++;
		while (start <= end && arr[brr[head]].m_cnt < arr[brr[end]].m_cnt) end--;
		if (start < end) {
			swap = brr[start];
			brr[start] = brr[end];
			brr[end] = swap;
		}
		if (start >= end) {
			swap = brr[end];
			brr[end] = brr[head];
			brr[head] = swap;
			break;
		}
	}
	quicksort1(head, end - 1, brr);
	quicksort1(end + 1, tail, brr);
}



void atrain::point_update(void) {
	for (int i = 0; i < t_cnt; i++) {
		double point = 0;
		for (int j = 0; j < arr[i].m_cnt; j++) {
			point += count(arr[i].m_arr[j]);
		}
		arr[i].t_point = point / arr[i].m_cnt * 100 / arr[i].m_cnt;
	}
}

double count(int i) {
	double first = table.list[i].BMIfirst, now = table.list[i].BMInow, goal = table.list[i].BMIgoal;

	double head = (first - now) * (first - now);
	double tail = (first > goal) ? first - goal : goal - first;

	if (first > goal) {
		if (now > first) return -(head / tail);
		else return head / tail;
	}
	if (first < goal) {
		if (now < first) return -(head / tail);
		else return head / tail;
	}
}

void atrain::best2(void) {
	point_update();

	int* brr = (int*)calloc(t_cnt, sizeof(int));
	for (int i = 0; i < t_cnt; i++) brr[i] = i;
	quicksort2(0, t_cnt - 1, brr);

	std::locale::global(std::locale("korean"));
	std::cout << "가장 성과가 좋은 트레이너는!" << '\n';
	std::locale::global(std::locale("ko_KR.UTF-8"));
	for (int i = 0; i < t_cnt; i++) printf("NO.%d : %s   point: %f\n", i + 1, arr[brr[t_cnt - 1 - i]].t_name, arr[brr[t_cnt - 1 - i]].t_point);
	return;
}

void atrain::quicksort2(int head, int tail, int* brr) {
	if (head >= tail) return;
	int start = head + 1;
	int end = tail;
	int swap;
	while (1) {
		while (start <= end && arr[brr[head]].t_point > arr[brr[start]].t_point) start++;
		while (start <= end && arr[brr[head]].t_point < arr[brr[end]].t_point) end--;
		if (start < end) {
			swap = brr[start];
			brr[start] = brr[end];
			brr[end] = swap;
		}
		if (start >= end) {
			swap = brr[end];
			brr[end] = brr[head];
			brr[head] = swap;
			break;
		}
	}
	quicksort2(head, end - 1, brr);
	quicksort2(end + 1, tail, brr);
}
void atrain::deb(void) {
	for (int i = 0; i < t_cnt; i++) {
		std::cout << arr[i].t_name << ',' << ' ' << arr[i].t_point << '\n';
	}
}