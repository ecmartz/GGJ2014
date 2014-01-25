#include <stdlib.h>
#include <stdio.h>
<<<<<<< HEAD

=======
>>>>>>> 4209d7fa695ed3ca80122e5b0635d01b657a6f19
#include "pque.h"

#define PARENT(N) ((N) >> 1)
#define LCHILD(N) ((N) << 1)
#define RCHILD(N) (((N) << 1) + 1)

void PQue_Swap(PQue* queue, u32 idxA, u32 idxB)
{
  Command* cmd = queue->queue[idxA];
  queue->queue[idxA] = queue->queue[idxB];
  queue->queue[idxB] = cmd;
}

void PQue_Init(PQue* queue)
{
  u32 i;
  queue->capacity = PQUE_MAX_SIZE;
  queue->size = 0;
  
  for(i = 0; i < queue->capacity; i++)
  {
    queue->queue[i] = NULL;
  }
}


void PQue_HeapifyUp(PQue* queue, u32 index)
{
  u32 pIdx = PARENT(index);
  if(pIdx && queue->queue[index]->executionTick < queue->queue[pIdx]->executionTick)
  {
    PQue_Swap(queue, index, pIdx);
    PQue_HeapifyUp(queue, pIdx);
  }
}

void PQue_HeapifyDown(PQue* queue, u32 index)
{
  u32 lidx = LCHILD(index);
  u32 ridx = RCHILD(index);
  Command** q = queue->queue;
  u32 lowIdx;

  if(lidx > queue->size || ridx > queue->size)
  {
    return;
  }

  lowIdx = q[lidx]->executionTick < q[ridx]->executionTick ? lidx : ridx;

  if(q[index]->executionTick > q[lowIdx]->executionTick)
  {
    PQue_Swap(queue, index, lowIdx);
    PQue_HeapifyDown(queue, lowIdx);
  }
}

void PQue_Insert(PQue* queue, Command* command)
{
  queue->queue[++queue->size] = command;
  PQue_HeapifyUp(queue, queue->size);
}

Command* PQue_Remove(PQue* queue)
{
  Command* top = queue->queue[1];
  if(queue->size < 1)
  {
    perror("\n\nPQue_Remove: EMPTY QUEUE!\n\n");
    exit(2);
  }
  PQue_Swap(queue, queue->size, 1);
  queue->size--;
  
  PQue_HeapifyDown(queue, 1);
<<<<<<< HEAD
=======

>>>>>>> 4209d7fa695ed3ca80122e5b0635d01b657a6f19
  return top;
}
