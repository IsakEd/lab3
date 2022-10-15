#include <sstream>

class List
{
private:
    struct Node
    {
        int value;
        Node *next; // Pekare till det länkade elementet
    };

    void insert_next(Node *current, Node *insert); // Lägg till i listan
    Node *head{};

public:
    void insert(int val);
    bool is_empty();
    std::string stringify();
};
