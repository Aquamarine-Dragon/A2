//
//  p2.cpp
//  Project2
//
//  Created by 百里无溟 on 10/3/20.
//

#include <stdio.h>
#include <iostream>
#include "recursive.h"

using namespace std;





int size(list_t list){
    // EFFECTS: Returns the number of elements in "list".
    // Returns zero if "list" is empty.
    if(list_isEmpty(list))
        return 0;
    else
        return 1+ size(list_rest(list));
}


bool memberOf(list_t list, int val){
    // EFFECTS: Returns true if the value "val" appears in "list".
    // Returns false otherwise.
    
    if(list_isEmpty(list))
        return false;
    if(list_first(list) == val){
        return true;
    }
    if(size(list)==1){
        return false;
    }else{
        return memberOf(list_rest(list), val);
    }
}

int dot(list_t v1, list_t v2){
    //REQUIRES: Both "v1" and "v2" are non-empty
    //EFFECTS: Treats both lists as vectors. Returns the dot
    //product of the two vectors. If one list is longer than the other, ignore the longer part of the vector.
    if(size(v1)==1 || size(v2)== 1){
        return list_first(v1) * list_first(v2);
    }else{
        return list_first(v1) * list_first(v2) + dot(list_rest(v1), list_rest(v2));
    }
}



bool isIncreasing(list_t v){
    //Checks if the list of integers is increasing.
    //A list is increasing if and only if no element
    //is smaller than its previous element. By default, an empty list and a list of a single element are increasing.
    // For example: (), (2), (1, 1), and (1, 2, 3, 3, 5) are
    // all increasing. (2, 1) and (1, 2, 3, 2, 5) are not.
    if(list_isEmpty(v)||size(v) == 1)
        return true;
    if(list_first(v) > list_first(list_rest(v)))
        return false;
    else
        return isIncreasing(list_rest(v));
}

static list_t reverse_helper(list_t list, list_t a){
    if(list_isEmpty(list))
        return a;
    else{
        a = list_make(list_first(list), a);
        return reverse_helper(list_rest(list), a);
    }
}

list_t reverse(list_t list){
    // EFFECTS: Returns the reverse of "list". //
    // For example: the reverse of ( 3 2 1 ) is ( 1 2 3 ).
    list_t a = list_make();
    return reverse_helper(list, a);
}

static list_t append_helper(list_t firstReverse, list_t second){
    if(list_isEmpty(list_rest(firstReverse)))
        return list_make(list_first(firstReverse), second);
    else
        return append_helper(list_rest(firstReverse), list_make(list_first(firstReverse), second));
}

list_t append(list_t first, list_t second){
    //EFFECTS: Returns the list (first second).
    //For example: append(( 2 4 6 ), ( 1 3 )) gives the list ( 2 4 6 1 3 ).
    if(list_isEmpty(first) && list_isEmpty(second))
        return first;
    if(list_isEmpty(first))
        return second;
    if(list_isEmpty(second))
        return first;
    return append_helper(reverse(first), second);
}

static bool isArithmeticSequence_helper(list_t v, int num){
    if(size(v) == 1)//the list only has 2 elements
        return true;
    if(num != list_first(list_rest(v)) - list_first(v)){
        return false;
    }else{
        return isArithmeticSequence_helper(list_rest(v), num);
    }
}

bool isArithmeticSequence(list_t v){
    // EFFECTS: Checks if the list of integers forms an
    // arithmetic sequence. By default, an empty list and
    // a list of a single element are arithmetic sequences. //
    //          For example: (), (1), (1, 3, 5, 7), and (2, 8, 14, 20)
    // are arithmetic sequences. (1, 2, 4), (1, 3, 3),
    // and (2, 4, 8, 10) are not.
    if(list_isEmpty(v)||size(v) == 1)
        return true;
    
    int num = list_first(list_rest(v)) - list_first(v);
    return isArithmeticSequence_helper(list_rest(v), num);
}

static list_t filter_odd_helper(list_t list, list_t newList){
    int i =list_first(list);
    if(i % 2 != 0)//check odd
        newList = list_make(i, newList);
    if(size(list) == 1)
        return reverse(newList);
    return filter_odd_helper(list_rest(list), newList);
}

list_t filter_odd(list_t list){
    // EFFECTS: Returns a new list containing only the elements of the
    // original "list" which are odd in value,
    // in the order in which they appeared in list. //
    //  For example, if you apply filter_odd to the list
    // (34156),youwouldgetthelist(315).
    if(list_isEmpty(list))
        return list;
    
    //create a empty list that will store the filtered list
    list_t newList = list_make();
    return filter_odd_helper(list, newList);
    
}


static list_t filter_helper(list_t list, list_t n, bool (*fn)(int)){
    int first =list_first(list);
    
    if(fn(first))
        n = list_make(first, n);
    if(size(list) == 1)
        return reverse(n);
    return filter_helper(list_rest(list), n, fn);
}

list_t filter(list_t list, bool (*fn)(int)){
    // EFFECTS: Returns a list containing precisely the elements of "list"
    //          for which the predicate fn() evaluates to true, in the
    // order in which they appeared in list. //
    //          For example, if predicate bool odd(int a) returns true
    //          if a is odd, then the function filter(list, odd) has
    // the same behavior as the function filter_odd(list).
    
    if(list_isEmpty(list))
        return list;
    list_t n = list_make();
    return filter_helper(list, n, fn);
}

static list_t unique_helper(list_t list, list_t nList){
    list_t rest = list_rest(list);
    if(list_isEmpty(rest))
        return reverse(nList);
    int first = list_first(list);
    if(!memberOf(nList, first))
        nList = list_make(first, nList);
    return unique_helper(rest, nList);
}

list_t unique(list_t list){
        // EFFECTS: Returns a new list comprising of each unique element
        // in "list". The order is determined by the first
        // occurrence of each unique element in "list". //
        //          For example, if you apply unique to the list
        // (11213553454),youwouldget(12354).
        //          If you apply unique to the list (0 1 2 3), you would
        // get(0123)
    if(list_isEmpty(list)||size(list) == 1)
        return list;
    //create a new list that will store unique integers
    list_t nList = list_make();
    return unique_helper(list, nList);
        
    }

static list_t insert_list_helper(list_t first, list_t second, unsigned int n, list_t nList){
    //all list are done, return
    if(list_isEmpty(first))
        return reverse(nList);
    else if(list_isEmpty(second)){
        //second part of the first list
        nList = list_make(list_first(first), nList);
        return insert_list_helper(list_rest(first), second, n, nList);
    }else if((unsigned (size(nList))) >= n){
        //inserting the second list
        nList = list_make(list_first(second), nList);
        return insert_list_helper(first, list_rest(second), n, nList);
    }else{
        //first part of the first list
        nList = list_make(list_first(first), nList);
        return insert_list_helper(list_rest(first), second, n, nList);
    }
}

list_t insert_list(list_t first, list_t second, unsigned int n){
    // REQUIRES: n <= the number of elements in "first".
    //
    // EFFECTS: Returns a list comprising the first n elements of
    //          "first", followed by all elements of "second",
    // followed by any remaining elements of "first". //
    // Forexample:insert((123),(456),2)
    // gives(124563).
    //create a new list that will store the list inserted
    if(list_isEmpty(first))
        return second;
    
    list_t nList = list_make();
    return insert_list_helper(first, second, n, nList);
}

static list_t chop_helper(list_t reverseList, int listLength){
    if(size(reverseList) == listLength)
        return reverse(reverseList);
    return chop_helper(list_rest(reverseList),listLength);
}

list_t chop(list_t list, unsigned int n){
    // REQUIRES: "list" has at least n elements.
    //
    // EFFECTS: Returns the list equal to "list" without its last n
    // elements.
    list_t reverseList  = reverse(list);
    int listLength = size(list) - n;
    return chop_helper(reverseList, listLength);
}

int tree_sum(tree_t tree){
    // EFFECTS: Returns the sum of all elements in "tree".
    // Returns zero if "tree" is empty.
    if(tree_isEmpty(tree))
        return 0;
    //when the tree only has one element
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
        return tree_elt(tree);
    else if(tree_isEmpty(tree_left(tree)))//only has the right subtree
        return tree_elt(tree) + tree_sum(tree_right(tree));
    else if(tree_isEmpty(tree_right(tree)))//only has the left subtree
        return tree_elt(tree) + tree_sum(tree_left(tree));
    else
        return tree_elt(tree) + tree_sum(tree_left(tree)) + tree_sum(tree_right(tree));//has both subtrees
    return -1;
}

bool tree_search(tree_t tree, int val){
    // EFFECTS: Returns true if the value "val" appears in "tree".
    // Returns false otherwise.
    if(tree_elt(tree) == val)
        return true;
    //the tree only has one incompatible element
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
        return false;
    else if(tree_isEmpty(tree_left(tree)))//only has the right subtree
        return tree_search(tree_right(tree), val);
    else if(tree_isEmpty(tree_right(tree)))//only has the left subtree
        return tree_search(tree_left(tree), val);
    //find in the two subtrees
    return tree_search(tree_left(tree), val) || tree_search(tree_right(tree), val);
}
int depth(tree_t tree){
    // EFFECTS: Returns the depth of "tree", which equals the number of
    //          layers of nodes in the tree.
    //          Returns zero if "tree" is empty
    
    //before getting into the subtree, the depth is increased by 1
    if(tree_isEmpty(tree))
        return 0;
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
        return 1;
    else if(tree_isEmpty(tree_left(tree)))
        return 1 + depth(tree_right(tree));
    else if(tree_isEmpty(tree_right(tree)))
        return 1 + depth(tree_left(tree));
    //take the deeper subtree
    return 1 + max(depth(tree_right(tree)), depth(tree_left(tree)));
}


int tree_max(tree_t tree){
    // REQUIRES: "tree" is non-empty.
    // EFFECTS: Returns the largest element in "tree".
    int temp = tree_elt(tree);
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
        return temp;
    else if(tree_isEmpty(tree_left(tree)))
        return max(temp, tree_max(tree_right(tree)));
    else if(tree_isEmpty(tree_right(tree)))
        return max(temp, tree_max(tree_left(tree)));
    return max(temp, max(tree_max(tree_left(tree)), tree_max(tree_right(tree))));
}

list_t traversal(tree_t tree){
    // EFFECTS: Returns the elements of "tree" in a list using an
    // in-order traversal. An in-order traversal prints
    // the "left most" element first, then the second-left-most,
    // and so on, until the right-most element is printed. //
    //          For any node, all the elements of its left subtree
    //          are considered as on the left of that node and
    //          all the elements of its right subtree are considered as
    // on the right of that node. //
    if(tree_isEmpty(tree))
        return list_make();
    //element store the tree ele
    list_t element = list_make(tree_elt(tree), list_make());
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
        return element;
    else if(tree_isEmpty(tree_left(tree)))
        return append(element, traversal(tree_right(tree)));
    else if(tree_isEmpty(tree_right(tree)))
        return append(traversal(tree_left(tree)), element);
    //right subtree, then the tree ele, then the left subtree
    return append(append(traversal(tree_left(tree)), element), traversal(tree_right(tree)));
}

static bool tree_hasMonotonicPath_helper(tree_t tree, bool right, bool increase){
    //increase means whether this path is increasing or decreasing
    //right means wthether this is the right or left subtree
    //rightSub and leftSub indicate whether the subtrees exist
    bool rightSub = true;
    bool leftSub = true;
    if(tree_isEmpty(tree_left(tree)))
        leftSub = false;
    if(tree_isEmpty(tree_right(tree)))
        rightSub = false;
    //no subtree exists
    if(!rightSub && !leftSub)
        return true;
    if(increase){
        if(right){
            //right and increasing
            //no element in the right sub
            if(!rightSub)
                return true;
            if(increase != (tree_elt(tree) < tree_elt(tree_right(tree))))
                return false;
        }else{
            //left and increasing
            //no element in the left sub
            if(!leftSub)
                return true;
            if(increase != (tree_elt(tree) < tree_elt(tree_left(tree))))
                return false;
        }
        //common part for increasing paths
        //both subtrees exist
        if(rightSub && leftSub)
            return tree_hasMonotonicPath_helper(tree_right(tree), true, true) || tree_hasMonotonicPath_helper(tree_left(tree), false, true);
        // only right subtree
        if(rightSub && !leftSub)
            return tree_hasMonotonicPath_helper(tree_right(tree), true, true);
        //only left subtree
        if(!rightSub && leftSub)
            return tree_hasMonotonicPath_helper(tree_left(tree), false, true);
    }else {
        //decreasing
        if(right){
            //right and decreasing
            if(!rightSub)
                return true;
            if(!increase != (tree_elt(tree) < tree_elt(tree_right(tree))))
                return false;
        }else{
            //left and decreasing
            if(!leftSub)
                return true;
            if(increase != (tree_elt(tree) < tree_elt(tree_left(tree))))
                return false;
        }
        //common part for decreasing paths
        if(rightSub && leftSub)
            return tree_hasMonotonicPath_helper(tree_right(tree), true, false) || tree_hasMonotonicPath_helper(tree_left(tree), false, false);
        if(rightSub && !leftSub)
            return tree_hasMonotonicPath_helper(tree_right(tree), true, false);
        if(!rightSub && leftSub)
            return tree_hasMonotonicPath_helper(tree_left(tree), false, false);
    }
    return false;
}


bool tree_hasMonotonicPath(tree_t tree){
    // EFFECTS: Returns true if and only if "tree" has at least one
    // root-to-leaf path such that all the elements along the
    //          path form a monotonically increasing or decreasing
    // sequence. //
    // A root-to-leaf path is a sequence of elements in a tree
    //          starting with the root element and proceeding downward
    // to a leaf (an element with no children). //
    // An empty tree has no root-to-leaf path. //
    //          A monotonically increasing (decreasing) sequence is a
    //          sequence of numbers where no number is smaller (larger)
    // than its previous number.
    if(tree_isEmpty(tree))
        return false;
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
        return true;
    
    
    bool leftIncrease = false;
    bool rightIncrease = false;
    if(tree_elt(tree) < tree_elt(tree_right(tree)))
       rightIncrease  = true;
    if(tree_elt(tree) < tree_elt(tree_left(tree)))
       leftIncrease  = true;
    //separate the tree into right and left subtrees, any one being true will let the method returns true
    if(tree_isEmpty(tree_left(tree)))
        return tree_hasMonotonicPath_helper(tree_right(tree), true, rightIncrease);
    if(tree_isEmpty(tree_right(tree)))
        return tree_hasMonotonicPath_helper(tree_left(tree), false, leftIncrease);
    return tree_hasMonotonicPath_helper(tree_left(tree), false, leftIncrease) || tree_hasMonotonicPath_helper(tree_right(tree), true, rightIncrease);
}
//[](int a, int b) -> bool{return a>=b}

static bool tree_allPathSumGreater_helper(tree_t tree, int tempSum, int sum){
    //update the current sum of the path
    tempSum = tempSum + tree_elt(tree);
    //reach the end of a path
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree))){
        //the sum of this path < sum
        if(tempSum < sum)
            return false;
        //the sum of this path > sum
        return true;
    }
    //only has right sub tree
    if(tree_isEmpty(tree_left(tree))){
        return tree_allPathSumGreater_helper(tree_right(tree), tempSum, sum);
    }
    //only has left sub tree
    if(tree_isEmpty(tree_right(tree))){
        return tree_allPathSumGreater_helper(tree_left(tree), tempSum, sum);
    }
    //has both sub trees
    return tree_allPathSumGreater_helper(tree_right(tree), tempSum, sum) && tree_allPathSumGreater_helper(tree_left(tree), tempSum, sum);
}


bool tree_allPathSumGreater(tree_t tree, int sum){
    // REQUIRES: tree is not empty
    //
    // EFFECTS:
    //Returns true if and only if for each root-to-leaf
    //path of "tree", the sum of all elements along the path is greater than "sum".

    int tempSum = tree_elt(tree);
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree))){
        if(tempSum < sum)
            return false;
        else
            return true;
    }
    //separate the tree into right and left subtrees to find all the paths, using "and" to ensure all paths satisfy the requirements
    
    if(tree_isEmpty(tree_left(tree)))
        return tree_allPathSumGreater_helper(tree_right(tree), tempSum, sum);
    if(tree_isEmpty(tree_right(tree)))
        return tree_allPathSumGreater_helper(tree_left(tree), tempSum, sum);
    return tree_allPathSumGreater_helper(tree_right(tree), tempSum, sum) && tree_allPathSumGreater_helper(tree_left(tree), tempSum, sum);
}

bool covered_by(tree_t A, tree_t B){
    // EFFECTS: Returns true if tree A is covered by tree B.
    //A is empty
    if(tree_isEmpty(A))
        return true;
    //A not empty and B empty
    if(tree_isEmpty(B))
        return false;
    if(tree_elt(A) == tree_elt(B)){
        //A has only one ele
        if(tree_isEmpty(tree_left(A))&& tree_isEmpty(tree_right(A)))
            return true;
        //check if the next root of right sub tree of A equals to that of B
        if(tree_isEmpty(tree_right(A)))
            return covered_by(tree_left(A), tree_left(B));
        //check if the next root of left sub tree of A equals to that of B
        if(tree_isEmpty(tree_left(A)))
            return covered_by(tree_right(A), tree_right(B));
        //check both subtrees
        return covered_by(tree_left(A), tree_left(B)) && covered_by(tree_right(A), tree_right(B));
    }else{
        return false;
    }
}

bool contained_by(tree_t A, tree_t B){
    // EFFECTS: Returns true if tree A is covered by tree B
    // or a subtree of B.
   
    //check if A is covered by B
    if(!tree_isEmpty(A) && tree_isEmpty(B))
        return false;
    if(covered_by(A, B))
        return true;
        else{
        //A not covered by B, search in the subtrees of B
        
        //there is nothing left in B
        if(tree_isEmpty(tree_left(B))&& tree_isEmpty(tree_right(B)))
            return false;
        //b only has right subtree
        if(tree_isEmpty(tree_left(B)))
           return contained_by(A, tree_right(B));
        //b only has left subtree
        if(tree_isEmpty(tree_right(B)))
            return contained_by(A, tree_left(B));
        //b has both subtrees
        return contained_by(A, tree_right(B)) ||contained_by(A, tree_left(B));
    }
}

//static bool checkSorted(tree_t tree){
//    if(tree_isEmpty(tree))
//        return true;
//    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree)))
//        return true;
//    if(tree_isEmpty(tree_left(tree)))
//        return checkSorted(tree_right(tree));
//    if(tree_isEmpty(tree_right(tree)))
//        return checkSorted(tree_left(tree));
//    if(tree_elt(tree) <= tree_elt(tree_left(tree)))
//        return false;
//    if(tree_elt(tree) > tree_elt(tree_right(tree)))
//       return false;
//    return checkSorted(tree_left(tree)) && checkSorted(tree_right(tree));
//}

tree_t insert_tree(int elt, tree_t tree){
    // REQUIRES: "tree" is a sorted binary tree.
    //
    // EFFECTS: Returns a new tree with elt inserted at a leaf such that
    // the resulting tree is also a sorted binary tree.
    
    //check tree is sorted
    //traces to the leaf of the tree
    if(tree_isEmpty(tree_left(tree))&& tree_isEmpty(tree_right(tree))){
        if(elt < tree_elt(tree))
            return tree_make(tree_elt(tree), tree_make(elt, tree_make(), tree_make()), tree_make());
        if(elt >= tree_elt(tree))
            return tree_make(tree_elt(tree), tree_make(), tree_make(elt, tree_make(), tree_make()));
    }else if(tree_isEmpty(tree_left(tree))){
        if(elt < tree_elt(tree))
            return tree_make(tree_elt(tree), tree_make(elt, tree_make(), tree_make()), tree_make());
    }else if(tree_isEmpty(tree_right(tree))){
        if(elt >= tree_elt(tree))
            return tree_make(tree_elt(tree), tree_make(), tree_make(elt, tree_make(), tree_make()));
    }
    return tree_make(tree_elt(tree), insert_tree(elt, tree_left(tree)), insert_tree(elt, tree_right(tree)));
    
}




