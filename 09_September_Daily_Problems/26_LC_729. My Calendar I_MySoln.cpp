class MyCalendar {
public:
    set<pair<int, int>> events;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto &event : events){
            if((event.first>=start && event.first<end) || (event.second>start && event.second<=end)){
                return false;
            }else if((start>=event.first && start<event.second) || (end>event.first && end<=event.second)){
                return false;
            }
        }
        events.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */