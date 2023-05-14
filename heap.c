#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){

  if(pq->size == 0) return NULL;

  return pq->heapArray[0].data;
    
}



void heap_push(Heap* pq, void* data, int priority){

  if(pq->size == pq->capac)
  {
    pq->capac = pq->capac * 2+1
    pq->heapArray = realloc(pq->heapArray,pq->capac * sizeof(heapElem));
  }

  int posicion = pq->size;

  while(priority > pq->heapArray[(posicion-1) / 2 ].priority && posicion)
    {
      pq->heapArray[posicion] = pq->heapArray[(posicion-1)/2];
      posicion = (posicion -1) / 2;
    }
  pq->heapArray[posicion].data = data;
  pq->heapArray[posicion].priority = priority;
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap(){

  Heap *auxM = malloc(sizeof(Heap));
  auxM->heapArray = (heapElem *)malloc(3*sizeof(heapElem));

  auxM->size = 0;
  auxM->capac = 3;

   return auxM;
}
