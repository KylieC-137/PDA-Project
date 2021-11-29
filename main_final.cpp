//Group Project
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void ruleApplied1();
void ruleApplied2();
void ruleApplied3();
void ruleApplied4();
void ruleApplied5();
void ruleApplied6();
void ruleApplied7();
void ruleApplied8();

void printStack(stack <char>);

void enter();
string createString(n);

stack <char> unreadInput;
stack <char> topOfStack;

int n;

string input;

int counter = 0;

string state;



int main()
{
  state = "p";
  int step = 0;
  enter();
  input = createString(n);
  
  for (int i = 0; i <input.length(); i++)
  {
    char in = input.at(i);
    unreadInput.push(in);
  }
  
  printStack(unreadInput);
  cout << endl;
  
  cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
  printStack(unreadInput);
  
  cout << " | " << "Stack: e" << " | " << "Rule Used: -" << " | " << "R Used: -" << " | " << endl;
  
  while(!unreadInput.empty())
  {
    if (state == "p")
    {
      ruleApplied1();
      step++;

      cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
      printStack(unreadInput);
      cout << " | " << "Stack: ";
      printStack(topOfStack);
      cout << " | " << "Rule Used: 1" << " | " << "R Used: - " << " | " << endl;
    }

    if(state == "q")
    {
      if(unreadInput.top() == '$')
      {
        ruleApplied6();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        printStack(topOfStack);
        cout << " | " << "Rule Used: 6" << " | " << "R Used: - " << " | " << endl;
      }
      else if(unreadInput.top() == 'b')
      {
        ruleApplied4();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        printStack(topOfStack);
        cout << " | " << "Rule Used: 4" << " | " << "R Used: - " << " | " << endl;
      }
      else
      {
        ruleApplied2();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        printStack(topOfStack);
        cout << " | " << "Rule Used: 2" << " | " << "R Used: - " << " | " << endl;
      }
    }
    if(state == "qa")
    {
      if (topOfStack.top() == 'S')
      {
        ruleApplied7();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        printStack(topOfStack);
        cout << " | " << "Rule Used: 7" << " | " << "R Used: S -> aSb" << " | " << endl;
      }
      else
      {
        ruleApplied3();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        printStack(topOfStack);
        cout << " | " << "Rule Used: 3" << " | " << "R Used: - " << " | " << endl;
      }
    }
    if(state == "qb")
    {
      if (topOfStack.top() == 'S')
      {
        ruleApplied8();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        printStack(topOfStack);
        cout << " | " << "Rule Used: 8" << " | " << "R Used: S -> e" << " | " << endl;
      }
      else
      {
        ruleApplied5();
        step++;
        cout << "Step: " << step << " | " << "State: " << state << " | " << "Unread Input: ";
        printStack(unreadInput);
        cout << " | " << "Stack: ";
        counter = 0;
        printStack(topOfStack);
        cout << " | " << "Rule Used: 5" << " | " << "R Used: - " << " | " << endl;
      }
    }
    }
  return 0;
  }



void enter()
{
  cout << "Please enter 'n' defined by L = {a^n b^n | n >= 0}" << endl;
  cin >> n;
}

string createString(n)
{
  string s;
  
  for (int i = 0; i < n; i++)
    s += "a";
  
  for (int i = 0; i < n; i++)
    s += "b";
  
  s += "$";
  
  return s;
}


void printStack(stack <char> s)
{
  if(s.empty())
  {
    if(counter == 0)
    {
      cout << "e";
      return;
    }
    if(counter != 0)
      return;
  }
  char x = s.top();
  s.pop();
  cout << x << " ";
  counter++;
  printStack(s);
  s.push(x);
}

void ruleApplied1()
{
  state = "q";
  topOfStack.push('S');
  counter=0;
}

void ruleApplied2()
{
  state = "qa";
  counter=0;
  unreadInput.pop();
}

void ruleApplied3()
{
  state = "q";
  counter=0;
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
