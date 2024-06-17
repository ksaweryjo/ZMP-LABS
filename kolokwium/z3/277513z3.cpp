#include <iostream>
#include <cstdio>

class Vector3d {
private:
    int x, y, z;

public:
    Vector3d(int x, int y, int z) : x(x), y(y), z(z) {}

    void display() {
        printf("(%d, %d, %d)\n", x, y, z);
    }

    Vector3d add(const Vector3d& other) {
        return Vector3d(x + other.x, y + other.y, z + other.z);
    }

    Vector3d scalarMultiply(int scalar) {
        return Vector3d(x * scalar, y * scalar, z * scalar);
    }

    int dotProduct(const Vector3d& other) {
        return x * other.x + y * other.y + z * other.z;
    }
};

int main() {
    int v1x, v1y, v1z, v2x, v2y, v2z, scalar;
    scanf_s("%d %d %d %d %d %d %d", &v1x, &v1y, &v1z, &v2x, &v2y, &v2z, &scalar);

    Vector3d v1(v1x, v1y, v1z);
    Vector3d v2(v2x, v2y, v2z);

    Vector3d av = v1.add(v2);
    printf("Suma wektorow: ");
    av.display();

    Vector3d v1Scalar = v1.scalarMultiply(scalar);
    printf("Wektor v1 pomnozony przez skalar: ");
    v1Scalar.display();

    int dotProduct = v1.dotProduct(v2);
    printf("Iloczyn skalarny v1 i v2: %d\n", dotProduct);

    return 0;
}