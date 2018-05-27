#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
typedef struct StackNode//mo ta Stack
        {
               char* item;
               struct StackNode *next;
        }STACKNODE;
typedef struct Stack
        {
               STACKNODE *top;
        }STACK;
int StackEmpty(const STACK *s)//kiem tra stack rong
    {
                return(s->top==NULL);
    }
int StackFull()//thong bao stack tran
    {
               printf("\nNO MEMORY! STACK IS FULL");
               system("pause");
               return 1;
    }
void Disp(STACK *s)//in ra cac phan tu cua stack
     {
                STACKNODE *node;
                int ct=0;
                char* m;
                printf("DANH SACH CAC PHAN TU CUA STACK\n\n");
                if(StackEmpty(s))
                {
                                 printf(">>>>>>>Stack Empty<<<<<<<\n");
                                 system("pause");
                }else{
                                 node=s->top;
                                 do{
                                             m=node->item;
                                             printf("%8.3s ",m);
                                             ct++;
                                             if(ct%9==0) printf("\n");
                                             node=node->next;
                                 }while(!(node==NULL));
                                 printf("\n");
                }
     }
int StackPush(STACK *s,char* item)//bo sung item vao stack
    {
                    STACKNODE *node;
                    node=(STACKNODE*) malloc(sizeof(STACKNODE));//tao nut moi cho item
                    if(node==NULL)
                    {
                                  StackFull();
                                  return 1;//Out of memory, Stack overflow
                    }
                    node->item=item;
                    node->next=s->top;//moc node vao diem dau cua stack
                    s->top=node;//node tro thanh top cua stack
                    return 0;
    }
char* StackPop(STACK* s)
      {
                      char* item;
                      STACKNODE *node;
                      if(StackEmpty(s)) return NULL;//Empty Stack, can't pop
                      node=s->top;
                      item=node->item;
                      s->top=node->next;
                      free(node);
                      return item;
      }
void StackDestroy(STACK *s)//giai phong stack
     {
                        while(!StackEmpty(s)) StackPop(s);
                        free(s);
     }
int toantu(char* c)//tinh do uu tien cua toan tu
    {
                    if((c=="sin")||(c=="cos")||(c=="tan")||(c=="cot")||/*(c=="!")*/(c=="sqrt")||(c=="~")||(c=="^")||(c=="++")) return 6;
                    else if((c=="*")||(c=="/")||(c=="%")) return 5;
                    else if((c=="+")||(c=="-")) return 4;
                    else if((c==">=")||(c=="<=")||(c==">")||(c=="<")||/*(c=="==")*/(c=="!=")) return 3;
                    else if(c=="NOT") return 2;
                    else if((c=="OR")||(c=="AND")) return 1;
                    else if(c=="=") return 0;
                    else return -1;
                     
    }
int toanhang(char *c)
    {
                  if((isalpha(((int)c)))||(isdigit(((int)c)))) return 1;
                  else return 0;
    }
main()
{
      STACK *stack1,*stack2;
      stack1=(STACK*) malloc(sizeof(STACK));
      stack2=(STACK*) malloc(sizeof(STACK));
      if((stack1==NULL)||(stack2==NULL))printf("Khong du bo nho cho stack\n");
      else printf("Stack construct complete!\n");
      stack1->top=NULL;
      stack2->top=NULL;
      FILE *input,*output;
      char *fin,*fout,*InputItem,*temp;
      fin="input.txt";//khai bao ten file
      fout="output.txt";
      if(input=fopen(fin,"r")) printf("Open input file complete.\n");//mo file
      if(output=fopen(fout,"w")) printf("Open output file complete.\n");
      do//duyet
      {
               fscanf(input,"%s",&InputItem);//doc du lieu tu input
               if(toanhang(InputItem)==1){
                                   StackPush(stack2,InputItem);//neu la toan hang thi day vao bieu thuc
                                   fprintf(output,"%s ",&InputItem);//va ghi ra output
                                   }
               else if(InputItem=="(") StackPush(stack1,InputItem);//neu la '(' thi day vao stack
               else if((InputItem==")"))
                    {
                                do{//lay tat ca toan hang trong stack cho toi khi gap '(' va day vao bieu thuc
                                                temp=StackPop(stack1);
                                                StackPush(stack2,temp);
                                                fprintf(output,"%s ",&temp);
                                }while(temp!="(");
                    }
               else if(toantu(InputItem)==6) StackPush(stack1,InputItem);/*
                    else{
                         while(!StackEmpty(stack1))//chung nao stack chua rong
                         {
                                temp=StackPop(stack1);
                                if(toantu(temp)>=toantu(InputItem)){
                                                                    StackPush(stack2,temp);//lay toan tu do ra va day vao bieu thuc
                                                                    fprintf(output,"%s ",&temp);
                                                                    }
                                else{
                                     StackPush(stack1,temp);
                                     break;
                                     }//tra lai toan tu vua lay ra
                         }
                         StackPush(stack1,InputItem);//day toan tu hien tai vao stack
                        }*/
      }while(!feof(input));
      while(!StackEmpty(stack1))
      {
                                temp=StackPop(stack1);
                                StackPush(stack2,temp);
                                fprintf(output,"%s ",temp);
      }
      if(!fclose(input)) printf("Input file closed.\n");//dong tep
      if(!fclose(output)) printf("Output file closed.\n");
      system("pause");//dung lai kiem tra ket qua
}
