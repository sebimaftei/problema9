#pragma once

template <class K, class V>
struct S
{
	K key; 
	V value;
	int index;
	S& operator++() { index++; return *this; }
	S& operator--() { index--; return *this; }
};

template <class K, class V>
class Map
{
	int nr_el;
	S<K, V> map[30];
public:
	S<K, V> val;
	Map();
	~Map() {};
	V& operator[](const K& cheie);
	void Set(K cheie, V valoare);
	bool Get(const K& key, V& value);
	int Count();
	void Clear();
	void Delete(const K& cheie);
	bool Includes(const Map<K, V>& map);
	const S<K, V>* begin();
	const S<K, V>* end();
};

template<class K, class V>
inline Map<K, V>::Map()
{
	nr_el = 0;
}

template<class K, class V>
inline V& Map<K, V>::operator[](const K& cheie)
{
	for (int i = 0; i < nr_el; i++)
		if (cheie == this->map[i].key)
			return map[i].value;
	this->map[nr_el].index = nr_el;
	this->map[nr_el++].key = cheie;
	return map[nr_el - 1].value;
}


template<class K, class V>
inline void Map<K, V>::Set(K cheie, V valoare)
{
	for (int i = 0; i < nr_el; i++)
		if (cheie == this->map[i].key)
		{
			this->map[i].value = valoare;
			this->map[i].index = i;
			break;
		}
	this->map[nr_el].index = nr_el;
	this->map[nr_el++].key = cheie;
}

template<class K, class V>
inline bool Map<K, V>::Get(const K& key, V& value)
{
	for (int i = 0; i < nr_el; i++)
		if (key == this->map[i].key)
		{
			value = this->map[i].value;
			return true;
		}
	return false;
}

template<class K, class V>
inline int Map<K, V>::Count()
{
	return nr_el;
}

template<class K, class V>
inline void Map<K, V>::Clear()
{
	nr_el = 0;
}

template<class K, class V>
inline void Map<K, V>::Delete(const K& cheie)
{
	int i = 0;
	while (i < nr_el && cheie != this->key[i]) i++;
	bool ok = false;
	while (i < nr_el)
	{
		ok = true;
		this->map[i - 1].key = this->map[i].key;
		this->map[i - 1].key = this->map[i].key;
		this->map[i - 1].index = this->map[i].index;
		i++;
	}
	if (ok == true) nr_el--;
}

template<class K, class V>
inline bool Map<K, V>::Includes(const Map<K, V>& map)
{
	for (int i = 0; i < this->nr_el; i++)
	{
		bool ok = false;
		for (int j = 0; j < map.Count(); j++)
		{
			if (this->map[i - 1].key == map.map[j])
				ok = true;
		}
		if (ok == false) return false;
	}
	return true;
}

template<class K, class V>
inline const S<K, V>* Map<K, V>::begin()
{
	return &map[0];
}

template<class K, class V>
inline const S<K, V>* Map<K, V>::end()
{
	return &map[nr_el];
}


