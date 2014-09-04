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
	for(int i = 0;i < 4;i++){
		Enemy * enemy = enemyVector.at(i);
		enemy->hurt(1000);
	}
}
void EnemyVector::clearEnemy(){
	enemyVector.clear();
}
void EnemyVector::delayTime(){
	for(int i = 0;i < 4;i++){
		Enemy * enemy = enemyVector.at(i);
		enemy->pauseSchedulerAndActions();
		DelayTime * dt = DelayTime::create(10);
		CallFunc * cf = CallFunc::create([=](){
			enemy->resumeSchedulerAndActions();
			enemy->schedule(schedule_selector(Enemy::changejd),6); 
			enemy->schedule(schedule_selector(Enemy::addFire), 1.2);
			enemy->schedule(schedule_selector(Enemy::move),enemy->getSpeed());
		});
		Sequence * seq = Sequence::create(dt,cf,NULL);
		enemy->runAction(seq);
	}
}