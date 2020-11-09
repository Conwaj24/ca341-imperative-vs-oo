template <typename Cmp>

class Comparable {
	public:
		virtual bool operator<(Cmp cmp) = 0;
		virtual bool operator>(Cmp cmp) = 0;
		virtual bool operator==(Cmp cmp) = 0;
		bool operator<=(Cmp cmp) {
			return this < cmp || this == cmp;
		}
		bool operator>=(Cmp cmp) {
			return this > cmp || this == cmp;
		}
};
