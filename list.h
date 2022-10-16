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
    void insert(int const val);
    bool is_empty();
    int length{0};
    std::string stringify();
    // List(const List& to_copy); copy constructor
    int index_of(int const val);  // Hittar index(en) för ett tal i listan
    int get(int i);               // hittar det i:te listelementet
    bool contains(int const val); //
};
