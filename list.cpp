#include "list.h"
#include <iostream>
#include <sstream>

void List::insert(int const number)
{ //Med dubbelpekare krävs ingen abstrakterande hjälpfunktion
    Node **tracer{&head};
    Node *nodeptr{new Node{number, nullptr}}; //Pekaren till noden som ska insättas
    while ((*tracer) && (*tracer)->value < number){ //Iterera fram tills tracern inte längre pekar på en nod med större värde
        tracer = &(*tracer)->next;

    
        
    }
    nodeptr->next = *tracer;
    *tracer = nodeptr;
    length++;
}



void List::remove(int const number)  //Tar ett värde som input
{
    Node **tracer{&head}; 
    Node *to_remove{};
    while ((*tracer) && (*tracer)->value != number){ //Iterera fram tills tracern inte längre pekar på en nod med större värde
        tracer = &(*tracer)->next;
}
   to_remove = *tracer;
   *tracer = (*tracer) -> next;
   delete(to_remove);
   to_remove = nullptr;
}

void List::destruct(){
    if (!head){
        return;
    }
    remove((head)->value);
    destruct();
}

std::string List::stringify()
{
   
	Node **tracer{&head};
    std::string str{"["};
	while ((*tracer) -> next) {
		str += std::to_string((*tracer)->value) + ", ";
		tracer = &(*tracer)->next;
	}
    return str + std::to_string((*tracer)->value) + "]";
}

// List::List(const List& to_copy)
//{
//     ;
// }

bool List::is_empty()
{
    return (length == 0);
}

bool List::contains(int val)
{
    return (index_of(val) != -1);
}

int List::index_of(int const val)
{
    int iterations{0};
    Node *current{head};
    while (current != nullptr)
    {
        if (current->value > val)
        {
            break;
        }
        else if (current->value == val)
        {
            return iterations;
        }
        current = current->next;
        iterations++;
    }
    return -1;
}

int List::get(int const i)
{
    if (i >= length)
    {
        throw std::invalid_argument("List index out of range");
    }
    Node *current{head};
    for (int k{0}; k < i; k++)
    {
        current = current->next;
    }
    return current->value;
}

int main()
{
    List testat;
     testat.insert(10);
    testat.insert(12);
    testat.insert(15);
    testat.insert(5);
    testat.remove(12);
    testat.insert(6);
    testat.insert(8);
    
    std::cout << testat.is_empty() << std::endl;
    std::cout << "length: " << testat.length << std::endl;
    std::cout << testat.stringify() << std::endl;
    std::cout << testat.index_of(12) << std::endl;
    std::cout << "...: " << std::endl;
    testat.destruct();
    std::cout << testat.is_empty() << std::endl;
    /*
    std::cout << std::endl;

    testat.insert(5);
    testat.insert(6);
    testat.insert(8);
    std::cout << testat.stringify() << std::endl;
    std::cout << "index of 8: " << testat.index_of(8) << std::endl;
    std::cout << "length: " << testat.length << std::endl;
    std::cout << "contains 6: " << testat.contains(6) << std::endl;
    std::cout << "contains 100: " << testat.contains(100) << std::endl;

    std::cout << testat.get(2) << std::endl;

    


    std::cout << testat.stringify() << std::endl;
    testat.insert(10);
    testat.insert(12);
    testat.insert(15);


    testat.insert(9);
    std::cout << testat.stringify() << std::endl;
    std::cout << testat.index_of(9) << std::endl;*/
}