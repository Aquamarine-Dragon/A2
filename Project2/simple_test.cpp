#include <iostream>
#include "recursive.h"
#include "p2.h"

using namespace std;

static bool list_equal(list_t l1, list_t l2)
    // EFFECTS: returns true iff l1 == l2.
{
    if(list_isEmpty(l1) && list_isEmpty(l2))
    {
        return true;
    }
    else if(list_isEmpty(l1) || list_isEmpty(l2))
    {
        return false;
    }
    else if(list_first(l1) != list_first(l2))
    {
        return false;
    }
    else
    {
        return list_equal(list_rest(l1), list_rest(l2));
    }    
}

bool gugugu(int a){
    if(a %3 == 0)
        return true;
    else
        return false;
}

int main()
{
    int i;
    list_t listA, listA_answer;
    list_t listB, listB_answer;

    listA = list_make();
    listB = list_make();
    listA_answer = list_make();
    listB_answer = list_make();

    for(i = 5; i>0; i--)
    {
        listA = list_make(i, listA);
        listA_answer = list_make(6-i, listA_answer);
        listB = list_make(i+10, listB);
        listB_answer = list_make(i+10, listB_answer);
    }

    for(i = 5; i>0; i--)
    {
        listB_answer = list_make(i, listB_answer);
    }

    list_print(listA);
    cout << endl;
    list_print(listB);
    cout << endl;

//    test for size()
//    cout<< "size(listA)" << size(listA) << endl;
//    cout << size(list_make(1, list_make())) << endl;
    
    //test for memberof
//    if(memberOf(listA, 6))
//        cout << "yes!"<< endl;
//    else
//        cout <<"no！" << endl;
//    if(memberOf(listA, 5))
//        cout << "yes!"<< endl;
    
    //test for dot
//    listB = list_make(3, listB);
//    list_print(listB);
//    cout << endl;
//    cout << dot(listA, listB) << endl;
//    cout << dot(listB, listA) << endl;

    
    //test for isIncreasing
//    if(isIncreasing(listA))
//        cout << "increase" << endl;
//    list_t listC = list_make(4, list_make());
//    list_print(listC);
//    listA = append(listA, listC);
//    list_print(listA);
//    if(isIncreasing(listA))
//        cout << "increase" << endl;
//    listA = list_make(1, listA);
//    list_print(listA);
//    if(isIncreasing(listA))
//        cout << "increase" << endl;
    
    //test for reverse
//    list_print(reverse(listA));
//    list_t listC = list_make(4, list_make());
//    list_print(listC);
//    list_print(reverse(listC));
//    listA = list_make(0, listA);
//    list_print(reverse(listA));


    
    //test for append
    list_t listC = list_make();
    listA = append(listA, listB);
    list_print(listA);
    list_print(append(listC, listA));
    
    //test for isArithmetic
//    if(isArithmeticSequence(listA))
//        cout << "arithmetic" << endl;
//    listA = list_make(3, listA);
//    if(!isArithmeticSequence(listA))
//        cout << "nope" << endl;
//    list_t listC = list_make();
//    listC = list_make(0, listC);
//    listC = list_make(1, listC);
//    if(isArithmeticSequence(listC))
//        cout << "arithmetic" << endl;
//
    
    //test for filter odd
//    list_t b = filter_odd(listA);
//    list_print(b);
//    list_t listC = list_make(2, list_make());
//    list_print(filter_odd(listC));
    
    //test for filter
//    listA = append(listA, listB);
//    list_print(filter(listA, gugugu));
    
    //test for unique
//    listA = list_make(5, listA);
//    listA = list_make(1, listA);
//    list_print(listA);
//    list_print(unique(listA));
//    list_t listC = list_make();
//    listC = list_make(0, listC);
//    list_print(unique(listC));
    
    
    //test for insert_list
//    list_print(insert_list(list_make(), listA, 0));
    
    //test for chop
//    list_print(chop(list_make(), 0));
    
    

//    listB = append(listA, listB);
//    listA = reverse(listA);
//    list_print(listA);
//    cout << endl;
//    list_print(listB);
//    cout << endl;
//
//    if(list_equal(listA, listA_answer)
//        && list_equal(listB, listB_answer))
//    {
//        cout << "Success!\n";
//        return 0;
//    }
//    else
//    {
//        cout << "Failed\n";
//        return -1;
//    }
    
}
