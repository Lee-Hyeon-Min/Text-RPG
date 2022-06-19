#pragma once
#include "Hero.h"
#include "Monster.h"

enum MENU {
	PLAY,
	EXIT
};

class GameWorld {
	int num;
	Hero Player;
	Lv1_Monster monster1;
	Lv5_Monster monster5;
	friend class Hero;//private�� �ִ� �Լ����� �����ϱ� ���� friend
	friend class Monster;//private�� �ִ� �Լ����� �����ϱ� ���� friend
	friend class Lv1_Monster;//private�� �ִ� �Լ����� �����ϱ� ���� friend
	friend class Lv5_Monster;//private�� �ִ� �Լ����� �����ϱ� ���� friend

	Monster* monsters[2] = { &monster1, &monster5 };// ���� Ŭ������ Monster�� �� �ڽ� Ŭ�������� �ߺ��Ǳ⶧���� ������ ����

	void Battle_Field1() {//LV1 ���Ϳ� �ο�
		system("cls");
		cout << "���Ϳ� �����ƽ��ϴ�!!" << endl;
		cout << "������ ����" << endl;
		cout << "HP = " << monster1.HP_Point1() << endl;
		cout << "���� = 1" << endl;
		cout << "���ݷ� = " << monster1.Attack_Point() << endl;
		cout << "1. ����" << endl;
		cout << "2. ��������" << endl;
		cin >> num;
		switch (num) {//1�̸� �ο�� 2�̸� ����ģ��.
		case 1:
			Fight1();
			if (monster1.Die()) {
				system("cls");
				cout << "���Ͱ� �׾����ϴ�!" << endl;
				cout << "���� ���������� �Ѿ�ϴ�." << endl;
				Battle_Field2();
			}
			if (Player.Die()) {
				system("cls");
				cout << "������ �׾����ϴ� �̤�" << endl;
				return;
			}
		case 2:
			return game_menu();
		default:
			break;
		}
	}

	void Battle_Field2() {//LV5 ���Ϳ� �ο�
		system("cls");
		cout << "���Ϳ� �����ƽ��ϴ�!!" << endl;
		cout << "������ ����" << endl;
		cout << "HP = " << monster5.HP_Point1() << endl;
		cout << "���� = 5" << endl;
		cout << "���ݷ� = " << monster5.Attack_Point() << endl;
		cout << "1. ����" << endl;
		cout << "2. ��������" << endl;
		cin >> num;
		switch (num) {//1�̸� �ο�� 2�̸� ����ģ��.
		case 1:
			Fight2();
			if (monster5.Die()) {
				cout << "���Ͱ� �׾����ϴ�!" << endl;
				return;
			}
			if (Player.Die()) {
				system("cls");
				cout << "������ �׾����ϴ� �̤�" << endl;
				return;
			}
		case 2:
			return game_menu();
		default:
			break;
		}
	}

	void Fight1() {//������ LV1 ���Ͱ� ���ݷ¿� ���� ���ظ� ����
		int damage_to_Hero = monster1.Attack_Point();
		int damage_to_Monster1 = Player.Attack_Point();
		Player.Ondamage(damage_to_Hero);
		monster1.Ondamaged(damage_to_Monster1);
	}
	void Fight2() {//������ LV5 ���Ͱ� ���ݷ¿� ���� ���ظ� ����
		int damage_to_Hero = monster5.Attack_Point();
		int damage_to_Monster1 = Player.Attack_Point();
		Player.Ondamage(damage_to_Hero);
		monster5.Ondamaged(damage_to_Monster1);
	}
public:

	void game_menu() {//������ ������ Ȯ�� �� �� �ִ�
		system("cls");
		cout << "������ ����" << endl;
		cout << "HP = " << Player.HP_Point() << endl;
		cout << "���ݷ� = " << Player.Attack_Point() << endl;
		cout << "\t" << endl;
		cout << "��� ���� �Ͻ÷��� �����̽��ٸ� �����ʽÿ�" << endl;
		if (_getch() == ' ') {
			Battle_Field1();
		}
	}
	void Main_Menu() {//���θ޴��̸� 1�� ������ ���� ����, 2�� ������ ����
		while (true) {
			system("cls");
			cout << "======================================" << endl;
			cout << "              " << "Text RPG" << endl;
			cout << "======================================" << endl;
			cout << "              ������ : ������" << endl;
			cout << "1. Play" << endl;
			cout << "2. Exit" << endl;
			cin >> num;
			switch (num) {//1�̸� ���Ӹ޴��� ���� 2�̸� ���Ḧ �Ѵ�
			case 1:
				game_menu();
			case 2:
				return;
			}
		}
	}
};