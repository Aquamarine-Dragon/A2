#include <iostream>
#include "recursive.h"
#include "p2.h"

using namespace std;

static bool tree_equal(tree_t t1, tree_t t2)
    // EFFECTS: returns true iff t1 == t2
{
    if(tree_isEmpty(t1) && tree_isEmpty(t2))
    {
        return true;
    }
    else if(tree_isEmpty(t1) || tree_isEmpty(t2))
    {
        return false;
    }
    else
    {
        return ((tree_elt(t1) == tree_elt(t2)) 
            && tree_equal(tree_left(t1), tree_left(t2))
            && tree_equal(tree_right(t1), tree_right(t2)));
    }
}

//int main()
//{
//    tree_t start = tree_make(2,
//                     tree_make(1, tree_make(), tree_make()),
//                     tree_make(4, tree_make(), tree_make()));
//    tree_t end = tree_make(2,
//                   tree_make(1, tree_make(), tree_make()),
//                   tree_make(4,
//                         tree_make(3, tree_make(), tree_make()),
//                         tree_make()));
//    tree_t special = tree_make(2,
//                   tree_make(1, tree_make(6, tree_make(), tree_make()), tree_make()),
//                   tree_make(4,
//                         tree_make(3, tree_make(1, tree_make(), tree_make()), tree_make()),
//                         tree_make(1,tree_make(), tree_make()
//                                   )));
//    tree_t special_covered = tree_make(1, tree_make(), tree_make());
//
//    tree_t sorted = tree_make(4, tree_make(2, tree_make(1, tree_make(), tree_make()), tree_make(3, tree_make(), tree_make())), tree_make(6, tree_make(5, tree_make(), tree_make()), tree_make(7, tree_make(), tree_make())));
//
//    tree_t left = tree_make(3, tree_make(), tree_make(4, tree_make(), tree_make(5, tree_make(), tree_make())));

    //test for tree_sum
//    tree_print(start);
//    tree_print(end);
//    tree_print(special);
////    tree_print(sorted);
//    tree_t empty = tree_make();
//    cout << "empty sum: " << tree_sum(empty) << endl;
//    cout << "start sum: " << tree_sum(start) << endl;
//    cout << "end sum: " << tree_sum(end) << endl;
    
    //test for tree_search
//    if(tree_search(start, 2))
//        cout << "2 exists in start" << endl;
//    if(tree_search(start, 1))
//        cout << "1 exists in start" << endl;
//    if(tree_search(end, 0))
//        cout << "0 exists in end" << endl;
//    else
//        cout <<"0 does not exists in end" << endl;
    
    //test for depth
//    cout << "start depth " << depth(start) << endl;
//    cout << "end depth " << depth(end) << endl;
//    cout << "empty depth " << depth(empty) << endl;
//    cout << "special depth " << depth(special) << endl;
    
    //test for tree-max
//    cout << "start: " << tree_max(start) << endl;
//    cout << "end: " << tree_max(end) << endl;
//
//    cout << "special: " << tree_max(special) << endl;

    //test for traversal
//    tree_print(left);
//    list_print(traversal(left));
//    tree_t c = tree_make(1, tree_make(), tree_make());
//    list_print(traversal(c));
//    list_print(traversal(end));
//    list_print(traversal(empty));
//    list_print(traversal(special));

    
    //test for tree_hasMonotonicPath
//    if(tree_hasMonotonicPath(start))
//        cout << "start: yes" << endl;
//    if(tree_hasMonotonicPath(end))
//        cout << "end: yes" << endl;
//    if(tree_hasMonotonicPath(special))
//            cout << "special: yes" << endl;
//    if(tree_hasMonotonicPath(empty))
//        cout << "empty: " << endl;

    //test for tree_allPathSumGreater
//    tree_t c = tree_make(1, tree_make(), tree_make());
//    tree_print(c);
//    if(tree_allPathSumGreater(c, 0))
//        cout << "C > 0" << endl;
//
//    if(tree_allPathSumGreater(start, 3))
//        cout << "start > 3" << endl;
//    if(tree_allPathSumGreater(start, 9))
//        cout << "start > 9" << endl;
//    if(tree_allPathSumGreater(end, 3))
//            cout << "end > 3" << endl;
//    if(tree_allPathSumGreater(special, 7))
//        cout << "special > 7" << endl;
//    if(tree_allPathSumGreater(special, 15))
//        cout << "special > 15" << endl;
    
    
    //test for contained_by
//    if(contained_by(special_covered, special))
//        cout << "sc is covered by s" << endl;
//    if(contained_by(start, end))
//        cout << "start is covered by end" << endl;
//    if(contained_by(end, start))
//        cout << "end is covered by start" << endl;
//    if(contained_by(end, end))
//        cout << "end is covered by end" << endl;
//    if(contained_by(end, special))
//        cout << "end is covered by special" << endl;
//    if(contained_by(empty, end))
//        cout << "empty is covered by end" << endl;
//    if(contained_by(empty, empty))
//        cout << "empty is covered by empty" << endl;
    
    //test for insert_tree
//    tree_print(insert_tree(3, sorted));
    
    
    
//    tree_t candidate = insert_tree(3, start);
//    tree_print(end);
//    cout << endl;
//    cout << endl;
//
//    tree_print(candidate);
//    cout << endl;
//
//    if(tree_equal(candidate, end))
//    {
//        cout << "Success!\n";
//        return 0;
//    }
//    else
//    {
//        cout << "Failed\n";
//        return -1;
//    }

//}
