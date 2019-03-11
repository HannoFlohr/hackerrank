

//Define the structs Workshops and Available_Workshops.
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    vector<Workshop> ws;
    Available_Workshops(int &nws) {
        ws = vector<Workshop>(n);
        n = nws;
    }
};

bool compare(Workshop &w1, Workshop &w2) {
    return w1.end_time < w2.end_time;
}

Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* aws = new Available_Workshops(n);
    Workshop ws;
    for(int i=0; i<n; i++) { 
        ws.start_time = start_time[i]; 
        ws.duration = duration[i]; 
        ws.end_time = start_time[i] + duration[i];
        aws->ws.push_back(ws);
    }
    sort(aws->ws.begin(), aws->ws.end(), compare); 
    return aws;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int cur_end=0, max_ws=0;
    for(int i=0; i<ptr->n; i++) {
        if(ptr->ws[i].start_time >= cur_end) {
            cur_end = ptr->ws[i].end_time;
            max_ws++;
        }
    }
    return max_ws;
}

/* works for all but one test case, too slow for last one
int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int n=ptr->n, max_ws=0, min_end, min_end_pos, start, end;

    //cout << "Found " << n << "workshops.." << endl; 

    vector<Workshop> v;
    for(int i=0; i<n; i++) v.push_back(ptr->ws[i]); 

    //cout << "processing.." << endl;

    Workshop ws;
    while(!v.empty() ) {
        //cout << "v: " << v.size() << " | max: " << max_ws << endl;
        //find workshop with earliest finishing time
        min_end=1000000, min_end_pos = -1;
        for(int i=0; i<v.size(); i++) {
            if(v[i].end_time < min_end) {
                min_end = v[i].end_time;
                min_end_pos = i;
            }
        }

        //delete that workshop and all overlapping workshops
        if(min_end_pos != -1) {
            max_ws++;
            start=v[min_end_pos].start_time;
            end=v[min_end_pos].end_time;
            v.erase(v.begin()+min_end_pos);

            for(int i=0; i<v.size(); i++) {    
                if( (v[i].start_time<=start && v[i].end_time>end) ||
                    (v[i].start_time<=start && v[i].end_time>=start) ||
                    (v[i].start_time>=start && v[i].end_time<=end) ||
                    (v[i].start_time<end && v[i].end_time>end)  
                    ) {
                    v.erase(v.begin()+i);
                    i--;
                }
            }
        }
    }

    return max_ws;
}*/

