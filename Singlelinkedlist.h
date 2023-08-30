#ifndef _SINGLELINKEDLIST_H_
#define _SINGLELINKEDLIST_H_

struct node {
    unsigned int listData ;
    struct node *nodelink ;
};

unsigned int Get_Length(struct node *list );
void Display_All_Nodes(struct node *list );
void Insert_Node_At_Beginning(struct node **list);
void Insert_Node_At_End(struct node **list);
void Insert_Node(struct node *list , unsigned int data , unsigned int posititon) ;
void Delete_node_at_beginning(struct node **list) ;
void Delete_node_After(struct node *list , unsigned int Position) ;
void Reverse_The_List(struct node *list);
void Swap_Nodes(struct node **list);
void Sort_Nodes(struct node **list);
void Print_The_Middle(struct node *list);
void Delete_The_Middle(struct node *list);
void Delete_Duplicate_Values(struct node *list);
void Delete_List(struct node **list);
void Merge_Two_List(struct node **list1 , struct node **list2 );
void Is_Palndimore(struct node *list);
void Delete_Key(struct node **list , unsigned int key );

#endif // _SINGLELINKEDLIST_H_
