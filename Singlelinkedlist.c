#include <stdio.h>
#include <stdlib.h>
#include "Singlelinkedlist.h"


unsigned int Get_Length(struct node *list )
{
    struct node *tempnode = list ;
    unsigned int count = 0 ;

    while( tempnode  !=  NULL )
    {
        count++ ;
        tempnode = tempnode->nodelink ;
    }
    return count ;
}

void Display_All_Nodes(struct node *list )
 {
     printf("The value = ") ;
    while( NULL != list )
    {
        printf(" %i  , ",list->listData) ;
        list = list->nodelink ;
    }
    printf(" Null \n") ;
 }

void Insert_Node_At_Beginning(struct node **list)
 {
     struct node *tempnode = NULL ;

     tempnode = (struct node*)malloc(sizeof(struct node)) ;

     if( NULL != tempnode )
     {
         printf("Enter the Data = ") ;
         scanf("%i",&(tempnode->listData)) ;

         if( NULL == *list )
         {
             *list = tempnode ;
             tempnode->nodelink = NULL ;
         }
         else
         {
             tempnode->nodelink = *list ;
             *list = tempnode ;
         }
     }
     else{}
 }


void Insert_Node_At_End(struct node **list)
 {
     struct node *tempnode = NULL , *lastNode = NULL ;

     tempnode = (struct node*)malloc(sizeof(struct node)) ;

     if( NULL != tempnode )
     {
         printf("Enter the Data = ") ;
         scanf("%i",&(tempnode->listData)) ;

         if( NULL == *list )
         {
             *list = tempnode ;
             tempnode->nodelink = NULL ;
         }
         else
         {
             lastNode = *list ;
             while( NULL != lastNode->nodelink )
             {
                 lastNode = lastNode->nodelink ;
             }

             lastNode->nodelink = tempnode ;
             tempnode->nodelink = NULL ;
         }
     }

     else{}

 }

void Insert_Node_After(struct node *list , unsigned int data , unsigned int Position)
 {
     struct node *tempnode = NULL  , *positionNode = NULL;
     unsigned int count =1  ;

     if( Position > Get_Length(list) )
     {
         printf("Error !! \n") ;
     }
     else if ( Position == 0 )
     {
         printf("Please use another function !! \n") ;
     }
     else
     {
         positionNode = list ;
         while( count < Position )
         {
             count++ ;
             positionNode = positionNode->nodelink ;
         }

        tempnode = (struct node*)malloc(sizeof(struct node)) ;

        if( NULL != tempnode )
        {
            tempnode->listData = data ;
            tempnode->nodelink = positionNode->nodelink ;
            positionNode->nodelink = tempnode ;
        }
        else{}
 }
 }

void Delete_node_at_beginning(struct node **list)
 {
     struct node *tempnode = NULL ;
     if( NULL == *list )
     {
         printf("List is empty !!\n") ;
     }
     else
     {
         tempnode = *list ;
         *list = tempnode->nodelink ;
         tempnode->nodelink = NULL ;
         free(tempnode) ;
     }
 }

 void Delete_node(struct node *list , unsigned int Position)
 {
    struct node *tempnode = NULL , *previousNode=NULL ;
    unsigned int count =1 ;

    if( Position > Get_Length(list) )
    {
        printf("Error !!\n") ;
    }
    else if ( 1 == Position )
    {
        printf("Please use another function !! \n") ;
    }
    else
    {
        tempnode = list ;
        while( count < Position )
        {
            if( count == Position -1 )
            {
                previousNode =  tempnode ;
            }
            count++ ;
            tempnode = tempnode->nodelink ;
        }

        previousNode->nodelink  =  tempnode->nodelink ;
        tempnode->nodelink = NULL ;
        free(tempnode) ;
    }
}


void Reverse_The_List(struct node *list)
{
    struct node *tempnode = list ;
    unsigned int arr[50]={0} ;
    unsigned int length = Get_Length(tempnode) , count = 0 ;

    while(  count < length )
    {
        arr[count] = tempnode->listData ;
        count++ ;
        tempnode = tempnode->nodelink ;
    }
    tempnode = list ;
    while( 0 != length )
    {
        length-- ;
        tempnode->listData = arr[length] ;
        tempnode = tempnode->nodelink ;
    }


}


void Swap_Nodes(struct node **list)
{
    struct node *tempnode1 = *list , *tempnode2 = *list ;
    unsigned int node1 = 0 , node2 = 0  , count = 1 , temp_data = 0 ;

    printf("Enter the position of node one = ");
    scanf("%i",&node1) ;

    printf("Enter the position of node two = ");
    scanf("%i",&node2) ;

    while( count < node1 )
    {
        count++ ;
        tempnode1 = tempnode1->nodelink ;
    }
    count = 1 ;

    while( count < node2 )
    {
        count++ ;
        tempnode2 = tempnode2->nodelink ;
    }

    temp_data = tempnode1->listData ;
    tempnode1->listData = tempnode2->listData ;
    tempnode2->listData = temp_data ;
}



void Sort_Nodes(struct node **list)
{
    struct node *tempnode = *list , *nodelist = *list ;
    unsigned int count1 = 0 , count2 = 0 , length = Get_Length(tempnode) , temp_data = 0 ;

    for( count1 = 1 ; count1 <= length ; count1++ )
    {
        for( count2 = count1 ; count2 <= length ; count2++)
        {
            if( (tempnode->listData) < (nodelist->listData) )
            {
                temp_data = nodelist->listData ;
                nodelist->listData = tempnode->listData ;
                tempnode->listData = temp_data ;
            }
            tempnode = tempnode->nodelink ;
        }
        nodelist = nodelist->nodelink ;
        tempnode = nodelist ;
    }
}

void Print_The_Middle(struct node *list)
{
    struct node *tempnode = NULL ;
    unsigned int length = Get_Length(list) , middle = 0 , count = 1 ;

    if( NULL == list )
    {
        printf("List is empty !!\n") ;
    }
    else
    {
        if( 0 == (length % 2 ) )
        {
            printf("Number of elements is even !!\n") ;
        }
        else
        {
            middle = ( length / 2 ) + 1 ;
            tempnode = list ;

            while( count < middle )
            {
                tempnode = tempnode->nodelink ;
                count++ ;
            }
            printf("The middle node data = %i \n",tempnode->listData) ;
        }
    }
}


void Delete_The_Middle(struct node *list)
{
    struct node *tempnode = NULL , *nodelist = NULL ;
    unsigned int length = Get_Length(list) , middle = 0 , count = 1 ;

    if( NULL == list )
    {
        printf("List is empty !!\n") ;
    }
    else
    {
        if( 0 == (length % 2 ) )
        {
            printf("Number of elements is even !!\n") ;
        }
        else
        {
            middle = ( length / 2 ) + 1 ;
            tempnode = list ;

            while( count < middle )
            {
                if( count == (middle -1) )
                {
                    nodelist = tempnode ;
                }
                tempnode = tempnode->nodelink ;
                count++ ;
            }
            nodelist->nodelink = tempnode->nodelink ;
            tempnode->nodelink = NULL ;
            free(tempnode) ;
        }
    }
}

void Delete_Duplicate_Values(struct node *list)
{
    struct node *tempnode = list , *nodelist = list ;
    unsigned int length = Get_Length(tempnode) , count =1 , Duplicate_Data = 0  ;

    if( NULL == list)
    {
        printf("List id empty !!\n") ;
    }
    else
    {
        Sort_Nodes(&list) ;
        Duplicate_Data = tempnode->listData ;

        while( count < length )
        {
            count++ ;
            tempnode = nodelist->nodelink ;
            if( (Duplicate_Data) == (tempnode->listData)  )
            {
                nodelist->nodelink =  tempnode->nodelink ;
                tempnode->nodelink = NULL ;
                free(tempnode) ;
            }
            else
            {
                Duplicate_Data = tempnode->listData ;
                nodelist = nodelist->nodelink ;
            }

        }
    }
}


void Delete_List(struct node **list)
{
    struct node *tempnode = *list , *nodelist = *list ;
    unsigned int length = Get_Length(tempnode) , count = 1 ;

    while( count < length )
    {
        count++ ;
        nodelist = nodelist->nodelink ;
        free(tempnode) ;
        tempnode = nodelist ;
    }
    *list = NULL ;
}


void Merge_Two_List(struct node **list1 , struct node **list2 )
{
    struct node *tempnode2 = *list2 ;
    unsigned int length = Get_Length(*list1) , count1 = 0  ,position1 = 1  ;

    if( NULL == *list1 )
    {
        printf("List One is empty !!\n");
    }
    else
    {
        if( NULL != *list2 )
        {
            while( count1 < length )
            {
                count1++ ;
                Insert_Node_After( *list1, tempnode2->listData , position1 ) ;
                tempnode2 = tempnode2->nodelink ;
                Delete_node_at_beginning(list2) ;
                position1 += 2 ;
            }
        }
    }
}


void Is_Palndimore(struct node *list)
{
    struct node *tempnode = list ;
    unsigned int length = Get_Length(list) , count = 0 , middle_node = (length/2)+1 ;
    unsigned int arr[50] = {0} ;

    if( NULL == list )
    {
        printf("List is empty !!\n") ;
    }
    else
    {
        if( (length%2) == 0 )
        {
            printf("List have Even numbers of nodes No Palindmore !! \n ") ;
        }
        else
        {
            while( count < middle_node )
            {
                arr[count] = tempnode->listData ;
                count++ ;
                if( middle_node !=  count)
                {
                   tempnode = tempnode->nodelink ;
                }
            }
            middle_node-- ;
            while( count <= length  )
            {
                if( arr[middle_node] != (tempnode->listData) )
                {
                    printf("List isnt Palindimore>>>\n") ;
                    break ;
                }
                else if (  count == length   )
                {
                    printf("List if palindimore>>>\n") ;
                }
                tempnode = tempnode->nodelink ;
                count++ ;
                middle_node-- ;
            }
        }
    }
}


void Delete_Key(struct node **list , unsigned int key )
{
    struct node *tempnode = *list ;
    unsigned int length = Get_Length(tempnode) , count = 1 , position = count ;

    if( NULL == *list )
    {
        printf("List is empty\n") ;
    }
    else
    {
        while( count <= length )
        {
            if( (tempnode->listData) ==  key )
            {
                tempnode = tempnode->nodelink ;
                Delete_node( *list , position ) ;
                position-- ;
            }
            else
            {
                tempnode = tempnode->nodelink ;
            }
            count++ ;
            position++ ;
        }
    }
}



