#include<stdio.h>

int main()
{
	int arr[6] = {15,48,84,37,78,45};
	int temp;
	//����ʱ����м���� 
	int flag = 0;
	//flag ��¼�Ƿ������� 
	int length = sizeof(arr) / sizeof(arr[0]);
	//sizeof �������������ռ���ֽڳ��� �������鳤��Ϊ������ ȡ��һ��Ԫ�ػ�ȡ������Ϊ���� 
	
	for(int i = 0; i < length; i++)
	{
		flag = 0;
		//ÿ�δ�ѭ����ʼ״̬ 
		for(int j = i; j < length - i; j++)//ð������ 
		{
			if(arr[j] > arr[j+1])
			{
				flag = 1; //�������� 
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				//���� 
			}
		}
		if(!flag)
		{
			break;
		}
		//�Ż�����һ��ѭ��δ����������ʱ���˳������������Ѿ����� 
	}
	
	for(int i = 0; i < length; i++)//��˳����� 
	{
		printf("%d ", arr[i]);
	}
	
	return 0;
}
