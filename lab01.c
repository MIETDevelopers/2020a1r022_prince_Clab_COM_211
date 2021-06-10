#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int input_elements(int *list, int n){
    int i;
    for(i=0; i<n; i++){
    printf("Enter Element at list[%d] : ", i);
    scanf("%d", (list+i));
    }
} 
int insert_element(int *list, int size, int insert, int element){
     int i;
     if(size>insert){
        list = realloc(list, ((size+1)*sizeof(int)));
        if(list == 0){
         printf("Memory cannot be allocated\n");
        }else{
            for(i = size; i>=insert; i--){
              *(list+i) = *(list+i-1);
            }
             *(list+insert) = element;
             size++;
        }
     }
     return size; 
}
int Linear_search(int *list, int size, int element){
    int i, index= -1;
    for(i=0; i<size; i++){
        if(*(list+i)== element){
            index = i;
            break;
        }
    }    
    return index; 
}
int delete_element(int *list, int size, int element){
    int i, index;
    index = Linear_search(list, size, element); 
    if(index == -1){
        return -1;
    }
    else{
        for(i = index; i<size; i++){
            *(list+i) = *(list+i+1);
        }
        size = size-1;
        return size;
    }
}
void output_elements(int *list, int n){
    int i;
    for(i = 0; i<n; i++)
        printf("%d \n" , *(list+i));
}
int main()
{
    int *list, size, item, position, index, del_element, del, option, searchFor;
     printf("Enter the size of list that you want. \n");
     scanf("%d", &size);
     list = (int *)malloc(size*sizeof(int));
     if(list == 0)
     printf("Memory cannot be allocated!");
     else{
        input_elements(list, size);
        printf("Entered elements are:\n");
        output_elements(list, size);
        do{
        printf("\n \t OPERATIONS \n");
        printf("1. Insertion \n");
        printf("2. Deletion \n");
        printf("3. Linear Seach \n");
        printf("4. Exit \n ");
        printf("Enter your choice : ");
        scanf("%d", &option);
        switch(option){
            case 1: printf("Insertion \n");
                    printf("\n Enter the element you want to insert : ");
                    scanf("%d", &item);
                    printf("Enter the position where you want to insert the element : ");
                    scanf("%d", &position);
                    index = position - 1;
                    size = insert_element(list, size, index, item);
                    printf("Updated List ... \n");
                    output_elements(list, size);
                    break;
            case 2: printf("Deletion \n");
                    printf("\n Enter the element you want to delete : ");
                    scanf("%d", &del_element);
                    del = delete_element(list,size, del_element);
                    if(del == -1 || size == 0){
                        printf("Element not found or the list is empty\n");
                    }else{
                        size = del;
                         printf("Element deleted!! \n");    
                         printf("New Updates list:\n");
                         output_elements(list, size);
                    }
                    break;
            case 3: printf("Linear Search \n");
                    printf("Enter the element you want to search : ");
                    scanf("%d", & searchFor);
                    index = Linear_search(list, size, searchFor);
                    if( index == -1 || size== 0){
                        printf("Element not found!\n");
                    }else
                     printf("Element found at index : %d\n", index);
                    break;
            case 4: exit(0);
            default: printf("Please enter the correct choice!\n");
                     break;
        }
        printf("Press any key to continue \n");
        getch();
    }while(1);
    }
    free(list);
    return 0;
}