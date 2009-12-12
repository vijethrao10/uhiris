#ifndef _TRACKER_H_
#define _TRACKER_H_
#include <vector>
#include "cv.h"

using namespace cv;
using std::vector;

class Tracker {

public:
	enum Topographic {UNKNOWN, PEAK, PIT, RIDGE, RAVINE, RIDGESADDLE, RAVINESADDLE, CONVEXHILL, CONCAVEHILL, CONVEXSADDLEHILL, CONCAVESADDLEHILL, SLOPEHILL, FLAT};
	Tracker();
	~Tracker();

	/**
		If no iris is located via Mutual Information search, try reinitialize.
		Keep initializing until the iris is located.
	*/
	void InitializeFrame(Mat img, vector<Point> &eyes);

private:
	Topographic TopographicClassification(Mat grad, double eval1, double eval2, Mat evec1, Mat evec2);
	float t_mag_;
	float t_ev_;
	float t_ge_;

	Mat h10_;
	Mat h20_;
	Mat h01_;
	Mat h11_;
	Mat h02_;

	static const double myeps;
};

#endif