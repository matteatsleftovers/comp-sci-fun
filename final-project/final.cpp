#include <iostream>
#include "stack.hpp"
#include "queue.hpp"

int main(void) {
    std::cout << "== Stack == " << std::endl;
    Stack<int> s = Stack<int>();

    for(int i = 1; i <= 15; i++)
        s.push(i);

    for(int i = 0; i < 10; i++)
        std::cout << s.pop() << std::endl;

    for(int i = 101; i <= 106; i++)
        s.push(i);

    while(!s.is_empty())
        std::cout << s.pop() << std::endl;

    std::cout << std::endl << "== Queue == " << std::endl;
    Queue<int> q = Queue<int>();

    for(int i = 1; i <= 15; i++)
        q.push(i);

    for(int i = 0; i < 10; i++)
        std::cout << q.pop() << std::endl;

    for(int i = 101; i <= 106; i++)
        q.push(i);

    while(!q.is_empty())
        std::cout << q.pop() << std::endl;

    return 0;
}
