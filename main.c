#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef enum {
    COMMON,
    RARE,
    LEGENDARY
}qulity;
typedef struct {
    char item_name[50];
    int quntity;
    qulity item_quality;

}item;
void display( item *ptr);
void save_file(item *ptr);
void view_file();

int main (){
    static bool isopen = true;
    char *tools[]={
        "FOOD",
        "BOW",
        "SHIELD",
        "MAP"    
    };
    

    int total = sizeof(tools)/sizeof(tools[0]);
  
        while (isopen)
        {   
            printf("------items-----\n");
            int choice , quality_choice ;   
            for (int i =0;i < total;i++){
               
                printf("\t%s \n",tools[i]);
               
            } 
            item* ptr = malloc(sizeof(item));
            if(ptr == NULL){
                printf("ERRO");
                free(ptr);
                continue;
            }
            printf("ENTER UR CHOICE: \n");
            if(scanf("%d",&choice)!=1 || choice >total || choice<1){
                printf("Invalid choice\n");
                free(ptr);
                return 1;
            }
            strcpy(ptr->item_name,tools[choice-1]);
            printf("Enter QUNTITY: \n");
            if(scanf("%d",&ptr ->quntity) != 1 || ptr->quntity < 1){
                printf("NEAR ZERO ERROR");
                free(ptr);
                return 1;
            }
           printf("ENTER QUALITY OF THE ITEM : \n");
           if(scanf("%d",&quality_choice) != 1 || quality_choice >LEGENDARY || quality_choice < COMMON){
            printf("NO_QUALITY ERROR\n");
            free(ptr);
            return 1;
           }
           ptr ->item_quality = (qulity)quality_choice;
           
          
        display(ptr);
        char input [20];
        printf("DO YOU WANT TO SAVE OR VIEW!!");
        scanf("%19s",&input);
        if(strcmp(input,"SAVE")==0||
            strcmp(input,"save")==0){
                save_file(ptr);
            }
        else if (strcmp(input,"VIEW")==0||strcmp(input,"view")==0){
            view_file();
        }
        
            
        
        free(ptr);    
        }
        
}
void display(item *ptr){
      printf("\n--- Inventory Item ---\n");
      printf("Name: %s\n", ptr->item_name);
       printf("Quantity: %d\n", ptr->quntity);
      printf("Quality: %d\n", ptr->item_quality);


}
void save_file(item *ptr){
    FILE *file = fopen("inventory.txt","a");
    if (file == NULL){
        printf("ERROR");
        return ;
    }
    fprintf(file,"Name: %s \n",ptr ->item_name);
    fprintf(file,"Quantity: %d \n",ptr ->quntity);
    fprintf(file,"Quality: %d\n", ptr->item_quality);
    fclose(file);
};
void view_file(){
    char buffer[1000];
    FILE *fp = fopen("inventory.txt","r");
    if(fp == NULL){
        printf("ERROR");
        return;}

        while(fgets(buffer,sizeof(buffer),fp)!=NULL){
            printf("%s",buffer);

        }
        fclose(fp);
    


}
