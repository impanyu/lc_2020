// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    int read(char *buf, int n) {
       int count = 0;
       int r = 0;
       while(count <= n/4){
           r = read4(buf+ count*4);
           if(r < 4 || n - count*4 < 4)
               break;
           count++;
       }
        return count*4 + min(r,n-count*4);
    }
};
