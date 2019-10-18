// Copyright (C) Common Computational Geometry Algorithms e.U, ZutterHao
//
// This file is implementation of Common Common Computational Geometry Algorithms.
//
// Please please pay attention to input according to the specified data type.
//
// Author: ZutterHao .Nanjing University ,VISG
// Github: https://github.com/fanghao6666

// ����ʵ�ֵ�һЩ���㼸���г������㷨�������㣬�ߣ�����ε�
// �����㷨ֻ������C++��׼�⣬���ð����κ�������������
// ʹ��ʱ��ע�ⰴ�չ涨���������ͽ�������
// Ŀǰֻʹ��C++��ʵ���㷨�������㷨ԭ���½����Github�ϸ���
// Github: https://github.com/fanghao6666

/*** ������ͷ�ļ� ***/
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

/*** ���ó��� ***/
const double PI = 3.14159265;

/******************************* ���������������� *******************************/
// ��,��ά����ά,ͬʱ��Ҳ���Ա�ʾһ��ʸ��
struct Point
{
	double x;	// x����
	double y;	// y����
	double z;	// z���꣨Ĭ��Ϊ0�������Ҫ��ά�����z��ֵ��

	Point(double a = 0, double b = 0, double c = 0) { x = a; y = b; z = c; } // ���캯��
};
// ��ļӷ�
Point add(const Point& lhs, const Point& rhs)
{
	Point res;

	res.x = lhs.x + rhs.x;
	res.y = lhs.y + rhs.y;
	res.z = lhs.z + rhs.z;

	return res;
}
// ��ļ���
Point sub(const Point& lhs, const Point& rhs)
{
	Point res;

	res.x = lhs.x - rhs.x;
	res.y = lhs.y - rhs.y;
	res.z = lhs.z - rhs.z;

	return res;
}
// �����ĳ˷�
Point mul(const Point& p, double ratio)
{
	Point res;

	res.x = p.x * ratio;
	res.y = p.y * ratio;
	res.z = p.z * ratio;

	return res;
}
// �����ĳ���
Point div(const Point& p, double ratio)
{
	Point res;

	res.x = p.x / ratio;
	res.y = p.y / ratio;
	res.z = p.z / ratio;

	return res;
}
// ���ж����
bool equal(const Point& lhs, const Point& rhs)
{
	return(lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z);
}
// ��,�����߶κ�ֱ��
struct Line
{
	Point s;	// ���
	Point e;	// �յ�
	bool is_seg; // �Ƿ����߶�

	Line() {};	// Ĭ�Ϲ��캯��
	Line(Point a, Point b, bool _is_seg = true) { s = a; e = b; is_seg = _is_seg; }	// ���캯��(Ĭ�����߶�)
};
// ������ƽ��
struct Triangle
{
	Point v0;
	Point v1;
	Point v2;
	bool is_plane;

	Triangle() {}; // Ĭ�Ϲ��캯��
	Triangle(Point a, Point b, Point c, bool _is_plane = false) { v0 = a; v1 = b; v2 = c; is_plane = _is_plane; }// ���캯����Ĭ���������Σ�
};

/******************************* ���㼸���㷨Ŀ¼ *******************************/

// һ����
// 1.1������֮��ľ���
double distance(const Point& p1, const Point& p2);

// 1.2��ʸ������
double length(const Point& vec);

// 1.3��ʸ����׼��
Point normalize(const Point& vec);

// 1.4��ʸ�����
double dotMultiply(const Point& op, const Point& p1, const Point& p2);
double dotMultiply(const Point& vec1, const Point& vec2);

// 1.5��ʸ�����
Point multiply(const Point& op, const Point& p1, const Point& p2);
Point multiply(const Point& vec1, const Point& vec2);

// 1.6���㵽�ߵľ���
double ptolDistance(const Point& p, const Line& l);

// 1.7���㵽�ߵ�ͶӰ��
Point ptolProjection(const Point& p, const Line& l);

// 1.8��������ߵĶԳƵ�
Point ptolSymmetry(const Point& p, const Line& l);

// 1.9�����Ƿ�������
bool isponl(const Point& p, const Line& l);

// 1.10��ʸ���н�����
double Sin(const Point& op, const Point& p1, const Point& p2);
double Sin(const Point& vec1, const Point& vec2);

// 1.11��ʸ���н�����
double Cos(const Point& op, const Point& p1, const Point& p2);
double Cos(const Point& vec1, const Point& vec2);

// 1.12��ʸ���н�����
double Tan(const Point& op, const Point& p1, const Point& p2);
double Tan(const Point& vec1, const Point& vec2);

// 1.13��ʸ���нǽǶ�
double Angle(const Point& op, const Point& p1, const Point& p2, bool is_radian = true);
double Angle(const Point& vec1, const Point& vec, bool is_radian = true);

// 1.14���ж������Ƿ���
bool isPointsCollinear(const Point& p1, const Point& p2, const Point& p3);

// 1.15���ڣ�-1��-1������1��1���������n����
vector<Point> randomGenPoints(int num);

// ������
// 2.1���߶��Ƿ��ཻ
bool isSegIntersect(const Line& l1, const Line& l2, Point& inter_p);

// 2.2����ֱ�ߵļн�
double angleOfLines(const Line& l1, const Line& l2, bool is_radian = true);

// 2.3��һ�ױ��������߲�ֵ
vector<Point> firstOrderBezier(const Point& s, const Point& e, int inter_num);

// 2.4�����ױ��������߲�ֵ
vector<Point> secondOrderBezier(const Point& s, const Point& e, const Point& p, int inter_num);

// 2.5�����ױ��������߲�ֵ
vector<Point> thirdOrderBezier(const Point& s, const Point& e, const Point& p1, const Point& p2, int inter_num);

// 2.6���ڣ�-1��-1������1��1���������n����
vector<Line> randomGenLines(int num);

// ����������
// 3.1���������������Ƿ��ܹ�����������
bool isTriangle(const Triangle& t);

// 3.2�����Ƿ����������ڲ�
bool isPointInTriangle(const Triangle& t, const Point& p, double& u, double& v);

// 3.3���㵽ƽ���ͶӰ�㣨��������ĵ㣩
Point ptotProjection(const Triangle& t, const Point& p);

// 3.4���㵽ƽ��ľ���
double ptotDistance(const Triangle& t, const Point& p);

// 3.5���߶κ�ƽ��Ľ���
Point ltotInterPoint(const Triangle& t, const Line& l);

// 3.6������ƽ��ĵ�λ������
Point getUnitNormal(const Triangle& t);

// 3.7�����������ε����
double areaOfTriangle(const Triangle& t);


// �ġ������
// 4.1���ж϶���ζ���İ�͹��
void checkConvex(const vector<Point>& polygon, vector<bool>& flags);

// 4.2���ж϶�����Ƿ�Ϊ͹�����
bool isConvex(const vector<Point>& polygon);

// 4.3��������Χ�ɵ����
double areaOfPolygon(const vector<Point>& polygon);

// 4.4���ж϶�����Ƿ�����ʱ������
bool isConterClock(const vector<Point>& polygon);

// 4.5���жϵ��Ƿ��ڶ�����ڲ�
bool isPointInPolygon(const vector<Point>& polygon, const Point& p);

// 4.6���ж��߶��Ƿ��ڶ�����ڲ�
bool isSegInPolygon(const vector<Point>& polygon, const Line& l);

// 4.7���ж�Բ�Ƿ��ڶ�����ڲ�
bool isCircleInPolygon(const vector<Point>& polygon, const Point& p, double radius);

// 4.8��Ѱ�ҵ㼯͹���㷨��graham�㷨��
vector<Point> findConvexGraham(const vector<Point>& points);

// 4.9��Ѱ�ҵ㼯͹���㷨������͹������ʱ�临�Ӷ�O(nlogn)
vector<Point> findConvex(const vector<Point>& points);

// 4.10����򵥶��������
Point centerOfPolygon(const vector<Point>& polygon);

// 4.11����϶��ڶ�����ڲ���һ����
Point pointInPolygon(const vector<Point>& polygon);

// 4.12���������εķ�Χ
void boxOfPolygon(const vector<Point>& polygon, Point& down_left, Point& up_right);

// �塢Բ
// 5.1�����Բ�Ĺ�ϵ
int pointToCircle(const Point& c, double radius, const Point& p);

// 5.2��ֱ�ߺ�Բ�Ĺ�ϵ
int lineToCircle(const Point& c, double radius, const Line& l);

// 5.3���߶κ�Բ�Ĺ�ϵ
int segToCircle(const Point& c, double radius, const Line& l);

// 5.4����Բ֮��Ĺ�ϵ
int circleToCircle(const Point& c1, double raduis1, const Point& c2, double radius2);



/******************************* ���㼸���㷨ʵ�� *******************************/
//һ����

// 1.1������֮��ľ���
//
// ������p1 : ��һ���� p2: �ڶ�����
//  
double distance(const Point& p1, const Point& p2)
{
	return(sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2)));
}

// 1.2��ʸ���ĳ���
//
// ������ vec ʸ��
//
double length(const Point& vec)
{
	return (sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
}

// 1.3��ʸ����׼����ʸ���ĳ��ȹ�Լ��1��
//
// ������ vec �� ʸ��
//
Point normalize(const Point& vec)
{
	Point res;

	res = div(vec, length(vec));

	return res;
}

// 1.4��ʸ�����
//
// ������(p1-op)Ϊʸ��1����p2-op��Ϊʸ��2
//
double dotMultiply(const Point& op, const Point& p1, const Point& p2)
{
	return ((p1.x - op.x) * (p2.x - op.x) + (p1.y - op.y) * (p2.y - op.y) + (p1.z - op.z) * (p2.z - op.z));
}
// ������vec1Ϊʸ��1��vec2Ϊʸ��2
//
double dotMultiply(const Point& vec1, const Point& vec2)
{
	return(vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z);
}

// 1.5��ʸ�����
//
// ������(p1-op)Ϊʸ��1����p2-op��Ϊʸ��2
// 
Point multiply(const Point& op, const Point& p1, const Point& p2)
{
	Point result;

	result.x = (p1.y - op.y) * (p2.z - op.z) - (p2.y - op.y) * (p1.z - op.z);
	result.y = (p1.z - op.z) * (p2.x - op.x) - (p2.z - op.z) * (p1.x - op.x);
	result.z = (p1.x - op.x) * (p2.y - op.y) - (p2.x - op.x) * (p1.y - op.y);

	return result;
}
// ������ vec1Ϊʸ��1��vec2Ϊʸ��2
//
Point multiply(const Point& vec1, const Point& vec2)
{
	Point result;

	result.x = vec1.y * vec2.z - vec2.y * vec1.z;
	result.y = vec1.z * vec2.x - vec2.z * vec1.x;
	result.z = vec1.x * vec2.y - vec2.x * vec1.y;

	return result;
}

// 1.6���㵽�ߵľ���
// 
// ������ p : ��  l��ֱ��
//
double ptolDistance(const Point& p, const Line& l)
{
	Point line_vec = sub(l.e, l.s);
	Point point_vec = sub(p, l.s);

	// ���ȼ�������߶�ͶӰ����
	double project_len = dotMultiply(line_vec, point_vec) / length(line_vec);

	// ���ݹ��ɶ�������ľ���
	double distance = sqrt(pow(length(line_vec), 2) - pow(project_len, 2));

	return distance;
}

// 1.7���㵽�ߵ�ͶӰ��
//
// ������p : ��  l : ��
//
Point ptolProjection(const Point& p, const Line& l)
{
	Point line_vec = sub(l.e, l.s);
	Point point_vec = sub(p, l.s);
	Point unit_line_vec = normalize(line_vec);

	// ����ͶӰ����
	double project_len = dotMultiply(point_vec, unit_line_vec);

	// ͶӰ��
	Point project_p = add(l.s, mul(unit_line_vec, project_len));

	return project_p;
}

// 1.8��������ߵĶԳƵ�
//
// ������ p : ��  l : �Գ���
//
Point ptolSymmetry(const Point& p, const Line& l)
{
	// �����������ֱ���ϵ�ͶӰ��
	Point project_p = ptolProjection(p, l);

	// �㵽ͶӰ�������
	Point project_vec = sub(project_p, p);

	// �ԳƵ�
	Point symmetry_p = add(p, mul(project_vec, 2));

	return symmetry_p;
}

// 1.9�����Ƿ�������
// �߷�Ϊֱ�ߺ��߶Σ�ֱ�߱�ʾ����ֱ���Ƿ񾭹���
//
// ������p : ��  l : �߶λ�����
// 
bool isponl(const Point& p, const Line& l)
{
	Point line_vec = sub(l.e, l.s);
	Point point_vec1 = sub(p, l.s);
	Point point_vec2 = sub(p, l.e);

	Point mul_vec = multiply(line_vec, point_vec1);
	double dot = dotMultiply(point_vec1, point_vec2);
	// ���Ƿ����߶���
	if (l.is_seg)
	{
		if (equal(p, l.s) || equal(p, l.e))
			return true;
		return (0.0 == length(mul_vec) && dot < 0.0);

	}
	// ���Ƿ���ֱ����
	else
	{
		return (0.0 == length(mul_vec));
	}
}

// 1.10��ʸ���н�����
//
// ������ op : ʸ�������� p1 : ʸ��1�˵� p2 : ʸ��2�˵�
//
double Sin(const Point& op, const Point& p1, const Point& p2)
{
	Point vec1 = sub(p1, op);
	Point vec2 = sub(p2, op);

	return Sin(vec1, vec2);
}
// ������ vec1 ʸ��1  vec2 ʸ��2
// 
double Sin(const Point& vec1, const Point& vec2)
{
	return sqrt(1.0 - pow(Cos(vec1, vec2), 2));
}

// 1.11��ʸ���н�����
//
// ������ op : ʸ�������� p1 : ʸ��1�˵� p2 : ʸ��2�˵�
//
double Cos(const Point& op, const Point& p1, const Point& p2)
{
	Point vec1 = sub(p1, op);
	Point vec2 = sub(p2, op);

	return Cos(vec1, vec2);
}
// ������ vec1 ʸ��1  vec2 ʸ��2
// 
double Cos(const Point& vec1, const Point& vec2)
{
	Point unit_vec1 = normalize(vec1);
	Point unit_vec2 = normalize(vec2);

	return dotMultiply(unit_vec1, unit_vec2);
}

// 1.12��ʸ���н�����
//
// ������ op : ʸ�������� p1 : ʸ��1�˵� p2 : ʸ��2�˵�
//
double Tan(const Point& op, const Point& p1, const Point& p2)
{
	Point vec1 = sub(p1, op);
	Point vec2 = sub(p2, op);

	return Tan(vec1, vec2);
}
// ������ vec1 ʸ��1  vec2 ʸ��2
// 
double Tan(const Point& vec1, const Point& vec2)
{
	double cos = Cos(vec1, vec2);
	double sin = Sin(vec1, vec2);

	// ��ĸ��Ϊ��
	if (0.0 == cos)
		return -1;
	else
		return (sin / cos);
}

// 1.13�������ļнǽǶ�
// ����:  op : ʸ�������� p1 : ʸ��1�˵� p2 : ʸ��2�˵� is_radian : Ĭ��Ϊ������
//
double Angle(const Point& op, const Point& p1, const Point& p2, bool is_radian)
{
	double cos_value = Cos(op, p1, p2);

	if (is_radian)
	{
		return acos(cos_value);
	}
	else
	{
		return (acos(cos_value) / PI * 180.0);
	}
}
// ������ vec1 : ʸ��1 vec2 : ʸ��2
// 
double Angle(const Point& vec1, const Point& vec2, bool is_radian)
{
	double cos_value = Cos(vec1, vec2);

	if (is_radian)
	{
		return acos(cos_value);
	}
	else
	{
		return (acos(cos_value) / PI * 180.0);
	}
}

// 1.14���ж������Ƿ���
bool isPointsCollinear(const Point& p1, const Point& p2, const Point& p3)
{
	Line line(p1, p2, false);

	// �жϵ��������Ƿ���ǰ��������߶���
	return isponl(p3, line);
}

// 1.15���ڣ�-1��-1������1��1���������n����
//
// ������ down_left : �������½� up_right: �������Ͻ� num : ���ɵ������
//
vector<Point> randomGenPoints(int num)
{
	vector<Point> result;

	std::uniform_real_distribution<double> dist(-0.9, 0.9);
	std::mt19937 rng;
	rng.seed(std::random_device{}());
	for (int i = 0; i < num; ++i)
	{
		double rand_x = dist(rng);
		double rand_y = dist(rng);

		result.push_back(Point(rand_x, rand_y));
	}
	return result;
}

// ������

// 2.1���߶��Ƿ��ཻ
// ��������߶εĶ˵��غϻ���ĳ���߶ζ˵�����һ���߶���Ҳ���ཻ
// �߶��ж��Ƿ��ཻ�������ֱ�����൱���ж��Ƿ�ƽ��
//
// ������ l1 : �߶�1  l2 : �߶�2  inter_p : ����ཻ���ؽ���
//
bool isSegIntersect(const Line& l1, const Line& l2, Point& inter_p)
{
	Point line1 = sub(l1.e, l1.s);
	Point line2 = sub(l2.e, l2.s);
	Point norm1 = normalize(line1);
	Point norm2 = normalize(line2);
	// �߶��ཻ
	if (l1.is_seg)
	{
		// �˵����߶���
		if (isponl(l1.s, l2))
		{
			inter_p = l1.s;
			return true;
		}
		if (isponl(l1.e, l2))
		{
			inter_p = l1.e;
			return true;
		}
		if (isponl(l2.s, l1))
		{
			inter_p = l2.s;
			return true;
		}
		if (isponl(l2.e, l1))
		{
			inter_p = l2.e;
			return true;
		}
		// �ж��߶��Ƿ��໥����
		double dot1 = dotMultiply(multiply(sub(l2.s, l1.s), line1), multiply(sub(l2.e, l1.s), line1));
		double dot2 = dotMultiply(multiply(sub(l1.s, l2.s), line2), multiply(sub(l1.e, l2.s), line2));
		if (dot1 < 0.0 && dot2 < 0.0)
		{
			double t1 = length(multiply(sub(l1.s, l2.s), norm2)) / length(multiply(norm2, norm1));
			double t2 = length(multiply(sub(l2.s, l1.s), norm1)) / length(multiply(norm1, norm2));

			inter_p = add(l1.s, mul(norm1, t1));
			return true;
		}
		else
		{
			return false;
		}

	}
	// ֱ���ཻ
	else
	{
		if (Cos(line1, line2) == 1.0)
			return false;

		double t1 = length(multiply(sub(l1.s, l2.s), norm2)) / length(multiply(norm2, norm1));
		double t2 = length(multiply(sub(l2.s, l1.s), norm1)) / length(multiply(norm1, norm2));

		inter_p = add(l1.s, mul(norm1, t1));
		return true;
	}
}

// 2.2����ֱ�ߵļн�
// 
// 
// ������ l1 : �߶�1 l2 : �߶�2
//
double angleOfLines(const Line& l1, const Line& l2, bool is_radian)
{
	Point line1 = sub(l1.e, l1.s);
	Point line2 = sub(l2.e, l2.s);

	return Angle(line1, line2, is_radian);
}

// 2.3��һ�ױ��������߲�ֵ
// 
// ������ s�� ��� e : �յ� inter_num����ֵ����������������ʼ�㣩
// ����ֵ������ʼ��
//
vector<Point> firstOrderBezier(const Point& s, const Point& e, int inter_num)
{
	vector<Point> res;
	res.push_back(s);
	for (int i = 1; i <= inter_num; ++i)
	{
		double a1 = double(i) / double(inter_num + 1);
		double a2 = 1.0 - a1;
		res.push_back(add(mul(s, a2), mul(e, a1)));
	}
	res.push_back(e);

	return res;
}

// 2.4�����ױ��������߲�ֵ
// 
// ������ s�� ��� e : �յ� p : ���Ƶ� inter_num����ֵ����������������ʼ�㣩
// ����ֵ������ʼ��
//
vector<Point> secondOrderBezier(const Point& s, const Point& e, const Point& p, int inter_num)
{
	vector<Point> res;
	res.push_back(s);
	for (int i = 1; i <= inter_num; ++i)
	{
		double a = double(i) / double(inter_num + 1);
		double a1 = pow(a, 2);
		double a2 = 2 * a * (1.0 - a);
		double a3 = pow(1.0 - a, 2);
		res.push_back(add(add(mul(s, a3), mul(p, a2)), mul(e, a1)));
	}
	res.push_back(e);

	return res;
}

// 2.5�����ױ��������߲�ֵ
// 
// ������ s�� ��� e : �յ� p1��p2 : ���Ƶ� inter_num����ֵ����������������ʼ�㣩
// ����ֵ������ʼ��
//
vector<Point> thirdOrderBezier(const Point& s, const Point& e, const Point& p1, const Point& p2, int inter_num)
{
	vector<Point> res;
	res.push_back(s);
	for (int i = 1; i <= inter_num; ++i)
	{
		double a = double(i) / double(inter_num + 1);
		double a1 = pow(a, 3);
		double a2 = 3 * pow(a, 2) * (1.0 - a);
		double a3 = 3 * pow(1.0 - a, 2) * a;
		double a4 = pow(1.0 - a, 3);
		res.push_back(add(add(add(mul(s, a4), mul(p1, a3)), mul(p2, a2)), mul(e, a1)));
	}
	res.push_back(e);

	return res;
}

// 2.6���ڣ�-1��-1������1��1���������n����
//
// ���� num : ��Ҫ���ɵ��߶ε�����
//
vector<Line> randomGenLines(int num)
{
	vector<Line> result;

	std::uniform_real_distribution<double> dist(-0.9, 0.9);
	std::mt19937 rng;
	rng.seed(std::random_device{}());
	for (int i = 0; i < num; ++i)
	{
		double rand_sx = dist(rng);
		double rand_sy = dist(rng);
		Point p1(rand_sx, rand_sy);
		double rand_ex = dist(rng);
		double rand_ey = dist(rng);
		Point p2(rand_ex, rand_ey);
		
		result.push_back(Line(p1,p2,true));
	}
	return result;
}

// ����������

// 3.1���������������Ƿ��ܹ�����������
// �����ߵ����������һ��������
// 
// ������ t : ������
// 
bool isTriangle(const Triangle& t)
{
	return isPointsCollinear(t.v0, t.v1, t.v2);
}

// 3.2�����Ƿ����������ڲ������ķ���
// �㷨�������ӣ� https://www.cnblogs.com/graphics/archive/2010/08/05/1793393.html
//
// ������ t : ������ p : ��Ҫ�жϵĵ� u,v�ֱ�Ϊ���ڱ�ʾ������������ͶӰϵ��
//
bool isPointInTriangle(const Triangle& t, const Point& p, double& u, double& v)
{
	Point vec1 = sub(t.v1, t.v0);
	Point vec2 = sub(t.v2, t.v0);
	Point vec_p = sub(p, t.v0);

	double dot00 = dotMultiply(vec1, vec1);
	double dot01 = dotMultiply(vec1, vec2);
	double dot02 = dotMultiply(vec1, vec_p);
	double dot11 = dotMultiply(vec2, vec2);
	double dot12 = dotMultiply(vec2, vec_p);

	double inverDeno = 1 / (dot00 * dot11 - dot01 * dot01);

	u = (dot11 * dot02 - dot01 * dot12) * inverDeno;
	v = (dot00 * dot12 - dot01 * dot02) * inverDeno;

	if (u < 0 || u > 1) return false;
	if (v < 0 || v > 1) return false;
	if (u + v < 1)return true;
	else return false;
}

// 3.3���㵽ƽ������ĵ㣬���㵽ƽ���ͶӰ
// 
// ������t : ������ p : ��
// 
Point ptotProjection(const Triangle& t, const Point& p)
{
	Point vec_p = sub(p, t.v0);
	Point unit_normal = getUnitNormal(t);

	double ratio = dotMultiply(vec_p, unit_normal);

	return sub(p, mul(unit_normal, ratio));
}

// 3.4���㵽ƽ��ľ���
//
// ������ t : ���������ڵ�ƽ�� p : ��Ҫ�жϵĵ�
//
double ptotDistance(const Triangle& t, const Point& p)
{
	Point project_p = ptotProjection(t, p);

	return distance(p, project_p);
}

// 3.5���߶κ�ƽ��Ľ���
// 
// ������ t : ����������ƽ�� l : ֱ��
//
Point ltotInterPoint(const Triangle& t, const Line& l)
{
	Point line_vec = sub(l.e, l.s);
	Point point_vec = sub(t.v0, l.s);
	Point unit_plane_normal = getUnitNormal(t);

	double ratio = dotMultiply(point_vec, unit_plane_normal) / dotMultiply(unit_plane_normal, line_vec);

	return add(l.s, mul(line_vec, ratio));
}

// 3.6������ƽ��ĵ�λ������
// 
// ������ t : ������ƽ��
// 
Point getUnitNormal(const Triangle& t)
{
	Point vec1 = sub(t.v1, t.v0);
	Point vec2 = sub(t.v2, t.v0);

	return normalize(multiply(vec1, vec2));
}

// 3.7�����������ε����
//
// ������ t : ������ƽ��
//
double areaOfTriangle(const Triangle& t)
{
	return (0.5 * length(multiply(sub(t.v1, t.v0), sub(t.v2, t.v0))));
}

// �ġ������
// ���û���ر�˵������Ĭ���������ζ��㰴����ʱ�����У���Ϊ��ά�㼴z=0

// 4.1���ж϶���ζ���İ�͹��
// 
// ������ polygon : ����ε㼯�� flags : ��־ÿ�����Ƿ���͹��
//
void checkConvex(const vector<Point>& polygon, vector<bool>& flags)
{
	flags.resize(polygon.size());

	// �ҵ���һ��͹�Ķ���
	int index = 0;
	for (int i = 1; i < polygon.size(); ++i)
	{
		if (polygon[i].y < polygon[index].y ||
			(polygon[i].y == polygon[index].y && polygon[i].x < polygon[index].x))
		{
			index = i;
		}
	}
	/* �ж�ÿ����İ�͹��
	*  ͨ���ж�ǰ�����������������ж��Ƿ�������ʱ��
	*/
	int size = polygon.size() - 1;
	flags[index] = true;
	while (size)
	{
		if (multiply(polygon[index], polygon[(index + 1) % size], polygon[(index + 2) % size]).z >= 0)
		{
			flags[(index + 1) % size] = true;
		}
		else
		{
			flags[(index + 1) % size] = false;
		}
		index++;
		size--;
	}
}

// 4.2���ж϶�����Ƿ�Ϊ͹�����
//
// ���� �� polygon : ����Ķ���ζ���
//
bool isConvex(const vector<Point>& polygon)
{
	vector<bool> flags;
	// �ж�ÿ����İ�͹��
	checkConvex(polygon, flags);
	// �����һ���㲻��͹�ģ���˶����Ϊ��͹
	for (auto c : flags)
		if (!c)
			return false;
	return true;
}

// 4.3��������Χ�ɵ����
//
// ������ polygon : �����
//
double areaOfPolygon(const vector<Point>& polygon)
{
	// �������ε����������������Ƿ�
	int size = polygon.size();
	if (size < 3) return 0;

	double area(0.0);
	for (int i = 0; i < size; ++i)
	{
		area += polygon[i].y * (polygon[(i - 1 + size) % size].x - polygon[(i + 1) % size].x);
	}

	return (area / 2);
}

// 4.4���ж϶�����Ƿ�����ʱ������
//
// ������ polygon : �����
//
bool isConterClock(const vector<Point>& polygon)
{
	return areaOfPolygon(polygon) > 0;
}

// 4.5���жϵ��Ƿ��ڶ�����ڲ�
// �жϴӵ�����һ���߶������εĽ���ĸ���
// ���������ཻ��ż�������ཻ
// 
// ������ polygon : ����� p : ��Ҫ�жϵĵ�
//
bool isPointInPolygon(const vector<Point>& polygon, const Point& p)
{
	Point down_left, up_right;
	boxOfPolygon(polygon, down_left, up_right);

	// λ�ڶ�����ⲿһ��
	Point out_p = sub(down_left, Point(10.0, 0.0));

	int cnt(0);
	Line p_line(p, out_p, true);
	for (int i = 0; i < polygon.size(); ++i)
	{
		Point s = polygon[i];
		Point e = polygon[(i + 1) % polygon.size()];
		Line seg(s, e, true);
		Point inter_p;
		if (isSegIntersect(p_line, seg, inter_p))
		{
			cnt++;
		}
	}

	return (cnt % 2 == 1);
}

// 4.6���ж��߶��Ƿ��ڶ�����ڲ�
// �߶��ڶ�����ڲ��������������˵㶼�ڶ�������Ҳ��������ཻ
// 
// ������ polygon : ����� l �� �߶�
bool isSegInPolygon(const vector<Point>& polygon, const Line& l)
{
	// �����ж��߶ζ˵��Ƿ��ڶ�����ڲ�
	bool is_s_in = isPointInPolygon(polygon, l.s);
	bool is_e_in = isPointInPolygon(polygon, l.e);

	// Ȼ���ж��߶��Ƿ��ཻ
	if (is_s_in && is_e_in)
	{
		for (int i = 0; i < polygon.size(); ++i)
		{
			Point s = polygon[i];
			Point e = polygon[(i + 1) % polygon.size()];
			Line seg(s, e, true);
			Point inter_p;
			if (isSegIntersect(l, seg, inter_p))
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

// 4.7���ж�Բ�Ƿ��ڶ�����ڲ�
// ֻ�ж�������еı߶���Բ���ⲿ��Բ�Ŵ��ڶ�����ڲ�
//
//	������ polygon : ����� c : Բ�� radius �� �뾶
//
bool isCircleInPolygon(const vector<Point>& polygon, const Point& c, double radius)
{
	for (int i = 0; i < polygon.size(); ++i)
	{
		const Point& p1 = polygon[i];
		const Point& p2 = polygon[(i + 1) % polygon.size()];
		Line line(p1, p2, true);
		if (segToCircle(c, radius, line) != 2)
			return false;
	}
	return true;
}

// 4.8��Ѱ�ҵ㼯͹���㷨��graham�㷨��
// �㷨���ӣ�https://blog.csdn.net/acm_zl/article/details/9342631
//
// ������ points �� ƽ��㼯
//Ŀǰʵ�ֵİ汾������
vector<Point> findConvexGraham(const vector<Point>& points)
{
	vector<Point> result;

	// ������������������
	if (points.size() < 3)
		return result;

	// Ѱ����ײ��ĵ�
	int index = 0;
	for (int i = 0; i < points.size(); ++i)
	{
		if (points[i].y < points[index].y)
		{
			index = i;
		}
	}
	Point convex_p = points[index];

	// ����ÿ����ļ���
	map<double, int> cos_map;
	Point x_vec(1.0, 0.0);
	for (int i = 0; i < points.size(); ++i)
	{
		if (i != index)
		{
			double cos_value = Cos(sub(points[i], convex_p), x_vec);
			// ����ж��������ͬ�ļ��ǣ���ȡ��Զ�ĵ�
			if (cos_map.count(-cos_value) != 0)
			{
				if (length(points[i]) > length(points[cos_map[-cos_value]]))
					cos_map[-cos_value] = i;
			}
			else
				cos_map[-cos_value] = i;
		}
	}

	// ��������ջ
	stack<int> result_stack;
	// ���뿪ʼ��������
	result_stack.push(index);
	result_stack.push(cos_map.begin()->second);

	for (auto iter = (++cos_map.begin()); iter != cos_map.end(); ++iter)
	{
		int first = result_stack.top();
		result_stack.pop();
		int second = result_stack.top();

		Point vec1 = sub(points[first], points[second]);
		Point vec2 = sub(points[iter->second], points[first]);
		if (multiply(vec1, vec2).z >= 0)
			result_stack.push(first);
		result_stack.push(iter->second);
	}

	// �����ݴ�ջ�ж�ȡ
	while (!result_stack.empty())
	{
		result.push_back(points[result_stack.top()]);
		result_stack.pop();
	}

	std::reverse(result.begin(), result.end());

	return result;
}

//// 4.9��Ѱ�ҵ㼯͹���㷨������͹������ʱ�临�Ӷ�O(nlogn)
////
////	������ points : ƽ��㼯
////
//// ������ֵ���ıȽϺ���
//bool cmp(Point a, Point b)
//{
//	if (a.x == b.x)
//		return a.y < b.y;
//	return a.x < b.x;
//}
//vector<Point> findConvex(const vector<Point>& points)
//{
//	vector<Point> result;
//	if (points.size() < 3)
//		return result;
//
//	vector<Point> tmp_points = points;
//	// ���Ƚ����е㰴���ֵ�������
//	sort(tmp_points.begin(), tmp_points.end(), cmp);
//
//	// ��͹��
//	vector<Point> upper_hull;
//	// �����һ���͵ڶ�����
//	upper_hull.push_back(tmp_points[0]);
//	upper_hull.push_back(tmp_points[1]);
//	for (int i = 2; i < tmp_points.size(); ++i)
//	{
//		upper_hull.push_back(tmp_points[i]);
//		while (upper_hull.size() > 2 && multiply(sub(upper_hull[upper_hull.size() - 2], upper_hull[upper_hull.size() - 3]), sub(upper_hull[upper_hull.size() - 1], upper_hull[upper_hull.size() - 3])).z >= 0)
//		{
//			upper_hull.erase(upper_hull.end() - 2);
//		}
//	}
//	// ��͹��
//	vector<Point> lower_hull;
//	// ���뵹����һ�ڶ�����
//	lower_hull.push_back(tmp_points[tmp_points.size() - 1]);
//	lower_hull.push_back(tmp_points[tmp_points.size() - 2]);
//	for (int i = tmp_points.size() - 3; i >= 0; --i)
//	{
//		lower_hull.push_back(tmp_points[i]);
//		while (lower_hull.size() > 2 && multiply(sub(lower_hull[lower_hull.size() - 2], lower_hull[lower_hull.size() - 3]), sub(lower_hull[lower_hull.size() - 1], lower_hull[lower_hull.size() - 3])).z >= 0)
//		{
//			lower_hull.erase(lower_hull.end() - 1);
//		}
//	}
//	// ɾ���ظ���
//	lower_hull.erase(lower_hull.begin());
//	lower_hull.erase(lower_hull.end() - 1);
//
//	// �ϲ�����͹��
//	upper_hull.insert(upper_hull.end(), lower_hull.begin(), lower_hull.end());
//
//	result = upper_hull;
//
//	return result;
//}

// 4.10����򵥶��������
// �㷨ԭ�����ӣ�
//
// ������ polygon �� �򵥶����
//
Point centerOfPolygon(const vector<Point>& polygon)
{
	double polygon_area(0.0);
	Point center;
	Point origin;

	for (int i = 0; i < polygon.size(); ++i)
	{
		Point curr_p = polygon[i];
		Point next_p = polygon[(i + 1) % polygon.size()];
		Triangle t(origin, curr_p, next_p);

		double curr_area = areaOfTriangle(t);
		polygon_area += curr_area;

		center = add(center, mul(div(add(curr_p, next_p), 3), curr_area));
	}

	center = div(center, polygon_area);

	return center;
}

// 4.11����϶��ڶ�����ڲ���һ����
// ����1: ÿ�������������һ��͹���㣬
//		  x���������С�ĵ�϶���͹���㣬y���������С�ĵ�϶���͹����
// ����2��������>= 4�ļ򵥶����������һ���Խ���
//
// ������ polygon �� �򵥶����
//
Point pointInPolygon(const vector<Point>& polygon)
{
	// ͹���������
	int index = 0;
	Point convex_p = polygon[0];
	// Ѱ��һ��͹����
	for (int i = 0; i < polygon.size(); ++i)
	{
		if (polygon[i].y < convex_p.y)
		{
			index = i;
			convex_p = polygon[i];
		}
	}
	// ��ȡ͹����ǰ��һ����
	int size = polygon.size();
	Point pre_p = polygon[(index - 1 + size) % size];
	Point next_p = polygon[(index + 1) % size];
	Triangle t(convex_p, pre_p, next_p);
	double min_d = double(INT_MAX);
	bool flag = false;
	Point min_p;
	for (int i = 0; i < polygon.size(); ++i)
	{
		if (i == index || i == ((index - 1 + size) % size) || i == ((index + 1) % size))
			continue;
		flag = true;
		if (distance(convex_p, polygon[i]) < min_d)
		{
			min_p = polygon[i];
			min_d = distance(convex_p, polygon[i]);
		}
	}
	// ���û�ж������������ڲ����򷵻�ǰ�����е�
	if (!flag)
	{
		return div(add(pre_p, next_p), 2);
	}
	// ����������͹������е�
	return div(add(convex_p, min_p), 2);
}

// 4.12����ȡ����εİ�Χ����
// ������ε���С��Χ�У������º������������ʾ
//
// ������ polygon : ����� down_left : ���µ�  up_right : ���ϵ�
//
void boxOfPolygon(const vector<Point>& polygon, Point& down_left, Point& up_right)
{
	double max_x = double(INT_MIN), min_x = double(INT_MAX);
	double max_y = double(INT_MIN), min_y = double(INT_MAX);

	for (auto c : polygon)
	{
		max_x = (c.x > max_x) ? c.x : max_x;
		min_x = (c.x < min_x) ? c.x : min_x;
		max_y = (c.y > max_y) ? c.y : max_y;
		min_y = (c.y < min_y) ? c.y : min_y;
	}

	down_left = Point(min_x, min_y);
	up_right = Point(max_x, max_y);
}


// �塢Բ
// 5.1�����Բ�Ĺ�ϵ
//
// ������ c: Բ�� radiuns �� Բ�İ뾶  p : �жϵĵ�
// ����ֵ �� 0 �� Բ�� 1 �� Բ�� 2�� Բ��
//
int pointToCircle(const Point& c, double radius, const Point& p)
{
	double ptoc_d = distance(c, p);

	if (ptoc_d < radius)
		return 0;
	else if (ptoc_d == radius)
		return 1;
	else
		return 2;
}

// 5.2��ֱ�ߺ�Բ�Ĺ�ϵ
//
// ������ c: Բ�� radiuns �� Բ�İ뾶  l : �жϵ�ֱ��
// ����ֵ �� 0 �� �ཻ 1 ������  2�� ����
//
int lineToCircle(const Point& c, double radius, const Line& l)
{
	double ctol_d = ptolDistance(c, l);

	if (ctol_d < radius)
		return 0;
	else if (ctol_d == radius)
		return 1;
	else
		return 2;
}

// 5.3���߶κ�Բ�Ĺ�ϵ
//
// ������ c: Բ�� radiuns �� Բ�İ뾶  l : �жϵ��߶�
// ����ֵ �� 0 �� Բ�� 1 �� ��Բ�ཻ  2�� Բ��
//
int segToCircle(const Point& c, double radius, const Line& l)
{
	double ctol_d = ptolDistance(c, l);

	if (ctol_d > radius)
		return 2;
	else if (ctol_d == radius)
		return 1;
	else
	{
		Point project_p = ptolProjection(c, l);
		if (isponl(project_p, l))
			return 1;
		else
			return 2;
	}
}

// 5.4����Բ֮��Ĺ�ϵ
// 
// ������ c1 : Բ1Բ�ģ�r1 Բ1�뾶 c2 : Բ2Բ�ģ�r2 Բ2�뾶
// ����ֵ��0 ���ں� 1������ 2���ཻ 3������ 4������
//
int circleToCircle(const Point& c1, double r1, const Point& c2, double r2)
{
	double ctoc_d = distance(c1, c2);

	if (ctoc_d < abs(r1 - r2))
		return 0;
	else if (ctoc_d == abs(r1 - r2))
		return 1;
	else if (ctoc_d > abs(r1 - r2) && ctoc_d < (r1 + r2))
		return 2;
	else if (ctoc_d == (r1 + r2))
		return 3;
	else if (ctoc_d >(r1 + r2))
		return 4;
}
