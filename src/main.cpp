extern "C"{
    // Add the header files required to run your main 
    #include "linked_list.h"
    #include <stdio.h>
    #include <stdlib.h>
}

// File for sandboxing and trying out code
int main(int argc, char **argv)
{
    //Test case for exercise 1
    // node *list = make_node(100, 
    //                 make_node(90,
    //                     make_node(80,
    //                         make_node(70, 
    //                             make_node(60,
    //                                 make_node(50,
    //                                     make_node(40, 
    //                                         make_node(-4,
    //                                             make_node(20,
    //                                                 make_node(10,  
    //                                                         NULL))))))))));
    // print_list(list);

    // //Test case for exercise 2
    // int sum;
    // node *ns = make_node (1,
	// 		        make_node (2,
	// 			        make_node (3,
	// 				      make_node (4,
	// 						  make_node (5,
	// 							    NULL)))));

	// sum = sum_squares (ns);
    // printf("%d", sum);

    /*node *X = make_node(1,
                make_node(2,
                    make_node(3, 
                        make_node(4, 
                            make_node(5,
                                &SENTINEL_node)))));*/

    return 0;
}