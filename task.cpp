class Task{
    private:
    int id;
    int releaseTime;
    int executionTime;
    int C;

    public:
    Task(int _id, int _relaseTime, int _executionTime):
    id(_id), releaseTime(_relaseTime), executionTime(_executionTime), C(0) {};


    int getReleaseTime(){
        return releaseTime;
    }

    int getExecutionTime(){
        return executionTime;
    }

    int getC(){
        return C;
    }

    void setC(int C){
        this->C = C;
    }
    
    bool operator < (const Task &r) const{
        if(releaseTime == r.releaseTime){
            return executionTime > r.executionTime;
        }

        return releaseTime < r.releaseTime;
    }
    
};