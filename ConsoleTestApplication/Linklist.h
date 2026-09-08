// module	:	linklist.h
// by		:	Al Stevens Teach Yourself C++
// date
// overview	:	This header file implements a linked list template
//				class data structure.  This template is designed to 
//				hold the addresses of the  T data type. If the Data
//				Type used is not intrinsic, you must define a default
//				contructor for it.
//

#ifndef LINKLIST_H
#define LINKLIST_H

//  Forward Class Reference
template <class T> class LinkedList;

template <class T>
// --- the linked list entry
class ListEntry    {
    T *thisentry;  // Pointer To Data For ListEntry To Hold
    ListEntry *nextentry;
    ListEntry *preventry;
    ListEntry(T& entry);
    ~ListEntry(void);
    friend class LinkedList<T>;
};

template <class T>
// ---- construct a linked list entry
ListEntry<T>::ListEntry(T &entry)
{
    thisentry = &entry;	// Initialize To Address Of Data to Hold
    nextentry = 0;
    preventry = 0;
}


template <class T>
ListEntry<T>::~ListEntry(void)
{
    delete thisentry;	// Deallocate Data 
}



template <class T>
// ---- the linked list
class LinkedList    {
    // --- the listhead
    ListEntry<T> *firstentry;
    ListEntry<T> *lastentry;
    ListEntry<T> *iterator;
    void RemoveEntry(ListEntry<T> *lentry);
    void InsertEntry(T& entry, ListEntry<T> *lentry);
public:
    LinkedList();
    ~LinkedList();
	void Destroy();
    void AppendEntry(T& entry);
    void RemoveEntry(int pos = -1);
    void InsertEntry(T&entry, int pos = -1);
    T *FindEntry(int pos);
    T *CurrentEntry();
    T *FirstEntry();
    T *LastEntry();
    T *NextEntry();
    T *PrevEntry();
};

template <class T>
// ---- construct a linked list
LinkedList<T>::LinkedList()
{
    iterator = 0;
    firstentry = 0;
    lastentry = 0;
}

template <class T>
// ---- destroy a linked list
LinkedList<T>::~LinkedList()
{
    while (firstentry)
        RemoveEntry(firstentry);
}

template <class T>
// ---- destroy a linked list
void LinkedList<T>::Destroy()
{
    while (firstentry)
        RemoveEntry(firstentry);
}

template <class T>
// ---- append an entry to the linked list
void LinkedList<T>::AppendEntry(T& entry)
{
    ListEntry<T> *newentry = new ListEntry<T>(entry);
    newentry->preventry = lastentry;
    if (lastentry)
        lastentry->nextentry = newentry;
    if (firstentry == 0)
        firstentry = newentry;
    lastentry = newentry;
}

template <class T>
// ---- remove an entry from the linked list
void LinkedList<T>::RemoveEntry(ListEntry<T> *lentry)
{
    if (lentry == 0)
        return;
    if (lentry == iterator)
        iterator = lentry->preventry;
    // ---- repair any break made by this removal
    if (lentry->nextentry)
        lentry->nextentry->preventry = lentry->preventry;
    if (lentry->preventry)
        lentry->preventry->nextentry = lentry->nextentry;
    // --- maintain listhead if this is last and/or first
    if (lentry == lastentry)
        lastentry = lentry->preventry;
    if (lentry == firstentry)
        firstentry = lentry->nextentry;
    delete lentry;
}

template <class T>
// ---- insert an entry into the linked list
// ---- insert before lentry
void LinkedList<T>::InsertEntry(T& entry, ListEntry<T> *lentry)
{
    ListEntry<T> *newentry = new ListEntry<T>(entry);
    newentry->nextentry = lentry;
    if (lentry)    {
        newentry->preventry = lentry->preventry;
        lentry->preventry = newentry;
    }
    if (newentry->preventry)
        newentry->preventry->nextentry = newentry;
    if (lentry == firstentry)
        firstentry = newentry;
}

template <class T>
// ---- remove an entry from the linked list
void LinkedList<T>::RemoveEntry(int pos)
{
    FindEntry(pos);
    RemoveEntry(iterator);
}

template <class T>
// ---- insert an entry into the linked list
void LinkedList<T>::InsertEntry(T& entry, int pos)
{
    FindEntry(pos);
    InsertEntry(entry, iterator);
}

template <class T>
// ---- return the current linked list entry
T *LinkedList<T>::CurrentEntry()
{
    return iterator != 0 ? (iterator->thisentry) : 0;
}

template <class T>
// ---- return a specific linked list entry
T *LinkedList<T>::FindEntry(int pos)
{
    if (pos != -1)    {
        iterator = firstentry;
        if (iterator)    {
            while (pos--)
                iterator = iterator->nextentry;
        }
    }
    return CurrentEntry();
}

template <class T>
// ---- return the first entry in the linked list
T *LinkedList<T>::FirstEntry()
{
    iterator = firstentry;
    return CurrentEntry();
}

template <class T>
// ---- return the last entry in the linked list
T *LinkedList<T>::LastEntry()
{
    iterator = lastentry;
    return CurrentEntry();
}

template <class T>
// ---- return the next entry in the linked list
T *LinkedList<T>::NextEntry()
{
    if (iterator == 0)
        iterator = firstentry;
    else
        iterator = iterator->nextentry;
    return CurrentEntry();
}

template <class T>
// ---- return the previous entry in the linked list
T *LinkedList<T>::PrevEntry()
{
    if (iterator == 0)
        iterator = lastentry;
    else
        iterator = iterator->preventry;
    return CurrentEntry();
}

#endif
