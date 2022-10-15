#include "list.h"
#include <iostream>
#include <sstream>
//::

void List::insert_next(Node *current, Node *input)
{
    // TODO: Avstöka
    if (current->next == nullptr) // Om nuvarande nod är den sista
    {
        current->next = input; // Sätt nästa element till input-pekaren, länk skapas
        input->next = nullptr; // Inputens nästa blir då "svansen"
        return;
    }

    else if (current->next->value >= input->value)
    // Om
    {
        std::cout << "debug: " << input->next << std::endl;
        input->next = current->next; // [a]input[] => [a]ins[next]
        std::cout << "debug:" << input->next << std::endl;
        current->next = input; // []current
        return;
    }

    else
    {
        insert_next(current->next, input); // Upprepa jämförelsen med nästa tal i listan
        std::cout << "hopp" << std::endl;
    }
}

void List::insert(int input_value)
{
    // Funktionen som användaren ser, för att dölja den inre strukruren i noderna
    Node *temp_node{new Node{input_value, nullptr}};
    // Eftersom vår lista kommer ha obestämd storlek så vill vi inte skapa våra noder på stack
    // new gör så att noden skapas i heap, vilket medför att den måste manuellt avallokeras(?)
    if (head == nullptr)
    {
        head = temp_node;
    }
    else if (input_value < head->value)
    {
        temp_node->next = head;
        head = temp_node;
    }
    else
    {
        insert_next(head, temp_node);
        // För alla andra fall måste vi ha tillgång till nodstrukturen
        // Därför skickar vi vidare noden till den privata funktionen.
    }
}

std::string List::stringify()
{
    Node *current{head};
    std::string output{"["};
    if (is_empty())
    {
        return (output + "]");
    }
    output += std::to_string(current->value);
    while (current->next != nullptr)
    {
        output += " -> ";
        output += std::to_string(current->next->value);
        current = current->next;
    }
    return (output + "]");
}

bool List::is_empty()
{
    if (head == nullptr)
    {
        return true;
    }
    return false;
}

int main()
{
    List testat;
    std::cout << testat.is_empty() << std::endl;
    std::cout << testat.stringify() << std::endl;
    testat.insert(5);
    std::cout << testat.stringify() << std::endl;
    testat.insert(10);
    testat.insert(9);
    std::cout << testat.stringify() << std::endl;
}