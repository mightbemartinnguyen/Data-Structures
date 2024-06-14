#include "stats.h"
#include "iostream"
#include <cassert> 


namespace main_savitch_2C {

	statistician::statistician() {
		reset();
	}

	void statistician::next(double r) {
		total += r;
		count++;

		if ((count == 1) || (r < tinyest)) {
			tinyest = r;
		}

		if ((count == 1) || (r > largest)) {
			largest = r;	
		}

	}

	void statistician::reset() {
		count = 0;
		total = 0.0;
		tinyest = 0.0;
		largest = 0.0;
	}

	int	statistician::length() const {
		return count;
	}

	double	statistician::sum() const {
		return total;
	}

	double	statistician::mean() const {
		assert(count > 0);
		return total / static_cast<double>(count);
		
	}

	double	statistician::minimum() const {
		assert(count > 0);
		return tinyest;
	}

	double	statistician::maximum() const {
		assert(count > 0);
		return largest;
	}

	statistician operator + (const statistician& s1, const statistician& s2) {
		statistician check;
				
		if (s1.length() == 0) {
			return s2;
		}
		if (s2.length() == 0) {
			return s1;
		}

		if (s1.maximum() < s2.maximum()) {
			check.largest = s2.maximum();
		}
		else {
			check.largest = s1.maximum();
		}
		
		if (s2.minimum() > s1.minimum() ) {
			check.tinyest = s1.minimum();
		}
		else {
			check.tinyest = s2.minimum();
		}

		check.count = s1.length() + s2.length();
		check.total = s1.sum()+ s2.sum();
		
		return check;
	}

	statistician operator *(double scale, const statistician& s) {
		statistician check;

		if (s.length() != 0) {
			check.total = scale * s.sum();
			check.count = s.length();

			if (scale > 0) {
				check.tinyest = scale * s.minimum();
				check.largest = scale * s.maximum();
			}
			else {
				check.tinyest = scale * s.maximum();
				check.largest = scale * s.minimum();
			}
		}
		return check;
	}

	bool operator ==(const statistician& s1, const statistician& s2) {
		return (s1.length() == 0 && s2.length() == 0 || (s1.length() == s2.length() && s1.maximum() == s2.maximum() &&
			s1.minimum() == s2.minimum() && s1.sum() == s2.sum()));

	}

}




