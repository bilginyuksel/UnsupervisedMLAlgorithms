#ifndef iostream
#include <iostream>
#endif

#ifndef vector
#include <vector>
#endif

#ifndef cmath
#include <cmath>
#endif

#ifndef dist
#include "../util/algo.h"
#endif

#ifndef UNCLASSIFIED
#define UNCLASSIFIED -1
#endif
#ifndef NOISE
#define NOISE 0
#endif

#ifndef DBSCA


#define DBSCA

struct db_point {

    std::vector<float> data;
    int status;

    db_point(const std::vector<float>& d) {
        for (const float f : d) data.push_back(f);
        status = UNCLASSIFIED;
    }
};

class DBSCAN {
    /*
    Density based clustering

     1.Find all the neighbor points within eps and identify the core points or visited with more than MinPts neighbors.
     2.For each core point if it is not already assigned to a cluster, create a new cluster.
     3.Find recursively all its density connected points and assign them to the same cluster as the core point.
     4.A point a and b are said to be density connected if there exist a point c which has a sufficient number of points in its neighbors and both the points a and b are within the eps distance. This is a chaining process. So, if b is neighbor of c, c is neighbor of d, d is neighbor of e, which in turn is neighbor of a implies that b is neighbor of a.
     5.Iterate through the remaining unvisited points in the dataset. Those points that do not belong to any cluster are noise.
*/
private:
    float eps;
    int min_points;
    std::vector<db_point> points;
public:
    DBSCAN(float eps, int minPoints) {
        this->eps = eps;
        this->min_points = minPoints;
    }
    
    // Fit function to train the model
    void fit(const std::vector<std::vector<float>>& data);

private:
    bool expandCluster(db_point& d, int clusterID);
    std::vector<int> findNeighbors(db_point& d);
    
};

#endif // !DBSCA
