#include <bits/stdc++.h>
using namespace std;

// Compass Card Sales

namespace DataStructures{

    /**
     * @param index index of query occurrence
     * @param value value of query
     */
    template <typename index_type = unsigned int, typename value_type = int>
    struct element{
        index_type leftOfRange;
        index_type rightOfRange;
        index_type index;
        value_type value;

        element(index_type leftOfRange, index_type rightOfRange,
                index_type index, value_type value){
            this->leftOfRange = leftOfRange;
            this->rightOfRange = rightOfRange;
            this->index = index;
            this->value = value;
        }

        element()= default;

    };

    template <typename index_type = unsigned int, typename value_type = int>
    struct range_query{
        pair<index_type, index_type> range;
        element<index_type, value_type> data;
        bool valid;

        range_query(pair<index_type, index_type> range,
                    element<index_type, value_type> data): data(data){
            this->range = range;
            valid = 1;
        }

        range_query(element<index_type, value_type> data): data(data){
            valid = 0;
        }
    };

    // Example query types:

    template <typename index_type = unsigned int, typename value_type = int>
    struct min_query_type{
        element<index_type, value_type> operator()(const element<index_type, value_type> & i1, const element<index_type, value_type> & i2) const{
            return i1.value < i2.value ? i1 : i2;
        }
    };

    template <typename index_type = unsigned int, typename value_type = int>
    struct max_query_type{
        element<index_type, value_type> operator()(const element<index_type, value_type> & i1, const element<index_type, value_type> & i2) const{
            return i1.value > i2.value ? i1 : i2;
        }
    };

    template <typename index_type = unsigned int, typename value_type = int>
    struct sum_query_type{
        element<index_type, value_type> operator()(const element<index_type, value_type> & i1, const element<index_type, value_type> & i2) const{
            return element<index_type, value_type>(0, 0, 0, i1.value + i2.value);
        }
    };

    template <typename query_type, typename index_type = unsigned int, typename value_type = int>
    struct segment_tree{
        vector<value_type> & values;
        unordered_map<index_type, element<index_type, value_type>> heap;
        vector<index_type> heapKey;
        query_type query_functor;
        range_query<index_type, value_type> invalid_rq = range_query<index_type, value_type>(element<index_type, value_type>());

        segment_tree(vector<value_type> & values): values(values){
            heapKey.resize(values.size());
            query_functor = query_type();
            build();
        }

        static inline index_type leftChild(index_type heap_index){
            return 2 * heap_index;
        }

        static inline index_type rightChild(index_type heap_index){
            return 2 * heap_index + 1;
        }

        static inline index_type parent(index_type heap_index){
            return heap_index / 2;
        }

        static inline index_type middle(index_type left, index_type right){
            return (left + right) / 2;
        }

        /**
         * O(n*lg(n)) time complexity
         */
        inline void build(){
            build(0, values.size()-1, 1);
        }

        void build(index_type left, index_type right, index_type heap_index){
            if(left == right){
                heap[heap_index] = element<index_type, value_type>(left, right, left, values[left]);
                heapKey[left] = heap_index;
                return;
            }
            index_type mid = middle(left, right);
            index_type leftC = leftChild(heap_index);
            index_type rightC = rightChild(heap_index);
            build(left, mid, leftC);
            build(mid+1, right, rightC);
            heap[heap_index] = query_functor(heap[leftC], heap[rightC]);
            heap[heap_index].leftOfRange = left;
            heap[heap_index].rightOfRange = right;
        }

        /**
         * O(lg(n)) time complexity
         */
        inline range_query<index_type, value_type> query(index_type left, index_type right){
            return query(left, right, 0, values.size()-1, 1);
        }

        range_query<index_type, value_type> query(index_type left, index_type right,
                                            index_type leftCandidate, index_type rightCandidate,
                                            index_type heap_index){
            if(rightCandidate < left || leftCandidate > right)
                return invalid_rq;

            if(leftCandidate >= left && rightCandidate <= right)
                return range_query<index_type, value_type>(make_pair(left, right), heap[heap_index]);

            index_type midCandidate = middle(leftCandidate, rightCandidate);
            index_type leftC = leftChild(heap_index);
            index_type rightC = rightChild(heap_index);
            range_query<index_type, value_type> left_rq = query(left, right, leftCandidate, midCandidate, leftC);
            range_query<index_type, value_type> right_rq = query(left, right, midCandidate+1, rightCandidate, rightC);
            if(!left_rq.valid)
                return right_rq;
            if(!right_rq.valid)
                return left_rq;
            return range_query<index_type, value_type>(make_pair(left, right), query_functor(left_rq.data, right_rq.data));
        }

        /**
         * O(lg(n)) time complexity
         */
        void notifyValueChanged(index_type index){
            heap[heapKey[index]].value = values[index];
            index_type it = parent(heapKey[index]);
            while(it >= 1){
                index_type leftO = heap[it].leftOfRange;
                index_type rightO = heap[it].rightOfRange;
                heap[it] = query_functor(heap[leftChild(it)], heap[rightChild(it)]);
                heap[it].leftOfRange = leftO;
                heap[it].rightOfRange = rightO;
                it = parent(it);
            }
        }
    };
}

using namespace DataStructures;

set<pair<int, int>>::iterator nexty(set<pair<int, int>>& l, set<pair<int, int>>::iterator it){
    return (next(it) == l.end()) ? l.begin() : next(it);
}

set<pair<int, int>>::iterator prevy(set<pair<int, int>>& l, set<pair<int, int>>::iterator it){
    return (it == l.begin()) ? prev(l.end()) : prev(it);
}

int n;
vector<pair<int, int>> cards;
vector<int> r, g, b;
set<pair<int, int>> red, green, blue;

int update_card(int i){
    int uni = 0;
    auto it = red.find({r[i], i});
    auto pit = prevy(red, it), nit = nexty(red, it);
    if(pit->first != it->first && nit->first != it->first){
        if(nit->first > pit->first)
            uni += nit->first - pit->first;
        else
            uni += 360 - (pit->first - nit->first);
    }
    it = green.find({g[i], i});
    pit = prevy(green, it), nit = nexty(green, it);
    if(pit->first != it->first && nit->first != it->first){
        if(nit->first > pit->first)
            uni += nit->first - pit->first;
        else
            uni += 360 - (pit->first - nit->first);
    }
    it = blue.find({b[i], i});
    pit = prevy(blue, it), nit = nexty(blue, it);
    if(pit->first != it->first && nit->first != it->first){
        if(nit->first > pit->first)
            uni += nit->first - pit->first;
        else
            uni += 360 - (pit->first - nit->first);
    }
    return uni;
}

set<int> update;

int main(){
    cin >> n;
    cards.resize(n), r.resize(n), g.resize(n), b.resize(n);
    for(int i = 0; i < n; i++){
        cin >> r[i] >> g[i] >> b[i] >> cards[i].second;
        red.insert({r[i], i}), green.insert({g[i], i}), blue.insert({b[i], i});
    }
    if(n == 1){
        cout << cards[0].second << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cards[i].first = update_card(i), cards[i].second *= -1;
    segment_tree<min_query_type<int, pair<int, int>>, int, pair<int, int>> tree(cards);
    for(int i = 0; 1; i++){
        int index = tree.query(0, n-1).data.index;
        cout << abs(cards[index].second) << endl;
        cards[index].first = INT_MAX;
        tree.notifyValueChanged(index);
        if(i == n-2)
            break;
        update.clear();
        auto it = red.find({r[index], index});
        update.insert(prevy(red, it)->second);
        update.insert(nexty(red, it)->second);
        red.erase(it);
        it = green.find({g[index], index});
        update.insert(prevy(green, it)->second);
        update.insert(nexty(green, it)->second);
        green.erase(it);
        it = blue.find({b[index], index});
        update.insert(prevy(blue, it)->second);
        update.insert(nexty(blue, it)->second);
        blue.erase(it);
        for(int u : update)
            cards[u].first = update_card(u), tree.notifyValueChanged(u);
    }
    cout << abs(cards[tree.query(0, n-1).data.index].second) << endl;
}