#pragma once
#include "Head.h"

using namespace std;

class Monster {//Monster�� Ŭ������ �߻�ȭ��Ŵ
	string name;
	int HP, Attack;
	void Ondamaged(int damage) {//damage�� ���� HP�� �����Ѵ�
		HP -= damage;
		if (HP < 0)
			HP = 0;
	}
	friend class GameWorld;
public:
	Monster(string n = "����", int MaxHP = 100, int Attack = 10) : name(n), HP(MaxHP), Attack(Attack) {}
	~Monster() {}
	int HP_Point1() { return HP; }
	int Die() {//HP�� 0 ���Ϸ� �������� ���
		return HP <= 0;
	}
	int Attack_Point() { return Attack; }
};

class Lv1_Monster : public Monster {//Monster Ŭ���� ��ӹ��� LV1 ����

	friend class GameWorld;
public:
	Lv1_Monster(string n = "1������", int MaxHP = 100, int Attack = 50) : Monster(n,MaxHP,Attack) {}
	~Lv1_Monster() {}
};

class Lv5_Monster : public Monster {//Monster Ŭ���� ��ӹ��� LV5 ����

	friend class GameWorld;
public:
	Lv5_Monster(string n = "5������", int MaxHP = 300, int Attack = 50) : Monster(n, MaxHP, Attack) {}
	~Lv5_Monster() {}
};