#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

class cmplx
{

public:

	cmplx(float = 0, float = 0);
	cmplx cmplxAdd(cmplx&);
	cmplx cmplxSub(cmplx&);
	cmplx cmplxMul(cmplx&);
	void cmplxPrint();
	void cmplxCube();

private:

	float realnb;
	float imgnb;

};

cmplx::cmplx(float r, float i)
{

	realnb = r;
	imgnb = i;

}

cmplx cmplx::cmplxAdd(cmplx& x)
{

	return cmplx(realnb + x.realnb, imgnb + x.imgnb);

}

cmplx cmplx::cmplxSub(cmplx& x)
{

	return cmplx(realnb - x.realnb, imgnb - x.imgnb);

}

cmplx cmplx::cmplxMul(cmplx& x)
{

	return cmplx((realnb * x.realnb - imgnb * x.imgnb), (realnb * x.imgnb + imgnb * x.realnb));

}

void cmplx::cmplxPrint()
{

	if (imgnb >= 0)
	{

		std::cout << realnb << "+" << imgnb << "i\n";

	}
	else
	{

		std::cout << realnb << imgnb << "i\n";

	}

}

void cmplx::cmplxCube()
{

	cmplx temp = cmplx(realnb, imgnb);

	temp = cmplxMul(temp);
	temp = cmplxMul(temp);

	realnb = temp.realnb;
	imgnb = temp.imgnb;

}

int main()
{

	cmplx x(2.16, 1.03);
	cmplx y(0.38, 4.61);

	std::cout << "Two complex numbers have been established, the following numbers are: \n";
	x.cmplxPrint();
	y.cmplxPrint();

	cmplx z = x.cmplxAdd(y);
	std::cout << "\nThe sum of both complex numbers: \n";
	z.cmplxPrint();

	std::cout << "\nThe difference between both complex numbers: \n";
	z = x.cmplxSub(y);
	x.cmplxPrint();

	std::cout << "\nThe product of both complex numbers: \n";
	z = x.cmplxMul(y);
	z.cmplxPrint();

	std::cout << "\nThe cube of both complex numbers: \n";
	x.cmplxCube();
	y.cmplxCube();
	x.cmplxPrint();
	y.cmplxPrint();

	return 0;

}
