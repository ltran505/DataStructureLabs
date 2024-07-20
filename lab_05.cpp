// Tran, Lily (Team Leader)
// Aljaffan, Maha

// Part 1
int hashValue(int key, int j, int capacity)
{
   return (((3 * key) + 3) + j * j) % capacity;
}

// Part 2
void insertKey(int table[], int capacity,
               int& numOfElements, int key)
{
   int j = 0;
   bool inserted = false;

   while (j < LIMIT && !inserted)
   {
      int index = hashValue(key, j, capacity);
      if (table[index] == 0 || table[index] == -2)
      {
         table[index] = key;
         ++numOfElements;
         inserted = true;
      }
      else if (table[index] == key)
      {
         cerr << "Key " << key <<
                  " is a duplicate." << endl;
         inserted = true;
      }
      
      ++j;
   }

   if (j == LIMIT)
   {
      cout << "Key " << key 
         << " not inserted. Need to rehash." << endl;
   }
}

// Part 3
bool searchKey(const int table[], int capacity, int key)
{
   int j = 0;
   while (j < LIMIT)
   {
      int index = hashValue(key, j, capacity);
      
      if (table[index] == 0) 
         return false;
      else if (table[index] == key)
         return true;
      
      ++j;
   }
   
   return false;
}

// Part 4
void deleteKey(int table[], int capacity, 
   int& numberOfElelment, int key)
{
   int j = 0;
   bool deleted = false;
   bool emptyIndex = false;
   while (!deleted && !emptyIndex && j < LIMIT)
   {
      int index = hashValue(key, j, capacity);
      if (table[index] == 0)
      {
         emptyIndex = true;
      }
      else if (table[index] == key)
      {
         table[index] = -2;
         deleted = true;
         --numberOfElelment;
      }
      
      ++j;
   }
   
   if (!deleted)
   {
      cout << "Key " << key << 
            " is not in the table.\n";
   }
}
