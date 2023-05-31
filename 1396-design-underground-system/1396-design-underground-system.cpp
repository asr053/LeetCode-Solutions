class UndergroundSystem {
public:
    map<int,pair<string,int>> store;
    map<pair<string,string>,pair<double,double>>time;
    UndergroundSystem() {
       
    }
    
    void checkIn(int id, string stationName, int t) {
        store[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string,int>p = store[id];
        //p.first = string p.second = time
        store.erase(id);
        if(time.count({p.first,stationName})){
            double value = time[{p.first,stationName}].first*time[{p.first,stationName}].second;
            value += (t-p.second);
            time[{p.first,stationName}]={value/(time[{p.first,stationName}].second+1.0),
                                         time[{p.first,stationName}].second+1.0};
        }else{
         //   cout<<p.first<<" "<<stationName<<endl;
          time[{p.first,stationName}]={(double)(t-p.second),1.0};  
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
      //  cout<<time[{startStation,endStation}].second<<endl;
        return time[{startStation,endStation}].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */