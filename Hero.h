#pragma once
#include "Head.h"
#include "Monster.h"
#include "World.h"

using namespace std;
Monster monster;
Lv1_Monster monster1;

class Hero {//Hero란 클래스를 추상화 시킴
private:// 코드의 보안을 위해 private 기능을 사용하여 캡슐화
	string name;
	int HP, Attack;
	int Die() {//HP가 0 이하로 떨어지면 사망
		return HP <= 0;
	}
	
	void Ondamage(int damage) {//damage에 따라 HP가 감소한다
		HP -= damage;
		if (HP < 0)
			HP = 0;
	}
	friend class GameWorld;
public:
	Hero(string n = "영웅", int MaxHP = 1000, int Attack_Point = 50, int Armor_Point = 20) :name(n), HP(MaxHP), Attack(Attack_Point) {}
	~Hero() {}

	int HP_Point() { return HP; }//HP 값 반환
	int Attack_Point() { return Attack; }// 공격력 값 반환
};