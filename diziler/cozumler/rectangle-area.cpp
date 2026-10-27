class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int rec1=abs(ax2-ax1)*abs(ay2-ay1);
        int rec2=abs(bx2-bx1)*abs(by2-by1);

        int ox1=(max(ax1,bx1)-min(ax2,bx2));
        int oy1=(max(ay1,by1)-min(ay2,by2));

        int rec3=0;
        if(ox1<0&&oy1<0)
            rec3=ox1*oy1;
        return rec1+rec2-rec3;
    }
};
