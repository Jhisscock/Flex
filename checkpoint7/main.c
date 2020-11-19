/*
 * ========================================================================
 * 
 * main.c ------- Main program file to run bison parser and scanner
 *                If no errors occur a gstal file will be created with
 *                opertaions that will store variables in a slic program 
 *                into unique memory addresses. Also it will generate gstal
 *                for if/else statements and print statements
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 11/19/2020
 * 
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "syntree.h"
#include "jumppoint.h"

int charCount(char* str);
//Define memory count
int adCount = 0;
int lineNum = 1;

//Define root node
struct symtable* start = NULL;
struct jumppoint* head = NULL;

//Creates a new node of type symtable
struct symtable* createNode(char *identifier, int dt, int ad, int tp, int sz) 
{ 
   struct symtable *new_node, *node; 
   new_node = (struct symtable*) malloc(sizeof(struct symtable)); 
   new_node->id = identifier;
   new_node->datatype = dt;
   new_node->address = ad;
   new_node->type = tp;
   new_node->size = sz;
   
   new_node->next = NULL; 
   
   //If start node does not exist yet intilize it and point to the new node else loop through all nodes until the last one and insert new node there
   if (start == NULL) { 
       start = (struct symtable*) malloc(sizeof(struct symtable)); 
       start->next = new_node; 
   } 
   else {
       node = start; 
       while (node->next != NULL) { 
           node = node->next; 
       } 
       node->next = new_node; 
   } 
   return start; 
}

//Displays current symbol table
struct symtable* display() 
{ 
   struct symtable* node; 
   node = start; 
   node = node->next;
   while (node != NULL) {
       printf("Variable Name: %s, Data Type: %d, Address: %d, Type: %d, Size: %d\n\n", node->id, node->datatype, node->address, node->type, node->size); 
       node = node->next; 
   } 
   printf("\n"); 
   return start; 
}

//Define root node of syntax tree
struct syntree* rootTree = NULL;

struct syntree *createSTree(char *identifier, int operation, float v, int pos, int cond)
{
   struct syntree *new_node, *node; 
   new_node = (struct syntree*) malloc(sizeof(struct syntree)); 
   new_node->id = identifier;
   new_node->op = operation;
   new_node->value = v;
   new_node->posistion = pos;
   new_node->conditional = cond;
   new_node->next = NULL; 
   
   //If start node does not exist yet intilize it and point to the new node else loop through all nodes until the last one and insert new node there
   if (rootTree == NULL) { 
       rootTree = (struct syntree*) malloc(sizeof(struct syntree)); 
       rootTree->next = new_node; 
   } 
   else {
       node = rootTree; 
       while (node->next != NULL) { 
           node = node->next; 
       } 
       node->next = new_node; 
   } 
   return rootTree;
}

//Evaluates all expression within symbol table and generates gstal code for the expressions
int expEval()
{
   displayTree();
   FILE *fp;
   fp = fopen("c7.gstal", "w");
   fprintf(fp, "ISP %d\n", adCount);
   lineNum++;
   
   struct syntree* node;
   node = rootTree;
   node = rootTree->next;
         int count = 1;
   while(node != NULL){
      if(node->conditional == 1){
         char* str = node->id;
         for(int i = 1; i < strlen(str) - 1; i++){
            fprintf(fp, "LLI %d\nPTC\n", (int)str[i]);
         }
         node = node->next;
         continue;

      }else if(node->conditional == 2){
         fprintf(fp, "PTL\n");
         node = node->next;
         continue;

      }

      if(lookup(node) == 0){
         printf("Variable name not declared: %s\n", node->id);
         return 0;
      }
      struct symtable *tNode = lookup(node);

      int address = tNode->address;
      int postion = node->posistion;
      int size = tNode->size;
      char* id = tNode->id;
      float value = node->value;
      int pos = address + postion;

      switch (node->op){
         case 0:
            break;
         case 1: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\n", pos);
            lineNum++;
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nSTO\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nSTO\n", value);
            }
            
            break;
         case 2: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nEQI\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nEQF\n", value);
            }
            fprintf(fp, "JPF %d\n", pop(&head));
            
            break;
         case 3: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nGEI\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nGEF\n", value);
            }
            fprintf(fp, "JPF %d\n", pop(&head));
            
            break;
         case 4: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nLEI\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nLEF\n", value);
            }
            fprintf(fp, "JPF %d\n", pop(&head));
            
            break;
         case 5: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nGTI\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nGTF\n", value);
            }
            fprintf(fp, "JPF %d\n", pop(&head));
            
            break;
         case 6: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nLTI\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nLTF\n", value);
            }
            fprintf(fp, "JPF %d\n", pop(&head));
            
            break;
         case 7: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            if(tNode->datatype == 0){
               fprintf(fp, "LLI %d\nNEI\n", (int)value);
            }else{
               fprintf(fp, "LLF %f\nNEF\n", value);
            }
            fprintf(fp, "JPF %d\n", pop(&head));
            
            break;
         case 8: ;
            if(pos >= size + address){
               printf("Address outside memory range for current variable %s\n", id);
               return 0;
            }
            fprintf(fp, "LAA %d\nLOD\n", pos);
            if(tNode->datatype == 0){
               fprintf(fp, "PTI\n");
            }else{
               fprintf(fp, "PTF\n");
            }
            
            break;
         default:
            break;
      }
      node = node->next;
                  
   }

   

   fprintf(fp, "HLT\n");
   fclose(fp);

   return 1;
}

//Finds variable in symble table with the same identifier as the syntax tree and returns the symble table node
struct symtable *lookup(struct syntree *treeNode){
   struct symtable* node;
   node = start;
   node = start->next;
   while(node != NULL){
      if(strcmp(node->id, treeNode->id) == 0){
         return node;
      }
      node = node->next;
   }

   
   return 0;
}

//Utility function to display nodes within syntax tree
struct syntree* displayTree() 
{ 
   struct syntree* node; 
   node = rootTree; 
   node = node->next;
   while (node != NULL) {
       printf("Variable Name: %s, Operation: %d, Value: %f, Position %d, Conditional %d\n\n", node->id, node->op, node->value, node->posistion, node->conditional); 
       node = node->next; 
   } 
   printf("\n"); 
   return rootTree; 
}

//Utility function to display jump point list
void displayJP(struct jumppoint* root) {
   struct jumppoint* node;
   node = root;
   while(node != NULL){
      printf("Jump Point %d\n", node->jp);
      node = node->next;
   }
}

//Function to insert jump points at the end of the current jump point list
struct jumppoint* push(int jump){
   struct jumppoint *new_node, *node;
   new_node = (struct jumppoint*)malloc(sizeof(struct jumppoint));
   new_node->jp = jump;

   if (head == NULL) { 
       head = (struct jumppoint*) malloc(sizeof(struct jumppoint)); 
       head->next = new_node; 
   } 
   else {
       node = head; 
       while (node->next != NULL) { 
           node = node->next; 
       } 
       node->next = new_node; 
   } 
   return head;
}

//Function to remove the first node in the jump point list
int pop(struct jumppoint** headRef){
   if(headRef == NULL){
      return -1;
   }

   struct jumppoint* node = *headRef;
   int result = node->next->jp;

   (*headRef) = (*headRef)->next;
   free(node);
   return result;
}

//Counts the number of charaters in a string
int charCount(char* str){
   int count = 0;
   for(int i = 1; i < strlen(str) - 1; i++){
      count++;
   }

   return count;
}

int main()
{
   if (yyparse())
      printf("Syntax error\n");
   else if(expEval()){
      printf("Succesfully generated gstal code in file c7.gstal");
   }else{
      printf("Error when generating gstal code");
   }
      
   return 0;
}