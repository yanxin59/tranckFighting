#include "EnemyVector.h"
#include "Enemy.h"
EnemyVector * EnemyVector::instence = nullptr;
EnemyVector * EnemyVector::getInstence(){
	if(!instence){
		instence = new EnemyVector();
	}
	return instence;
}
void EnemyVector::addEnemy(Enemy * bt){
	enemyVector.pushBack(bt);
}
void EnemyVector::deleEnemy(Enemy * bt){
	enemyVector.eraseObject(bt);
}
void EnemyVector::reset(){
	while(!enemyVector.empty()){
		Enemy * enemy = enemyVector.at(0);
		enemy->hurt(10000);
	}
}