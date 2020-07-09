#include <stdio.h>
#include <stdlib.h>
#include "member.h"


class node {
public:
	int member_ID;
	int nchild;
	node** childs;
	void init();
	void traversal(member_info& table);
	int is_empty();
	int insert_node(node* rnode, int rmember_id);
	void set(int member_id);
	int search(int member_id);
	int get_member_ID();
	int count();
	int max_child();
	int find_max_idx(int idx);
};

typedef node* nptr;

class forest {
	nptr* root;
	int ntree;
	int size;
public:
	void print(member_info& table);
	void init(int max_size);
	void forest_insert(int member_id, int rmember_id);
	int forest_search(int member_id);
	void remove(int idx);
	void count_result(member_info& table);
};
