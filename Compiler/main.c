/*
 * ========================================================================
 * 
 * main.c ------- Main program file to run bison parser and scanner.
 *                Creates an array of code numbers with modifiers attached
 *                to them that will be parsed through at the end of the
 *                program. When parsed the code numbers will match a set of
 *                print statements that will add a line to a file called 
 *                output.gstal. These statements are matching gstal
 *                instructions for the given slic instructions.
 * 
 * Programmer --- Jacob Hisscock
 * Date --- 12/10/2020
 * 
 * ========================================================================
 */

#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtable.h"
#include "syntree.h"
#include <math.h>
#include "codenum.h"

int lineNumber = 0;
struct codepair* codeArray[9999];
int addressCount = 0;
int andCount = 1;
int prevao = 0;
int trueWhile = 0;
int startWhile = 0;
int startCount = 0;

//Initialize jump point stack
struct jumppoint* head = NULL;
struct jumppoint* whilehead = NULL;
struct jumppoint* push(struct jumppoint** root, int jump);
int pop(struct jumppoint** root);

//Utility to display syntax tree
void displayTree(){
   struct syntree* node;

   node = tree;
   while(node != NULL){
      printf("ID: %s, POS: %d, STATEMENT: %d\n", node->id, node->position, node->statement);
      displayExpression(node->link);
      node = node->next;
   }
}

//Utility to display Expression tree
void displayExpression(struct expression* root){
   if(root == NULL){
      return;
   }
   if(root->kind == KI_VAR){
      printf("ID: %s, OP: %d\n", root->id, root->operation);
   }else{
      printf("Value: %f, OP: %d, Kind: %d\n", root->value, root->operation, root->kind);
   }
   displayExpression(root->l_op);
   displayExpression(root->r_op);
   displayExpression(root->next);
   
   
}

//Utility to look up a symtable node for a matching id
//Returns the symbol table node
struct symtable* lookupNode(char *identifier){
   struct symtable* node;

   node = table;
   while(node != NULL){
      if(strcmp(node->id, identifier) == 0){
         return node;
      }
      node = node->next;
   }

   return NULL;
}

//Disaplys the symbol table.
void displayTable(){        
   struct symtable *p;
   
   p = table;
   while (p != NULL) {
      printf("ID: %s, DT: %d, AD: %d, TP: %d, SZ: %d\n", p->id, p->datatype, p->address, p->type, p->size);
      p = p->next;
   }
   return;
}

//Functions to store code numbers in their correct postions in the codeArray for conditional statements
void GenConditional(struct expression* node, int andor){
   if(andor == 4){
      if(node->datatype == 0){
      switch (node->operation){
      case OP_EQUAL:
         codeArray[lineNumber]->instruction = NEI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_NEI:
         codeArray[lineNumber]->instruction = EQI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GEI:
         codeArray[lineNumber]->instruction = LTI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GTI:
         codeArray[lineNumber]->instruction = LEI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LEI:
         codeArray[lineNumber]->instruction = GTI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LTI:
         codeArray[lineNumber]->instruction = GEI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      default:
         break;
      }
   }else{
      switch (node->operation){
      case OP_EQUAL:
         codeArray[lineNumber]->instruction = NEF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GEI:
         codeArray[lineNumber]->instruction = LTF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GTI:
         codeArray[lineNumber]->instruction = LEF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LEI:
         codeArray[lineNumber]->instruction = GTF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LTI:
         codeArray[lineNumber]->instruction = GEF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_NEI:
         codeArray[lineNumber]->instruction = EQF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      default:
         break;
      }
   }
   }else{
   if(node->datatype == 0){
      switch (node->operation){
      case OP_EQUAL:
         codeArray[lineNumber]->instruction = EQI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_NEI:
         codeArray[lineNumber]->instruction = NEI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GEI:
         codeArray[lineNumber]->instruction = GEI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GTI:
         codeArray[lineNumber]->instruction = GTI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LEI:
         codeArray[lineNumber]->instruction = LEI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LTI:
         codeArray[lineNumber]->instruction = LTI;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      default:
         break;
      }
   }else{
      switch (node->operation){
      case OP_EQUAL:
         codeArray[lineNumber]->instruction = EQF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GEI:
         codeArray[lineNumber]->instruction = GEF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_GTI:
         codeArray[lineNumber]->instruction = GTF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LEI:
         codeArray[lineNumber]->instruction = LTF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_LTI:
         codeArray[lineNumber]->instruction = LTF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      case OP_NEI:
         codeArray[lineNumber]->instruction = NEF;
         lineNumber++;
         push(&head, lineNumber);
         codeArray[lineNumber]->instruction = JPF;
         lineNumber++;
         break;
      default:
         break;
      }
   }
   }
}

//Used to parse and generate correct code numbers and positions for expressions
void GenExpression(struct expression* root, int datatype){
   float value;

   if(root->kind == KI_NUM){
      if(datatype == 0){
         codeArray[lineNumber]->instruction = LLI;
         codeArray[lineNumber]->imod = (int)root->value;
         lineNumber++;
      }else{
         codeArray[lineNumber]->instruction = LLF;
         codeArray[lineNumber]->fmod = root->value;
         lineNumber++;
      }
   }else if(root->kind == KI_VAR){
      codeArray[lineNumber]->instruction = LAA;
      codeArray[lineNumber]->imod = lookupNode(root->id)->address + root->position;
      lineNumber++;
      codeArray[lineNumber]->instruction = LOD;
      lineNumber++;
   }else{
      switch (root->operation){
      case OP_ADD: 
            GenExpression(root->l_op, datatype);
            GenExpression(root->r_op, datatype);
            if(datatype == 0){
               codeArray[lineNumber]->instruction = ADI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = ADF;
               lineNumber++;
            }
         break;
      case OP_SUB:
            GenExpression(root->l_op, datatype);
            GenExpression(root->r_op, datatype);
            if(datatype == 0){
               codeArray[lineNumber]->instruction = SBI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = SBF;
               lineNumber++;
            }
         break;
      case OP_MUL:
            GenExpression(root->l_op, datatype);
            GenExpression(root->r_op, datatype);
            if(datatype == 0){
               codeArray[lineNumber]->instruction = MLI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = MLF;
               lineNumber++;
            }
         break;
      case OP_DIV:
            GenExpression(root->l_op, datatype);
            GenExpression(root->r_op, datatype);
            if(datatype == 0){
               codeArray[lineNumber]->instruction = DVI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = DVF;
               lineNumber++;
            }
         break;
      case OP_UMI:
            GenExpression(root->r_op, datatype);
            if(datatype == 0){
               codeArray[lineNumber]->instruction = NEI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = NEF;
               lineNumber++;
            };
      break;
      default:
         GenExpression(root->l_op, datatype);
         GenExpression(root->r_op, datatype);
         if(root->next != NULL){
            GenConditional(root, prevao);
            GenExpression(root->next, datatype);
            if(prevao == 4){
               codeArray[pop(&head)]->imod = lineNumber + 2;
            }else{
               andCount++;
            }
            prevao = root->next->kind;
         }
         break;
      }
   }
}


//Function to insert jump points at the end of the current jump point list
struct jumppoint* push(struct jumppoint** root, int jump){
   struct jumppoint* stack = (struct jumppoint*)malloc(sizeof(struct jumppoint));
   stack->jp = jump;
   stack->next = *root;
   *root = stack;
}

int isEmpty(struct jumppoint* root)
{
    return !root;
}
//Function to remove the first node in the jump point list
int pop(struct jumppoint** root){
   if(isEmpty(*root)){
      return -1;
   }

   struct jumppoint* node = *root;
   *root = (*root)->next;
   int result = node->jp;
   free(node);
   return result;
}

void displayJP(struct jumppoint* root) {
   struct jumppoint* node;
   node = root;
   while(node != NULL){
      printf("Jump Point %d\n", node->jp);
      node = node->next;
   }
}

//Main functions that will go through the enitre syntax tree and generate matching gstal code numbers.
//As it parses it will insert the code number into the matching line number of the codeArray with any mods it might have.
int CodeGen(){
   codeArray[lineNumber]->instruction = ISP;
   codeArray[lineNumber]->imod = addressCount;
   lineNumber++;

   struct syntree* node;

   node = tree;
   while(node != NULL){
      switch (node->statement){
      case ST_ASSIGN:
         codeArray[lineNumber]->instruction = LAA;
         codeArray[lineNumber]->imod = lookupNode(node->id)->address + node->position;
         lineNumber++;
         GenExpression(node->link, lookupNode(node->id)->datatype);
         codeArray[lineNumber]->instruction = STO;
         lineNumber++;
         break;
      case ST_PRINT:
         while(node->link != NULL){
            switch (node->link->operation)
            {
            case OP_EXC:
               codeArray[lineNumber]->instruction = PTL;
               lineNumber++;
               break;
            case OP_STR: ;
               char* str = node->link->id;
               for(int i = 1; i < strlen(str) - 1; i++){
                  codeArray[lineNumber]->instruction = LLI;
                  codeArray[lineNumber]->imod = (int)str[i];
                  lineNumber++;
                  codeArray[lineNumber]->instruction = PTC;
                  lineNumber++;
               }
               break;
            default:
               GenExpression(node->link, node->link->datatype);
               if(node->link->datatype == 0){
                  codeArray[lineNumber]->instruction = PTI;
               }else{
                  codeArray[lineNumber]->instruction = PTF;
               }
               lineNumber++;
               break;
            }
            node->link = node->link->next;
         } 
         break;
      case ST_IF:
         prevao = node->link->kind;
         GenExpression(node->link, node->link->datatype);
         while (node->link->next != NULL)
         {
            node->link = node->link->next;
         }
         GenConditional(node->link, 5);
      break;
      case ST_ELSE:
         codeArray[lineNumber]->instruction = JMP;
         lineNumber++;
         codeArray[pop(&head)]->imod = lineNumber;
         push(&head, lineNumber - 1);
         break;
      case ST_ENDIF:
         for(int i = 0; i < andCount; i++){
            codeArray[pop(&head)]->imod = lineNumber;
         }
         andCount = 1;
         break;
      case ST_WHILE:
         startWhile = lineNumber;
         if(node->link->r_op == NULL && (int)node->link->value == 1){
            push(&whilehead, 1);
            push(&head, lineNumber);
         }else{
            push(&whilehead, 0);
            trueWhile = 0;
            prevao = node->link->kind;
            GenExpression(node->link, node->link->datatype);
            while (node->link->next != NULL)
            {
               node->link = node->link->next;
            }
            GenConditional(node->link, 5);
            push(&head, lineNumber);
         }
      break;
      case ST_ENDWHILE:
         if(pop(&whilehead) == 1){
            codeArray[lineNumber]->instruction = JMP;
            codeArray[lineNumber]->imod = pop(&head);
            trueWhile = 0;
            lineNumber++;
         }else{
            codeArray[lineNumber]->instruction = JMP;
            codeArray[lineNumber]->imod = startWhile;
            lineNumber++;
            pop(&head);
            for(int i = 0; i < andCount; i++){
               codeArray[pop(&head)]->imod = lineNumber;
            }
         }
         break;
      case ST_EXIT:
         codeArray[lineNumber]->instruction = HLT;
         lineNumber++;
         break;
      case ST_COUNT:;
         int address = lookupNode(node->id)->address + node->position;
         codeArray[lineNumber]->instruction = LAA;
         codeArray[lineNumber]->imod = address;
         lineNumber++;
         node->link->kind = 1;
         GenExpression(node->link, node->link->datatype);
         codeArray[lineNumber]->instruction = STO;
         lineNumber++;
         startCount = lineNumber;
         codeArray[lineNumber]->instruction = LAA;
         codeArray[lineNumber]->imod = address;
         lineNumber++;
         codeArray[lineNumber]->instruction = LAA;
         codeArray[lineNumber]->imod = address;
         lineNumber++;
         codeArray[lineNumber]->instruction = LOD;
         lineNumber++;
         if(node->link->datatype == 0){
               codeArray[lineNumber]->instruction = LLI;
               codeArray[lineNumber]->imod = 1;
               lineNumber++;
         }else{
            codeArray[lineNumber]->instruction = LLF;
            codeArray[lineNumber]->fmod = 1.0;
            lineNumber++;
         }
         if(node->link->operation == OP_LEI){
            if(node->link->datatype == 0){
               codeArray[lineNumber]->instruction = ADI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = ADF;
               lineNumber++;
            }
         }else{
            if(node->link->datatype == 0){
               codeArray[lineNumber]->instruction = SBI;
               lineNumber++;
            }else{
               codeArray[lineNumber]->instruction = SBF;
               lineNumber++;
            }
         }
         codeArray[lineNumber]->instruction = STO;
         lineNumber++;
         codeArray[lineNumber]->instruction = LAA;
         codeArray[lineNumber]->imod = lookupNode(node->id)->address + node->position;
         lineNumber++;
         codeArray[lineNumber]->instruction = LOD;
         lineNumber++;
         GenExpression(node->link->l_op, node->link->l_op->datatype);
         GenConditional(node->link, 5);
         push(&head, lineNumber);
         break;
      case ST_ENDCOUNT:
         codeArray[lineNumber]->instruction = JMP;
         codeArray[lineNumber]->imod = startCount;
         lineNumber++;
         codeArray[pop(&head) - 1]->imod = lineNumber;
         break;
      case ST_READ:
         codeArray[lineNumber]->instruction = LAA;
         //codeArray[lineNumber]->imod = lookupNode(node->id)->address + node->position;
         lineNumber++;
         if(lookupNode(node->id)->datatype == 0){
            codeArray[lineNumber]->instruction = INI;
            lineNumber++;
         }else{
            codeArray[lineNumber]->instruction = INF;
            lineNumber++;
         }
         codeArray[lineNumber]->instruction = STO;
         lineNumber++;
         break;
      default:
         break;
      }
      
      node = node->next;

   }

   codeArray[lineNumber]->instruction = HLT;
   lineNumber++;

   return 0;
}

//Fucntion that will create and display code in output.gstal
void PrintCode(){
   FILE *fp;
   fp = fopen("output.gstal", "w");

   for(int i = 0; i < lineNumber; i++){
      switch (codeArray[i]->instruction){
      case ADI:
         fprintf(fp, "ADI\n");
         break;
      case SBI:
         fprintf(fp, "SBI\n");
         break;
      case MLI:
         fprintf(fp, "MLI\n");
         break;
      case DVI:
         fprintf(fp, "DVI\n");
         break;
      case NGI:
         fprintf(fp, "NGI\n");
         break;
      case ADF:
         fprintf(fp, "ADF\n");
         break;
      case SBF:
         fprintf(fp, "SBF\n");
         break;
      case MLF:
         fprintf(fp, "MLF\n");
         break;
      case DVF:
         fprintf(fp, "DVF\n");
         break;
      case NGF:
         fprintf(fp, "NGF\n");
         break;
      case EQI:
         fprintf(fp, "EQI\n");
         break;
      case NEI:
         fprintf(fp, "NEI\n");
         break;
      case LTI:
         fprintf(fp, "LTI\n");
         break;
      case LEI:
         fprintf(fp, "LEI\n");
         break;
      case GTI:
         fprintf(fp, "GTI\n");
         break;
      case GEI:
         fprintf(fp, "GEI\n");
         break;
      case EQF:
         fprintf(fp, "EQF\n");
         break;
      case NEF:
         fprintf(fp, "NEF\n");
         break;
      case LTF:
         fprintf(fp, "LTF\n");
         break;
      case LEF:
         fprintf(fp, "LEF\n");
         break;
      case GTF:
         fprintf(fp, "GTF\n");
         break;
      case GEF:
         fprintf(fp, "GEF\n");
         break;
      case FTI:
         fprintf(fp, "FTI\n");
         break;
      case ITF:
         fprintf(fp, "ITF\n");
         break;
      case PTI:
         fprintf(fp, "PTI\n");
         break;
      case PTF:
         fprintf(fp, "PTF\n");
         break;
      case PTC:
         fprintf(fp, "PTC\n");
         break;
      case PTL:
         fprintf(fp, "PTL\n");
         break;
      case INI:
         fprintf(fp, "INI\n");
         break;
      case INF:
         fprintf(fp, "INF\n");
         break;
      case LLI:
         fprintf(fp, "LLI %d\n", codeArray[i]->imod);
         break;
      case LLF:
         fprintf(fp, "LLF %f\n", codeArray[i]->fmod);
         break;
      case ISP:
         fprintf(fp, "ISP %d\n", codeArray[i]->imod);
         break;
      case DSP:
         fprintf(fp, "DSP %d\n", codeArray[i]->imod);
         break;
      case STO:
         fprintf(fp, "STO\n");
         break;
      case STM:
         fprintf(fp, "STM\n");
         break;
      case LOD:
         fprintf(fp, "LOD\n");
         break;
      case LAA:
         fprintf(fp, "LAA %d\n", codeArray[i]->imod);
         break;
      case LRA:
         fprintf(fp, "LRA %d\n", codeArray[i]->imod);
         break;
      case JMP:
         fprintf(fp, "JMP %d\n", codeArray[i]->imod);
         break;
      case JPF:
         fprintf(fp, "JPF %d\n", codeArray[i]->imod);
         break;
      case PAR:
         fprintf(fp, "PAR %d\n", codeArray[i]->imod);
         break;
      case CAL:
         fprintf(fp, "CAL %d\n", codeArray[i]->imod);
         break;
      case RET:
         fprintf(fp, "RET\n");
         break;
      case NOP:
         fprintf(fp, "NOP\n");
         break;
      case HLT:
         fprintf(fp, "HLT\n");
         break;
      default:
         break;
      }
   }

   fclose(fp);
}

//Initiate parsing and code generation
int main()
{
   for(int i = 0; i < 9999; i++){
      codeArray[i] = malloc(sizeof(struct codepair));
   }
   if (yyparse()){
      printf("Syntax error\n");
   }else{
      displayTable();
      CodeGen();
      PrintCode();
   }
   return 0;
}