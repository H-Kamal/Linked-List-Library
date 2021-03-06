#include <iostream>
using namespace std;

struct list{
  int data_item;
  struct list* ptr;
};

struct list* list_make_cell(int data_item, struct list* tail);
struct list* list_cons(int data_item, struct list* tail);
int list_car(struct list* lst);
int list_get_data_item(struct list* lst);
struct list* list_get_next_cell(struct list* lst);
struct list* list_cdr(struct list* lst);
int list_get_nth_item(struct list* lst, int index);
void list_set_nth_item(struct list* lst, int index, int new_value);
int list_length(struct list* lst);



int main()
{
  /***TESTING***/
  /*
  //Test list_make_cell func. Does it make new cell and put 10 in it
  //Need a base cell first
  list* tail = new list;
  tail->ptr = NULL;
  list* head = list_make_cell(10,tail);

  */

  // ~~~~~~~MAKING A LINKED LIST MAUALLY ~~~~~~~ //
  list* cell;
  list* temp;
  list* head;
  //1st cell
  //Creates a new cell
  cell = new list;
  cell->data_item = 1;
  //makes its ptr to NUll
  cell->ptr = NULL;
  //Point both temp and head to the same cell
  head=cell;
  temp=cell;
  //2nd cell
  //This creates a new "list" and has cell point to it.
  cell = new list;
  //makes the head point to new list
  head = cell;
  //temp still points to last cell/list. therefore, have ptr of new
  //cell point in same place as it.
  head->ptr = temp;
  head->data_item = 2;
  //move the temp to the head so you can repeat the process
  temp = head;
  //3rd cell
  cell = new list;
  head=cell;
  head->ptr = temp;
  head->data_item=3;
  temp = head;

  //Testing list_get_item ****WORKS WITH LARGER LIST AS WELL****
  cout << list_get_data_item(head) <<" is the data at the head" << endl;

  //Testing list_get_data_item *WORKS*
  cout << list_get_data_item(head) << endl;

  //Testing list_get_next_cell *WORKS*
  list* dataPTR = list_get_next_cell(head);
  int data = dataPTR->data_item;
  cout << data << " - list_get_next_cell test" << endl;

  //Testing get nth item *WORKS*
  cout << list_get_nth_item(head, 2) << endl;

  //Testing list_SET_nth_item *WORKS*
  list_set_nth_item(head, 2, 10);
  cout << list_get_nth_item(head, 2) << endl;

  //Testing this new linked list's listlength *WORKS*
  cout << list_length(head) << " is the length" << endl;

  return 0;
}

struct list* list_make_cell(int data_item,struct list* tail){
  //The tail is the "head" a preexisting list.
  //Just need to attach ptr of new cell to the tail which acts as the head of
  //the existing list.
  // cell--> [ | ] ptr-----> tail -> [ | ] ->[ | ] -> [ | ]

  //Creating a new cell/list
  list* cell = new list;
  //Populates the new cell's data
  cell->data_item = data_item;
  //Takes the new cell's ptr and points it to same loc as tail which is old cell
  cell->ptr = tail;

  //Moves tail forward to newest cell so you can use this function again
  //POSSIBLY NOT NEEDED
  tail = cell;

  //Returns this so you can then point to it later AS the tail
  //Note how cell essentially works as the head
  return cell;
}

//Function that takes pointer to struct lst and returns the value inside
int list_get_data_item(struct list* lst){
  int item = lst->data_item;
  return item;
}
//Used to traverse the list so just need to find the one older cell
struct list* list_get_next_cell(struct list* lst){
  list* older = lst->ptr;
  return older;
}
//Used to find the data item of a specific list
//index starts from newest cell (head) = 0;
int list_get_nth_item(struct list* lst, int index){
  int i = 0;
  list* temp;
  for(i=0; i < index; i++)
  {
    //Checking if the next even exists by using an if
    //if(lst->ptr)
    //{
      //Leads to temp pointing one ahead of lst
      //Repeated leads to moving down as loc of lst changes
      temp = lst->ptr;
      //lst changes as it points to the same loc as its ptr. (next cell)
      lst = lst->ptr;
    //}
  }
  int nth_item = lst->data_item;
  return nth_item;
}
//Sets the data_item of specific cell
void list_set_nth_item(struct list* lst, int index, int new_value){
  //Note i starts at 1 as natural counting start from there
  int i = 0;
  list* temp;
  for(i=0; i < index; i++)
  {
    //Checking if the next even exists by using an if
    if(lst->ptr)
    {
      //Leads to temp pointing one ahead of lst
      //Repeated leads to moving down as loc of lst changes
      temp = lst->ptr;
      //lst changes as it points to the same loc as its ptr. (next cell)
      lst = lst->ptr;
    }
  }
  lst->data_item = new_value;
}

int list_length(struct list* lst){
  int i = 1;
  list* temp;
  while(lst->ptr != NULL)
  {
    //Leads to temp pointing one ahead of lst
    //Repeated leads to moving down as loc of lst changes
    temp = lst->ptr;
    //lst changes as it points to the same loc as its ptr. (next cell)
    lst = lst->ptr;
    //Counting loops
    i++;
  }
  return i;
}

struct list* list_cons(int data_item, struct list* tail){
  //The tail is the "head" a preexisting list.
  //Just need to attach ptr of new cell to the tail which acts as the head of
  //the existing list.
  // cell--> [ | ] ptr-----> tail -> [ | ] ->[ | ] -> [ | ]

  //Creating a new cell/list
  list* cell = new list;
  //Populates the new cell's data
  cell->data_item = data_item;
  //Takes the new cell's ptr and points it to same loc as tail which is old cell
  cell->ptr = tail;

  //Moves tail forward to newest cell so you can use this function again
  //POSSIBLY NOT NEEDED
  tail = cell;

  //Returns this so you can then point to it later AS the tail
  //Note how cell essentially works as the head
  return cell;
}

int list_car(struct list* lst){
  int item = lst->data_item;
  return item;
}

struct list* list_cdr(struct list* lst){
  list* older = lst->ptr;
  return older;
}
