// Tran, Lily (Team Leader)
// Aljaffan, Maha

// Part 1
void iterSwapStacks(stack<int>& firstStack, stack<int>& secondStack)
{
   while (!firstStack.empty())
   {
      int length = static_cast<int>(firstStack.size());
      for (int i = 0; i < length; ++i)
      {
         secondStack.push(firstStack.top());
         firstStack.pop();
      }
      
      int element = secondStack.top();
      secondStack.pop();
      for (int j = 0; j < length - 1; ++j)
      {
         firstStack.push(secondStack.top());
         secondStack.pop();
      }
      
      secondStack.push(element);
   }
   
}

// Part 2
void recurSwapStacks(stack<int>& firstStack, stack<int>& secondStack)
{
   if (!firstStack.empty())
   {
      int element = firstStack.top();
      firstStack.pop();
      recurSwapStacks(firstStack, secondStack);
      secondStack.push(element);
   }
} 

// Part 3
void stlSwapStacks(stack<int>& firstStack, stack<int>& secondStack)
{
   secondStack.swap(firstStack);
}

// Part 4
void moveStacks(stack<int>& firstStack, stack<int>& secondStack)
{
   secondStack = move(firstStack);
}
