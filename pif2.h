const int INF = 1e+9;
const int MAXN= 1e+5;
int d[100000];//d[MAXN]

typedef struct {
	int city_no;
	int distance;
}node;

typedef struct {
	int capacity;
	int size;
	node *e;
}pq;

struct listnode{
	node element;
	struct listnode *next;
};
typedef struct listnode listnode;

typedef struct{
	int size;
	listnode *a[1000];
}citygraph;

void _initialize(pq *q,int max);
void insert_in_pq(pq *q,node e);
node del(pq *q);
citygraph *initgraph();
void insert(citygraph *t);
void delete(citygraph *t,int cityno);
void display(citygraph *t);
