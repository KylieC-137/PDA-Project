//Group Project
#include <iostream>
#include <string>
#include <stack>
#include <iomanip>
using namespace std;

void ruleApplied1();
void ruleApplied2();
void ruleApplied3();
void ruleApplied4();
void ruleApplied5();
void ruleApplied6();
void ruleApplied7();
void ruleApplied8();

//prints to terminal a stack
void printStack(stack <char>);

//asks user for input "n"
//@post: returns n given by the user, n is >= 0
int enter();

//@pre: n >= 0
//@post: returns an intialized stack (unread input)
stack<char> createStack(int n);


stack <char> unreadInput;

stack <char> topOfStack;

//function that takes care of outputting and formatting the output table
//@parameters: current step, state of the machine, and current rule being used
void printALL(int step, string state, int rule);


string state;



int main()
{
  state = "p";
  int step = 0;

  //asking for user input
  int n = enter();

  //initializing the unread input stack
  unreadInput = createStack(n);


  int rule = -1;
 

  printStack(unreadInput);
  cout << endl;
  
  //table headers
  cout << left << setw(10) << setfill(' ') << "STEP" 
       << left << setw(10) << setfill(' ') << "STATE"
       << left << setw(24) << setfill(' ') << "UNREAD INPUT"
       << left << setw(24) << setfill(' ') << "STACK" 
       << left << setw(10) << setfill(' ') << "RULE" 
       << "RRULE \n";

  //print initial state of machine
  printALL(step, state, rule);
  

  //while loop that will call on functions to apply rules depending on the
  //current state and the top of both the unread input and stack
  while(!unreadInput.empty())
  {
    if (state == "p")
    {
      ruleApplied1();
      step++;
      rule = 1;
    }

    if(state == "q")
    {
      if(unreadInput.top() == '$')
      {
        ruleApplied6();
        step++;
        rule = 6;           
      }
      else if(unreadInput.top() == 'b')
      {
        ruleApplied4();
        step++;
        rule = 4;  
      }
      else
      {
        ruleApplied2();
        step++;
        rule = 2;
      }
    }
    if(state == "qa")
    {
      if (topOfStack.top() == 'S')
      {
        ruleApplied7();
        step++;
        rule = 7;
      }
      else
      {
        ruleApplied3();
        step++;
        rule = 3;
      }
    }
    if(state == "qb")
    {
      if (topOfStack.top() == 'S')
      {
        ruleApplied8();
        step++;
        rule = 8;
      }
      else
      {
        ruleApplied5();
        step++;
        rule = 5;
      }
    }
    printALL(step, state, rule);
  }

  return 0;
}



int enter()
{
  int num;
  do{
      cout << "Please enter 'n' defined by L = {a^n b^n | n >= 0}" << endl;
      cin >> num;
  }while(num<0);

  return num;
}

stack<char> createStack(int n)
{
  stack<char> s;
  
  s.push('$');

  for (int i = 0; i < n; i++)
    s.push('b');
  
  for (int i = 0; i < n; i++)

    s.push('a');
  
  
  return s;
}


void printStack(stack<char> s)
{
    // creating a temp stack as to not alter the values in our stack
    stack<char> temp = s;

    //string to store the stack -> needed to make setw work
    string set;

    while (!s.empty())
    {
      set+= s.top();
      s.pop();
    }

    cout << set;

}

void ruleApplied1()
{
  state = "q";
  topOfStack.push('S');
}

void ruleApplied2()
{
  state = "qa";
  unreadInput.pop();
}

void ruleApplied3()
{
  state = "q";
  topOfStack.pop();
}

void ruleApplied4()
{
  state = "qb";
  unreadInput.pop();
}

void ruleApplied5()
{
  state = "q";
  topOfStack.pop();
}

void ruleApplied6()
{
  state = "q$";
  unreadInput.pop();
}

void ruleApplied7()
{
  state = "qa";
  topOfStack.pop();
  topOfStack.push('b');
  topOfStack.push('S');
  topOfStack.push('a');
}

void ruleApplied8()
{
  state = "qb";
  topOfStack.pop();
}

void printALL(int step, string state, int rule)
{
    char sep = ' ';
    int width1 = 10;
    int width2 = 24;

    //print step and state
    cout << setw(width1) << setfill(sep) << step 
         << setw(width1) << setfill(sep) << state  
         << setw(width2) << setfill(sep);

    //print unread input
    if (!unreadInput.empty())
        printStack(unreadInput);
    else
        cout << "e";

    cout << setw(width2) << setfill(sep);
    
    //print stack
    if (!topOfStack.empty())
        printStack(topOfStack);
    else if (step == 0)
        cout << "-";
    else
        cout << "e";
    
    //print rule used
    cout << setw(width1) << setfill(sep);
    if(rule >=0)
        cout << rule;
    else
        cout << "-";

    //print/determine if rrule was used
    cout << setw(width1) << setfill(sep);
    if (rule == 7)
        cout << "S -> aSb";
    else if (rule == 8)
        cout << "S -> e";
    else
        cout << "-";

    cout << endl;
}
