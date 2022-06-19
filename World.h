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
	friend class Hero;//private에 있는 함수들을 참조하기 위한 friend
	friend class Monster;//private에 있는 함수들을 참조하기 위한 friend
	friend class Lv1_Monster;//private에 있는 함수들을 참조하기 위한 friend
	friend class Lv5_Monster;//private에 있는 함수들을 참조하기 위한 friend

	Monster* monsters[2] = { &monster1, &monster5 };// 마더 클래스가 Monster인 두 자식 클래스들이 중복되기때문에 다형성 적용

	void Battle_Field1() {//LV1 몬스터와 싸움
		system("cls");
		cout << "몬스터와 마주쳤습니다!!" << endl;
		cout << "몬스터의 정보" << endl;
		cout << "HP = " << monster1.HP_Point1() << endl;
		cout << "레벨 = 1" << endl;
		cout << "공격력 = " << monster1.Attack_Point() << endl;
		cout << "1. 공격" << endl;
		cout << "2. 도망가기" << endl;
		cin >> num;
		switch (num) {//1이면 싸우고 2이면 도망친다.
		case 1:
			Fight1();
			if (monster1.Die()) {
				system("cls");
				cout << "몬스터가 죽었습니다!" << endl;
				cout << "다음 스테이지로 넘어갑니다." << endl;
				Battle_Field2();
			}
			if (Player.Die()) {
				system("cls");
				cout << "영웅은 죽었습니다 ㅜㅜ" << endl;
				return;
			}
		case 2:
			return game_menu();
		default:
			break;
		}
	}

	void Battle_Field2() {//LV5 몬스터와 싸움
		system("cls");
		cout << "몬스터와 마주쳤습니다!!" << endl;
		cout << "몬스터의 정보" << endl;
		cout << "HP = " << monster5.HP_Point1() << endl;
		cout << "레벨 = 5" << endl;
		cout << "공격력 = " << monster5.Attack_Point() << endl;
		cout << "1. 공격" << endl;
		cout << "2. 도망가기" << endl;
		cin >> num;
		switch (num) {//1이면 싸우고 2이면 도망친다.
		case 1:
			Fight2();
			if (monster5.Die()) {
				cout << "몬스터가 죽었습니다!" << endl;
				return;
			}
			if (Player.Die()) {
				system("cls");
				cout << "영웅은 죽었습니다 ㅜㅜ" << endl;
				return;
			}
		case 2:
			return game_menu();
		default:
			break;
		}
	}

	void Fight1() {//영웅과 LV1 몬스터가 공격력에 따른 피해를 입음
		int damage_to_Hero = monster1.Attack_Point();
		int damage_to_Monster1 = Player.Attack_Point();
		Player.Ondamage(damage_to_Hero);
		monster1.Ondamaged(damage_to_Monster1);
	}
	void Fight2() {//영웅과 LV5 몬스터가 공격력에 따른 피해를 입음
		int damage_to_Hero = monster5.Attack_Point();
		int damage_to_Monster1 = Player.Attack_Point();
		Player.Ondamage(damage_to_Hero);
		monster5.Ondamaged(damage_to_Monster1);
	}
public:

	void game_menu() {//영웅의 정보를 확인 할 수 있다
		system("cls");
		cout << "영웅의 정보" << endl;
		cout << "HP = " << Player.HP_Point() << endl;
		cout << "공격력 = " << Player.Attack_Point() << endl;
		cout << "\t" << endl;
		cout << "계속 진행 하시려면 스페이스바를 누르십시오" << endl;
		if (_getch() == ' ') {
			Battle_Field1();
		}
	}
	void Main_Menu() {//메인메뉴이며 1을 누르면 게임 시작, 2를 누르면 종료
		while (true) {
			system("cls");
			cout << "======================================" << endl;
			cout << "              " << "Text RPG" << endl;
			cout << "======================================" << endl;
			cout << "              제작자 : 이현민" << endl;
			cout << "1. Play" << endl;
			cout << "2. Exit" << endl;
			cin >> num;
			switch (num) {//1이면 게임메뉴로 들어가고 2이면 종료를 한다
			case 1:
				game_menu();
			case 2:
				return;
			}
		}
	}
};