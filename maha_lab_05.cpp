//Part 1

int hashValue(int key, int j, int capacity)
{
   return (((3 * key) + 3) + j * j) % capacity;
}

//Part 2

void insertKey(int table[], int capacity,
                  int& numOfElements, int key)
{
   int j = 0;
   bool inserted = false;
   
   while(j < LIMIT && !inserted)
   {
      int index = hashValue(key, j, capacity);
      if(table[index] == 0 || table[index] == -2)
      {
         table[index] = key;
         ++numOfElements;
         inserted = true;
      }
      else if(table[index] == key)
      {
         cerr << "Key " << key <<
                  " is a duplicate." << endl;
         inserted = true;
      }
      ++j;
   }
   
   if(j == LIMIT)
   {
      cerr << "Key " << key 
         << " not inserted. Need to rehash." << endl;
   }
}

//Part 3

bool searchKey(const int table[], int capacity, int key)
{
   int j = 0;
   while(j < capacity)
   {
      int index = hashValue(key, j, capacity);
      if(table[index] == key)
      {
         return true;
      }
      else if(table[index] == -1)
      {
         return false;
      }
      ++j;
   }
   return false;
}

//Part 4

void deleteKey(int table[], int capacity,
               int& numOfElements, int key)
{
   int j = 0;
   bool deleted = false;
   
   while(j < LIMIT && !deleted)
   {
      int index = hashValue(key, j, capacity);
      if(table[index] == key)
      {
         table[index] = -2;
         --numOfElements;
         deleted = true;
      }
      else if(table[index] == -1)
      {
         deleted = true;
         cerr << "Key " << key
            << " is not in the table." << endl;
      }
      ++j;
   }
   
   if(j == LIMIT)
   {
      cerr << "Key " << key
         << " is not in the table." << endl;
   }
}
