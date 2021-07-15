#ifndef VEC3_H
#define VEC3_H

#include <iostream>
#include <cmath>

using std::sqrt;

class vec3 {
private:
	//Vector Values
	float e[3];

public:
	//Constructor
	vec3() : e{0, 0, 0} {}
	vec3(float e0, float e1, float e2) : e{e0, e1, e2} {}

	//Getters
	float x() const { return e[0]; }
	float y() const { return e[1]; }
	float z() const { return e[2]; }

	//Operator Overloading

		//Negative
	vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
		//Constant Value Accessing
	float operator[](int i) const { return e[i]; }
		//Variable Value Accessing
	float& operator[](int i) { return e[i]; }

	vec3& operator+=(const vec3& v) {
		e[0] += v[0];
		e[1] += v[1];
		e[2] += v[2];
		return *this;
	}

	vec3& operator*=(const float t) {
		e[0] *= t;
		e[1] *= t;
		e[2] *= t;
		return *this;
	}

	vec3& operator/=(const float t) {
		return *this *= 1/t;
	}

	float length() const {
		return sqrt(length_squared());
	}

	float length_squared() const {
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}
};

//Utility Functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v[0] << ' ' << v[1] << ' ' << v	[2];
}

inline vec3 operator+(const vec3& v, const vec3& u) {
	return vec3(v[0] + u[0], v[1] + u[1], v[2] + u[2]);
}

inline vec3 operator-(const vec3& v, const vec3& u) {
	return vec3(v[0] - u[0], v[1] - u[1], v[2] - u[2]);
}

		//Hadamard Product
inline vec3 operator*(const vec3& v, const vec3& u) {
	return vec3(v[0]*u[0], v[1]*u[1], v[2]*u[2]);
}

inline vec3 operator*(const vec3& v, const float t) {
	return vec3(v[0]*t, v[1]*t, v[2]*t);
}

inline vec3 operator*(const float t, const vec3& v) {
	return v * t;
}

inline vec3 operator/(const vec3& v, const float t) {
	return v * (1/t);
}

inline float dot(const vec3& v, const vec3& u) {
	return v[0]*u[0] + v[1]*u[1] + v[2]*u[2];
}

inline vec3 cross(const vec3& v, const vec3& u) {
	return vec3(v[1]*u[2] - v[2]*u[1], 
				v[2]*u[0] - v[0]*u[2],
				v[0]*u[1] - v[1]*u[0]);
}

inline vec3 unit_vector(vec3 v) {
	return v / v.length();
}

//Type Aliases
using point3 = vec3; //3D point
using color = vec3; //RGB color

#endif