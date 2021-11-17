# PDA-Project

Language L = {an bn | n >= 0} <br>
generated by context free grammar G = ({a,b,S}, {a,b}, R, S)
&emsp;  where R contains rules S->aSb and S->e <br>
The resulting PDA is <br>
&emsp;  M1 = ({p,q,qa,qb,q$}, {a,b}, {a,b,S}, rules, p, {q$}) <br>
  where rules = <br>
      1 (p,e,e)  -> (q,S) <br>
      2 (q,a,e)  -> (qa,e) <br>
      3 (qa,e,a) -> (q,e) <br>
      4 (q,b,e)  -> (qb,e) <br>
      5 (qb,e,b) -> (q,e) <br>
      6 (q,$,e)  -> (q$,e) <br>
      7 (qa,e,S) -> (qa,aSb) <br>
      8 (qb,e,S) -> (qb,e) <br>

<br>
//using queue because it makes more sense: eg. string aaabbb$ we gonna be putting the "a's" first then the "b's", we will also be
//getting rid of the "a's" first then the "b's" --> queues follow FIFO
using queue for unread input 

//stack because last LIFO
Using stack for new input

Main -> fuction takes 3 inputs -> returns rule used -> apply rule in separate function -> print line
In each rule function 
  If the unread input is empty
  
  While loop condition is unread input is empty
  
  ----------------------------------------------------------------HEADERS------------------------------------------------------------------------
  <br>
  #include <iostream>
  #include <queue>
  
  using namespace std;
  
  ------------------------------------------------------------------FUNCTION DECLARATIONS-------------------------------------------------------
  //asks for n
  //returns n
  int take_input();
  
  //initializes queue (unread input) to an bn $
  //parameter: int n
  //returns the initialized queue
  queue<int> init_queue(int n);
  
  //print the current queue
  //parameter: the unread queue
  void print_queue (queue<int> q);
  

  ---------------------------------------------------------------------MAIN----------------------------------------------------------------------
  Main{
    //take input
    int n;
    n = take_input();
    
    //initialize step = 0, initial state = p
    step = 0;
    state = p;
    
    //intializing queue with a's b's
    queue<int> unread = init_queue(n);
    
    //creating an empty stack
    
    stack s = stack(NULL);
    while(queue != NULL && stack != NULL){
      rule = applyRules(state, read, unread)
    }
  }
  
  
  applyRules(state, read, unread){
      rule = findRules();
      applyrule   
  }
  ------------------------------------------------------------FUNCTION DEFINITIONS--------------------------------------------------------------
  
  int take_input()
  {
    int n;
    
    do {
    cout << "Enter n (n>=0): ";
    cin >> n;
    } while(n<0);
    
    return n;
  }
  
  queue<int> init_queue(int n)
  {
    queue<char> q;
    for (int i=0; i<n; i++)
    {
      q.push('a');
    }
    for (int i=0; i<n; i++)
    {
      q.push('b');
    }
    q.push('$');
  
    return q;
  }
  
  void print_queue (queue<int> q)
  {
    //creating a temp queue = unread_queue, so that our unread_queue stays the same
    queue<int> temp = q;
    while(!temp.empty())
    {
      cout << temp.front() << " ";
      temp.pop();
    }
    // might need to add a "tab" here for formatting the table after the unread queue has been displayed
  }
  
  
  FindRules
  
  ApplyRule1{
    pop
    push 
    set new state
    print line
    step++
  }
  ApplyRule2
  
  
  
  
