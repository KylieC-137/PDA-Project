#include <iostream>
#include <iomanip>
#include <string>
#include <stack>
#include <queue>
using namespace std;

//Var and Function declarations
queue<char> unread;
string currentState;
int step;
string rRule;

    //creating an empty read queue

    stack<char> read;

//applies rules
//parameters: currentState, unread queue and current queue
//changes global currentState and unread and queue according to rule
void applyRules();

//Shows the queue
//parameter: queue to be printed
void showq(queue<char> gq)
{
    queue<char> g = gq;
    while (!g.empty() && g.front()!=NULL) {
        cout<<g.front()<< " ";
        g.pop();
    }
    
}


  void print_stack (stack<char> s)
  {
    // creating a temp queue as to not alter the values in our stack
    stack<char> temp = s;
    while (!s.empty() && s.top() != NULL)
    {
      cout << s.top() << " ";
      s.pop();
    }
  }

//initializes queue (unread input) to an bn $
//parameter: int n
//returns the initialized queue of form a^n b^n $
queue<char> init_queue(int n);

//find rule function
//parameters: current state - string, unread input - queue, queue - QUEUE
//returns an int (1-8) which corresponds to which rule to use
int find_rule();

//prints whole line
void printAll(queue<char> toRead, stack<char> readInput, int numStep){
      cout<< numStep<< setw(10) <<currentState <<setw(5);
      showq(toRead);
      if(toRead.empty()){
        cout<<"e ";
        }
        cout<< setw(10);
      print_stack(readInput);
      if(readInput.empty()){
        cout <<"e ";
        }
      int rulePrint = find_rule();
      cout <<setw(10) <<rulePrint;
      cout <<setw(20)<<rRule <<endl;
  }


//currently I have the main just taking in a string and putting it into a char queue
//it prints out everything

int main(){

    rRule = "";
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


    //heading to display the process as we go
    cout<< "Step \t" << "State \t" << "Read \t\t" << "Unread \t\t" << "Transition rule \t" << "R rule \n";

    while (step < 9) {
      printAll(unread, read, step);
      applyRules();
      step++;

    }

    //for testing purposes
    //delete for final project

}

//rules
// 1 (p,e,e) -> (q,S)
// 2 (q,a,e) -> (qa,e)
// 3 (qa,e,a) -> (q,e)
// 4 (q,b,e) -> (qb,e)
// 5 (qb,e,b) -> (q,e)
// 6 (q,$,e) -> (q$,e)
// 7 (qa,e,S) -> (qa,aSb)
// 8 (qb,e,S) -> (qb,e)

void applyRules(){
    
    int ruleNum = find_rule();
    
    if(ruleNum == 1){
        read.push('S');
        currentState = "q";
        rRule = "";
    }
    else if(ruleNum == 2){
        if(!unread.empty()){
            unread.pop();
        }
        currentState = "qa";
        rRule = "";
    }
    else if(ruleNum == 3){
        read.pop();
        currentState = "q";
        rRule = "";
    }
    else if(ruleNum == 4){
        unread.pop();
        currentState = "qb";
        rRule = "";
    }
    else if(ruleNum == 5){
        read.pop();
        currentState = "q";
        rRule = "";
    }
    else if(ruleNum == 6){
        unread.pop();
        currentState = "q$";
        rRule = "";
    }
    else if(ruleNum == 7){
        read.pop();
        read.push('b');
        read.push('S');
        read.push('a');
        currentState = "qa";
        rRule = "S -> aSb";
    }
    else if(ruleNum == 8){
        read.pop();
        currentState = "qb";
        rRule = "S -> e";
    }
    
    
}


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


int find_rule()
{

  //row of if statements
  //instead of having another one -- it can still return an int of the rule used (thoughts?)
  //if rule 7 or 8 are used then we need to output the R rule (i.e. S -> aSb)

  // rule 1
  if (currentState == "p"){
    return 1;
  }
  
  //rule 2
  else if (currentState == "q" && unread.front() == 'a'){
    
    return 2;
  }
  //rule 3
  else if (currentState == "qa" && read.top() == 'a'){
    return 3; 
  }
  //rule 4
  else if (currentState == "q" && unread.front() == 'b'){
    return 4;
  }
  //rule 5
  else if (currentState == "qb" && read.top() == 'b'){
    return 5;
  }
  //rule 6
  else if (currentState == "q" && unread.front() == '$'){
    return 6;
  }
  //rule 7
  else if (currentState == "qa" && read.top() == 'S'){
    return 7;
  }
  //rule 8
  else if(currentState == "qb" && read.top() == 'S'){
    return 8;
  }
  //default

}
