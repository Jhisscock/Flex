/*
 * ========================================================================
 * 
 * main.c ------- Main program file to run bison parser and scanner
 *                If no errors occur when parsing the symbol table will
 *                be printed out.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 11/5/2020
 * 
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include "symtable.h"

//Define root node
struct symtable* start = NULL;

//Creates a new node of type symtable
struct symtable* createNode(char *identifier, int dt, int ad, int type, int sz) 
{ 
   struct symtable *new_node, *node; 
   new_node = (struct symtable*) malloc(sizeof(struct symtable)); 
   new_node->id = identifier;
   new_node->datatype = dt;
   new_node->address = ad;
   
   //Based on code number assign type to current node
   if(type == TP_ARRAY){
      new_node->type = "ARRAY";
   }else{
      new_node->type = NULL;
   }
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
       printf("Variable Name: %s, Data Type: %d, Address: %d, Type: %s, Size: %d\n\n", node->id, node->datatype, node->address, node->type, node->size); 
       node = node->next; 
   } 
   printf("\n"); 
   return start; 
}

int main()
{
   if (yyparse())
      printf("Syntax error\n");
   else
      display();
      
   return 0;
}