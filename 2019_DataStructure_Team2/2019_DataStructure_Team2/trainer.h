class trainer {
public:
	double t_point;
	char* t_name;
	int m_cnt;
	int* m_arr;
};
class atrain {
public:
	void init(void);
	int loading(int);
	void best1(void);
	void quicksort1(int, int, int*);
	void best2(void);
	void quicksort2(int, int, int*);
	void point_update(void);
	void deb(void);
private:
	trainer* arr;
	int t_cnt;
};
double count(int);