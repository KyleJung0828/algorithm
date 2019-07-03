#include <list>
#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache {
public:
    int m_capacity;
    list<int> m_list; // Priority list
    unordered_map<int, int> m_map; // map
    
    LRUCache(int capacity) 
        : m_capacity(capacity)
    {
        
    }
    
    int get(int key) 
    {
        auto it = m_map.find(key);
        
        if(it != m_map.end())
        {
            // Erase the used key, and renew it by pushing the key to the front.
            auto listIter = find(m_list.begin(), m_list.end(), it->first);
            m_list.erase(listIter);
            m_list.push_front(it->first);
            return it->second;
        }
        else
        {
            return -1;
        }
    }
    
    void put(int key, int value) 
    {
        auto it = m_map.find(key);
        
        if(it == m_map.end())
        {
            m_map.insert(make_pair(key, value));
        }
        else
        {
            // update map 
            m_map[key] = value;
            
            // Erase the used key, and renew it by pushing the key to the front.
            auto listIter = find(m_list.begin(), m_list.end(), it->first);
            m_list.erase(listIter);
        }
        
        m_list.push_front(key);

        // Evict if capacity overflows
        if(m_map.size() > m_capacity)
        {
            m_map.erase(m_list.back());
            m_list.pop_back();
        }
    }
};

int main(int argc, char* argv[])
{
    int capacity = 2;
    LRUCache* obj = new LRUCache(capacity);

    obj->put(2, 1);
    obj->put(2, 2);
    int get_1 = obj->get(2);
    obj->put(1, 1);
    int get_2 = obj->get(2);
    obj->put(4, 4);
    int get_3 = obj->get(1);
    int get_4 = obj->get(3);
    int get_5 = obj->get(4);

    delete obj;

    return 0;
}

