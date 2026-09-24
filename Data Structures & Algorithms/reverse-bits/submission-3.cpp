class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = n;
        ret = (ret >> 16) | (ret << 16); // FFFF0000 <=> 0000FFFF
        ret = ((ret & 0xff00ff00) >> 8) | ((ret & 0x00ff00ff) << 8); 
        ret = ((ret & 0xf0f0f0f0) >> 4) | ((ret & 0x0f0f0f0f) << 4);
        ret = ((ret & 0xcccccccc) >> 2) | ((ret & 0x33333333)<< 2); // cccc'cccc == 1100 ... 1100 <=> 3333'3333 0011 ... 0011
        ret = ((ret & 0xaaaaaaaa)>> 1) | ((ret & 0x555555555)<< 1);
        return ret;
    }
};