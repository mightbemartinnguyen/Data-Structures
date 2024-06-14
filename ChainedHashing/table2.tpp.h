// FILE: table2.tpp.h
// TEMPLATE CLASS IMPLEMENTED: Table (see table2.h for documentation)
// INVARIANT for the Table ADT:
//   1. The number of records in the Table is in the member variable
//      total_records.
//   2. The actual records of the table are stored in a chained hash table.
//      An entry with key i is stored on the linked list with the head
//      pointer at data[hash(i)].

#include <assert.h> // Provides assert

template <class RecordType>
size_t Table<RecordType>::hash_function(int key) const
{
	return (key % TABLE_SIZE);
}

template <class RecordType>
Table<RecordType>::Table()
{
    size_t i;
    total_records = 0;

    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = 0;
    }
}

template <class RecordType>
Table<RecordType>::~Table()
{
    Node<RecordType>* currentPtr;
    Node<RecordType>* removePtr;

    for (size_t i = 0; i < TABLE_SIZE; i++) {
        currentPtr = hash_table[i];
        while (currentPtr != 0) {
            removePtr = currentPtr;
            currentPtr = currentPtr->link;
            delete removePtr;
        }
        hash_table[i] = 0;
    }

    total_records = 0;
}

template <class RecordType>
Table<RecordType>::Table(const Table<RecordType>& source)
{
    size_t i;
    total_records = 0;
    
    for (i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = 0;
    }
   
   
    for (i = 0; i < TABLE_SIZE; i++) {
        Node<RecordType>* sourceNode = source.hash_table[i];
        Node<RecordType>* destination = 0;
        while (sourceNode != 0) {
            if (destination == 0) {
                hash_table[i] = new Node<RecordType>;
                destination = hash_table[i];
            }
            else {
                destination->link = new Node<RecordType>;
                destination = destination->link;
            }
            destination->data = sourceNode->data;
            destination->link = 0;
            sourceNode = sourceNode->link;
            total_records++;
        }
    }
}

template <class RecordType>
void Table<RecordType>::insert(const RecordType& entry)
{
	Node<RecordType>* cursor; 
	assert(entry.key >= 0);
	cursor = find_node(entry.key);
	if (cursor != 0) {
		cursor->data = entry;
	}
	else {
		size_t hashIndex = hash_function(entry.key);
		Node<RecordType>* newNode = new Node<RecordType>;
        newNode->data = entry;
        newNode->link = hash_table[hashIndex];
		hash_table[hashIndex] = newNode;
		total_records++;
	}
}

template <class RecordType>
void Table<RecordType>::remove(int key)
{
    Node<RecordType>* cursor;    
    Node<RecordType>* precursor; 
    assert(key >= 0);

   
    cursor = find_node(key);
    if (cursor != 0) {
        if (cursor == hash_table[hash_function(key)]) {
            hash_table[hash_function(key)] = cursor->link;
        }
        else {
            precursor = hash_table[hash_function(key)];
            while (precursor->link != cursor)
                precursor = precursor->link;
            precursor->link = cursor->link;
        }
        delete cursor;
        total_records--;
    }
}

template <class RecordType>
void Table<RecordType>::remove(int key)
{
    Node<RecordType>* cursor;
    Node<RecordType>* precursor;
    assert(key >= 0);


    cursor = find_node(key);
    if (cursor != 0) {
        if (cursor == hash_table[hash_function(key)]) {
            hash_table[hash_function(key)] = cursor->link;
        }
        else {
            precursor = hash_table[hash_function(key)];
            while (precursor->link != cursor)
                precursor = precursor->link;
            precursor->link = cursor->link;
        }
        delete cursor;
        total_records--;
    }
}

template <class RecordType>
bool Table<RecordType>::is_present(int key) const
{
    assert(key >= 0);

    Node<RecordType>* cursor = find_node(key);
    return (cursor != 0);
}

template <class RecordType>
void Table<RecordType>::find(int key, bool& found, RecordType& result) const
{
    Node<RecordType>* cursor = find_node(key);
    if (cursor == 0) {
        found = false;
    }
    else {
        found = true;
        result = cursor->data;
    }
}

template <class RecordType>
Node<RecordType>* Table<RecordType>::find_node(int key) const
{
    Node<RecordType>* cursor;
    size_t i = hash_function(key);
    cursor = hash_table[i];
    
    while ((cursor != 0) && (cursor->data.key != key)) {
        cursor = cursor->link;
    }
    
    return cursor;
}
