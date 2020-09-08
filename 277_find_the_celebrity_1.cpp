/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        this->n = n;
        int candidate = 0;
        for(int i=0;i<n;i++){
            if(knows(candidate,i))
                candidate = i;
        }
        if(is_celebrity(candidate)) return candidate;
        return -1;
    }
private: 
      int n =0 ;
      bool is_celebrity(int i){
        for(int k=0;k<this->n;k++){
            if(k == i) continue;
            //two cases to reject candidate
            if(!knows(k,i) || knows(i,k)) return false;
        }
          return true;
     }
};
