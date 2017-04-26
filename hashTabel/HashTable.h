#ifndef HASHTABLE_H
#define HASHTABLE_H



template <typename HashElement>
class HashTable
{
private:
	// member variables for you to decide on
	// but it is required that you use an array (not a vector) for the table
	class Element {
	public:
		enum State { FREE, USED, REMOVED };
		HashElement data;
		Element() {
			State = FREE;
		}
	};

	Element** arr;

	int hashTableSize;
	int nrOfElements;

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
inline HashTable<HashElement>::HashTable(int hashTableSize){
	this->hashTableSize = hashTableSize;
	nrOfElements = 0;
	arr = new Element*[this->hashTableSize];
}

template<typename HashElement>
inline HashTable<HashElement>::~HashTable()
{
}

template<typename HashElement>
inline int HashTable<HashElement>::contains(const HashElement & elem) const
{
	return 0;
}

template<typename HashElement>
inline bool HashTable<HashElement>::insert(const HashElement & elem) {
	bool inserted = false;
	int index = myHash(elem);

	inserted = true;

	return inserted;
	
}

template<typename HashElement>
inline bool HashTable<HashElement>::remove(const HashElement & elem)
{
	return false;
}

template<typename HashElement>
inline const HashElement & HashTable<HashElement>::get(int index) const
{
	// TODO: insert return statement here
}

template<typename HashElement>
inline int HashTable<HashElement>::getHashTableSize() const{
	return hashTableSize;
}
