#include "utils.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

typedef struct node {
    int data;
    struct node* next;
}node;

typedef struct list {
    int size;
    node* head;
    node* tail;
}list;

void list_insert(list* plist, int idx) {
    node* temp = new node;
    temp->data = plist->size;
    temp->next = NULL;

    node* cur = plist->head;

    if (plist->head == NULL) {
        plist->head = temp;
        plist->tail = temp;
    } //when plist is empty
    else if (idx == 0) {
        temp->next = plist->head;
        plist->head = temp;
    }
    else {
        for (int i = 0; i < idx - 1; i++) {
            cur = cur->next;
        }
        temp->next = cur->next;
        cur->next = temp;
        if (idx == plist->size) plist->tail = plist->tail->next;
    }
    plist->size++;
    return;
}

void list_delete(list* plist, int idx) {
    node* cur = plist->head;
    if (idx == 0) {
        plist->head = plist->head->next;
    }
    for (int i = 0; i < idx - 1; i++) {
        cur = cur->next;
    }
    cur->next = cur->next->next;
    plist->size--;
    return;
}
 
typedef struct stack {
    int size;
    node* top;
}stack;

void stack_push(stack* s, int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = s->top;
    s->top = temp;
    s->size++;
    return;
}

void stack_pop(stack* s) {
    s->top = s->top->next;
    s->size--;
    return;
}

void stack_top(stack* s) {
    if (s->size == 0) {
        std::cout << -1 << std::endl;
    }
    else {
        std::cout << s->top->data << std::endl;
    }
    return;
}

typedef struct queue {
    int size;
    node* front;
    node* rear;
}queue;

void q_enqueue(queue* q, int data) {
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;

    if (q->size == 0) {
        q->front = temp;
        q->rear = temp;
        q->size++;
    }
    else {
        q->rear->next = temp;
        q->rear = temp;
        q->size++;
    }
    return;
}

void q_dequeue(queue* q) {
    q->front = q->front->next;
    q->size--;
    return;
}

typedef struct circular_queue {
    int size;
    node* front;
    node* rear;
}c_queue;

void cq_enqueue(c_queue* cq, int data) {
    node* temp = new node;

    temp->data = data;
    temp->next = NULL;
    
    if (cq->size == 0) {
        cq->front = temp;
        cq->rear = temp;
        cq->size++;
    }
    else if (cq->size < 4) {
        cq->rear->next = temp;
        cq->rear = temp;
        cq->size++;
    }
    return;
}

void cq_dequeue(c_queue* cq) {

    cq->front = cq->front->next;
    cq->size--;
    return;
}



/* 
    [Task 1] Choose the TIGHT bound of the following arraySum function
    
    *arraySum*
        Input
        - int n: the length of the input arrays (n >=1)
        - int* A: an array storing n >= 1 integers
        Output
        - int: Sum of given array A
	int arraySum(int n, int* A) {
	    int currSum = 0;
	    for (int i = 0; i < n; i++)
	        currSum += A[i];
	    return currSum;
	}


    Choices
        1: O( 1 )
        2: O( n )
        3: O( n log(n) )
        4: O( n^2 )
*/
void task_1(ofstream &fout) {
    int answer = 2;  // TODO: Change to your answer

    fout << "[Task 1]" << endl;
    fout << answer << endl;

    return;
}

/*
    [Task 2] Choose the TIGHT bound of the following primeSearch function

    *primeSearch*
        Input
        - int n: input number for ending range
        Output
        - int numPrimes: The total number of prime numbers less than n
	int primeSearch(int n) {
	    int numPrimes = 0;
	    int ctr = 0;
	    for (int i = 0; i < n; i++) {
	        for(int j = 2; j <= sqrt(i); j++) {
	            if(i % j == 0) {
			ctr++;
			break;
	            }
	        }
		if(ctr == 0 && i > 1)
	            numPrimes++;
	        ctr=0;
	    }
	    return numPrimes;
	}


    Choices
        1: O( log(n) )
        2: O( n log(n) )
        3: O( n^(1/2) )
        4: O( n*n^(1/2) )
*/
void task_2(ofstream &fout) {
    int answer = 4;  // TODO: Change to your answer

    fout << "[Task 2]" << endl;
    fout << answer << endl;

    return;
}

/*
    [Task 3] List

    Description:
        Implement a function that can insert or delete an integer into the list.
        An user can insert or delete an element at the specific index.
        If the specified index is out of range of the given list, print “error”.

    Input:
        Sequence of commands, which is one of the following
        - (‘insert’,index): insert “# of elements in the current list” at the
   index in the list. index indicates zero-based index.
        - (‘delete’,index): delete an element at the index in the list. index
   indicates zero-based index.

    Output:
        - An array after insertion/deletion in a string separated with the
   spacebar
        - “error” if the index is out of range
*/

void task_3(ofstream &fout, InstructionSequence *instr_seq) {
  string answer = "";
  list ilist;
  ilist.size = 0;
  ilist.head = NULL;
  ilist.tail = NULL;
  
  int data = 0;
  
  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    if (command.compare("insert") == 0) {
      data = instr_seq->instructions[i].value;
      if (data > ilist.size || data < 0) answer = "error";
      else {
        list_insert(&ilist, data);
      }

    } else if (command.compare("delete") == 0) {
      data = instr_seq->instructions[i].value;
      if (data > ilist.size - 1 || data < 0) answer = "error";
      else {
        list_delete(&ilist, data);
      }

    } else {
      cerr << "Invalid command" << endl;
      exit(-1);
    }
  }
  if (answer != "error") {
    node* cur = ilist.head;
    for (int i = 0; i < ilist.size; i++) {
      answer.append(to_string(cur->data));
      if (cur != ilist.tail) answer.append(" ");
      cur = cur->next;
    }
  }

  fout << "[Task 3]" << endl;
  fout << answer << endl;
}

/*
    [Task 4] Stack

    Description:
        Implement a function that prints the top values of the stack when “top”
   operation is called after the sequence of “push” or “pop” operations. If the
   stack is empty, and the “top” operation is called, then print “-1”, If “pop”
   operation from the empty stack then print “error”

    Input:
        Sequence of commands, which is one of the following,
        - (‘push’,integer): push integer into the current stack (integer is
   always positive)
        - (‘pop’,NULL): pop the top value of the current stack (this operation
   will print nothing)
        - (‘top’,NULL): print the top value of the current stack (print ‘-1’ if
   the current stack is empty)

    Output:
        - Expected printed values after processing the whole sequence, in a
   string separated with the spacebar
        - “error” if the pop operation is executed on an empty stack
*/

void task_4(ofstream &fout, InstructionSequence *instr_seq) {
  string answer="";
  stack istack;
  istack.size = 0;
  istack.top = NULL;

  int data = 0;
  
  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    if (command.compare("push") == 0) {
      data = instr_seq->instructions[i].value;
      stack_push(&istack, data);

    } else if (command.compare("pop") == 0) {
      if (istack.size == 0) answer = "error";
      else {
        stack_pop(&istack);
      }

    } else if (command.compare("top") == 0) {
      if (answer != "error") {
        if (istack.size == 0) answer.append("-1");
        else {
          answer.append(to_string(istack.top->data));
        }
        if (i != instr_seq->length - 1) answer.append(" ");
      }

    } else {
      cerr << "Invalid command" << endl;
      exit(-1);
    }
  }

  fout << "[Task 4]" << endl;
  fout << answer << endl;
}

/*
    [Task 5] Queue

    Description:
        Implement a function which shows the value of a queue after the sequence
   of arbitrary queue operation. If the queue after the operations is empty,
   print “empty”. If “dequeue” operates on an empty queue, print “error”.

    Input:
        Sequence of commands, which is one of the following,
        - (‘enqueue’,integer): enqueue integer into the current queue
        - (‘dequeue’,NULL): dequeue from the current queue

    Output
        - Values in the queue from the head to the tail, in a string separated
   with spacebar
        - “empty” if the queue is empty
        - “error” if the “dequeue” operation is executed on an empty queue
*/

void task_5(ofstream &fout, InstructionSequence *instr_seq) {
  string answer = "";
  queue iqueue;
  iqueue.size = 0;
  iqueue.front = NULL;
  iqueue.rear = NULL;

  int data = 0;

  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    //int value = instr_seq->instructions[i].value;

    if (command.compare("enqueue") == 0) {
      data = instr_seq->instructions[i].value;
      q_enqueue(&iqueue, data);
      
    } else if (command.compare("dequeue") == 0) {
      if (iqueue.size == 0) answer = "error";
      else {
        q_dequeue(&iqueue);
      }
      
    } else {
      cerr << "Invalid command" << endl;
      exit(-1);
    }
  }

  if (answer != "error") {
    if (iqueue.size == 0) answer = "empty";
    else {
      node* cur = iqueue.front;
      for (int i = 0; i < iqueue.size; i++) {
        answer.append(to_string(cur->data));
        if (cur != iqueue.rear) answer.append(" ");
        cur = cur->next;
      }
    }
  }

  fout << "[Task 5]" << endl;
  fout << answer << endl;
}

/*
    [Task 6] Circular Queue

    Description:
        - a.	Implement a function which shows the value in the circular queue
   from the head to tale. If “enqueue” operates on full or “dequeue” operates
   on an empty queue, no change would happen.

    Input:
        Sequence of commands, which is one of the following,
        -(‘enqueue’,integer): enqueue integer into the current queue
        -(‘dequeue’,NULL): dequeue integer into the current queue

    Output:
        - Values in the queue from the head to the tail, in a size of 4.
   string separated with the spacebar, empy memory shows NULL -	No
   pointer movement if dequeue on empty, enqueue on full queue

*/

void task_6(ofstream &fout, InstructionSequence *instr_seq) {
  string answer = "";
  int queue_size = 4;
  c_queue cq;
  cq.size = 0;
  cq.front = NULL;
  cq.rear = NULL;

  int data = 0;

  for (int i = 0; i < instr_seq->length; i++) {
    string command = instr_seq->instructions[i].command;
    if (command.compare("enqueue") == 0) {
      if (cq.size < 4) {
        data = instr_seq->instructions[i].value;
        cq_enqueue(&cq, data);
      }

    } else if (command.compare("dequeue") == 0) {
      if (cq.size == 0) answer = "error";
      else {
        cq_dequeue(&cq);
      }

    } else {
      cerr << "Invalid command" << endl;
      exit(-1);
    }
  }

  if (answer != "error") {
    node* cur = cq.front;
    for (int i = 0; i < cq.size; i++) {
      answer.append(to_string(cur->data));
      if (cur != cq.rear) answer.append(" ");
      cur = cur->next;
    }   
  }

  fout << "[Task 6]" << endl;
  fout << answer << endl;
}

int main(int argc, char **argv) {
  string filename = "submit.txt";
  int task_num = 0;
  InstructionSequence *instr_seq;

  // Open file
  ofstream fout;
  fout.open(filename, fstream::app);
  if (!fout.is_open()) {
    cerr << "Unable to open file: " << filename << endl;
    return -1;
  }

  // Choosing task number. Default is running ALL tasks (0)
  if (argc >= 2)
    task_num = atoi(argv[1]);
  if (argc >= 3) {
    try {
      instr_seq = ParseInstructions(argv[2]);
    } catch (const char *e) {
      cerr << e << endl;
      return -1;
    }
  }

  // Running the task(s)
  switch (task_num) {
  case 1:
    task_1(fout);
    break;
  case 2:
    task_2(fout);
    break;
  case 3:
    task_3(fout, instr_seq);
    break;
  case 4:
    task_4(fout, instr_seq);
    break;
  case 5:
    task_5(fout, instr_seq);
    break;
  case 6:
    task_6(fout, instr_seq);
    break;
  case 0:
    task_1(fout);

    task_2(fout);

    InstructionSequence *instr_seq_3;
    instr_seq_3 = ParseInstructions(TASK_3_DEFAULT_ARGUMENT);
    task_3(fout, instr_seq_3);

    InstructionSequence *instr_seq_4;
    instr_seq_4 = ParseInstructions(TASK_4_DEFAULT_ARGUMENT);
    task_4(fout, instr_seq_4);

    InstructionSequence *instr_seq_5;
    instr_seq_5 = ParseInstructions(TASK_5_DEFAULT_ARGUMENT);
    task_5(fout, instr_seq_5);

    InstructionSequence *instr_seq_6;
    instr_seq_6 = ParseInstructions(TASK_6_DEFAULT_ARGUMENT);
    task_6(fout, instr_seq_6);
    break;
  default:
    cout << "Wrong task number" << endl;
  }

  fout.close();
  return 0;
}

