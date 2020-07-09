//q4를 해결하기위해 필요한 자료구조 (map)
#include <stdio.h>
#include <string>

class element {
public:
	char* name; //동 이름 
	int n_mem; //각 동에 사는 회원 수
	void set(char* name_); //처음등장하는 동 이름을 저장하는 함수
};

class address {
	int n; //배열의 최대 원소 수
	int cnt; //배열에 현재 저장된 원소의 수
	element* addr; //address의 배열
public:
	void init(int n); //배열 초기화 함수
	void insert(char* addr); //동 이름을 insert할 함수 이미 존재하는 동의 경우에는 해당 adrress의 n_mem++
	void sort(); //n_mem을 기준으로 정렬
	void print(); //프린트,,확인용
	void result(); //가장 많은,가장 적은 동의 결과를 출력해 줄 함수
};
