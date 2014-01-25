#include "pque.h"

#define PARENT(N) ((N) >> 1)
#define LCHILD(N) ((N) << 1)
#define RCHILD(N) (((N) << 1) + 1)

void PQue_Init(PQue* queue)
{
  u32 i;
  queue->capacity = PQUE_MAX_SIZE;
  queue->size = 0;
  
  for(i = 0; i < queue->capacity; i++)
  {
    queue->queue[i] = 0;
  }
}

void PQue_Swap(PQue* queue, u32 idxA, u32 idxB)
{
  Command* cmd = queue->queue[idxA];
  queue->queue[idxA] = queue->queue[idxB];
  queue->queue[idxB] = cmd;
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