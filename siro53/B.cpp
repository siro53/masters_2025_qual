#pragma region Macros
#include <bits/stdc++.h>
using namespace std;
// input output utils
namespace siro53_io {
    // https://maspypy.github.io/library/other/io_old.hpp
    struct has_val_impl {
        template <class T>
        static auto check(T &&x) -> decltype(x.val(), std::true_type{});

        template <class T> static auto check(...) -> std::false_type;
    };

    template <class T>
    class has_val : public decltype(has_val_impl::check<T>(std::declval<T>())) {
    };

    // debug
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void dump(const T t) {
        cerr << t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void dump(const T t) {
        cerr << t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void dump(const T &t) {
        cerr << t.val();
    }
    void dump(__int128_t n) {
        if(n == 0) {
            cerr << '0';
            return;
        } else if(n < 0) {
            cerr << '-';
            n = -n;
        }
        string s;
        while(n > 0) {
            s += (char)('0' + n % 10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cerr << s;
    }
    void dump(const string &s) { cerr << s; }
    void dump(const char *s) {
        int n = (int)strlen(s);
        for(int i = 0; i < n; i++) cerr << s[i];
    }
    template <class T1, class T2> void dump(const pair<T1, T2> &p) {
        cerr << '(';
        dump(p.first);
        cerr << ',';
        dump(p.second);
        cerr << ')';
    }
    template <class T> void dump(const vector<T> &v) {
        cerr << '{';
        for(int i = 0; i < (int)v.size(); i++) {
            dump(v[i]);
            if(i < (int)v.size() - 1) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(const set<T> &s) {
        cerr << '{';
        for(auto it = s.begin(); it != s.end(); it++) {
            dump(*it);
            if(next(it) != s.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class Key, class Value> void dump(const map<Key, Value> &mp) {
        cerr << '{';
        for(auto it = mp.begin(); it != mp.end(); it++) {
            dump(*it);
            if(next(it) != mp.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class Key, class Value>
    void dump(const unordered_map<Key, Value> &mp) {
        cerr << '{';
        for(auto it = mp.begin(); it != mp.end(); it++) {
            dump(*it);
            if(next(it) != mp.end()) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(const deque<T> &v) {
        cerr << '{';
        for(int i = 0; i < (int)v.size(); i++) {
            dump(v[i]);
            if(i < (int)v.size() - 1) cerr << ',';
        }
        cerr << '}';
    }
    template <class T> void dump(queue<T> q) {
        cerr << '{';
        while(!q.empty()) {
            dump(q.front());
            if((int)q.size() > 1) cerr << ',';
            q.pop();
        }
        cerr << '}';
    }

    void debug_print() { cerr << endl; }
    template <class Head, class... Tail>
    void debug_print(const Head &h, const Tail &...t) {
        dump(h);
        if(sizeof...(Tail)) dump(' ');
        debug_print(t...);
    }
    // print
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void print_single(const T t) {
        cout << t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void print_single(const T t) {
        cout << t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void print_single(const T t) {
        cout << t.val();
    }
    void print_single(__int128_t n) {
        if(n == 0) {
            cout << '0';
            return;
        } else if(n < 0) {
            cout << '-';
            n = -n;
        }
        string s;
        while(n > 0) {
            s += (char)('0' + n % 10);
            n /= 10;
        }
        reverse(s.begin(), s.end());
        cout << s;
    }
    void print_single(const string &s) { cout << s; }
    void print_single(const char *s) {
        int n = (int)strlen(s);
        for(int i = 0; i < n; i++) cout << s[i];
    }
    template <class T1, class T2> void print_single(const pair<T1, T2> &p) {
        print_single(p.first);
        cout << ' ';
        print_single(p.second);
    }
    template <class T> void print_single(const vector<T> &v) {
        for(int i = 0; i < (int)v.size(); i++) {
            print_single(v[i]);
            if(i < (int)v.size() - 1) cout << ' ';
        }
    }
    template <class T> void print_single(const set<T> &s) {
        for(auto it = s.begin(); it != s.end(); it++) {
            print_single(*it);
            if(next(it) != s.end()) cout << ' ';
        }
    }
    template <class T> void print_single(const deque<T> &v) {
        for(int i = 0; i < (int)v.size(); i++) {
            print_single(v[i]);
            if(i < (int)v.size() - 1) cout << ' ';
        }
    }
    template <class T> void print_single(queue<T> q) {
        while(!q.empty()) {
            print_single(q.front());
            if((int)q.size() > 1) cout << ' ';
            q.pop();
        }
    }

    void print() { cout << '\n'; }
    template <class Head, class... Tail>
    void print(const Head &h, const Tail &...t) {
        print_single(h);
        if(sizeof...(Tail)) print_single(' ');
        print(t...);
    }

    // input
    template <class T, enable_if_t<is_integral<T>::value, int> = 0>
    void input_single(T &t) {
        cin >> t;
    }
    template <class T, enable_if_t<is_floating_point<T>::value, int> = 0>
    void input_single(T &t) {
        cin >> t;
    }
    template <class T, typename enable_if<has_val<T>::value>::type * = nullptr>
    void input_single(T &t) {
        cin >> t;
    }
    void input_single(__int128_t &n) {
        string s;
        cin >> s;
        if(s == "0") {
            n = 0;
            return;
        }
        bool is_minus = false;
        if(s[0] == '-') {
            s = s.substr(1);
            is_minus = true;
        }
        n = 0;
        for(int i = 0; i < (int)s.size(); i++) n = n * 10 + (int)(s[i] - '0');
        if(is_minus) n = -n;
    }
    void input_single(string &s) { cin >> s; }
    template <class T1, class T2> void input_single(pair<T1, T2> &p) {
        input_single(p.first);
        input_single(p.second);
    }
    template <class T> void input_single(vector<T> &v) {
        for(auto &e : v) input_single(e);
    }
    void input() {}
    template <class Head, class... Tail> void input(Head &h, Tail &...t) {
        input_single(h);
        input(t...);
    }
}; // namespace siro53_io
#ifdef DEBUG
#define debug(...)                                                             \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]: ", debug_print(__VA_ARGS__)
#else
#define debug(...) (void(0))
#endif
// io setup
struct Setup {
    Setup() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(15);
    }
} __Setup;
using namespace siro53_io;
// types
using ll = long long;
using i128 = __int128_t;
// input macros
#define INT(...)                                                               \
    int __VA_ARGS__;                                                           \
    input(__VA_ARGS__)
#define LL(...)                                                                \
    ll __VA_ARGS__;                                                            \
    input(__VA_ARGS__)
#define STRING(...)                                                            \
    string __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define CHAR(...)                                                              \
    char __VA_ARGS__;                                                          \
    input(__VA_ARGS__)
#define DBL(...)                                                               \
    double __VA_ARGS__;                                                        \
    input(__VA_ARGS__)
#define LD(...)                                                                \
    long double __VA_ARGS__;                                                   \
    input(__VA_ARGS__)
#define UINT(...)                                                              \
    unsigned int __VA_ARGS__;                                                  \
    input(__VA_ARGS__)
#define ULL(...)                                                               \
    unsigned long long __VA_ARGS__;                                            \
    input(__VA_ARGS__)
#define VEC(name, type, len)                                                   \
    vector<type> name(len);                                                    \
    input(name);
#define VEC2(name, type, len1, len2)                                           \
    vector name(len1, vector<type>(len2));                                     \
    input(name);
// other macros
// https://trap.jp/post/1224/
#define OVERLOAD3(_1, _2, _3, name, ...) name
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
#define REP1(i, n) for(int i = 0; i < int(n); i++)
#define REP2(i, a, b) for(int i = (a); i < int(b); i++)
#define REP(...) OVERLOAD3(__VA_ARGS__, REP2, REP1)(__VA_ARGS__)
#define SORT(v) sort(ALL(v))
#define RSORT(v) sort(RALL(v))
#define UNIQUE(v)                                                              \
    sort(ALL(v)), (v).erase(unique(ALL(v)), (v).end()), v.shrink_to_fit()
#define REV(v) reverse(ALL(v))
#define SZ(v) ((int)(v).size())
#define MIN(v) (*min_element(ALL(v)))
#define MAX(v) (*max_element(ALL(v)))
// util const
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
constexpr int MOD = 1000000007;
constexpr int MOD2 = 998244353;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
// util functions
void Case(int i) { cout << "Case #" << i << ": "; }
int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
template <class T> inline bool chmax(T &a, T b) {
    return (a < b ? a = b, true : false);
}
template <class T> inline bool chmin(T &a, T b) {
    return (a > b ? a = b, true : false);
}
template <class T, int dim>
auto make_vector_impl(vector<int>& sizes, const T &e) {
    if constexpr(dim == 1) {
        return vector(sizes[0], e);
    } else {
        int n = sizes[dim - 1];
        sizes.pop_back();
        return vector(n, make_vector_impl<T, dim - 1>(sizes, e));
    }
}
template <class T, int dim>
auto make_vector(const int (&sizes)[dim], const T &e = T()) {
    vector<int> s(dim);
    for(int i = 0; i < dim; i++) s[i] = sizes[dim - i - 1];
    return make_vector_impl<T, dim>(s, e);
}
vector<int> iota_gen(int n, int start = 0) {
    vector<int> ord(n);
    iota(ord.begin(), ord.end(), start);
    return ord;
}
template<typename T>
vector<int> ord_sort(const vector<T>& v, bool greater = false) {
    auto ord = iota_gen((int)v.size());
    sort(ALL(ord), [&](int i, int j) {
        if(greater) return v[i] > v[j];
        return v[i] < v[j];
    });
    return ord;
}
#pragma endregion Macros

int main() {
    INT(N, M);
    VEC(C, string, N);
    // 現在地
    int si{}, sj{};
    REP(i, N) REP(j, N) {
        if(C[i][j] == 'A') {
            si = i, sj = j;
        }
    }
    auto is_inside = [&](int i, int j) -> bool {
        return (0 <= i and i < N and 0 <= j and j < N);
    };
    auto get_dir = [&](int from_i, int from_j, int to_i, int to_j) -> char {
        int di = to_i - from_i;
        int dj = to_j - from_j;
        assert(abs(di) + abs(dj) == 1);
        if(di == -1 and dj == 0) return 'U';
        else if(di == 1 and dj == 0) return 'D';
        else if(di == 0 and dj == -1) return 'L';
        else if(di == 0 and dj == 1) return 'R';
        assert(false);
    };

    auto output = [&](int action, char dir, vector<pair<int, char>>& v) -> void {
        v.emplace_back(action, dir);
    };
    map<char, pair<int, int>> holes;
    for(char c : {'A', 'B', 'C'}) {
        REP(i, N) REP(j, N) if(C[i][j] == c) {
            holes[c] = {i, j};
        }
    }
    auto bfs = [&](int start_i, int start_j, char hole) -> pair<vector<vector<int>>, vector<vector<pair<int, int>>>> {
        auto dp = make_vector<int>({N, N}, INF);
        auto pre = make_vector<pair<int, int>>({N, N}, {-1, -1});
        dp[start_i][start_j] = 0;
        queue<pair<int, int>> que;
        que.emplace(start_i, start_j);
        while(!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            REP(dir, 4) {
                int ni = i + dx[dir], nj = j + dy[dir];
                if(!is_inside(ni, nj)) continue;
                if(!(C[ni][nj] == '.' or C[ni][nj] == hole)) continue;
                if(chmin(dp[ni][nj], dp[i][j] + 1)) {
                    que.emplace(ni, nj);
                    pre[ni][nj] = {i, j};
                }
            }
        }
        return {dp, pre};
    };
    auto restore_bfs = [&](int goal_i, int goal_j, vector<vector<pair<int, int>>>& pre) -> vector<pair<int, int>> {
        int now_i = goal_i, now_j = goal_j;
        vector<pair<int, int>> ret;
        ret.emplace_back(now_i, now_j);
        while(1) {
            auto [pre_i, pre_j] = pre[now_i][now_j];
            if(pre_i == -1) break;
            ret.emplace_back(pre_i, pre_j);
            now_i = pre_i, now_j = pre_j;
        }
        REV(ret);
        return ret;
    };
    // 最も評価値の高い鉱石を1つだけ穴に落とす
    vector<pair<int, char>> res;
    auto del_ore = [&]() {
        vector<tuple<int, int, char>> starts;
        REP(i, N) REP(j, N) if(islower(C[i][j])) {
            char c = (char)('A' + (C[i][j] - 'a'));
            starts.emplace_back(i, j, c);
        }
        if(starts.empty()) return false;
        vector<vector<tuple<int, int, char>>> gs;
        REP(k, SZ(starts)) {
            auto [ssi, ssj, c] = starts[k];
            auto hole = holes[c];
            int i = hole.first - 1, j = hole.second;
            vector<tuple<int, int, char>> goals;
            while(i >= 0) {
                if(C[i][j] == '.' or (i == ssi and j == ssj)) {
                    goals.emplace_back(i, j, 'D');
                    i--;
                } else break;
            }
            i = hole.first + 1, j = hole.second;
            while(i < N) {
                if(C[i][j] == '.' or (i == ssi and j == ssj)) {
                    goals.emplace_back(i, j, 'U');
                    i++;
                } else break;
            }
            i = hole.first, j = hole.second - 1;
            while(j >= 0) {
                if(C[i][j] == '.' or (i == ssi and j == ssj)) {
                    goals.emplace_back(i, j, 'R');
                    j--;
                } else break;
            }
            i = hole.first, j = hole.second + 1;
            while(j < N) {
                if(C[i][j] == '.' or (i == ssi and j == ssj)) {
                    goals.emplace_back(i, j, 'L');
                    j++;
                } else break;
            }
            gs.push_back(goals);
        }
        // 一番ゴールに近いやつから転がす
        int start_i{-1}, start_j{-1}, start_c{'-'};
        auto min_goals = gs[0];
        {
            int mn = INF;
            int idx = 0;
            for(auto [i, j, c] : starts) {
                auto [dp, _] = bfs(i, j, c);
                const auto& goals = gs[idx++];
                for(auto [gi, gj, __] : goals) {
                    if(chmin(mn, dp[gi][gj] + abs(i - si) + abs(j - sj))) {
                        start_i = i, start_j = j, start_c = c;
                        min_goals = goals;
                    }
                }
            }
        }
        auto [dp, pre] = bfs(start_i, start_j, start_c);
        int goal_i{-1}, goal_j{-1};
        char direction;
        int mn = INF;
        
        for(auto [gi, gj, dir]: min_goals) {
            if(chmin(mn, dp[gi][gj])) {
                goal_i = gi;
                goal_j = gj;
                direction = dir;
            }
        }
        auto path = restore_bfs(goal_i, goal_j, pre);
        // スタート地点まで移動する
        {
            int di = start_i - si;
            int dj = start_j - sj;
            while(di < 0) {
                output(1, 'U', res);
                ++di;
            }
            while(di > 0) {
                output(1, 'D', res);
                --di;
            }
            while(dj < 0) {
                output(1, 'L', res);
                ++dj;
            }
            while(dj > 0) {
                output(1, 'R', res);
                --dj;
            }
            si = start_i, sj = start_j;
        }
        // debug(si, sj);
        // 運ぶ
        {
            for(auto [ni, nj] : path) {
                if(si == ni and sj == nj) continue;
                output(2, get_dir(si, sj, ni, nj), res);
                si = ni, sj = nj;
            }
        }
        // 転がす
        {
            output(3, direction, res);
        }
        C[start_i][start_j] = '.';
        return true;
    };
    while(del_ore());

    for(auto [i, j] : res) print(i, j);
}