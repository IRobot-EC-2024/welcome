#include<stdlib.h>
#include"sys.h"
sys::sys() {};
void sys::show_menu() {
	cout << endl;
	cout << "ս�ӳ�Ա����ϵͳ" << endl;
	cout << "1.�����Ա" << endl;
	cout << "2.ɾ����Ա" << endl;
	cout << "3.��ѯ��Ա" << endl;
	cout << "4.�г�������Ա" << endl;
	cout << "5.�޸���Ա��Ϣ" << endl;
	cout << "6.��Ա����" << endl;
	cout << "7.���ӿ�����Ϣ" << endl;
	cout << "8.��ѯ������Ϣ" << endl;
	cout << "9.ɾ��������Ϣ" << endl;
	cout << "10.�޸Ŀ�����Ϣ" << endl;
	cout << "11.�Կ�����Ϣ����" << endl;
	cout << "12.�˳�" << endl;
	cout << endl;
}
void sys::exit() {
	cout << endl;
	cout << "�´�һ��" << endl;
	cout << endl;
	system("pause");
	exit();
}
sys::~sys(){};