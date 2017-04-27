#ifndef HASHTABLE_H
#define HASHTABLE_H

enum State {FREE, USED, REMOVED };

template <typename HashElement>
class HashTable
{
private:
	// member variables for you to decide on
	// but it is required that you use an array (not a vector) for the table
	class Element {
	public:
		State state;
		HashElement data;
		Element() {
			data = nullptr;
		}
	};

	Element** elements;


	int hashTableSize;
	int nrOfElements;

	int findTarget(int index, HashElement target);

	unsigned int myHash(const HashElement& elem) const 
	{ 
		static Hash<HashElement> hashFunc; 
		return hashFunc(elem) % hashTableSize; // hashFunc(elem) is a call of the defined operator() for HashElement
	}
public:
	HashTable(int hashTableSize = 101);
	HashTable(const HashTable& aTable) = delete;
	virtual ~HashTable();
	HashTable& operator=(const HashTable& aTable) = delete;
	int contains(const HashElement& elem) const; // returns index or -1
	bool insert(const HashElement& elem);
	bool remove(const HashElement& elem);

	const HashElement& get(int index) const; 
	void makeEmpty();
	double loadFactor() const;
	int getNrOfElements() const;
	int getHashTableSize() const;
};

#endif

template<typename HashElement>
inline int HashTable<HashElement>::findTarget(int index, HashElement target) {
	int returnIndex = -1;
	if (elements[index]->state == USED) {
		returnIndex = findFree(index + 1);
	}
	return returnIndex;
}

template<typename HashElement>
inline HashTable<HashElement>::HashTable(int hashTableSize){
	this->hashTableSize = hashTableSize;
	nrOfElements = 0;
	elements = new Element*[this->hashTableSize];
	for (int i = 0; i < hashTableSize; i++) {
		elements[i] = nullptr;
	}
}

template<typename HashElement>
inline HashTable<HashElement>::~HashTable(){
	for (int i = 0; i < hashTableSize; i++) {
		delete elements[i];
	}
	delete[] elements;
}

template<typename HashElement>
inline int HashTable<HashElement>::contains(const HashElement & elem) const{
	int index = myHash(elem);
	if(elements[index]->data == elem)

	return 0;
}

template<typename HashElement>
inline bool HashTable<HashElement>::insert(const HashElement & elem) {
	bool inserted = false;
	int index = myHash(elem);
	if (!contains(elem)) {
		if (elements[index]->state != USED) {
			inserted = true;
		} else {
			index = findFree(index);
			inserted = true;
		}
		if (inserted) {
			elements[index]->data = elem;
			elements[index]->state = USED;
			nrOfElements++;
		}
	}
	return inserted;
}

template<typename HashElement>
inline bool HashTable<HashElement>::remove(const HashElement & elem){
	bool removed = false;
	int index = contains(elem);
	if(index != -1){
		//elements[index]->data = nullptr;
		elements[index]->state = REMOVED;
		removed = true;
	}

	return removed;
}

template<typename HashElement>
inline const HashElement & HashTable<HashElement>::get(int index) const{
	HashElement target;
	if (elements[index]->state == USED) {
		target = elements->data;
	}

	return target;
}

template<typename HashElement>
inline double HashTable<HashElement>::loadFactor() const {
	return nrOfElements/hashTableSize;
}

template<typename HashElement>
inline int HashTable<HashElement>::getNrOfElements() const {
	return nrOfElements;
}

template<typename HashElement>
inline int HashTable<HashElement>::getHashTableSize() const{
	return hashTableSize;
}
