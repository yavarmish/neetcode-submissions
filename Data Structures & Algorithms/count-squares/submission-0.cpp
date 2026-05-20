class CountSquares {
    unordered_map<string, int> pointsMap; // since duplicate points are allowed, count of points at a given location is needed
    vector<vector<int>> points;
public:

    CountSquares() {
        
    }
    string createHash(vector<int> point) {
        return to_string(point[0]) + "," + to_string(point[1]); 
    }
    
    void add(vector<int> point) {
        points.push_back(point);
        ++pointsMap[createHash(point)];
    }
    
    int count(vector<int> curPoint) {
        int res = 0, x1 = curPoint[0], y1 = curPoint[1];
        for(vector<int> &point : points) {
            int x3 = point[0], y3 = point[1];
            if(!abs(x1 - x3)  or abs(x1 - x3) != abs(y1 - y3)) continue;
            res += pointsMap[createHash({x1, y3})] * pointsMap[createHash({x3, y1})];   
        }
        return res;
    }
};
