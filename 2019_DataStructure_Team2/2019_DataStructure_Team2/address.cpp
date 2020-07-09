#include <stdio.h>
#include <string>
#include "address.h"
#include "member.h"
#pragma warning(disable : 4996)

void most_addr(member_info& table)
{
	address address;
	address.init(1000);
	for (int i = 0; i < table.cnt; i++)
		address.insert(table.list[i].addr);
	address.sort();
	address.result();
}

void element::set(char* name_) {

	name = (char*)malloc(16);
	strcpy(name, name_);
	n_mem = 0;
}

void address::init(int n)
{
	this->n = n;
	cnt = 0;
	addr = (element*)calloc(n, sizeof(element));
}
void address::insert(char* name)
{
	for (int i = 0; i < cnt; i++) {
		if (strcmp(addr[i].name, name) == 0) {
			addr[i].n_mem++;
			return;
		}
	}
	addr[cnt++].set(name);
}
void swap(element & a, element & b) {
	element x;
	x = a;
	a = b;
	b = x;
}
void address::sort()
{
	int i, j;
	for (i = 0; i < cnt - 1; i++) {
		for (j = cnt - 1; j > i; j--) {
			if (addr[j - 1].n_mem < addr[j].n_mem)
				swap(addr[j - 1], addr[j]);
		}
	}
}
void address::print()
{
	for (int i = 0; i < cnt; i++)
		printf("%s %d\n", addr[i].name, addr[i].n_mem);
}
void address::result()
{
	printf("%s", addr[0].name);
	std::locale::global(std::locale("korean"));
	printf("이 %d명으로 가장 많은 회원이 거주하고 있습니다.\n", addr[0].n_mem);
	std::locale::global(std::locale("ko_KR.UTF-8"));
	printf("%s", addr[cnt - 1].name);
	std::locale::global(std::locale("korean"));
	printf("이 %d명으로 가장 적은 회원이 거주하고 있습니다.\n", addr[cnt - 1].n_mem);
}