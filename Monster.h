#pragma once
#include "Head.h"

using namespace std;

class Monster {//Monster란 클래스를 추상화시킴
	string name;
	int HP, Attack;
	void Ondamaged(int damage) {//damage에 따라 HP가 감소한다
		HP -= damage;
		if (HP < 0)
			HP = 0;
	}
	friend class GameWorld;
public:
	Monster(string n = "괴물", int MaxHP = 100, int Attack = 10) : name(n), HP(MaxHP), Attack(Attack) {}
	~Monster() {}
	int HP_Point1() { return HP; }
	int Die() {//HP가 0 이하로 떨어지면 사망
		return HP <= 0;
	}
	int Attack_Point() { return Attack; }
};

class Lv1_Monster : public Monster {//Monster 클래스 상속받은 LV1 몬스터

	friend class GameWorld;
public:
	Lv1_Monster(string n = "1랩괴물", int MaxHP = 100, int Attack = 50) : Monster(n,MaxHP,Attack) {}
	~Lv1_Monster() {}
};

class Lv5_Monster : public Monster {//Monster 클래스 상속받은 LV5 몬스터

	friend class GameWorld;
public:
	Lv5_Monster(string n = "5랩괴물", int MaxHP = 300, int Attack = 50) : Monster(n, MaxHP, Attack) {}
	~Lv5_Monster() {}
};