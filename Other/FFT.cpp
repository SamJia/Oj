#include <iostream>
#include <cmath>
using namespace std;
#define DOUBLE_PI 6.283185307179586476925286766559


class complex{
public:
	complex(double real = 1, double image = 0) : real_(real), image_(image){}
	complex operator+(const complex &num2){
		complex result(real_ + num2.real_, image_ + num2.image_);
		return result;
	}
	complex operator-(const complex &num2){
		complex result(real_ - num2.real_, image_ - num2.image_);
		return result;
	}
	complex operator*(const complex &num2){
		complex result(real_ * num2.real_ - image_ * num2.image_, real_ * num2.image_ + image_ * num2.real_);
		return result;
	}
	void operator/=(int num2){
		real_ /= num2;
		image_ /= num2;
	}
	friend istream &operator>>(istream &is, complex &num){
		is >> num.real_ >> num.image_;
		return is;
	}
	friend ostream &operator<<(ostream &os, complex &num){
		os << num.real_ << ' ' << num.image_;
		return os;
	}
	double real_, image_;
};

complex* FFT(complex *source, int depth, bool inverse = false){
	complex **result = new complex*[2];
	int total_number = 1<<depth;
	result[0] = new complex[total_number];
	result[1] = new complex[total_number];
	int sign = inverse ? 1 : -1;
	double Pi = 3.1415926, power_number;
	complex wnk, wn0, wn_init, even, odd;
	for(int i = 0; i < total_number; ++i)
		result[depth&1][i] = source[i];
	for(int tmp_number = total_number, tmp_depth = depth; tmp_number; tmp_number = tmp_number>>1, --tmp_depth){
		power_number = sign * 2 * Pi / (depth - tmp_depth);
		wnk = wn_init;
		wn0.real_ = cos(power_number);
		wn0.image_ = sin(power_number);
		for(int k = 0, half_N = 1<<(depth - tmp_depth - 1), start = 0; k < half_N; ++k, wnk = wnk * wn0, start += tmp_number){
			for(int i = start; i < start + tmp_number; ++i){
				even = result[(tmp_depth + 1)&1][2 * k * tmp_number];
				odd = result[(tmp_depth + 1)&1][(2 * k + 1) * tmp_number] * wnk;
				result[tmp_depth&1][i] = even + odd;
				result[tmp_depth&1][i + half_N] = even - odd;
			}
		}
	}
	return result[0];
}

void FFT3(double * data, int n, bool isInverse = false)
{
	int mmax, m, j, step, i;
	double temp;
	double theta, sin_htheta, sin_theta, pwr, wr, wi, tempr, tempi;
	n = 2 * (1 << n);
	int nn = n >> 1;
	j = 1;
	for(i = 1; i < n; i += 2)
	{
		if(j > i)
		{
			temp = data[j - 1];
			data[j - 1] = data[i - 1];
			data[i - 1] = temp;
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
		m = nn;
		while(m >= 2 && j > m)
		{
			j -= m;
			m >>= 1;
		}
		j += m;
	}
	mmax = 2;
	while(n > mmax)
	{
		step = mmax << 1;
		theta = DOUBLE_PI / mmax;
		if(isInverse)
		{
			theta = -theta;
		}
		sin_htheta = sin(0.5 * theta);
		sin_theta = sin(theta);
		pwr = -2.0 * sin_htheta * sin_htheta;
		wr = 1.0;
		wi = 0.0;
		for(m = 1; m < mmax; m += 2)
		{
			for(i = m; i <= n; i += step)
			{
				j = i + mmax;
				tempr = wr * data[j - 1] - wi * data[j];
				tempi = wr * data[j] + wi * data[j - 1];
				data[j - 1] = data[i - 1] - tempr;
				data[j] = data[i] - tempi;
				data[i - 1] += tempr;
				data[i] += tempi;
			}
			sin_htheta = wr;
			wr = sin_htheta * pwr - wi * sin_theta + wr;
			wi = wi * pwr + sin_htheta * sin_theta + wi;
		}
		mmax = step;
	}
	if(isInverse)
		for(int i = 0; i < n; ++i)
			data[i] /= (n>>1);
}


complex *FFT2(complex *Data,int Log2N,int flag = -1)
{

 int i,j,k,m,step,length;
 int index0,index1;
 complex wn,temp;
 length=1<<Log2N;
 for(i = 1, j = 1; i < length; i++)
	{
		if(j > i)
		{
			temp = Data[j];
			Data[j] = Data[i];
			Data[i] = temp;
		}
		m = length>>1;
		while(m >= 2 && j > m)
		{
			j -= m;
			m >>= 1;
		}
		j += m;
	}
 for(i=1;i<=Log2N;i++)
 {
  step=1<<(Log2N-i+1);

  for(j=0;j<step/2;j++)
  {
   wn=complex(cos(DOUBLE_PI/step*j),sin(DOUBLE_PI/step*j*flag));

   for(k=0;k<length/step;k++)
   {
    index0=k*step+j;
    index1=k*step+step/2+j;
    temp=Data[index0];
    Data[index0]=temp+Data[index1];
    Data[index1]=(temp-Data[index1])*wn;
   }
  }
 }
 if(flag==1)
  for(i=0;i<length;i++)
   Data[i]/=length;
 return Data;
}

main(){
	//complex source[8], *result;
	double a[16] = {}, b[16] = {}, c[16] = {}, *d;
	// for(int i = 7; i >= 0; --i)
	// 	cin >> a[2 * i] >> a[2 * i + 1];
	for(int i = 0; i < 16; ++i)
		cin >> b[i];
	// for(int i = 0; i < 16; ++i)
	// 	cin >> a[i];
	// for(int i = 0; i < 8; ++i)
	// 	cin >> a[i];
	FFT3(b, 3);
	// for(int i = 0; i < 16; i += 2)
	// 	cout << b[i] << ' ' << b[i + 1] << '\n';
	// FFT3(b, 3, 1);
	for(int i = 0; i < 16; i += 2)
		cout << b[i] << ' ' << b[i + 1] << '\n';
	// FFT3(a, 3);
	// // for(int i = 0; i < 16; i += 2)
	// // 	cout << a[i] << ' ' << a[i + 1] << '\n';
	// for(int i = 0; i < 16; i +=2){
	// 	c[i] = a[i] * b[i] - a[i + 1] * b[i + 1];
	// 	c[i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
	// 	// c[i + 1] = -c[i + 1];
	// }
	// // for(int i = 0; i < 16; i += 2)
	// // 	cout << c[i] << ' ' << c[i + 1] << '\n';
	// FFT3(c, 3, 1);
	// // for(int i = 0; i < 16; i += 2)
	// // 	cout << a[i] << ' ' << a[i + 1] << '\n';
	// for(int i = 0; i < 16; i += 2)
	// 	cout << c[i] << ' ' << c[i + 1] << '\n';
	// FFT(b, 3);
	// for(int i = 0; i < 8; ++i){
	// 	c[i<<1] = a[i<<1] * b[i<<1] - a[1 + (i<<1)] * b[1 + (i<<1)];
	// 	c[1 + (i<<1)] = -(a[i<<1] * b[1 + (i<<1)] + a[1 + (i<<1)] * b[i<<1]);
	// }
	// for(int i = 0; i < 8; ++i)
	// 	cout << c[i<<1] << ' ' << c[2 * i + 1] << '\n';
	// FFT(c, 3, true);
	// for(int i = 0; i < 8; ++i)
	// 	cout << c[i<<1] << ' ' << c[2 * i + 1] << '\n';
}
