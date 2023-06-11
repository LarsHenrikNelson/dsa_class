#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using std::list;
using std::string;
using std::vector;
using std::cin;
using std::cout;

struct Query {
    string type, s;
    size_t ind;
};

class QueryProcessor {
    int bucket_count;
    vector<list<string>> hash_table;
    size_t hash_func(const string& s) const {
        static const size_t multiplier = 263;
        static const size_t prime = 1000000007;
        unsigned long long hash = 0;
        for (int i = static_cast<int> (s.size()) - 1; i >= 0; --i)
            hash = ((hash * multiplier + s[i]) % prime);
        return hash % static_cast<size_t>(bucket_count);
    }

public:
    explicit QueryProcessor(int bucket_count): bucket_count(bucket_count), hash_table(bucket_count) {
        hash_table.resize(bucket_count);
    }

    Query readQuery() const {
        Query query;
        cin >> query.type;
        if (query.type != "check"){
            cin >> query.s;
        }
        else{
            cin >> query.ind;
        }
        return query;
    }

    void writeSearchResult(bool was_found) const {
        cout << (was_found ? "yes\n" : "no\n");
    }

    void processQuery(const Query& query) {
        size_t hash = hash_func(query.s);
        if (query.type == "check") {
            for (auto &n: hash_table.at(query.ind)){
                cout << n << " ";
            }
            cout << "\n";
        } else {
            list<string>::iterator it = std::find(hash_table.at(hash).begin(), hash_table.at(hash).end(), query.s);
            if (query.type == "find")
                writeSearchResult(it != hash_table.at(hash).end());
            else if (query.type == "add") {
                if (it == hash_table.at(hash).end())
                    hash_table.at(hash).push_front(query.s);
            } else if (query.type == "del") {
                if (it != hash_table.at(hash).end()){
                    hash_table.at(hash).erase(it);
                }
            }
        }
    }

    void processQueries() {
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            processQuery(readQuery());
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    int bucket_count;
    cin >> bucket_count;
    QueryProcessor proc(bucket_count);
    proc.processQueries();
    return 0;
}
