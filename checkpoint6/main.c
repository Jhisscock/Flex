/*
 * ========================================================================
 * 
 * main.c ------- Main program file to run bison parser and scanner
 *                If no errors occur a gstal file will be created with
 *                opertaions that will store variables in a slic program 
 *                into unique memory addresses.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 11/5/2020
 * 
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "syntree.h"

//Define memory count
int adCount = 0;

//Define root node
struct symtable* start = NULL;

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

struct syntree *createSTree(char *identifier, int operation, float v, int pos)
{
   struct syntree *new_node, *node; 
   new_node = (struct syntree*) malloc(sizeof(struct syntree)); 
   new_node->id = identifier;
   new_node->op = operation;
   new_node->value = v;
   new_node->posistion = pos;
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
   FILE *fp;
   fp = fopen("c6.gstal", "w");
   fprintf(fp, "ISP %d\n", adCount);
   
   struct syntree* node;
   node = rootTree;
   node = rootTree->next;
   
   while(node != NULL){
      struct symtable *tNode;
      tNode = lookup(node);
      if(node->op == 1){
         int pos = tNode->address + node->posistion;
         if(pos >= tNode->size + tNode->address){
            printf("Address outside memory range for current variable %s\n", tNode->id);
            return 0;
         }
         fprintf(fp, "LAA %d\n", pos);
         if(tNode->datatype == 0){
            fprintf(fp, "LLI %d\nSTO\n", (int)node->value);
         }else{
            fprintf(fp, "LLF %f\nSTO\n", node->value);
         }
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
       printf("Variable Name: %s, Operation: %d, Value: %d\n\n", node->id, node->op, node->value); 
       node = node->next; 
   } 
   printf("\n"); 
   return rootTree; 
}

int main()
{
   if (yyparse())
      printf("Syntax error\n");
   else if(expEval()){
      printf("Succesfully generated gstal code in file c6.gstal");
   }else{
      printf("Error when generating gstal code");
   }
      
   return 0;
}