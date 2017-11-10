# polyProject

Some pseudo code if anyone wants to use it for their modules. 
Most of these will require create poly to be done similar to my pseudo code


1)Create poly:
Ask user for power and coeffecient of highest power term.
Create a linked list node with these values
Ask user if there is any more terms in polynomial (do with a char or a simple 1/0 for yes and no)
if no 
  create nodes in linked list for all terms down to order of 0 storing 0 as their coeffecient
else
  while user asks for more terms or power of current node is not 0
    ask user for power of term
    if (input power+1) is not equal to power of current term
      while (input power+1) is not equal to power of current term
        make new node with power set to power of (current term-1) with coeffecient of 0
        make current node the new node
    else 
      ask user for coeffecient of polynomial term
      make new node with entered power and coeffecient values
    ask user if there are more terms in polynomials
    
2) Delete poly:
 Use the code from linkedList.c for deleteList
 
3) Add poly:
  Create two variables that store power of first element in both polynomials ((llist name)->head->next->power)
  Make result a copy of the polynomial with higher order term
  while power of result is not equal to power of lower order polynomial
    move to next node in result polynomial.
  while current node is not null
    add coeffecient of result polynomial to coeffecient of lower order polynomial
    move to next node in result and lower order polynomial
    
 4) Subtract polynomial:
  Store power of first element in both polynomials
  If power of first polynomial is bigger
    do as with add poly but in second while loop just subtract the values
  Else 
    Make result a copy of second polynomial
    while power of result is not equal to power of lower order polynomial
      set coeffecient of result polynomial to its negative
      move to next node in result polynomial.
    while current node is not null
      subtract coeffecient of result polynomial from coeffecient of first polynomial
      move to next node in result and first polynomial
      
 5) Print polynomial
  Go to first element in polynomial
  While current node is not Null
    if coeffecient of current node is not 0
      print (coeffecient)x^(power)
      move to next node
    else
      move to next node
      
 6) print order
  Go to first element in polynomial and read power ((llist name)->head->next->power)
  print power of that node
