#include "Champion.h"

CHAMPION::CHAMPION()
{
	name = "";
	type = "";
	health = 0;
	attack = 0;
	defense = 0;
	attackSpeed = 0;
}
CHAMPION::CHAMPION(const CHAMPION &x)
{
	name = x.name;
	type = x.type;
	health = x.health;
	attack = x.attack;
	defense = x.defense;
	attackSpeed = x.attackSpeed;
}
CHAMPION::CHAMPION(string _name, string _type, float _health, float _attack, float _defense, float _attackSpeed)
{
	name = _name;
	type = _type;
	health = _health;
	attack = _attack;
	defense = _defense;
	attackSpeed = _attackSpeed;
}
void CHAMPION::setName(string _name)
{
	name = _name;
}
void CHAMPION::setType(string _type)
{
	type = _type;
}

void CHAMPION::setHealth(float _typealth)
{
	health = _typealth;
}
void CHAMPION::setAttack(float _attack)
{
	attack = _attack;
}
void CHAMPION::setDefense(float _defense)
{
	defense = _defense;
}
void CHAMPION::setAttackSpeed(float _attackSpeed)
{
	attackSpeed = _attackSpeed;
}
string CHAMPION::getName()
{
	return name;
}
string CHAMPION::getType()
{
	return type;
}
float CHAMPION::getHealth()
{
	return health;
}
float CHAMPION::getAttack()
{
	return attack;
}
float CHAMPION::getDefense()
{
	return defense;
}
float CHAMPION::getAttackSpeed()
{
	return attackSpeed;
}
string *CHAMPION::getGandRType()
{
	string h = getType();
	string *gr = new string[4];
	if (h == "Water") // dựa vào quy luật tương sinh tương khắc để cho ra kết quả
	{
		gr[0] = "Earth";
		gr[1] = "Metal";
		gr[2] = "Fire";
		gr[3] = "Wood";
	}
	else if (h == "Wood")
	{
		gr[2] = "Earth";
		gr[0] = "Metal";
		gr[3] = "Fire";
		gr[1] = "Water";
	}
	else if (h == "Fire")
	{
		gr[3] = "Earth";
		gr[2] = "Metal";
		gr[0] = "Water";
		gr[1] = "Wood";
	}
	else if (h == "Earth")
	{
		gr[2] = "Water";
		gr[3] = "Metal";
		gr[1] = "Fire";
		gr[0] = "Wood";
	}
	else if (h == "Metal")
	{
		gr[1] = "Earth";
		gr[3] = "Water";
		gr[0] = "Fire";
		gr[2] = "Wood";
	}
	else
	{
		return gr;
	}
	return gr;
}
float CHAMPION::timeToKill(CHAMPION enemy)
{
	float time = 0;
	float enemyHealth = enemy.health;
	if (attack < enemy.defense)
		return -1; // không đánh vào máu nổi
	while (enemyHealth > 0)
	{
		enemyHealth -= (attack - enemy.defense);
		time += attackSpeed;
	}
	return time;
}
bool CHAMPION::isDie()
{
	return health == 0;
}
void CHAMPION::print(ostream &outDev)
{
	outDev << getName() << ";" << getType() << ";" << getHealth() << ";" << getAttack() << ";" << getDefense() << ";" << getAttackSpeed();
}
istream &operator>>(istream &inDev, CHAMPION &x)
{
	string temp;
	getline(inDev, temp, ';');
	x.name = temp;
	getline(inDev, temp, ';');
	x.type = temp;
	getline(inDev, temp, ';');
	x.health = stof(temp);
	getline(inDev, temp, ';');
	x.attack = stof(temp);
	getline(inDev, temp, ';');
	x.defense = stof(temp);
	getline(inDev, temp, '\n');
	x.attackSpeed = stof(temp);
	return inDev;
}
ostream &operator<<(ostream &outDev, CHAMPION &x)
{
	outDev << "\n";
	x.print(outDev);
	return outDev;
}
void CHAMPION::inputInfo()
{
	cout << "INPUT NAME: ";
	getline(cin, name);
	cout << "INPUT ORIGIN: ";
	getline(cin, type);
	cout << "INPUT HEALTH: ";
	cin >> health;
	cout << "INPUT ATTACK DAMAGE: ";
	cin >> attack;
	cout << "INPUT ARMOR: ";
	cin >> defense;
	cout << "INPUT ATTACK SPEED: ";
	cin >> attackSpeed;
}