#include <iostream>
#include "classes/SearchTree.h"

int main() {
    SearchTree<int> dub;
    dub.Insert(8,8);
    dub.Insert(3,3);
    dub.Insert(10,10);
    dub.Insert(1,1);
    dub.Insert(14,14);
    dub.Insert(6,6);
    dub.Insert(4,4);
    dub.Insert(7,7);
    dub.Insert(13,13);
    size_t calculator = 0;
    dub.pre_order_traversal(dub.GetRoot(), calculator);
    std::cout<<std::endl;
    calculator = 0;
    dub.in_order_traversal(dub.GetRoot(), calculator);
    std::cout<<std::endl;
    calculator = 0;
    dub.post_order_traversal(dub.GetRoot(), calculator);
    std::cout<<std::endl;
}
