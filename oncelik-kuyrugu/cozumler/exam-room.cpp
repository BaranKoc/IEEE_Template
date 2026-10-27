class ExamRoom {
public:
    set<int> s;
    int num;
    ExamRoom(int n) {
        num=n;
    }

    int seat() {
        if(s.size()==0) { s.insert(0); return 0;}
        auto itr = s.begin();
        if(s.size()==1) {
            if(*itr > num-1-(*itr)){ s.insert(0); return 0; }
              else{  s.insert(num-1); return num-1;}
        }
        int mx=-1;
        int l=0;

        if(s.find(0)==s.end()){mx = (*itr); l=-mx;}

        for(int i=0;i<s.size()-1;i++)
        {
           int a=*itr;
           itr++;
           int b = *itr;

           if(mx<(b-a)/2){
               mx=(b-a)/2;
               l=a;
           }
        }
        if(s.find(num-1)==s.end()) {
           if(mx< num-1-(*itr)) {
               mx = (num-1-(*itr));
               l=*itr;
           }
        }
        s.insert(l+mx);
        return l+mx;

    }

    void leave(int p) {

        s.erase(p);
    }
};
