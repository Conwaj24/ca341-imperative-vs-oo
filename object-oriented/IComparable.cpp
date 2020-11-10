template <typename T>
class IComparable {
	public:
		virtual bool operator<(T cmp) = 0;
		virtual bool operator>(T cmp) = 0;
		virtual bool operator==(T cmp) = 0;
		bool operator<=(T cmp) {
			return this < cmp || this == cmp;
		}
		bool operator>=(T cmp) {
			return this > cmp || this == cmp;
		}
};
/*
class IntComparable: public Comparable<int> {
	int data;
	public:
		bool operator<(int cmp) { return data < cmp; }
		bool operator>(int cmp) { return data < cmp; }
		bool operator==(int cmp) { return data == cmp; }
};

class StringComparable: public Comparable<char *> {
	int data;
	public:
		bool operator<(char *cmp) { return strcmp(data; }
		bool operator>(char *cmp) { return data < cmp; }
		bool operator==(char *cmp) { return data == cmp; }
};
*/
