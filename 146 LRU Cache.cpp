//146. LRU Cache
//实现LRU Cache
//利用std::list
//利用自制的HashMap

template<typename T_Key, typename T_Value>
struct HashPair
{
	T_Key key;
	T_Value value;

	HashPair() = default;
	HashPair(T_Key tarKey, T_Value tarValue);

	bool operator==(const HashPair& rVal);
	bool operator!=(const HashPair& rVal);
	const HashPair<T_Key, T_Value>& operator=(const HashPair& rVal);
};

template<typename T_Key, typename T_Value>
HashPair<T_Key, T_Value>::HashPair(T_Key tarKey, T_Value tarValue)
{
	key = tarKey;
	value = tarValue;
}

template<typename T_Key, typename T_Value>
bool HashPair<T_Key, T_Value>::operator==(const HashPair& rVal)
{
	if (this->key == rVal.key && this->value == rVal.value)
		return true;
	else
		return false;
}

template<typename T_Key, typename T_Value>
bool HashPair<T_Key, T_Value>::operator!=(const HashPair& rVal)
{
	if (this->key == rVal.key && this->value == rVal.value)
		return false;
	else
		return true;
}

template<typename T_Key, typename T_Value>
const HashPair<T_Key, T_Value>& HashPair<T_Key, T_Value>::operator=(const HashPair& rVal)
{
	this->key = rVal.key;
	this->value = rVal.value;
	return (*this);
}

template<typename T_Key, typename T_Value>
class HashMap
{
public:

	bool virtual insert(HashPair<T_Key, T_Value> tarPair) = 0;
	bool virtual insert(T_Key tarKey, T_Value tarValue) = 0;
	int virtual find(T_Key tarKey) = 0;
	T_Value virtual get(T_Key tarKey) = 0;
	T_Value virtual pop(T_Key tarKey) = 0;

	int virtual getHash(T_Key tarKey) = 0;

	int virtual size() = 0;
	int virtual capacity() = 0;
};

template<typename T_Key, typename T_Value>
class OpenAddressHashMap : public HashMap<T_Key, T_Value>
{
public:
	OpenAddressHashMap();
	OpenAddressHashMap(int capacity);
	~OpenAddressHashMap();

	bool insert(HashPair<T_Key, T_Value> tarPair);
	bool insert(T_Key tarKey, T_Value tarValue);
	int getHash(T_Key tarKey);

	int find(T_Key tarKey);
	T_Key findHash(T_Key tarKey);
	T_Value get(T_Key tarKey);
	T_Value pop(T_Key tarKey);

	int size();
	int capacity();

private:
	int mCapacity;
	int mSize;
	HashPair<T_Key, T_Value>* mVal;
	int mHash;
};

template<typename T_Key, typename T_Value>
OpenAddressHashMap<T_Key, T_Value>::OpenAddressHashMap()
{
	mCapacity = 0;
	mSize = 0;
	mVal = nullptr;
}

template<typename T_Key, typename T_Value>
OpenAddressHashMap<T_Key, T_Value>::OpenAddressHashMap(int capacity)
{
	mCapacity = capacity;
	mVal = new HashPair<T_Key, T_Value>[mCapacity];

	for (int i = 0; i < mCapacity; i++)
	{
		mVal[i].key = 0;
		mVal[i].value = 0;
	}

	for (int tarN = mCapacity; tarN > 0; tarN--)
	{
		if (tarN<2)
			mHash = tarN;

		for (int i = 2; i < sqrt(tarN) + 1; i++)
		{
			if (mCapacity%i == 0)
			{
				mHash = tarN;
				break;
			}
		}

		if (mHash == tarN)
			break;
	}


	mSize = 0;
}

template<typename T_Key, typename T_Value>
OpenAddressHashMap<T_Key, T_Value>::~OpenAddressHashMap()
{
	mCapacity = 0;
	mSize = 0;
	delete[] mVal;
}

template<typename T_Key, typename T_Value>
bool OpenAddressHashMap<T_Key, T_Value>::insert(HashPair<T_Key, T_Value> tarPair)
{
	if (mSize == mCapacity)
		return false;

	int HashKey = getHash(tarPair.key);

	if (HashKey == -1)
		return false;

	mVal[HashKey] = tarPair;
	this->mSize = this->mSize + 1;
	return true;
}

template<typename T_Key, typename T_Value>
bool OpenAddressHashMap<T_Key, T_Value>::insert(T_Key tarKey, T_Value tarValue)
{
	if (mSize == mCapacity)
		return false;

	int HashKey = getHash(tarKey);

	if (HashKey == -1)
		return false;

	mVal[HashKey].key = tarKey;
	mVal[HashKey].value = tarValue;
	this->mSize = this->mSize + 1;
	return true;
}

template<typename T_Key, typename T_Value>
int OpenAddressHashMap<T_Key, T_Value>::getHash(T_Key tarKey)
{
	int HashValue = tarKey % mHash;

	int tempUpHash = HashValue;
	int tempDownHash = HashValue;

	if (mVal[HashValue].key == 0)
		return HashValue;
	else
	{
		for (int i = 0;; i++)
		{
			if (i % 2 == 0)
			{
				tempDownHash = tempDownHash - 1;
				if (tempDownHash < 0 && tempUpHash >= mCapacity)
					break;
				if (tempDownHash >= 0 && mVal[tempDownHash].key == 0)
					return tempDownHash;
			}
			else
			{
				tempUpHash = tempUpHash + 1;
				if (tempDownHash < 0 && tempUpHash >= mCapacity)
					break;
				if (tempUpHash < mCapacity && mVal[tempUpHash].key == 0)
					return tempUpHash;
			}

		}
		return -1;
	}

}

template<typename T_Key, typename T_Value>
int OpenAddressHashMap<T_Key, T_Value>::find(T_Key tarKey)
{

	int HashValue = tarKey % mHash;

	int tempUpHash = HashValue;
	int tempDownHash = HashValue;

	if (mVal[HashValue].key == tarKey)
		return HashValue;
	else
	{
		for (int i = 0;; i++)
		{
			if (i % 2 == 0)
			{
				tempDownHash = tempDownHash - 1;
				if (tempDownHash < 0 && tempUpHash >= mCapacity)
					break;
				if (tempDownHash >= 0 && mVal[tempDownHash].key == tarKey)
					return tempDownHash;
			}
			else
			{
				tempUpHash = tempUpHash + 1;
				if (tempDownHash < 0 && tempUpHash >= mCapacity)
					break;
				if (tempUpHash < mCapacity && mVal[tempUpHash].key == tarKey)
					return tempUpHash;
			}

		}
		return -1;
	}
}

template<typename T_Key, typename T_Value>
T_Key OpenAddressHashMap<T_Key, T_Value>::findHash(T_Key tarKey)
{
	int HashValue = tarKey % mHash;

	int tempUpHash = HashValue;
	int tempDownHash = HashValue;

	if (mVal[HashValue].key == tarKey)
		return mVal[HashValue].key;
	else
	{
		for (int i = 0;; i++)
		{
			if (i % 2 == 0)
			{
				tempDownHash = tempDownHash - 1;
				if (tempDownHash < 0 && tempUpHash >= mCapacity)
					break;
				if (tempDownHash >= 0 && mVal[tempDownHash].key == tarKey)
					return mVal[tempDownHash].key;
			}
			else
			{
				tempUpHash = tempUpHash + 1;
				if (tempDownHash < 0 && tempUpHash >= mCapacity)
					break;
				if (tempUpHash < mCapacity && mVal[tempUpHash].key == tarKey)
					return mVal[tempUpHash].key;
			}

		}
		return -1;
	}
}

template<typename T_Key, typename T_Value>
T_Value OpenAddressHashMap<T_Key, T_Value>::get(T_Key tarKey)
{
	int HashKey = find(tarKey);

	if (HashKey == -1)
		return false;

	return mVal[HashKey].value;
}

template<typename T_Key, typename T_Value>
T_Value OpenAddressHashMap<T_Key, T_Value>::pop(T_Key tarKey)
{
	int HashKey = find(tarKey);

	if (HashKey == -1)
		return false;

	T_Value tempVal = mVal[HashKey].value;
	mVal[HashKey].value = 0;
	mVal[HashKey].key = 0;
	mSize = mSize - 1;
	return tempVal;
}

template<typename T_Key, typename T_Value>
int OpenAddressHashMap<T_Key, T_Value>::capacity()
{
	return mCapacity;
}

template<typename T_Key, typename T_Value>
int OpenAddressHashMap<T_Key, T_Value>::size()
{
	return mSize;
}


class LRUCache {
public:
	LRUCache(int capacity) {
		MainList = new list<int>();
		hashmap = new OpenAddressHashMap<int, int>(capacity);

	}

	int get(int key) {
		int i = hashmap->get(key);
		if (i)
		{
			MainList->remove(key);
			MainList->push_front(key);
			return i;
		}
		else
		{
			return -1;
		}


	}

	void put(int key, int value)
	{
		if (hashmap->findHash(key) == key)
		{
			hashmap->pop(key);
			hashmap->insert(key, value);
			MainList->remove(key);
			MainList->push_front(key);
		}
		else
		{
			if (hashmap->insert(key, value) == false)
			{
				int iKey = MainList->back();
				MainList->pop_back();
				hashmap->pop(iKey);
				hashmap->insert(key, value);
			}

			MainList->push_front(key);
		}
	}

	list<int>* MainList;
	OpenAddressHashMap<int, int>* hashmap;
};