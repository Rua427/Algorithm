#include <iostream>

using namespace std;

struct RectAngle {
	long long x1, y1, x2, y2;
};

// 겹쳐지는 사각형의 좌표 구하기
RectAngle Calc_Intersect_Coord(const RectAngle& a, const RectAngle& b) {
	RectAngle t{ 0,0,0,0 };

	// 겹쳐지지 않을 경우
	if (a.x2 < b.x1 || a.x1 > b.x2 || a.y2 < b.y1 || a.y1 > b.y2) return t;

	// 겹쳐지는 부분의 좌표 계산
	t.x1 = max(a.x1, b.x1);
	t.y1 = max(a.y1, b.y1);
	t.x2 = min(a.x2, b.x2);
	t.y2 = min(a.y2, b.y2);

	return t;
}

// 겹쳐지는 면적 구하기
long long Calc_Intersect_Area(const RectAngle &a, const RectAngle &b) 
{
	// 겹쳐지는 부분의 좌표 계산
	RectAngle t = Calc_Intersect_Coord(a, b);

	// 겹쳐지는 면적 계산
	long long width = t.x2 - t.x1;
	long long height = t.y2 - t.y1;

	return width * height;
}

int main() {
	int tc = 0;
	cin >> tc;
	RectAngle w{ 0,0,0,0 };
	RectAngle b[2]{ 0,0,0,0 };

	for (int i = 0; i < tc; i++)
	{
		cin >> w.x1 >> w.y1 >> w.x2 >> w.y2;
		long long area = (w.x2 - w.x1) * (w.y2 - w.y1);

		for (int j = 0; j < 2; j++)
		{
			cin >> b[j].x1 >> b[j].y1 >> b[j].x2 >> b[j].y2;
		}

		// 흰 종이와 검은 종이가 겹쳐지는 면적을 구함
		long long inter_A = Calc_Intersect_Area(w, b[0]);
		long long inter_B = Calc_Intersect_Area(w, b[1]);
		// 검은종이 끼리 겹쳐있을경우 중복으로 흰 종이가 가려지는 면적을 계산할 수 있으므로
		long long inter_C = Calc_Intersect_Area(w, Calc_Intersect_Coord(b[0], b[1]));
		// 흰 종이가 보여지는 면적을 구함
		area = area - (inter_A + inter_B - inter_C);

		cout <<  (area <= 0 ? "NO" : "YES") << endl;
	}
	return 0;
}
