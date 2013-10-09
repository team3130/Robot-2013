namespace util{
	inline double deadzones(double input, double threshold) {
		return (fabs(input) < threshold) ? 0 : input;
	}
}
