#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include "pif2.h"
#include "pimpl2.h"

void main()
{
	citygraph *t=initgraph();
	int ch;
	do{
		printf("\n      ~~~~MENU:\n1. Display\n2. Insert\n3. Delete\n4. Dijkstras\n5. Exit\n~~~~~~~~~~~~~\nEnter your choice: ");
		
		scanf("%d",&ch);
		if(ch==2){
			insert(t);
		}
		if(ch==1){
			display(t);
		}
		if(ch==3){
			int cityno;
			printf("Enter city no to be deleted");
			scanf("%d",&cityno);
			delete(t,cityno);
		}
		if(ch==4){
			int i;
			int s;
			printf("Enter the source vertex: ");
			scanf("%d", &s);
			Djik(t, s);
			printf("\nSOURCE->VERTEX\tDISTANCE\n");
			for(i=1; i<=MAXN; i++){
				if(d[i]!=INF)
					printf("   %d->%d\t\t %d\n", s,i,d[i]);
			}

		}
		printf("\n\n");

	}while(ch!=5);
}
