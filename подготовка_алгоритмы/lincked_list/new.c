#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TEXT

#ifdef array
void print_array(int*, int);
void add_alement(int*, int, int, int pos);
void do_array(int*, int);
void delete_element(int*, int, int);

int main(){
  int n = 10, pos = 0, k = 0;
  int* array = (int*)calloc(n, sizeof(int));
  do_array(array, n);
  scanf("%d %d", &k, &pos);
  print_array(array, n);
  delete_element(array, n , pos);
  //add_alement(array, n, k, pos - 1);
  print_array(array, n);
  return 0;
}

void print_array(int* array, int n){
  for(int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }
  printf("\n");
}

void add_alement(int* array, int n, int k, int pos){
  for (int i = n - 2; i >= pos && array[i] != 0; i--){
    array[i + 1] = array[i];
  }
  array[pos] = k;
}

void do_array(int* array, int n){
  srand(time(NULL));
  for (int i = 0; i < n - 1; i++){
    array[i] = rand() % 10 + 1;
  }
}

void delete_element(int* array, int n, int pos){
  for (int i = pos - 1; i < n - 1 && array[i] != 0; i++){
    array[i] = array[i + 1];
  }
  if (array[n - 1] != 0);
    array[n-1] = 0;
}
#endif

#ifdef linked_list
struct linked_list{
  int value;
  struct linked_list* next;
};

struct linked_list* head;

struct linked_list* get(int pos){
  struct linked_list *current = head;
  for (int i = 0; i < pos; i++){
    current = current->next;
  }
  return current;
}

void insert(int pos, int value){
  struct linked_list* new_list = malloc(sizeof(struct linked_list));
  new_list->value = value;
  new_list->next = 0;
  if (pos == 0){
    new_list->next = head;
    head = new_list;
  }
  else{
    struct linked_list *prev = get(pos - 1);
    struct linked_list *curr = prev->next;
    new_list->next = curr;
    prev->next = new_list;
  }
}

void delete(int pos){
  if (pos == 0){
    struct linked_list *del = head;
    head = del->next;
    free(del);
  }
  else{
    struct linked_list *prev = get(pos - 1);
    struct linked_list *del = prev->next;
    prev->next = del->next;
    free(del);
  }
}

void delete_everything(){
  struct linked_list *current = head;
  struct linked_list *prev;
  while (current != 0){
    prev = current;
    current = current->next;
    free(prev);
  }
}

void print(){
  struct linked_list *current = head;
  while (current != 0){
    printf("address: %p value: %d\n", current, current->value);
    current = current->next;
  }
}

int main(){
  head = 0;
  insert(0, 1);
  insert(1, 2);
  delete(0);
 
  print(); 
  delete_everything();
  return 0;
}
#endif

#ifdef stack_program
#define n 100000
#define m 100000
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char p;
	int number = 0, i = -1, j = -1, count = -1, max = 0, min = 0;
	int array[n] = { 0 };
	int array_min[m] = { 0 };
	int array_max[m] = { 0 };
	scanf("%c", &p);
	while (p != '5')
	{
		switch (p)
		{
		case '0':
			if (count < n)
			{
				count += 1;
				scanf("%d", &number);
				array[count] = number;
				if ((max <= number) || (i == -1))
				{
					i += 1;
					array_max[i] = count;
					max = number;
				}
				if ((min >= number) || (j == -1))
				{
					j += 1;
					array_min[j] = count;
					min = number;
				}
			}
			else
				printf("Overflow\n");
			break;
		case '1':
			if (count >= 0)
			{
				array[count] = 0;
				if (array_max[i] == count)
				{
					array_max[i] = 0;
					i -= 1;
					if (i >= 0)
						max = array[array_max[i]];
				}
				if (array_min[j] == count)
				{
					array_min[j] = 0;
					j -= 1;
					if (j >= 0)
						min = array[array_min[j]];
				}
				count -= 1;
			}
			else
				printf("Underflow\n");
			break;
		case '2':
			if (count >= 0)
			{
				printf("%d\n", array[count]);
			}
			else
				printf("Stack is empty\n");
			break;
		case '3':
			if (count >= 0)
			{
				printf("%d\n", array[array_max[i]]);
			}
			else
				printf("Stack is empty\n");
			break;
		case '4':
			if (count >= 0)
			{
				printf("%d\n", array[array_min[j]]);
			}
			else
				printf("Stack is empty\n");
			break;
		}
		scanf("%c", &p);
	}
}
#endif

//stack
#ifdef TEXT
#define size 10

int stack[size];
int current = 0;

void push(){
  if (current == size){
    printf("Stack over flow\n");
    return;
  }
  int element = 0;
  scanf("%d", &element);
  stack[current++] = element;
}

void pop(){
  if (current < 0){
    printf("No elements\n");
    return;
  }
  stack[--current] = 0;
}

int main(){
  char number;
  scanf("%c", &number);
  while (number != '0'){
    switch (number){
    case '1':
      push();
      break;
    case '2':
      pop();
    default:
      break;
    }
    scanf("%c", &number);
  }
  for (int i = 0; i < size; i++){
    printf("%d ", stack[i]);
  }
  return 0;
}
#endif