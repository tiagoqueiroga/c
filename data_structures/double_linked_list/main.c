#include <stdio.h>
#include <stdlib.h>


struct d_link_list {
  int data;
  struct d_link_list *prev;
  struct d_link_list *next;
};

int main() {

  struct d_link_list *d1,*d2,*d3,*d4;
  
  d1 = malloc(sizeof(struct d_link_list));
  d2 = malloc(sizeof(struct d_link_list));
  d3 = malloc(sizeof(struct d_link_list));
  d4 = malloc(sizeof(struct d_link_list));

  d1->data = 22;
  d2->data = 332;
  d3->data = 1;
  d4->data = 54;


  d1->prev = NULL;
  d1->next = d2;
 
  d2->prev = d1;
  d2->next = d3;

  d3->prev = d2;
  d3->next = d4;

  d4->prev = d3;
  d4->next = NULL;  


  printf("d3[prev]:%d\n",d3->prev->data);
  printf("d3[data]:%d\n",d3->data);
  printf("d3[next]:%d\n",d3->next->data);


  free(d1);
  free(d2);
  free(d3);
  free(d4);

  return 0;
}
