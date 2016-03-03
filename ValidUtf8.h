/*
Write a function to validate whether the input is valid UTF-8. 
Input will be string or byte array, output should be true or false.

1~4 Byte to repensent a symbol

0xxxxxxx valid
110xxxxx 10xxxxxx valid 2 Byte
1110xxxx 10xxxxxx 10xxxxxx valid 3 Byte
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx valid 4 Byte
*/

bool valid_utf8(const vector<unsigned char>& data) {
    int size = 0;
    for(auto c : data) {
        // check First byte
        if(size == 0) {
            if((c >> 5) == 0b110) size = 1;
            else if((c >> 4) == 0b1110) size = 2;
            else if((c >> 3) == 0b11110) size = 3;
            else if(c >> 7) return false;
        } else {
            if((c >> 6) != 0b10) return false;
            --size;
        }
    }
    return size == 0;
}