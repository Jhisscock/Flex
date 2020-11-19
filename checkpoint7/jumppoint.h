/*
 * ==========================================================================
 * 
 * checkpoint7.y ----- Jump point list for if else statements.
 * Programmer --- Jacob Hisscock
 * Date --- 11/19/2020
 * 
 * ==========================================================================
 */

#ifndef JUMPPOINT_H
#define JUMPPOINT_H

//Define jump point list includes next node and a jump point
struct jumppoint { 
    int jp;
    struct jumppoint* next; 
}; 

//Function declartaions to display add and remove nodes from the list
void displayJP(struct jumppoint* root);
struct jumppoint* push(int jump);
int pop(struct jumppoint** headRef);
#endif