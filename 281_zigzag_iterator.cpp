class ZigzagIterator {
public:
    int i = 0;
    vector<int> v;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        int n1 = v1.size(), n2 = v2.size(), n = max(n1,n2);
        for(int i = 0; i<n; i++){
            if(i < n1) v.push_back(v1[i]);
            if(i < n2) v.push_back(v2[i]);
        }
    }

    int next() {
        return v[i++];
    }

    bool hasNext() {
        return i < v.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
