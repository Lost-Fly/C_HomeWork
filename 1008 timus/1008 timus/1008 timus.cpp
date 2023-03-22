#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Pair {
public:
	void SetCords(int x, int y) {
		this->x_ = x;
		this->y_ = y;
	}

	void ShowCords() {
		cout << this->x_ << ' ' << this->y_ << endl;
	}


	int x_;
	int y_;
};



class Neighbours {
public:
	bool top = false;
	bool bottom = false;
	bool right = false;
	bool left = false;
	Pair p_t, p_b, p_r, p_l;
	bool mentioned = false;

	void ShowNeib() {
		if (true) {
			string s = "";
			if (right == true)
				s += "R";
			if (top == true)
				s += "T";
			if (bottom == true)
				s += "B";
			s += ",";
			cout << s << endl;
		}
		else {
			cout << "," << endl;
		}

	};
};

bool comparePairs(Pair& a, Pair& b) {
	return a.y_ < b.y_;
}

void sortCordsByY(vector<Pair>& Cords) {
	sort(Cords.begin(), Cords.end(), comparePairs);
}

int main() {

	vector<Pair> Cords;
	int cords_amount = 0;
	cin >> cords_amount;
	int x, y;

	Neighbours* Neig = new Neighbours[cords_amount];

	for (int i = 0; i < cords_amount; i++) {
		Pair p;
		cin >> x >> y;
		p.SetCords(x, y);
		Cords.push_back(p);
	}

	cout << endl;


	for (int i = 0; i < cords_amount; i++) {
		Cords[i].ShowCords();
	}

	cout << endl;

	sortCordsByY(Cords);

	for (int i = 0; i < cords_amount; i++) {
		Cords[i].ShowCords();
	}

	cout << endl;


	Cords[0].ShowCords();

	for (int i = 0; i < cords_amount - 1 ; i++) {

		for (int j = i + 1; j < cords_amount; j++) {
			if ((Cords[i].x_ == Cords[j].x_) && (Cords[j].y_ - Cords[i].y_ == 1)) {
				Neig[i].top = true;
				Neig[i].p_t.x_ = Cords[j].x_;
				Neig[i].p_t.y_ = Cords[j].y_;
				Neig[j].mentioned = true;
			}
			if ((Cords[i].x_ == Cords[j].x_) && (Cords[i].y_ - Cords[j].y_ == 1)) {
				Neig[i].bottom = true;
				Neig[i].p_b.x_ = Cords[j].x_;
				Neig[i].p_b.y_ = Cords[j].y_;
				Neig[j].mentioned = true;
			}
			if ((Cords[j].x_ - Cords[i].x_ == 1) && (Cords[i].y_ == Cords[j].y_)) {
				Neig[i].right = true;
				Neig[i].p_r.x_ = Cords[j].x_;
				Neig[i].p_r.y_ = Cords[j].y_;
				Neig[j].mentioned = true;
			}
		}

		Neig[i].ShowNeib();


	}


	cout << "." << endl;


}
