#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <memory.h>
#include <assert.h>


void* my_memcpy(void* dest, const void* src, size_t sz)
{
	assert(dest && src);

	void* ret = dest;
	while (sz--)
	{
		*(char*)dest = *(char*)src;
		dest =(char*)dest + 1;
		src = (char*)src + 1;
	}
	return ret;
}

void test1()
{
	int arr1[] = { 1,2,3,4,5,6,7,8,9 };
	int arr2[20] = { 0 };
	//memcpy(arr2, arr1, sizeof(arr1));
	//my_memcpy(arr2, arr1, sizeof(arr1));
	//my_memcpy(arr1+2, arr1, 20);
	memcpy(arr1 + 2, arr1, 20);
}

void* my_memmove(void* dest, void* src, size_t size)
{
	assert(dest && src);

	void* ret = dest;
	if (dest < src)
	{
		while (size--)
		{
			*(char*)dest = *(char*)src;
			dest = (char*)dest + 1;
			src = (char*)src + 1;
		}
	}
	else
	{
		while (size--)
		{
			*((char*)dest+size) = *((char*)src+size);
		}
	}

	return ret;

}

void test2()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	my_memmove(arr + 2, arr, 20);
}


void test3()
{
	char arr[] = "wojiao fuqingyun";
	int arr1[10] = { 0 };
	memset(arr+6, 'x', 9);
	memset(arr1, 1, 40);//�޸ĵ���ÿ���ֽ�
}

int test4(int m)
{
	if (m < 3)
	{
		return 2;
	}
	int n = 1;
	m = m / 6;
	while (m--)
	{
		n *= 2;
		n += n;
	}
	return n;
}

int main()
{
	//test1();
	//test2();
	//test3();
	int m = 0;
	scanf("%d", &m);
	printf("%d\n", test4(m));
	return 0;
}