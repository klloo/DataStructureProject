#include "forest.h"
#include "member.h"
#include <stdio.h>
#include <stdlib.h>

void forest::init(int max_size)
{
	ntree = 0;
	size = max_size;
	root = (nptr*)calloc(size, sizeof(nptr));
}
void forest::forest_insert(int member_id, int rmember_id)
{
	//��õ���̶� ���̸��̶� ������ �ȵ�
	if (member_id == rmember_id) {
		printf("data error\n");
		return;
	}
	//�� �ؿ� ���� ��õ�� ����� ������ ���� �ȵ�
	int idx = forest_search(member_id);
	if (idx != -1 && root[idx]->search(rmember_id)) {
		printf("data error\n");
		return;
	}
	for (int i = 0; i < ntree; i++) {
		//��Ʈ�� �ƴѵ� ��Ʈ�� ��� -1�� �޾Ҵµ� Ʈ�� �ȿ� ������ ���ķ��ä� ��������?
		if (idx == -1 && root[i]->search(member_id)) {
			printf("data error\n");
			return;
		}
		if (root[i]->search(rmember_id)) {
			//���� ��Ʈ�̰� ���� �ٸ� ���ϵ尡 �ִµ� ���� ��õ���� �ٸ�Ʈ���� ���ϵ�� ���ִ� ��Ȳ

			if (idx != -1) {
				root[i]->insert_node(root[idx], rmember_id);
				remove(idx);
				return;
			}

			node* temp = (node*)malloc(sizeof(node));
			temp->set(member_id);
			root[i]->insert_node(temp, rmember_id);
			return;
		}
	}
	//���� ��Ʈ�ε� ���� ��õ�� ����� ���� ���� �� ������ ���ߵ�
	if (idx != -1) {
		root[ntree] = (nptr)malloc(sizeof(node)); //���ο� ��Ʈ �����
		root[ntree]->set(rmember_id); //��õ���̸� �����ϰ�
		root[ntree++]->insert_node(root[idx], rmember_id); //��Ʈ�� �� �ֱ�
		this->remove(idx); //�ε��� �ϳ��� �մ�ܼ� �� ����
		return;
	}
	root[ntree] = (nptr)malloc(sizeof(node));
	root[ntree]->init();
	node* temp = (node*)malloc(sizeof(node));
	temp->set(member_id);
	if (root[ntree]->insert_node(temp, rmember_id))
		ntree++;
}
void forest::print(member_info& table)
{
	for (int i = 0; i < ntree; i++) {
		printf("root %d : %s\n", i, table.list[root[i]->get_member_ID()].name);
		root[i]->traversal(table);
	}
}
int forest::forest_search(int member_id)
{
	for (int i = 0; i < ntree; i++)
		if (root[i]->get_member_ID() == member_id)
			return i;
	return -1;
}
void forest::remove(int idx)
{
	for (int j = idx + 1; j < ntree; j++)
		root[j - 1] = root[j];
	ntree--;
}
void forest::count_result(member_info& table)
{
	int max_root = 0, max_root_idx = 0;
	int max_node = 0, max_node_idx = 0;
	for (int i = 0; i < ntree; i++) {
		if (max_root < root[i]->count()) {
			max_root = root[i]->count();
			max_root_idx = i;
		}
		if (max_node < root[i]->max_child()) {
			max_node = root[i]->max_child();
			max_node_idx = i;
		}
	}
	max_node_idx = root[max_node_idx]->find_max_idx(max_node);
	max_root_idx = root[max_root_idx]->get_member_ID();
	printf("%s", table.list[max_root_idx].name);
	std::locale::global(std::locale("korean"));
	printf(" ȸ���� %d���� ȸ���� �����Ͽ� �ｺ�忡 ���� ū �⿩�� �Ͽ����ϴ�.\n", max_root);
	std::locale::global(std::locale("ko_KR.UTF-8"));
	printf("%s", table.list[max_node_idx].name);
	std::locale::global(std::locale("korean"));
	printf(" ȸ���� %d���� ȸ���� ��õ�Ͽ� ���� ���� ȸ���� ��õ�Ͽ����ϴ�.\n", max_node);
}

void node::init()
{
	member_ID = -1;
	nchild = 0;
	childs = childs = (nptr*)calloc(300, sizeof(nptr));
}
void node::traversal(member_info& table)
{
	printf("[ %s ] ", table.list[member_ID].name);
	for (int i = 0; i < nchild; i++)
		printf("%s ", table.list[childs[i]->member_ID].name);
	printf("\n");
	for (int i = 0; i < nchild; i++)
		childs[i]->traversal(table);
}
int node::is_empty()
{
	return member_ID == -1;
}
int node::insert_node(node* rnode, int rmember_id)
{
	//��Ʈ��忡 ����
	if (this->member_ID == -1) {
		this->member_ID = rmember_id;
		childs[nchild] = (nptr)malloc(sizeof(node));
		this->childs[nchild] = rnode;
		this->nchild++;
		return 1;
	}
	if (rmember_id == this->member_ID) {
		childs[nchild] = (nptr)malloc(sizeof(node));
		this->childs[nchild] = rnode;
		this->nchild++;
		return 1;
	}
	for (int i = 0; i < nchild; i++) {
		if (childs[i]->insert_node(rnode, rmember_id))
			return 1;
	}
	return 0;
}
void node::set(int member_id)
{
	member_ID = member_id;
	nchild = 0;
	childs = (nptr*)calloc(300, sizeof(nptr));
}

int node::search(int member_id)
{
	if (this->member_ID == member_id)
		return 1;
	for (int i = 0; i < nchild; i++)
		if (childs[i]->get_member_ID() == member_id)
			return 1;
	for (int i = 0; i < nchild; i++)
		if (childs[i]->search(member_id))
			return 1;
	return 0;
}
int node::get_member_ID()
{
	return member_ID;
}
int node::count()
{
	int cnt = nchild;
	for (int i = 0; i < nchild; i++)
		cnt += childs[i]->count();
	return cnt;
}
int node::max_child()
{
	int max_child = nchild;
	for (int i = 0; i < nchild; i++)
		if (max_child < childs[i]->max_child())
			max_child = childs[i]->max_child();
	return max_child;
}
int node::find_max_idx(int max_nchild)
{
	if (nchild == max_nchild)
		return member_ID;
	for (int i = 0; i < nchild; i++)
		if (childs[i]->nchild == max_nchild)
			return childs[i]->get_member_ID();
	for (int i = 0; i < nchild; i++)
		childs[i]->find_max_idx(max_nchild);
}

void most_recommender(member_info& table)
{
	forest forest;
	forest.init(table.cnt);
	int mm, rm;
	for (int i = 0; i < table.cnt; i++) {
		mm = i;
		rm = table.search(table.list[i].recommender);
		if (rm != -1)
			forest.forest_insert(mm, rm);
	}
	forest.count_result(table);
}