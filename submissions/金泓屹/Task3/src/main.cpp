#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include"sys.h"
#include"team.h"
#include "AttendanceRecord.h"
using namespace std;
int main() {
	std::vector<AttendanceRecord> attendanceRecords;
	sys syst;
	Team team;
	int choice = 0;
	int subchoice = 0;
	int subsubchoice = 0;
	string name;
	int id;
	int year;
	int month;
	size_t num;
	int h;
	int m;
	int index;
	while (true) {
		syst.show_menu();
		//ѡ��
		while (!(std::cin >> choice)) { // ѭ��ֱ������ɹ�
			std::cin.clear(); // ���ʧ��״̬
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
			std::cout << "������Ч������������: ";
		}
		

		switch (choice) {
			//�����Ա
		case 1: {

			cout << endl;
			cout << "�������Ա������" << endl;
			cin >> name;
			cout << "�������Աѧ��" << endl;
			while (!(std::cin >> id)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			std::cout << "�����ѧ����: " << id << std::endl;
			cout << "�������Ա������" << endl;
			while (!(std::cin >> year)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			std::cout << "�������������: " << year << std::endl;
			cout << "����������·ݣ�" << endl;
			while (!(std::cin >> month)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			std::cout << "���������·���: " << month << std::endl;
			team.addMember(name, id, year,month);
			cout << endl;
			cout << "��ӳɹ�����Ӻ������Ϊ��" << endl;
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //ɾ����Ա
		case 2:{
			cout << endl;
			team.printMembers();
			cout << endl;
			cout << "��������Ҫɾ�����ǵڼ�����Ա��" << endl;
			while (!(std::cin >> num)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			num = num - 1;
			team.removeMember(num);
			cout << endl;
			cout << "ɾ���ɹ���ɾ���������Ϊ��" << endl;
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //��ѯ��Ա
		case 3: {
			cout << endl;
			cout << "�������Ա������" << endl;
			cin >> name;
			
			team.printspecificMember(team.findMember(name));
			cout << endl;
			break;
		}
			  //�г�������Ա
		case 4: {
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //�޸���Ա��Ϣ
		case 5: {
			cout << endl;
			team.printMembers();
			cout << endl;
			cout << "��������Ҫ���ĵ��ǵڼ�����Ա��" << endl;
			cout << endl;
			while (!(std::cin >> num)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			num = num - 1;
			cout << endl;
			cout << "�������Ա�������֣�" << endl;
			cout << endl;
			while (!(std::cin >> name)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			cout << endl;
			cout << "�������Ա����ѧ�ţ�" << endl;
			cout << endl;
			while (!(std::cin >> id)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			cout << endl;
			cout << "�������Ա���������ݣ�" << endl;
			cout << endl;
			while (!(std::cin >> year)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			cout << "�������Ա��������·�" << endl;
			cout << endl;
			while (!(std::cin >> month)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			team.updateMember(num, name, id, year,month);
			cout << "�޸ĳɹ����޸ĺ������Ϊ��" << endl;
			cout << endl;
			team.printMembers();
			cout << endl;
			break;
		}
			  //��Ա����
		case 6: {
			cout << "��ѡ���������ͣ�" << endl;
			cout << "1.��ѧ������" << endl;
			cout << "2.�����ʱ������" << endl;
			while (!(std::cin >> subchoice)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			cout << "��ѡ��������" << endl;
			cout << "1.�ɸߵ���" << endl;
			cout << "2.�ɵ͵���" << endl;
			while (!(std::cin >> subsubchoice)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			switch (subchoice) {
			case 1: {
				switch (subsubchoice) {
				case 1:team.sortByStudentIDjian();
				case 2:team.sortByStudentIDzeng();
				}
			case 2: {
				switch (subsubchoice) {
				case 1:team.sortByStudentEntryjian();
				case 2:team.sortByStudentEntryzeng();
				}
			}
			}
			}
		}

			  //���ӿ�����Ϣ
		case 7: {
			cout << "�������Ա����������ʱ�䣺HH���ûس��ָ���MM" << endl;
			cin >> name;
			while (!(std::cin >> h)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			while (!(std::cin >> m)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			if (h > 24 || h < 0 || m>60 || m < 0) {
				cout << "ʱ������������" << endl;
				break;
			}
			addRecord(attendanceRecords, name, h, m);
			break;
		}
			  //��ѯ������Ϣ
		case 8: {
			cout << "1.�鿴���п��ڼ�¼" << endl;
			cout << "2.��ѯĳ�˿��ڼ�¼" << endl;
			while (!(std::cin >> subchoice)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			switch (subchoice) {
			case 1://�鿴ȫ����
				cout << endl;
				for (const auto& record : attendanceRecords) {
					printRecord(record);
				}
				cout << endl; break;
			case 2: //�鿴ĳ���˵�
				cout << "" << endl;
				cin >> name;
				cout << endl;
				printRecords(attendanceRecords, name);
				cout << endl;
				break;
			}
			break;
		}
			  //ɾ��������Ϣ
		case 9: {
			cout << "" << endl;
			while (!(std::cin >> subsubchoice)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			switch (subsubchoice) {
			case 1://ɾ������
				clearAllRecords(attendanceRecords);
			case 2://ɾ��ĳ��
				cout << "��������Ҫɾ���Ŀ��ڼ�¼������Ա������(���Ϊ�����޴��˼�¼��" << endl;
				cin >> name;
				cout << endl;
				printRecords(attendanceRecords, name);
				cout << endl;
				cout << "1.ɾ������ĳһ����¼" << endl;
				cout << "2.ɾ���������м�¼" << endl;
				while (!(std::cin >> subchoice)) { // ѭ��ֱ������ɹ�
					std::cin.clear(); // ���ʧ��״̬
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
					std::cout << "������Ч������������: ";
				}
				switch (subchoice) {
				case 1://ɾ��ĳһ��
					cout << "��������Ҫɾ���ڼ�����¼��" << endl;
					while (!(std::cin >> index)) { // ѭ��ֱ������ɹ�
						std::cin.clear(); // ���ʧ��״̬
						std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
						std::cout << "������Ч������������: ";
					}
					index = index - 1;
					removeSpecificRecord(attendanceRecords, name, index);
					cout << endl;
					cout << "ɾ���ɹ���ɾ������˵Ŀ��ڼ�¼Ϊ��" << endl;
					printRecords(attendanceRecords, name);
					cout << endl;
					break;
				case 2://ɾ������
					removeRecord(attendanceRecords, name);
				}
			}
			break;
		}
			  //�޸Ŀ�����Ϣ
		case 10: {
			cout << "��������Ҫ�޸ĵĿ��ڼ�¼������Ա������" << endl;
			cin >> name;
			printRecords(attendanceRecords, name);
			cout << "��������Ҫ�޸ĵڼ�����¼��" << endl;
			while (!(std::cin >> index)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			index = index - 1;
			cout << "�������޸ĵĹ���ʱ�䣺HH���ûس��ָ���MM" << endl;
			while (!(std::cin >> h)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			while (!(std::cin >> m)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			modifyRecord(attendanceRecords, name, index, h, m);
			break;
		}
			  //�Կ�����Ϣ����
		case 11: {
			cout << "��ѡ���������ͣ�" << endl;
			cout << "1.�����ڴ�������" << endl;
			cout << "2.��������ʱ������" << endl;
			while (!(std::cin >> subchoice)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			cout << "��ѡ��������" << endl;
			cout << "1.�ɸߵ���" << endl;
			cout << "2.�ɵ͵���" << endl;
			while (!(std::cin >> subsubchoice)) { // ѭ��ֱ������ɹ�
				std::cin.clear(); // ���ʧ��״̬
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ���Դ�������ֱ����һ�����з�
				std::cout << "������Ч������������: ";
			}
			switch (subchoice) {
			case 1: {
				switch (subsubchoice) {
				case 1:sortRecordsByCountjian(attendanceRecords);
				case 2:sortRecordsByCountzeng(attendanceRecords);
				}
			}
			case 2: {
				switch (subsubchoice) {
				case 1:sortRecordsByTotalMinutesjian(attendanceRecords);
				case 2:sortRecordsByTotalMinuteszeng(attendanceRecords);
				}
				break;
			}

			}
		}
				  //�˳�
		case 12: {
				syst.exit();
				break;
			}
			}
			}
		}

		