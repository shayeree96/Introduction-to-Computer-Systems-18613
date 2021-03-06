/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 * Modified to store strings, 2018
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "harness.h"
#include "queue.h"
/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    queue_t *q =(queue_t *)malloc(sizeof(queue_t));
    if(q==NULL)
     return q;
    else
    { 
    /* What if malloc returned NULL? */
    q->head = NULL;
    q->tail= NULL;
    q->qsize = 0;/*We derefernce the pointer and hence use q--> or (q*).members*/
    return q;
    } 
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* How about freeing the list elements and the strings? */
    /* Free queue structure */
    list_ele_t *temp;
    if(q==NULL)
      return;
    if(q!=NULL)
    {    
    while(q->head!=NULL)
    {
        temp=q->head;
        q->head=q->head->next;
        free(temp->value);
        free(temp);
    }    
    free(q);
}
}
/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_head(queue_t *q, char *s)
{
    list_ele_t *newh;
    char *news;
    /* What should                                                 you do if the q is NULL? */
    if(q==NULL)
      return false;
    else
    {  
     newh = (list_ele_t *)malloc(sizeof(list_ele_t));
     if(newh==NULL)
     {
       free(newh);      
       return false;
      } 
     else
     {   
      news=malloc(strlen(s)+1);
      if(news==NULL)
       {
       	free(newh);
	       
	     return false;
       }
      else
      {
       strcpy(news,s);
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
       newh->value=news;
      if(q->head!=NULL)
      {
        newh->next = q->head;
        q->head = newh;
        q->qsize++;
        return true;
        
      }
      else{
      newh->next=NULL;
      q->head=newh;
      q->tail=newh;
      q->qsize++;
      return true;
      }
      }
}
}
}
/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
  Argument s points to the string to be stored.
  The function must explicitly allocate space and copy the string into it.
 */
bool q_insert_tail(queue_t *q, char *s)
{
	list_ele_t *newt;
    char *news;
    /* What should you do if the q is NULL? */
    if(q==NULL)
      return false;
    else
    {  
     newt = (list_ele_t *)malloc(sizeof(list_ele_t));
     if(newt==NULL)
       return false;
     else
     {   
      news=malloc(strlen(s)+1);
      if(news==NULL)
       {
	       free(newt);
         return false;
       }
      else
      {
       strcpy(news,s);
       newt->value=news;
    /* Don't forget to allocate space for the string and copy it */
    /* What if either call to malloc returns NULL? */
    
      if(q->tail!=NULL)
      {
        
        q->tail->next = newt;
        newt->next = NULL;
        q->tail=newt;
        q->qsize++;
        return true;
      }
      else{
      newt->next=NULL;
      q->tail=newt;
      q->head=newt;
      q->qsize++;
      return true;
      }
      }
}
}
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If sp is non-NULL and an element is removed, copy the removed string to *sp
  (up to a maximum of bufsize-1 characters, plus a null terminator.)
  The space used by the list element and the string should be freed.
*/
bool q_remove_head(queue_t *q, char *sp, size_t bufsize)
{
    list_ele_t *temp;  
    if(q==NULL)
      return false;
    else
    if(q->qsize==0)
      return false;  
    else
    {  
      if(q->head!=NULL && sp!=NULL )
      {
        size_t n;
        n=bufsize-1;
        q->qsize--;
        temp=q->head;
        if(bufsize<strlen(temp->value))
        {
         q->head=q->head->next;
         strncpy(sp,temp->value,n);
         sp[n]='\0';
         free(temp->value);
         free(temp);
         return true;
         }
        else
        {
         q->head=q->head->next;
         strcpy(sp,temp->value);
         free(temp->value);
         free(temp);
         return true;
         
        }
      }
      
      else
      {
        return false;
        //q->qsize--;
        //temp=q->head;
        //q->head=q->head->next;
        //free(temp->value);
       // free(temp);
        //return true;
      }
       
      }
}


/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* You need to write the code for this function */
    /* Remember: It should operate in O(1) time */
   if(q!=NULL)
      return (q->qsize);
   else
     return 0;   
}

/*
  Reverse elements in queue
  No effect if q is NULL or empty
  This function should not allocate or free any list elements
  (e.g., by calling q_insert_head, q_insert_tail, or q_remove_head).
  It should rearrange the existing ones.
 */
void q_reverse(queue_t *q)
{
    /* You need to write the code for this function */
  list_ele_t *prev;
  list_ele_t *current;
  list_ele_t *next;

  
  if(q==NULL)
  {
   return;
   }
  else
  if(q->qsize<=1)
    return;
  else
  {
  prev=q->head;
  current=prev->next;
  prev->next=NULL;
  q->tail=prev;   
  while(current!=NULL)
  {
    next=current->next;
    current->next=prev;
    prev=current;
    current=next;
  }
  
  q->head=prev;
  q->tail->next=NULL;
  }
}




