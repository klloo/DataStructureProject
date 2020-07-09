#define _CRT_SECURE_NO_WARNINGS
#include "member.h"
typedef std::pair<int, char*> enrollname;

// �ʱ�ȭ �ϴ� �Լ� //
void member_info::init(int max_size)
{
	n = max_size;
	cnt = 0;
	list = (member*)calloc(n, sizeof(member));



}
// �ε��ϴ� �Լ�
void member_info::load()
{
	std::ifstream in("info.csv");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	char buffer[1024];

	if (in.is_open())
	{
		in.getline(buffer, 1024);
	}
	std::string str;
	list = new member[1000];
	while (getline(in, str))
	{
		std::vector<std::string> parsing = split(str, ','); // ���ڿ��� . ������ �߶� parsing�̶�� vector�� �����Ѵ�.
		for (int i = 0; i < 18; i++) // index�� �´� ������ ����
		{
			switch (i)
			{
			case 0:
				list[cnt].ID = atoi(parsing[i].c_str());
				break;
			case 1:
				list[cnt].name = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].name, parsing[i].c_str());
				break;
			case 2:
				list[cnt].addr = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].addr, parsing[i].c_str());
				break;
			case 3:
				list[cnt].phone = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].phone, parsing[i].c_str());
				break;
			case 4:
				list[cnt].recommender = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].recommender, parsing[i].c_str());
				break;
			case 5:
				list[cnt].birthday = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].birthday, parsing[i].c_str());
				break;
			case 6:
				list[cnt].ticket = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].ticket, parsing[i].c_str());
				break;
			case 7:
				list[cnt].pt_enroll = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].pt_enroll, parsing[i].c_str());
				break;
			case 8:
				list[cnt].trainer = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].trainer, parsing[i].c_str());
				break;
			case 9:
				list[cnt].BMIfirst = atof(parsing[i].c_str());
				break;
			case 10:
				list[cnt].BMInow = atof(parsing[i].c_str());
				break;
			case 11:
				list[cnt].BMIgoal = atof(parsing[i].c_str());
				break;
			case 12:
				list[cnt].locker = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].locker, parsing[i].c_str());
				break;
			case 13:
				list[cnt].enroll_date = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].enroll_date, parsing[i].c_str());
				break;
			case 14:
				list[cnt].exer_cnt = atoi(parsing[i].c_str());
				break;
			case 15:
				list[cnt].pt_cnt = atoi(parsing[i].c_str());
				break;
			case 16:
				list[cnt].latest = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].latest, parsing[i].c_str());
				break;
			case 17:
				list[cnt].finish = (char*)malloc(sizeof(char) * 256);
				strcpy(list[cnt].finish, parsing[i].c_str());
				break;
			}
		}
		cnt++;
	}
	in.close();
}

void Q11(member_info &table, member* arr) {
	int i, j = 0;

	std::locale::global(std::locale("korean"));
	printf("<PT �޴� ȸ�� �� ��Ŀ�� �̿����� �ʴ� ȸ��>\n");
	std::locale::global(std::locale("ko_KR.UTF-8"));
	for (i = 0; i < 350; i++) { //���ڷ� �Ѱܹ��� �迭�� �ϳ��� Ȯ���ϸ鼭
		if ((strcmp(table.list[i].pt_enroll, "Y") == 0) && (strcmp(table.list[i].locker, "-") == 0)) { //PT����� Y�̸鼭 ��Ŀ�� ������� �ʴ� ȸ������ �� ID, �̸�, PT ��Ͽ���, ��Ŀ�� ���ο� �迭�� ����
			arr[j].ID = table.list[i].ID;
			arr[j].name = (char*)malloc(sizeof(char) * 256);
			strcpy(arr[j].name, table.list[i].name);
			arr[j].pt_enroll = (char*)malloc(sizeof(char) * 256);
			strcpy(arr[j].pt_enroll, table.list[i].pt_enroll);
			arr[j].locker = (char*)malloc(sizeof(char) * 256);
			strcpy(arr[j].locker, table.list[i].locker);
			j++;
		}
	}

	for (i = 0; i < j; i++) { //����� ȸ������ ���
		printf("%d %s PT: %s Locker: %s\n", arr[i].ID, arr[i].name, arr[i].pt_enroll, arr[i].locker);
	}

}

// ȸ���� �̸��� �޾Ƽ� list�� ��ȣ(index)�� ��ȯ�ϴ� �Լ�
int member_info::search(char* name)
{
	for (int i = 0; i < cnt; i++)
		if (strcmp(list[i].name, name) == 0)
			return i;
	return -1;
}


// ���ڿ��� delemeter ������ �߶� vector�� ������� �������ִ� �Լ�
std::vector<std::string> split(std::string str, char delimiter) {
	std::vector<std::string> internal;
	std::stringstream ss(str);
	std::string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}
