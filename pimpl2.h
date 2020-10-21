citygraph *initgraph()
{
	citygraph *t=(citygraph *)malloc(sizeof(citygraph));
	t->size=0;
	int i;
	for(i=0;i<1000;i++)
	{
		t->a[i]=(listnode *)malloc(sizeof(listnode));
	}
	return t;
}	

int findcity(citygraph *t,int city)
{
	
		if((t->a[city])->element.city_no==city)
			{
				return city;
			}
		
		return -1;
}
void insert(citygraph *t)
{
	int fcity,tcity,dist,ch;
	printf("Enter city no of city to be inserted:");
	scanf("%d",&fcity);
	int k=findcity(t,fcity);
	if(k==-1)
	{
		(t->a[fcity])->element.city_no=fcity;
		(t->a[fcity])->element.distance=0;
		(t->a[fcity])->next=NULL;
		t->size++;
	}	
	printf("\nDo you want to make any connections(1 if yes):");
	scanf("%d",&ch);
	while(ch==1)
	{
	printf("\nEnter the city to which edge has to be made:");
	scanf("%d",&tcity);
	printf("\nEnter distance between them : ");
	scanf("%d",&dist);
	int m=findcity(t,tcity);
	if(m==-1)
	{
		(t->a[tcity])->element.city_no=tcity;
		(t->a[tcity])->element.distance=0;
		(t->a[tcity])->next=NULL;
		t->size++;
	}
	k=findcity(t,fcity);
	listnode *p=(listnode *)malloc(sizeof(listnode));
	p->element.city_no=tcity;
	p->element.distance=dist;
	p->next=(t->a[k])->next;
	(t->a[k])->next=p;
	printf("\nDo you want to make any connections(1 if yes):");
	scanf("%d",&ch);
	}		
}

void delete(citygraph *t,int cityno)
{
	int i,j;
	for(i=0;i<t->size;i++)
	{
		if((t->a[i])->element.city_no==cityno){
			for(j=i;j<t->size-1;j++){
				t->a[j]=t->a[j+1];
			}
			break;
		}
	}
	
	for(i=0;i<t->size;i++){
		listnode *temp=(t->a[i])->next;
		listnode *prev=t->a[i]; 
		while(temp!=NULL){
			if(temp->element.city_no==cityno){
				prev->next=temp->next;
				break;
			}
			prev=temp;
			temp=temp->next;
		}
	}
	
	t->size--;
}

void display(citygraph *t){
	int i;
	for(i=0;i<1000;i++){
		if(i==findcity(t,i)){
			if(((t->a[i])->next)!=NULL){
				printf("\ndistance from %d :",(t->a[i])->element.city_no);
				listnode *temp=(t->a[i])->next;
				while(temp!=NULL){
						printf("(%2d,%3d)",temp->element.city_no,temp->element.distance);
						temp=temp->next;
				}
			}
		}
	}
}

void _initialize(pq *q,int max){
	q->e=malloc(sizeof(node)*max);
	q->capacity=max;
	q->size=0;
	q->e[0].distance=-1;
}

void insert_in_queue(pq *q,node x){
	int i;
	if(q->size==q->capacity){
		printf("MEMORY IS FULL!!!\n");
		return ;
	}
	for(i=++q->size;q->e[i/2].distance>x.distance;i/=2)
		q->e[i]=q->e[i/2];
	q->e[i]=x;
}


node del(pq *q){
	if(q->size==0){
		node y;
		y.distance=INF;
		printf("MEMORY IS EMPTY!!!\n");
		return y;
	}
	int i, child;
	node minelement, lastelement;
	minelement=q->e[1];
	lastelement=q->e[q->size--];
	for(i=1;(i*2)<=q->size;i=child){
		child=i*2;
		if(q->e[child+1].distance < q->e[child].distance)
			child++;
		if(lastelement.distance > q->e[child].distance)
			q->e[i]=q->e[child];
		else
			break;
	}
	q->e[i]=lastelement;
	return minelement;
}

void Djik(citygraph *t, int s){
	int i=0;	
	for(;i<=MAXN; i++)d[i]=INF;	
	d[s] = 0;
	pq q;_initialize(&q, 100);
	node x; x.city_no=s; x.distance=0;
	insert_in_queue(&q,x);//q.push({0, s});
	while ((q.size)) {
		x=del(&q);//q.pop();
		int v=x.city_no;//int v = q.top().second;
		int d_v=x.distance;//int d_v = q.top().first;

		if (d_v != d[v])
		    continue;
		
		listnode *temp=(t->a[v])->next;
		while(temp!=NULL){
			int to=temp->element.city_no;//int to = edge.first;
	   	 	int len=temp->element.distance;//int len = edge.second;	
			if (d[v] + len < d[to]) {
				d[to] = d[v] + len;
				x.city_no=to; x.distance=d[to];//q.push({d[to], to});
				insert_in_queue(&q,x);
				//p[to] = v;
			}	
			temp=temp->next;
		}
		
	}
	
}	


