#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;

//Var and Function declarations
queue<char> unread;
typedef string state;
typedef int rule;
state currentState;
int step;

//applies rules
//parameters: currentState, unread queue and current stack
//changes global currentState and unread and stack according to rule
void applyRules(queue<char> unread, stack<char> stack);


//Shows the queue
//parameter: queue to be printed
void showq(queue<char> gq)
{
    queue<char> g = gq;
    while (!g.empty() && g.front()!=NULL) {
        cout<<g.front()<< " ";
        g.pop();
    }
    cout<< "\t";
}


  void print_stack (stack<char> s)
  {
    // creating a temp stack as to not alter the values in our stack
    stack<char> temp = s;
    while (!s.empty() && s.top() != NULL)
    {
      cout << s.top() << " ";
      s.pop();
    }
    cout<<"\t";
  }

//initializes queue (unread input) to an bn $
//parameter: int n
//returns the initialized queue of form a^n b^n $
queue<char> init_queue(int n);

//find rule function
//parameters: current state - string, unread input - queue, stack - stack
//returns an int (1-8) which corresponds to which rule to use
int find_rule(queue<char> unread, stack<char> stack);

//prints whole line
void printAll(queue<char> toRead, stack<char> readInput, int numStep){
      cout<< numStep<< "\t"<<currentState << "\t";
      showq(toRead);
      print_stack(readInput); 
      int rulePrint = find_rule(toRead, readInput);
      cout <<rulePrint<< "\t";
      int rRule = 0;
      cout <<rRule <<endl;
  }


//currently I have the main just taking in a string and putting it into a char queue
//it prints out everything

int main(){


    //take input as a number n
    int n;
    cout<<"Enter n (>0): ";
    cin>>n;
    if(n>0){
      unread = init_queue(n);
    }

    //initialize step = 0, initial state = p
    step = 0;
    currentState = "p";

    //intializing queue with a's b's
    //toCharQueue(stringIn);

    //creating an empty stack

    stack<char> read;

    //heading to display the process as we go
    cout<< "Step \t" << "State \t" << "Read \t\t" << "Unread \t\t" << "Transition rule \t" << "R rule \n";

    while (unread.empty() == false && step < 9) {
      applyRules(unread, read);
      printAll(unread, read, step);
      step++;

    }



    //for testing purposes
    //delete for final project

}

void applyRules(queue<char> unread, stack<char> read){
    int ruleNum = find_rule(unread, read);
}

//void toCharQueue(char initString[50]){
//    for(int i = 0; i < 50; i++){
//        unread.push(initString[i]);
//    }
//}

queue<char> init_queue(int n)
 {
   queue<char> q;
   for (int i=0; i<n; i++)
     q.push('a');

   for (int i=0; i<n; i++)
     q.push('b');

   q.push('$');

   return q;
 }


int find_rule(queue<char> unread, stack<char> stack)
{

  //row of if statements
  //instead of having another one -- it can still return an int of the rule used (thoughts?)
  //if rule 7 or 8 are used then we need to output the R rule (i.e. S -> aSb)

  // rule 1
  if (currentState == "p")
    return 1;
  
  //rule 2
  else if (currentState == "q" && unread.front() == 'a')
    return 2;
    
  //rule 3
  else if (currentState == "qa" && stack.top() == 'a')
    return 3; 
  //rule 4
  else if (currentState == "q" && unread.front() == 'b')
    return 4;
  //rule 5
  else if (currentState == "qb" && stack.top() == 'b')
    return 5;
  //rule 6
  else if (currentState == "q" && unread.front() == '$')
    return 6;
  //rule 7
  else if (currentState == "qa" && stack.top() == 'S')
    return 7;
  //rule 8
  else if(currentState == "qb" && stack.top() == 'S')
    return 8;
}
