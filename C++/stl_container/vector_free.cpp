#include <iostream>
#include <vector>

class Node
{
public:
    int i = 0;
    int *p = nullptr;
    Node(int i) : i(i)
    {
        p = new int[i];
        std::cout << "Node Constructor" << std::endl;
    }
    Node()
    {
        // p = new int[i];
        std::cout << "Node Constructor" << std::endl;
    }
    Node(const Node &other) : i(other.i + 1)
    {
        // memcpy(p, other.p, sizeof(int)*i);
        std::cout << "Node Copy Constructor" << std::endl;
    }
    ~Node()
    {
        if (p != nullptr)
        {
            delete[] p;
            p = nullptr;
        }
        std::cout << "Node Destructor" << std::endl;
    }
};

int main(int argc, char *argv[])
{
    {
        Node n[3];
    }

    // void *;

    std::vector<Node> nodelist;
    nodelist.push_back(Node(1));
    std::cout << nodelist.size() << std::endl;
}
