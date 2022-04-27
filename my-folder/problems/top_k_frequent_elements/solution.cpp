class MinHeap {
public:
    vector<pair<int,int>> harr;
    int capacity;
    int heap_size;
    MinHeap(int cap){
        heap_size = 0;
        capacity = cap;
        harr = {};
    }
    int parent(int k) {return (k-1)/2;}
    int left(int k){return (2*k + 1);}
    int right(int k){return (2*k + 2);}
    void insert(pair<int,int> k);
    void update(int i, pair<int,int> k);
    int extractMin();
    void MinHeapify(int);
    void assignPair(pair<int,int> &x, pair<int,int> y);
    // void swap(pair<int,int> &x, pair<int,int> &y);
};

void MinHeap::assignPair(pair<int,int> &x, pair<int,int> y){
    x.first = y.first;
    x.second = y.second;
}

// void MinHeap::swap(pair<int,int> &x, pair<int,int> &y){
//     pair<int,int> tmp;
//     assignPair(tmp, x);
//     assignPair(x, y);
//     assignPair(y, tmp);
// }

void MinHeap::insert(pair<int,int> k){
    // if (heap_size == capacity)
    // {
    //     return;
    // }
    
    heap_size++;
    int i=heap_size - 1;
    harr.push_back(k);
    
    while(i!=0 && harr[i].second < harr[parent(i)].second){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::update(int i, pair<int,int> k){
    assignPair(harr[i], k);
    while(i!=0 && harr[i].second < harr[parent(i)].second){
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin(){
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0].second;
    }
  
    int root = harr[0].second;
    assignPair(harr[0], harr[heap_size-1]);
    heap_size--;
    harr.pop_back();
    MinHeapify(0);
    return root;
}

void MinHeap::MinHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < heap_size && harr[l].second < harr[smallest].second) smallest = l;
    if(r < heap_size && harr[r].second < harr[smallest].second) smallest = r;
    if(smallest != i){
        swap(harr[smallest], harr[i]);
        MinHeapify(smallest);
    }
}

class Solution {
public:    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res = {};
        map<int, int> fre;
        for(int i=0; i<nums.size(); i++){
            fre[nums[i]]++;
        }
        MinHeap heap(k);
        for (auto itr = fre.begin(); itr != fre.end(); ++itr) {
            heap.insert(*itr);
            if(heap.heap_size > k){
                heap.extractMin();
            }
        }
        for(auto p : heap.harr){
            res.push_back(p.first);
        }
        return res;
    }
};