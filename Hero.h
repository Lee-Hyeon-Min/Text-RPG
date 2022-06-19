#pragma once
#include "Head.h"
#include "Monster.h"
#include "World.h"

using namespace std;
Monster monster;
Lv1_Monster monster1;

class Hero {//Hero�� Ŭ������ �߻�ȭ ��Ŵ
private:// �ڵ��� ������ ���� private ����� ����Ͽ� ĸ��ȭ
	string name;
	int HP, Attack;
	int Die() {//HP�� 0 ���Ϸ� �������� ���
		return HP <= 0;
	}
	
	void Ondamage(int damage) {//damage�� ���� HP�� �����Ѵ�
		HP -= damage;
		if (HP < 0)
			HP = 0;
	}
	friend class GameWorld;
public:
	Hero(string n = "����", int MaxHP = 1000, int Attack_Point = 50, int Armor_Point = 20) :name(n), HP(MaxHP), Attack(Attack_Point) {}
	~Hero() {}

	int HP_Point() { return HP; }//HP �� ��ȯ
	int Attack_Point() { return Attack; }// ���ݷ� �� ��ȯ
};